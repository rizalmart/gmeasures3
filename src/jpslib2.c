/***************************************************************************
    file        : jpslib2.c
    project     : JPS Library for GTK2
    date        : 2007.01.22
    copyright   : (C)2007 Paul Schuurmans
    email       : paul.schuurmans@home.nl
***************************************************************************/

/***************************************************************************
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Library General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
***************************************************************************/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>

#include "support.h"
#include "jpslib2.h"

unsigned char B64List[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Miscellaneous Utility Functions ///////////////////////////////////////////

char *B64Encode (char *result, unsigned long val)
{
	char res[7];
	int i;
	res[0] = B64List[(val & 0xc0000000) >> 30];
	res[1] = B64List[(val & 0x3f000000) >> 24];
	res[2] = B64List[(val & 0x00fc0000) >> 18];
	res[3] = B64List[(val & 0x0003f000) >> 12];
	res[4] = B64List[(val & 0x00000fc0) >> 6];
	res[5] = B64List[(val & 0x0000003f)];
	res[6] = 0;
	for(i = 0; i < 5; i++) {
		if(res[i] != B64List[0]) {
			strcpy(result, res+i);
			return(result);
		}
	}
	strcpy(result, res+5);
	return(result);
}

void ClearArray(GPtrArray *a)
{
	int i;
	for(i = a->len - 1; i >= 0; i--)  g_ptr_array_remove_index(a, i);
}

gchar *ComboGetActiveText (GtkComboBox *combobox)
{
	GtkTreeIter iter;
	gchar *text = NULL;
	GtkTreeModel *model = gtk_combo_box_get_model(combobox);
	if(gtk_combo_box_get_active_iter(combobox, &iter))  gtk_tree_model_get(model, &iter, 0, &text, -1);
	return(text);
}

int ComboGetSelectedItem (GtkWidget *combo)
{
	GList *list, *sel;
	gpointer p;
	//list = GTK_LIST(GTK_COMBO(combo)->list)->children;
	
	GtkTreeModel *model = gtk_combo_box_get_model(GTK_COMBO_BOX(combo));
	GList *combolist = NULL;

	if (GTK_IS_LIST_STORE(model)) {
		GtkListStore *list_store = GTK_LIST_STORE(model);
		GtkTreeIter iter;
		gboolean valid = gtk_tree_model_get_iter_first(model, &iter);

		while (valid) {
			gpointer item;
			gtk_tree_model_get(model, &iter, 0, &item, -1);
			combolist = g_list_append(combolist, item);
			valid = gtk_tree_model_iter_next(model, &iter);
		}
	}
	
	GtkListBox *list_box = GTK_LIST_BOX(combolist);
	list = gtk_container_get_children(GTK_CONTAINER(list_box));
	sel = gtk_list_box_get_selected_row(list_box);
	
	//list = GTK_LIST(GTK_COMBO(combo)->list)->children;
	//sel = GTK_LIST(GTK_COMBO(combo)->list)->selection;
	
		
	
	p = g_list_nth_data(sel, 0);
	return(g_list_index(list, p));
}

void EditorAppendText (GtkTextView *tw, char *txt)
{
	GtkTextIter iter;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_iter_at_offset(buffer, &iter, -1);
	gtk_text_buffer_place_cursor(buffer, &iter);
	gtk_text_buffer_insert(buffer, &iter, txt, strlen(txt));
}

void EditorClear (GtkTextView *tw)
{
	GtkTextIter startiter, enditer;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_bounds(buffer, &startiter, &enditer);
	gtk_text_buffer_delete(buffer, &startiter, &enditer);
}

void EditorDeleteLine (GtkTextView *tw, int linenum)
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	int startpos, endpos;
	GtkTextIter startiter, enditer;
	EditorGetLineOffsets(tw, linenum, &startpos, &endpos);
	gtk_text_buffer_get_iter_at_offset(buffer, &startiter, startpos);
	gtk_text_buffer_get_iter_at_offset(buffer, &enditer, endpos+1);
	gtk_text_buffer_delete(buffer, &startiter, &enditer);
}

void EditorGetCurIter (GtkTextView *tw, GtkTextIter *iter)
{
	GtkTextMark *mark;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, iter, mark);
}

