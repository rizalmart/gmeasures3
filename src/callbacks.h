/***************************************************************************
    file        : callbacks.h
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
 
#include <gtk/gtk.h>

void on_aboutdlg_btn_close_clicked (GtkButton *button, gpointer user_data);
void on_app_destroy (GObject *object, gpointer user_data);
void on_app_show (GtkWidget *widget, gpointer user_data);
void on_btn_about_clicked (GtkButton *button, gpointer user_data);
void on_btn_edit_add_clicked (GtkButton *button, gpointer user_data);
void on_btn_exit_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_0_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_1_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_2_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_3_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_4_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_5_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_6_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_7_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_8_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_9_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_bksp_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_clear_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_dot_clicked (GtkButton *button, gpointer user_data);
void on_btn_num_minus_clicked (GtkButton *button, gpointer user_data);
void on_combo_unit1_changed (GtkComboBox *combobox, gpointer user_data);
void on_combo_unit2_changed (GtkComboBox *combobox, gpointer user_data);
void on_editdlg_btn_cancel_clicked (GtkButton *button, gpointer user_data);
void on_editdlg_btn_delete_clicked (GtkButton *button, gpointer user_data);
void on_editdlg_btn_ok_clicked (GtkButton *button, gpointer user_data);
void on_editdlg_entry_unit1_changed (GtkEditable *editable, gpointer user_data);
void on_editdlg_entry_unit2_changed (GtkEditable *editable, gpointer user_data);
void on_sb_entry_cdegrees_changed (GtkEditable *editable, gpointer user_data);
void on_sb_entry_cdegrees_grab_focus (GtkWidget *widget, gpointer user_data);
void on_sb_entry_fdegrees_changed (GtkEditable *editable, gpointer user_data);
void on_sb_entry_fdegrees_grab_focus (GtkWidget *widget, gpointer user_data);
void on_sb_entry_val1_changed (GtkEditable *editable, gpointer user_data);
void on_sb_entry_val1_grab_focus (GtkWidget *widget, gpointer user_data);


