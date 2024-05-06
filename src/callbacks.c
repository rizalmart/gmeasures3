/***************************************************************************
    file        : callbacks.c
    project     : gMeasures
    date        : 2007.02.01 (v0.7)
    copyright   : (C)2007 by Paul Schuurmans
    email       : paul.schuurmans@home.nl
 ***************************************************************************/
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
 
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "main.h"

extern GtkWidget *App, *EditDlg, *AboutDlg;
extern GPtrArray *Msr;
extern int Mode, InSetup;

void on_app_show (GtkWidget *widget, gpointer user_data)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Unit1", renderer, "text", LIST_UNIT1, NULL);
	gtk_tree_view_column_set_clickable(column, FALSE);
	gtk_tree_view_column_set_sort_column_id(column, LIST_UNIT1);
	InSetup = 1;
	AppSetUnit1();
	AppUpdateUnit2();
	InSetup = 0;
}

void on_app_destroy (GObject *object, gpointer user_data)
{
	gtk_main_quit();
}

void on_aboutdlg_btn_close_clicked (GtkButton *button, gpointer user_data)
{
	gtk_widget_hide(AboutDlg);
}

void on_btn_about_clicked (GtkButton *button, gpointer user_data)
{
	if(!G_IS_OBJECT(AboutDlg))  AboutDlg = create_AboutDlg();
	gtk_widget_show(AboutDlg);
}

void on_btn_edit_add_clicked (GtkButton *button, gpointer user_data)
{
	GtkWidget *w;
	TMeasuresInfo *m;
	char text[64] = "";
	if(!G_IS_OBJECT(EditDlg))  EditDlg = create_EditDlg();
	m = AppGetMeasure();
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_entry_unit1");
	gtk_entry_set_text(GTK_ENTRY(w), m->Unit1);
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_entry_value");
	sprintf(text, "%g", m->Equals);
	gtk_entry_set_text(GTK_ENTRY(w), text);
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_entry_unit2");
	gtk_entry_set_text(GTK_ENTRY(w), m->Unit2);
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_btn_delete");
	gtk_widget_set_sensitive(w, TRUE);
	gtk_widget_show(EditDlg);
}

void on_btn_exit_clicked (GtkButton *button, gpointer user_data)
{
	gtk_main_quit();
}

void on_btn_num_0_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("0");
}

void on_btn_num_1_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("1");
}

void on_btn_num_2_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("2");
}

void on_btn_num_3_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("3");
}

void on_btn_num_4_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("4");
}

void on_btn_num_5_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("5");
}

void on_btn_num_6_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("6");
}

void on_btn_num_7_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("7");
}

void on_btn_num_8_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("8");
}

void on_btn_num_9_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("9");
}

void on_btn_num_bksp_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("B");
}

void on_btn_num_clear_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("C");
}

void on_btn_num_dot_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked(".");
}

void on_btn_num_minus_clicked (GtkButton *button, gpointer user_data)
{
	AppNumPadClicked("-");
}

void on_combo_unit1_changed (GtkComboBox *combobox, gpointer user_data)
{
	Mode = 0;
	if(!InSetup)  AppUpdateUnit2();
}

void on_combo_unit2_changed (GtkComboBox *combobox, gpointer user_data)
{
	Mode = 0;
	if(!InSetup)  AppCalculate();
}

void on_editdlg_btn_cancel_clicked (GtkButton *button, gpointer user_data)
{
	gtk_widget_hide(EditDlg);
}

void on_editdlg_btn_delete_clicked (GtkButton *button, gpointer user_data)
{
	TMeasuresInfo *m;
	m = AppGetMeasure();
	g_ptr_array_remove(Msr, m);
	AppReadWriteConfig(OF_WRITE);
	InSetup = 1;
	AppSetUnit1();
	InSetup = 0;
	gtk_widget_hide(EditDlg);
	on_combo_unit1_changed(NULL, NULL);
}