char *EditorGetCurLine (GtkTextView *tw)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;
	gint curline, linelen;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start, &end);
	curline = EditorGetCurLineNum(tw);
	gtk_text_buffer_get_iter_at_line(buffer, &start, curline);
	linelen = EditorGetCurLineLen(tw);
	gtk_text_iter_set_line_offset(&end, linelen-1);
	return(gtk_text_buffer_get_text(buffer, &start, &end, FALSE));
}

int EditorGetCurLineLen (GtkTextView *tw)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	return(gtk_text_iter_get_chars_in_line(&start_iter));
}

int EditorGetCurLineNum (GtkTextView *tw)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	return(gtk_text_iter_get_line(&start_iter));
}

char *EditorGetCurWord (GtkTextView *tw, GtkTextIter *start_iter, GtkTextIter *end_iter)
{
	GtkTextBuffer *buffer;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, start_iter, end_iter);
	if(gtk_text_iter_starts_word(start_iter)) {
		gtk_text_iter_forward_word_end(end_iter);
	}
	else if(gtk_text_iter_ends_word(start_iter)) {
		gtk_text_iter_backward_word_start(start_iter);
	}
	else if(gtk_text_iter_inside_word(start_iter)) {
		gtk_text_iter_backward_word_start(start_iter);
		gtk_text_iter_forward_word_end(end_iter);
	}
	return(gtk_text_buffer_get_text(buffer, start_iter, end_iter, FALSE));
}

char *EditorGetLine (GtkTextView *tw, int linenum)
{
	GtkTextIter start_iter, end_iter;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_bounds(buffer, &start_iter, &end_iter);
	gtk_text_iter_set_line(&start_iter, linenum);
	gtk_text_iter_set_line(&end_iter, linenum);
	if(!gtk_text_iter_ends_line(&end_iter))  gtk_text_iter_forward_to_line_end(&end_iter);
	return(gtk_text_iter_get_text(&start_iter, &end_iter));
}

void EditorGetLineIters (GtkTextView *tw, int linenum, GtkTextIter *start, GtkTextIter *end)
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_bounds(buffer, start, end);
	gtk_text_iter_set_line(start, linenum);
	gtk_text_iter_set_line(end, linenum);
	gtk_text_iter_forward_to_line_end(end);
}

void EditorGetLineOffsets (GtkTextView *tw, int linenum, int *start, int *end)
{
	GtkTextIter start_iter, end_iter;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_bounds(buffer, &start_iter, &end_iter);
	gtk_text_iter_set_line(&start_iter, linenum);
	*start = gtk_text_iter_get_offset(&start_iter);
	gtk_text_iter_set_line(&end_iter, linenum);
	gtk_text_iter_forward_to_line_end(&end_iter);
	*end = gtk_text_iter_get_offset(&end_iter);
}

int EditorGetNumLines (GtkTextView *tw)
{
	return(gtk_text_buffer_get_line_count(gtk_text_view_get_buffer(tw)));
}

int EditorGetSelectedLineNums (GtkTextView *tw, int *startline, int *endline)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	int linecount = 0;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	*startline = gtk_text_iter_get_line(&start_iter);
	*endline = gtk_text_iter_get_line(&end_iter);
	if(gtk_text_iter_starts_line(&end_iter))  (*endline)--;
	linecount = (*endline - *startline) + 1;
	return(linecount);
}

char *EditorGetSelectedText (GtkTextView *tw, int *start, int *end, int *selcount)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	*start = gtk_text_iter_get_offset(&start_iter);
	*end = gtk_text_iter_get_offset(&end_iter);
	*selcount = *end - *start;
	return(gtk_text_buffer_get_text(buffer, &start_iter, &end_iter, FALSE));
}

gboolean EditorHasSelection (GtkTextView *tw)
{
	GtkTextIter start_iter, end_iter;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	return(gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter));
}

int EditorInsertLine (GtkTextView *tw, int linenum, char *txt)
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	GtkTextIter iter;
	gtk_text_buffer_get_iter_at_line_offset(buffer, &iter, linenum, 0);
	gtk_text_buffer_place_cursor(buffer, &iter);
	gtk_text_buffer_insert(buffer, &iter, txt, strlen(txt));
	return(gtk_text_iter_get_offset(&iter));
}

int EditorMoveToLineEnd (GtkTextView *tw)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	gtk_text_iter_set_line_offset(&end_iter, strlen(EditorGetCurLine(tw)));
	gtk_text_buffer_place_cursor(buffer, &end_iter);
	return(gtk_text_iter_get_offset(&end_iter));
}

int EditorMoveToLineStart (GtkTextView *tw)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	gint pos;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	pos = gtk_text_iter_get_line_offset(&start_iter);
	gtk_text_iter_backward_chars(&start_iter, pos);
	gtk_text_buffer_place_cursor(buffer, &start_iter);
	return(gtk_text_iter_get_offset(&start_iter));
}

gboolean EditorSelectLine (GtkTextView *tw, int linenum, gboolean del_eol)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	int start = 0, end = 0;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_bounds(buffer, &start_iter, &end_iter);
	gtk_text_iter_set_line(&start_iter, linenum);
	gtk_text_iter_set_line(&end_iter, linenum);
	if(gtk_text_iter_starts_line(&start_iter) && gtk_text_iter_ends_line(&start_iter))  return(FALSE);
	if(del_eol)  gtk_text_iter_forward_line(&end_iter);
	gtk_text_iter_forward_to_line_end(&end_iter);
	start = gtk_text_iter_get_offset(&start_iter);
	end = gtk_text_iter_get_offset(&end_iter);
	gtk_text_buffer_select_range(buffer, &start_iter, &end_iter);
	return(TRUE);
}

gboolean EditorSelectOneChar (GtkTextView *tw)
{
	GtkTextIter start_iter, end_iter;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	end_iter = start_iter;
	if(gtk_text_iter_forward_char(&end_iter) == FALSE)  return(FALSE);
	gtk_text_buffer_select_range(buffer, &start_iter, &end_iter);
	return(TRUE);
}

void EditorSetSelectedText (GtkTextView *tw, char *text)
{
	GtkTextBuffer *buffer;
	GtkTextIter start_iter, end_iter;
	buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_selection_bounds(buffer, &start_iter, &end_iter);
	gtk_text_buffer_delete(buffer,  &start_iter, &end_iter);
	gtk_text_buffer_insert(buffer, &start_iter, text, -1);
}

void EditorTextCen (GtkTextView *tw, int center, int width, int usetab)
{
	GtkTextIter iter;
	char line[1024], temp[1024];
	int i, startline, endline, linecnt, linelen;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	linecnt = EditorGetSelectedLineNums(tw, &startline, &endline);
	if(!linecnt) {
		startline = endline = EditorGetCurLineNum(tw);
		linecnt = 1;
	}
	for(i = startline; i < startline + linecnt; i++) {
		strcpy(line, EditorGetLine(tw, i));
		linelen = strlen(line);
		if(!linelen || (width <= linelen) || (!center && line[0] != ' ')) {
			EditorGetCurIter(tw, &iter);
			if(gtk_text_iter_forward_line(&iter)) {
				gtk_text_buffer_place_cursor(buffer, &iter);
			}
			continue;
		}
		StrCvt(line, RLWHITE | RTWHITE);
		if(center) {
			strcpy(temp, line);
			StrJustify(line, temp, ' ', width, JUST_CENTER);
			if(usetab)  StrTabfy(line, 8);
			StrCvt(line, RTWHITE);
		}
		EditorDeleteLine(tw, i);
		strcat(line, "\n");
		EditorInsertLine(tw, i, line);
	}
}

void EditorTextChangeCase (GtkTextView *tw)
{
	gboolean ok;
	char *text;
	int start, end, selcount;
	if(!EditorHasSelection(tw)) {
		ok = EditorSelectOneChar (tw);
		if(!ok)  return;
	}
	text = EditorGetSelectedText(tw, &start, &end, &selcount);
	StrCvt(text, TOCASE);
	EditorSetSelectedText(tw, text);
	g_free(text);
}

void EditorTextConcatenateLines (GtkTextView *tw)
{
	gchar *txt;
	char *line;
	int len, ndx;
	GtkTextIter start, end;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	if(!gtk_text_buffer_get_selection_bounds(buffer, &start, &end))  return;
	txt = gtk_text_iter_get_text(&start, &end);
	len = strlen(txt);
	line = g_malloc0(len+2);
	strcpy(line, txt);
	for(ndx = 0; ndx < strlen(line); ndx++) {
		if(line[ndx] == '\n')  line[ndx] = ' ';
	}
	EditorSetSelectedText(tw, line);
	g_free(line);
}