void on_editdlg_btn_ok_clicked (GtkButton *button, gpointer user_data)
{
	GtkWidget *w;
	GtkTreeModel *model;
	GtkTreeIter iter;
	TMeasuresInfo *m, *mn = NULL;
	gboolean valid;
	char unit1[64], unit2[64], value[64];
	gchar *text;
	int cnt, ndx = 0;
	m = AppGetMeasure();
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_entry_unit1");
	strcpy(unit1, gtk_entry_get_text(GTK_ENTRY(w)));
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_entry_unit2");
	strcpy(unit2, gtk_entry_get_text(GTK_ENTRY(w)));
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_entry_value");
	strcpy(value, gtk_entry_get_text(GTK_ENTRY(w)));
	if(strcasecmp(unit1, m->Unit1) || strcasecmp(unit2, m->Unit2)) {
		mn = g_malloc0(sizeof(TMeasuresInfo));
		strcpy(mn->Unit1, unit1);
		strcpy(mn->Unit2, unit2);
		mn->Equals = atof(value);
		g_ptr_array_add(Msr, mn);
	}
	else {
		strcpy(m->Unit1, unit1);
		strcpy(m->Unit2, unit2);
		m->Equals = atof(value);
	}
	AppReadWriteConfig(OF_WRITE);
	InSetup = 1;
	AppSetUnit1();
	if(mn)  m = mn;
	w = lookup_widget(GTK_WIDGET(App), "combo_unit1");
	model = gtk_combo_box_get_model(GTK_COMBO_BOX(w));
	cnt = gtk_tree_model_iter_n_children(model, NULL);
	valid = gtk_tree_model_get_iter_first(model, &iter);
	while(valid) {
	    gtk_tree_model_get(model, &iter, LIST_UNIT1, &text, -1);
		if(!strcasecmp(m->Unit1, text)) {
			gtk_combo_box_set_active(GTK_COMBO_BOX(w), ndx);
			break;
		}
		ndx++;
		valid = gtk_tree_model_iter_next(model, &iter);
	}
	w = lookup_widget(GTK_WIDGET(App), "combo_unit2");
	model = gtk_combo_box_get_model(GTK_COMBO_BOX(w));
	cnt = gtk_tree_model_iter_n_children(model, NULL);
	ndx = 0;
	valid = gtk_tree_model_get_iter_first(model, &iter);
	while(valid) {
	    gtk_tree_model_get(model, &iter, LIST_UNIT1, &text, -1);
		if(!strcasecmp(m->Unit2, text)) {
			gtk_combo_box_set_active(GTK_COMBO_BOX(w), ndx);
			break;
		}
		ndx++;
		valid = gtk_tree_model_iter_next(model, &iter);
	}
	InSetup = 0;
	gtk_widget_hide(EditDlg);
	AppCalculate();
}

void on_editdlg_entry_unit1_changed (GtkEditable *editable, gpointer user_data)
{
	GtkWidget *w;
	TMeasuresInfo *m;
	gchar *text;
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_btn_delete");
	if(gtk_widget_get_sensitive(w)) {
		m = AppGetMeasure();
		text = gtk_editable_get_chars(editable, 0, -1);
		if(strcasecmp(m->Unit1, text))  gtk_widget_set_sensitive(w, FALSE);
		g_free(text);
	}
}

void on_editdlg_entry_unit2_changed (GtkEditable *editable, gpointer user_data)
{
	GtkWidget *w;
	TMeasuresInfo *m;
	gchar *text;
	w = lookup_widget(GTK_WIDGET(EditDlg), "editdlg_btn_delete");
	if(gtk_widget_get_sensitive(w)) {
		m = AppGetMeasure();
		text = gtk_editable_get_chars(editable, 0, -1);
		if(strcasecmp(m->Unit2, text))  gtk_widget_set_sensitive(w, FALSE);
		g_free(text);
	}
}

void on_sb_entry_cdegrees_changed (GtkEditable *editable, gpointer user_data)
{
	if(gtk_widget_has_focus(editable)) {
		Mode = 1;
		AppCalculate();
	}
}

void on_sb_entry_cdegrees_grab_focus (GtkWidget *widget, gpointer user_data)
{
	Mode = 1;
}

void on_sb_entry_fdegrees_changed (GtkEditable *editable, gpointer user_data)
{
	if(gtk_widget_has_focus(editable)) {
		Mode = 2;
		AppCalculate();
	}
}

void on_sb_entry_fdegrees_grab_focus (GtkWidget *widget, gpointer user_data)
{
	Mode = 2;
}

void on_sb_entry_val1_changed (GtkEditable *editable, gpointer user_data)
{
	Mode = 0;
	AppCalculate();
}

void on_sb_entry_val1_grab_focus (GtkWidget *widget, gpointer user_data)
{
	Mode = 0;
}