void EditorTextSplitLine (GtkTextView *tw, int linelen)
{
	GtkTextIter start, end;
	char *txt, *line;
	int len, ndx;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	EditorGetCurIter(tw, &start);
	if(gtk_text_iter_is_end(&start))  return;
	txt = EditorGetCurLine(tw);
	len = strlen(txt);
	if(len <= linelen)  return;
	line = g_malloc0(len+2);
	strcpy(line, txt);
	for(ndx = linelen; ndx; ndx--) {
		if(line[ndx] == ' ') {
			line[ndx] = '\n';
			break;
		}
	}
	ndx = EditorGetCurLineNum(tw);
	EditorDeleteLine(tw, ndx);
	strcat(line, "\n");
	EditorInsertLine(tw, ndx, line);
	g_free(line);
	EditorGetLineIters(tw, ndx+1, &start, &end);
	gtk_text_buffer_place_cursor(buffer, &start);
}

void EditorTextTabify (GtkTextView *tw, int tabify, int tabsize)
{
	GtkTextIter iter;
	char line[1024], temp[1024];
	int i, startline, endline, linecnt, linelen;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	linecnt = EditorGetSelectedLineNums(tw, &startline, &endline);
	if(!linecnt) {
		startline = endline = EditorGetCurLineNum(tw);
		linecnt = 1;
	}
	for(i = startline; i < startline + linecnt; i++) {
		strcpy(line, EditorGetLine(tw, i));
		linelen = strlen(line);
		if(!linelen) {
			EditorGetCurIter(tw, &iter);
			if(gtk_text_iter_forward_line(&iter)) {
				gtk_text_buffer_place_cursor(buffer, &iter);
			}
			continue;
		}
		if(tabify)  StrTabfy(line, tabsize);
		else {
			strcpy(temp, line);
			StrExpand(line, temp, tabsize, linelen * tabsize);
		}
		EditorDeleteLine(tw, i);
		strcat(line, "\n");
		EditorInsertLine(tw, i, line);
	}
}

void EditorTextTitleCase (GtkTextView *tw)
{
	char *text;
	int i, start, end, selcount;
	text = EditorGetSelectedText(tw, &start, &end, &selcount);
	if(!selcount) { g_free(text); return; }
	text[0] = toupper(text[0]);
	for(i = 1; i < selcount; i++) {
		switch(text[i-1]) {
		  case ' ': case '-': case '\r': case '\n': case '.': case '(': case '[':
		  case '\"':  case '{': case '/':
			text[i] = toupper(text[i]);
			break;
		  default:
			text[i] = tolower(text[i]);
			break;
		}
	}
	EditorSetSelectedText(tw, text);
	g_free(text);
}

int FileExists (char *path)
{
	return(access(path, 0) == 0);
}

int FileSize (char *name)
{
	int eof_ftell;
	FILE *file;
	file = fopen(name, "r");
	if(file == NULL)  return(0L);
	fseek(file, 0, SEEK_END);
	eof_ftell = ftell(file);
	fclose(file);
	return(eof_ftell);
}

void FnExpand (char *rpath, char *defext)
{
	char path[MAXPATH], dir[MAXDIR], file[MAXFILE], ext[MAXEXT], *temp;
	int flags;
	strcpy(path, rpath);
	flags = FnSplit(path, dir, file, ext);
	if(!(flags & FN_DIR)) {
		temp = g_malloc0(MAXPATH);
		getcwd(temp, MAXDIR - 1);
		strcpy(dir, temp);
		g_free(temp);
	}
	if(!(flags & FN_EXT) && defext)  strcpy(ext, defext);
	FnMerge(rpath, dir, file, ext);
}

void FnMerge (char *rpath, char *dir, char *file, char *ext)
{
	int len = 0;
	strcpy(rpath, dir);
	len = strlen(dir);
	if(len && rpath[len-1] != '/')  strcat(rpath, "/");
	strcat(rpath, file);
	if(ext != NULL && strlen(ext)) {
		if(ext[0] != '.')  strcat(rpath, ".");
		strcat(rpath, ext);
	}
}

int FnSplit (char *rpath, char *dir, char *file, char *ext)
{
	int retval = 0, ndx = 0, len;
	strcpy(dir, g_dirname(rpath));
	if((len = strlen(dir))) {
		if(len == 1 && dir[0] == '.')  dir[0] = 0;
		else  retval += FN_DIR;
	}
	strcpy(file, g_basename(rpath));
	if(strlen(file))  retval += FN_FILE;
	ndx = StrChrIndex('.', file);
	if(ndx != -1) {
		strcpy(ext, file+ndx+1);
		*(file+ndx) = 0;
	}
	else  ext[0] = 0;
	if(strlen(ext))  retval += FN_EXT;
	return(retval);
}

void GetConfigBool (FILE *fn, char *key, gboolean *bval, gboolean bdef)
{
	char line[1024] = "", txt[1024] = "";
	int len = strlen(key);
	if(fn != NULL) {
		fseek(fn, 0, SEEK_SET);
		while(ReadLine(fn, line, 1023) != -1) {
			if(!strncmp(key, line, len)) {
				strcpy(txt, line+len+1);
				if(!strcmp(txt, "TRUE") || !strcmp(txt, "true") || !strcmp(txt, "True")) *bval = TRUE;
				else  *bval = FALSE;
				break;
			}
		}
	}
	else  *bval = bdef;
}

void GetConfigInt (FILE *fn, char *key, int *nval, int ndef)
{
	char line[1024] = "", txt[1024] = "";
	int len, i, keylen = strlen(key);
	if(fn != NULL) {
		fseek(fn, 0, SEEK_SET);
		while(ReadLine(fn, line, 1023) != -1) {
			if(!strncmp(key, line, keylen)) {
				strcpy(txt, line+keylen+1);
				len = strlen(txt);
				for(i = 0; i < len; i++) {
					switch(txt[i]) {
					  case '0': case '1': case '2': case '3': case '4': case '5': 
					  case '6': case '7': case '8': case '9':  break;
					  default:  len = 0;  break;
					}
				}
				if(len)  *nval = atoi(txt);
				else  *nval = -1;
				break;
			}
			else  *nval = ndef;
		}
	}
	else  *nval = ndef;
}

void GetConfigString (FILE *fn, char *key, char *sval, char *sdef)
{
	char line[1024] = "";
	int len = strlen(key);
	if(fn != NULL) {
		fseek(fn, 0, SEEK_SET);
		while(ReadLine(fn, line, 1023) != -1) {
			if(!strncmp(key, line, len)) {
				strcpy(sval, line+len+1);
				break;
			}
		}
	}
	else {
		if(strlen(sdef))  strcpy(sval, sdef);
		else  strcpy(sval, "");
	}
}

gboolean GetWidgetValBool (GtkWidget *parent, char *name, gboolean defval)
{
	GtkWidget *w;
	if((w = lookup_widget(parent, name)) == 0) {
		g_print("Widget Not Found: %s", name);
		return(defval);
	}
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w)))  return(TRUE);
	return(FALSE);
}

int GetWidgetValInt (GtkWidget *parent, char *name, int defval)
{
	GtkWidget *w;
	gchar *txt = NULL;
	int i, len = 0, nval = 0;
	if((w = lookup_widget(parent, name)) == 0) {
		g_print("Widget Not Found: %s", name);
		return(defval);
	}
	txt = gtk_editable_get_chars(GTK_EDITABLE(w), 0, -1);
	len = strlen(txt);
	for(i = 0; i < len; i++) {
		switch(txt[i]) {
		  case '0': case '1': case '2': case '3': case '4': case '5': 
		  case '6': case '7': case '8': case '9':  break;
		  default:  len = 0;  break;
		}
	}
	if(len)  nval = atoi(txt);
	else  nval = defval;
	g_free(txt);
	return(nval);
}

char *GetWidgetValString (GtkWidget *parent, char *name, char *sval, char *defval)
{
	GtkWidget *w;
	gchar *txt = NULL;
	if((w = lookup_widget(parent, name)) == 0) {
		g_print("Widget Not Found: %s", name);
		strcpy(sval, defval);
		return(sval);
	}
	txt = gtk_editable_get_chars(GTK_EDITABLE(w), 0, -1);
	strcpy(sval, txt);
	g_free(txt);
	return(sval);
}

gboolean IsDirectory (char *filename)
{
	struct stat st;
	if(stat(filename, &st) != 0)  return(FALSE);
	if(S_ISDIR(st.st_mode))  return(TRUE);
	return(FALSE);
}

int ReadLine (FILE *rfile, char *line, int maxlinesize)
{
	int ch, c = 0;
	do {
		ch = getc(rfile);
		if((ch == EOF) || (ch == -1)) return(-1);
		if(ch == 13)  continue;
		if(ch == 10) break;
		line[c] = ch;
		c++;
	} while(c < maxlinesize && ch != 10);
	line[c] = 0;
	return(c);
}

gboolean SetFileAttribs (char *filename, time_t *tstamp, int mode, uid_t owner, gid_t group)
{
	struct utimbuf timebuf;
	if(!FileExists(filename))  return(FALSE);
	timebuf.modtime = *tstamp;
	utime(filename, &timebuf);
	if(!mode)  mode = S_IREAD|S_IWRITE;
	chmod(filename, mode);
	chown(filename, owner, group);
	return(TRUE);
}

int StrChrIndex (char check, char *psearch)
{
	char *p;
	if((p = strchr(psearch, check)) == NULL)  return (-1);
	return((int) (p - psearch));
}

char *StrCvt (char *psource, int conv)
{
	char *pfrom = psource;	       //Next character to get fron source
	char *pto = psource;  // Next position to fill in target
	char c;
	char quote_char = '\0';
	int rlwhite = conv & RLWHITE;
	int rwhite = conv & RWHITE;
	int reduce = (!rwhite) && (conv & REDUCE);
	int ckquotes = conv & NOQUOTE;
	int to_up = conv & TOUP;
	int to_low = conv & TOLOW;
	int rcontrol = conv & RCONTROL;
	int to_case = conv & TOCASE;
	int in_white = FALSE;   	// Not in a white field yet.
	int hit_nonwhite = FALSE;   	// No nonwhite chars encountered.
	int quote_on = FALSE;   	// Not in a quote yet.
	while((c = *pfrom++) != '\0') {
		if(quote_on) {
			*pto++ = c;
			if(c == quote_char)  quote_on = FALSE;
		}
		else if (ckquotes && ((c == '"') || (c == '\''))) {
			*pto++ = c;
			in_white = FALSE;
			hit_nonwhite = TRUE;
			quote_on = TRUE;
			quote_char = c;
		}
		else if(isspace(c) && isascii(c)) {
			if(rwhite)  ;
			else if(rlwhite && !hit_nonwhite)  ;
			else if(reduce) {
				if(in_white)  ;
				else {
					*pto++ = BLANK;
					in_white = TRUE;
				}
			}
			else if(rcontrol && iscntrl(c))  ;
			else  *pto++ = c;
		}
		else if(iscntrl(c) && isascii(c)) {
			in_white = FALSE;
			hit_nonwhite = TRUE;
			if (rcontrol)  ;
			else  *pto++ = c;
		}
		else {
			in_white = FALSE;
			hit_nonwhite = TRUE;
			if(isascii(c)) {
				if(to_up)  c = toupper(c);
				if(to_low)  c = tolower(c);
				if(to_case)  c = islower(c) ? toupper(c) : tolower(c);
			}
			*pto++ = c;
		}
	}
	*pto = '\0';
	if(conv & RTWHITE)
		for (c = *--pto; isspace(c) && isascii(c) && (pto >= psource); c = *--pto)
			*pto = '\0';
	return (psource);
}

char *StrExpand (char *ptarget, char *psource, int incr, int tarsize)
{
	char c;
	int numspaces;
	int len = 0;
	tarsize--;
	while(((c = *psource) != NUL) && (len < tarsize)) {
		switch(c) {
		  case TAB:
			if((incr > 0) && ((numspaces = (incr - (len % incr))) != 0)) {
				if((len += numspaces) < tarsize) {
					while(numspaces--) *ptarget++ = BLANK;
					break;
				}
				else   continue;	// There isn't enough room, so quit
			}
		  default:
			*ptarget++ = c;
			len++;
			break;
		}
		psource++;
	}
	*ptarget = '\0';
	return(c ? psource : NULL);
}

char *StrJustify (char *ptarget, char *psource, char fill, int fldsize, int code)
{
	int diff,i;
	int numleft;
	char *savetarget = ptarget;
	if(fldsize < 0)  fldsize = 0;
	if((diff = ((int) strlen(psource)) - fldsize) >= 0) {
		switch (code) {
		  case JUST_RIGHT:  psource += diff;  break;
		  case JUST_CENTER:  psource += diff >> 1;  break;
		  case JUST_LEFT:
		  default:  break;
		}
		while (fldsize--)  *ptarget++ = *psource++;
	}
	else {
		diff = -diff;
		switch(code) {
		  case JUST_RIGHT:  numleft = diff;  break;
		  case JUST_CENTER:  numleft = diff / 2;  break;
		  case JUST_LEFT:
		  default:  numleft = 0;  break;
		}
		for(i = numleft; i; i--)  *ptarget++ = fill;
		while(*psource)  *ptarget++ = *psource++;
		for (i = diff - numleft; i; i--)  *ptarget++ = fill;
	}
	*ptarget = '\0';
	return(savetarget);
}

int StrPos (char *searchstr, char *targstr, gboolean caseflag)
{
	int c = 0, c1 = 0;
	if(searchstr[0] == 0 || targstr[0] == 0)  return(-1);
	else {
		while(targstr[c] && searchstr[c1]) {
			if(caseflag) {
				if(targstr[c] == searchstr[c1])  c1++;
				else  c1 = 0;
				c++;
			}
			else {
				if(toupper(targstr[c]) == toupper(searchstr[c1]))  c1++;
				else  c1 = 0;
				c++;
			}
		}
		if(searchstr[c1] == 0)	return(c - c1);
		else  return(-1);
	}
}

char *StrTabfy (char *psource, int incr)
{
	char c;
	int col = 0, numblanks = 0;
	char *pfrom = psource;
	char *pto = psource;
	do {
		switch(c = *pfrom++) {
		  case BLANK:
			numblanks++;
			col++;
			if((incr <= 0) || (col % incr == 0)) {
				*pto++ = (char) ((numblanks > 1) ? TAB : BLANK);
				numblanks = 0;
			}
			break;
		  case TAB:
			col = numblanks = 0;
			*pto++ = TAB;
			break;
		  default:
			col++;
			for(; numblanks; numblanks--)  *pto++ = BLANK;
			*pto++ = c;
			break;
		}
	} while(c);
	return(psource);
}

gchar *TextViewGetText (GtkTextView *tw)
{
	GtkTextIter start, end;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	gtk_text_buffer_get_start_iter(buffer, &start);
	gtk_text_buffer_get_end_iter(buffer, &end);
	return(gtk_text_buffer_get_text(buffer, &start, &end, FALSE));
}

void TextViewSetText (GtkTextView *tw, gchar *text)
{
	gchar *utf8str;
	gssize len;
	gsize bytes_read, bytes_written;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(tw);
	len = strlen(text);
	utf8str = g_locale_to_utf8(text, len, &bytes_read, &bytes_written, NULL);
	gtk_text_buffer_set_text(buffer, utf8str, -1);
	g_free(utf8str);
}

int TreeViewGetSelCount (GtkWidget *parent, char *name)
{
	GtkTreeView *treeview;
	GtkTreeSelection *selection;
	treeview = (GtkTreeView *) lookup_widget(GTK_WIDGET(parent), name);
	selection = gtk_tree_view_get_selection(treeview);
	return(gtk_tree_selection_count_selected_rows(selection));
}

int TreeViewGetSelIndex (GtkWidget *parent, char *name)
{
	GtkTreeView *treeview;
	GtkListStore *liststore;
	GtkTreeSelection *selection;
	GtkTreeIter iter;
	gboolean valid;
	GtkTreePath *path;
	gchar *pathstr;
	int ndx = -1;
	treeview = (GtkTreeView *) lookup_widget(GTK_WIDGET(parent), name);
	liststore = (GtkListStore *) gtk_tree_view_get_model(treeview);
	selection = gtk_tree_view_get_selection(treeview);
	valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(liststore), &iter);
	while(valid) {
		if(gtk_tree_selection_iter_is_selected(selection, &iter)) {
			path = gtk_tree_model_get_path(GTK_TREE_MODEL(liststore), &iter);
			pathstr = gtk_tree_path_to_string(path);
			ndx = atoi(pathstr);
			g_free(pathstr);
			break;
		}
		valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(liststore), &iter);
    }	
	return(ndx);
}

gboolean TreeViewSelectRow (GtkWidget *parent, char *name, int row)
{
	GtkTreeView *treeview;
	GtkTreeSelection *selection;
	GtkTreePath *path;
	treeview = (GtkTreeView *) lookup_widget(GTK_WIDGET(parent), name);
	if(!G_IS_OBJECT(treeview))  return(FALSE);
	selection = gtk_tree_view_get_selection(treeview);
	path = gtk_tree_path_new_from_indices(row, -1);
	gtk_tree_selection_select_path(selection, path);
	return(TRUE);
}

