/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    g_object_ref(widget), (GDestroyNotify) gtk_widget_unmap)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_App (void)
{
  GtkWidget *App;
  GtkWidget *hbox1;
  GtkWidget *vbox9;
  GtkWidget *frame1;
  GtkWidget *alignment1;
  GtkWidget *table_measures;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label19;
  GtkWidget *label4;
  GtkWidget *label28;
  GtkWidget *entry_val2;
  GObject *sb_entry_val1_adj;
  GtkWidget *sb_entry_val1;
  GtkWidget *combo_unit1;
  GtkWidget *combo_unit2;
  GtkWidget *label26;
  GtkWidget *frame2;
  GtkWidget *alignment2;
  GtkWidget *table_temperatures;
  GtkWidget *hbox11;
  GtkWidget *label6;
  GtkWidget *label23;
  GtkWidget *hbox12;
  GtkWidget *label11;
  GtkWidget *label24;
  GObject *sb_entry_cdegrees_adj;
  GtkWidget *sb_entry_cdegrees;
  GObject *sb_entry_fdegrees_adj;
  GtkWidget *sb_entry_fdegrees;
  GtkWidget *label8;
  GtkWidget *label20;
  GtkWidget *label27;
  GtkWidget *vseparator1;
  GtkWidget *vbox5;
  GtkWidget *btn_edit_add;
  GtkWidget *table1;
  GtkWidget *btn_num_1;
  GtkWidget *btn_num_2;
  GtkWidget *btn_num_3;
  GtkWidget *btn_num_4;
  GtkWidget *btn_num_5;
  GtkWidget *btn_num_6;
  GtkWidget *btn_num_7;
  GtkWidget *btn_num_8;
  GtkWidget *btn_num_9;
  GtkWidget *btn_num_0;
  GtkWidget *btn_num_dot;
  GtkWidget *btn_num_minus;
  GtkWidget *hbox8;
  GtkWidget *btn_num_bksp;
  GtkWidget *btn_num_clear;
  GtkWidget *hbox13;
  GtkWidget *btn_about;
  GtkWidget *btn_exit;

  App = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (App), "gMeasures 3.0");
  gtk_window_set_resizable (GTK_WINDOW (App), FALSE);
  gtk_window_set_type_hint (GTK_WINDOW (App), GDK_WINDOW_TYPE_HINT_DIALOG);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (App), hbox1);

  vbox9 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox9);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox9, TRUE, TRUE, 0);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (vbox9), frame1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame1), 4);
  gtk_frame_set_label_align (GTK_FRAME (frame1), 0.5, 0.5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_ETCHED_OUT);

  alignment1 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (frame1), alignment1);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment1), 0, 8, 8, 8);

  table_measures = gtk_table_new (3, 3, FALSE);
  gtk_widget_show (table_measures);
  gtk_container_add (GTK_CONTAINER (alignment1), table_measures);

  label1 = gtk_label_new ("  ");
  gtk_widget_show (label1);
  gtk_table_attach (GTK_TABLE (table_measures), label1, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label2 = gtk_label_new ("Equals :  ");
  gtk_widget_show (label2);
  gtk_table_attach (GTK_TABLE (table_measures), label2, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label19 = gtk_label_new ("  ");
  gtk_widget_show (label19);
  gtk_table_attach (GTK_TABLE (table_measures), label19, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label19), 0, 0.5);

  label4 = gtk_label_new ("  ");
  gtk_widget_show (label4);
  gtk_table_attach (GTK_TABLE (table_measures), label4, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label28 = gtk_label_new ("  ");
  gtk_widget_show (label28);
  gtk_table_attach (GTK_TABLE (table_measures), label28, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label28), 0, 0.5);

  entry_val2 = gtk_entry_new ();
  gtk_widget_show (entry_val2);
  gtk_table_attach (GTK_TABLE (table_measures), entry_val2, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_unset_state_flags(entry_val2, GTK_STATE_FOCUSED);
  gtk_editable_set_editable (GTK_EDITABLE (entry_val2), FALSE);
  gtk_entry_set_width_chars (GTK_ENTRY (entry_val2), 12);

  sb_entry_val1_adj = gtk_adjustment_new (1, 0, 100000000, 1, 10, 10);
  sb_entry_val1 = gtk_spin_button_new (GTK_ADJUSTMENT (sb_entry_val1_adj), 1, 0);
  gtk_widget_show (sb_entry_val1);
  gtk_table_attach (GTK_TABLE (table_measures), sb_entry_val1, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (sb_entry_val1, 96, -1);

  combo_unit1 = gtk_combo_box_text_new ();
  gtk_widget_show (combo_unit1);
  gtk_table_attach (GTK_TABLE (table_measures), combo_unit1, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_unset_state_flags(combo_unit1, GTK_STATE_FOCUSED);

  combo_unit2 = gtk_combo_box_text_new ();
  gtk_widget_show (combo_unit2);
  gtk_table_attach (GTK_TABLE (table_measures), combo_unit2, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_unset_state_flags(combo_unit2, GTK_STATE_FOCUSED);

  label26 = gtk_label_new ("<b>Weights and Measures</b>");
  gtk_widget_show (label26);
  gtk_frame_set_label_widget (GTK_FRAME (frame1), label26);
  gtk_label_set_use_markup (GTK_LABEL (label26), TRUE);
  gtk_label_set_justify (GTK_LABEL (label26), GTK_JUSTIFY_CENTER);
  gtk_misc_set_padding (GTK_MISC (label26), 4, 4);

  frame2 = gtk_frame_new (NULL);
  gtk_widget_show (frame2);
  gtk_box_pack_start (GTK_BOX (vbox9), frame2, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame2), 4);
  gtk_frame_set_label_align (GTK_FRAME (frame2), 0.5, 0.5);
  gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_ETCHED_OUT);

  alignment2 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (frame2), alignment2);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment2), 0, 8, 8, 8);

  table_temperatures = gtk_table_new (3, 2, FALSE);
  gtk_widget_show (table_temperatures);
  gtk_container_add (GTK_CONTAINER (alignment2), table_temperatures);

  hbox11 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox11);
  gtk_table_attach (GTK_TABLE (table_temperatures), hbox11, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  label6 = gtk_label_new (" degrees Celsius");
  gtk_widget_show (label6);
  gtk_box_pack_start (GTK_BOX (hbox11), label6, FALSE, FALSE, 0);

  label23 = gtk_label_new ("  ");
  gtk_widget_show (label23);
  gtk_box_pack_start (GTK_BOX (hbox11), label23, TRUE, TRUE, 0);

  hbox12 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox12);
  gtk_table_attach (GTK_TABLE (table_temperatures), hbox12, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  label11 = gtk_label_new (" degrees Fahrenheit");
  gtk_widget_show (label11);
  gtk_box_pack_start (GTK_BOX (hbox12), label11, FALSE, FALSE, 0);

  label24 = gtk_label_new ("  ");
  gtk_widget_show (label24);
  gtk_box_pack_start (GTK_BOX (hbox12), label24, TRUE, TRUE, 0);

  sb_entry_cdegrees_adj = gtk_adjustment_new (0, -100000, 100000, 1, 10, 10);
  sb_entry_cdegrees = gtk_spin_button_new (GTK_ADJUSTMENT (sb_entry_cdegrees_adj), 1, 0);
  gtk_widget_show (sb_entry_cdegrees);
  gtk_table_attach (GTK_TABLE (table_temperatures), sb_entry_cdegrees, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (sb_entry_cdegrees, 64, -1);

  sb_entry_fdegrees_adj = gtk_adjustment_new (32, -100000, 100000, 1, 10, 10);
  sb_entry_fdegrees = gtk_spin_button_new (GTK_ADJUSTMENT (sb_entry_fdegrees_adj), 1, 0);
  gtk_widget_show (sb_entry_fdegrees);
  gtk_table_attach (GTK_TABLE (table_temperatures), sb_entry_fdegrees, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_widget_set_size_request (sb_entry_fdegrees, 32, -1);

  label8 = gtk_label_new ("Equals :");
  gtk_widget_show (label8);
  gtk_table_attach (GTK_TABLE (table_temperatures), label8, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  label20 = gtk_label_new ("  ");
  gtk_widget_show (label20);
  gtk_table_attach (GTK_TABLE (table_temperatures), label20, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  label27 = gtk_label_new ("<b>Temperatures</b>");
  gtk_widget_show (label27);
  gtk_frame_set_label_widget (GTK_FRAME (frame2), label27);
  gtk_label_set_use_markup (GTK_LABEL (label27), TRUE);
  gtk_label_set_justify (GTK_LABEL (label27), GTK_JUSTIFY_CENTER);
  gtk_misc_set_padding (GTK_MISC (label27), 4, 4);

  vseparator1 = gtk_vseparator_new ();
  gtk_widget_show (vseparator1);
  gtk_box_pack_start (GTK_BOX (hbox1), vseparator1, FALSE, TRUE, 0);
  gtk_widget_set_size_request (vseparator1, 8, -1);

  vbox5 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox5);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox5, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox5), 4);

  btn_edit_add = gtk_button_new_with_mnemonic ("Edit/Add...");
  gtk_widget_show (btn_edit_add);
  gtk_box_pack_start (GTK_BOX (vbox5), btn_edit_add, TRUE, TRUE, 4);
  gtk_container_set_border_width (GTK_CONTAINER (btn_edit_add), 2);

  table1 = gtk_table_new (4, 3, TRUE);
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (vbox5), table1, TRUE, TRUE, 0);

  btn_num_1 = gtk_button_new_with_mnemonic (" 1 ");
  gtk_widget_show (btn_num_1);
  gtk_table_attach (GTK_TABLE (table1), btn_num_1, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_1), 2);
  gtk_widget_unset_state_flags(btn_num_1, GTK_STATE_FOCUSED);

  btn_num_2 = gtk_button_new_with_mnemonic (" 2 ");
  gtk_widget_show (btn_num_2);
  gtk_table_attach (GTK_TABLE (table1), btn_num_2, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_2), 2);
  gtk_widget_unset_state_flags(btn_num_2, GTK_STATE_FOCUSED);

  btn_num_3 = gtk_button_new_with_mnemonic (" 3 ");
  gtk_widget_show (btn_num_3);
  gtk_table_attach (GTK_TABLE (table1), btn_num_3, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_3), 2);
  gtk_widget_unset_state_flags(btn_num_3, GTK_STATE_FOCUSED);

  btn_num_4 = gtk_button_new_with_mnemonic (" 4 ");
  gtk_widget_show (btn_num_4);
  gtk_table_attach (GTK_TABLE (table1), btn_num_4, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_4), 2);
  gtk_widget_unset_state_flags(btn_num_4, GTK_STATE_FOCUSED);

  btn_num_5 = gtk_button_new_with_mnemonic (" 5 ");
  gtk_widget_show (btn_num_5);
  gtk_table_attach (GTK_TABLE (table1), btn_num_5, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_5), 2);
  gtk_widget_unset_state_flags(btn_num_5, GTK_STATE_FOCUSED);

  btn_num_6 = gtk_button_new_with_mnemonic (" 6 ");
  gtk_widget_show (btn_num_6);
  gtk_table_attach (GTK_TABLE (table1), btn_num_6, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_6), 2);
  gtk_widget_unset_state_flags(btn_num_6, GTK_STATE_FOCUSED);

  btn_num_7 = gtk_button_new_with_mnemonic (" 7 ");
  gtk_widget_show (btn_num_7);
  gtk_table_attach (GTK_TABLE (table1), btn_num_7, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_7), 2);
  gtk_widget_unset_state_flags(btn_num_7, GTK_STATE_FOCUSED);

  btn_num_8 = gtk_button_new_with_mnemonic (" 8 ");
  gtk_widget_show (btn_num_8);
  gtk_table_attach (GTK_TABLE (table1), btn_num_8, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_8), 2);
  gtk_widget_unset_state_flags(btn_num_8, GTK_STATE_FOCUSED);

  btn_num_9 = gtk_button_new_with_mnemonic (" 9 ");
  gtk_widget_show (btn_num_9);
  gtk_table_attach (GTK_TABLE (table1), btn_num_9, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_9), 2);
  gtk_widget_unset_state_flags(btn_num_9, GTK_STATE_FOCUSED);

  btn_num_0 = gtk_button_new_with_mnemonic (" 0 ");
  gtk_widget_show (btn_num_0);
  gtk_table_attach (GTK_TABLE (table1), btn_num_0, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_0), 2);
  gtk_widget_unset_state_flags(btn_num_0, GTK_STATE_FOCUSED);

  btn_num_dot = gtk_button_new_with_mnemonic (" . ");
  gtk_widget_show (btn_num_dot);
  gtk_table_attach (GTK_TABLE (table1), btn_num_dot, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_dot), 2);
  gtk_widget_unset_state_flags(btn_num_dot, GTK_STATE_FOCUSED);

  btn_num_minus = gtk_button_new_with_mnemonic (" - ");
  gtk_widget_show (btn_num_minus);
  gtk_table_attach (GTK_TABLE (table1), btn_num_minus, 2, 3, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_minus), 2);
  gtk_widget_unset_state_flags(btn_num_minus, GTK_STATE_FOCUSED);

  hbox8 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox8);
  gtk_box_pack_start (GTK_BOX (vbox5), hbox8, TRUE, TRUE, 0);

  btn_num_bksp = gtk_button_new_with_mnemonic ("BkSp");
  gtk_widget_show (btn_num_bksp);
  gtk_box_pack_start (GTK_BOX (hbox8), btn_num_bksp, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_bksp), 2);
  gtk_widget_unset_state_flags(btn_num_bksp, GTK_STATE_FOCUSED);

  btn_num_clear = gtk_button_new_with_mnemonic ("Clear");
  gtk_widget_show (btn_num_clear);
  gtk_box_pack_start (GTK_BOX (hbox8), btn_num_clear, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_num_clear), 2);
  gtk_widget_unset_state_flags(btn_num_clear, GTK_STATE_FOCUSED);

  hbox13 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox13);
  gtk_box_pack_start (GTK_BOX (vbox5), hbox13, TRUE, TRUE, 2);

  btn_about = gtk_button_new_with_mnemonic (" ? ");
  gtk_widget_show (btn_about);
  gtk_box_pack_start (GTK_BOX (hbox13), btn_about, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_about), 2);

  btn_exit = gtk_button_new_with_mnemonic ("Exit");
  gtk_widget_show (btn_exit);
  gtk_box_pack_start (GTK_BOX (hbox13), btn_exit, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (btn_exit), 2);

  g_signal_connect ((gpointer) App, "destroy",
                    G_CALLBACK (on_app_destroy),
                    NULL);
  g_signal_connect ((gpointer) App, "show",
                    G_CALLBACK (on_app_show),
                    NULL);
  g_signal_connect ((gpointer) sb_entry_val1, "changed",
                    G_CALLBACK (on_sb_entry_val1_changed),
                    NULL);
  g_signal_connect ((gpointer) sb_entry_val1, "grab_focus",
                    G_CALLBACK (on_sb_entry_val1_grab_focus),
                    NULL);
  g_signal_connect ((gpointer) combo_unit1, "changed",
                    G_CALLBACK (on_combo_unit1_changed),
                    NULL);
  g_signal_connect ((gpointer) combo_unit2, "changed",
                    G_CALLBACK (on_combo_unit2_changed),
                    NULL);
  g_signal_connect ((gpointer) sb_entry_cdegrees, "changed",
                    G_CALLBACK (on_sb_entry_cdegrees_changed),
                    NULL);
  g_signal_connect ((gpointer) sb_entry_cdegrees, "grab_focus",
                    G_CALLBACK (on_sb_entry_cdegrees_grab_focus),
                    NULL);
  g_signal_connect ((gpointer) sb_entry_fdegrees, "changed",
                    G_CALLBACK (on_sb_entry_fdegrees_changed),
                    NULL);
  g_signal_connect ((gpointer) sb_entry_fdegrees, "grab_focus",
                    G_CALLBACK (on_sb_entry_fdegrees_grab_focus),
                    NULL);
  g_signal_connect ((gpointer) btn_edit_add, "clicked",
                    G_CALLBACK (on_btn_edit_add_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_1, "clicked",
                    G_CALLBACK (on_btn_num_1_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_2, "clicked",
                    G_CALLBACK (on_btn_num_2_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_3, "clicked",
                    G_CALLBACK (on_btn_num_3_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_4, "clicked",
                    G_CALLBACK (on_btn_num_4_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_5, "clicked",
                    G_CALLBACK (on_btn_num_5_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_6, "clicked",
                    G_CALLBACK (on_btn_num_6_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_7, "clicked",
                    G_CALLBACK (on_btn_num_7_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_8, "clicked",
                    G_CALLBACK (on_btn_num_8_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_9, "clicked",
                    G_CALLBACK (on_btn_num_9_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_0, "clicked",
                    G_CALLBACK (on_btn_num_0_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_dot, "clicked",
                    G_CALLBACK (on_btn_num_dot_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_minus, "clicked",
                    G_CALLBACK (on_btn_num_minus_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_bksp, "clicked",
                    G_CALLBACK (on_btn_num_bksp_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_num_clear, "clicked",
                    G_CALLBACK (on_btn_num_clear_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_about, "clicked",
                    G_CALLBACK (on_btn_about_clicked),
                    NULL);
  g_signal_connect ((gpointer) btn_exit, "clicked",
                    G_CALLBACK (on_btn_exit_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (App, App, "App");
  GLADE_HOOKUP_OBJECT (App, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (App, vbox9, "vbox9");
  GLADE_HOOKUP_OBJECT (App, frame1, "frame1");
  GLADE_HOOKUP_OBJECT (App, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (App, table_measures, "table_measures");
  GLADE_HOOKUP_OBJECT (App, label1, "label1");
  GLADE_HOOKUP_OBJECT (App, label2, "label2");
  GLADE_HOOKUP_OBJECT (App, label19, "label19");
  GLADE_HOOKUP_OBJECT (App, label4, "label4");
  GLADE_HOOKUP_OBJECT (App, label28, "label28");
  GLADE_HOOKUP_OBJECT (App, entry_val2, "entry_val2");
  GLADE_HOOKUP_OBJECT (App, sb_entry_val1, "sb_entry_val1");
  GLADE_HOOKUP_OBJECT (App, combo_unit1, "combo_unit1");
  GLADE_HOOKUP_OBJECT (App, combo_unit2, "combo_unit2");
  GLADE_HOOKUP_OBJECT (App, label26, "label26");
  GLADE_HOOKUP_OBJECT (App, frame2, "frame2");
  GLADE_HOOKUP_OBJECT (App, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (App, table_temperatures, "table_temperatures");
  GLADE_HOOKUP_OBJECT (App, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (App, label6, "label6");
  GLADE_HOOKUP_OBJECT (App, label23, "label23");
  GLADE_HOOKUP_OBJECT (App, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (App, label11, "label11");
  GLADE_HOOKUP_OBJECT (App, label24, "label24");
  GLADE_HOOKUP_OBJECT (App, sb_entry_cdegrees, "sb_entry_cdegrees");
  GLADE_HOOKUP_OBJECT (App, sb_entry_fdegrees, "sb_entry_fdegrees");
  GLADE_HOOKUP_OBJECT (App, label8, "label8");
  GLADE_HOOKUP_OBJECT (App, label20, "label20");
  GLADE_HOOKUP_OBJECT (App, label27, "label27");
  GLADE_HOOKUP_OBJECT (App, vseparator1, "vseparator1");
  GLADE_HOOKUP_OBJECT (App, vbox5, "vbox5");
  GLADE_HOOKUP_OBJECT (App, btn_edit_add, "btn_edit_add");
  GLADE_HOOKUP_OBJECT (App, table1, "table1");
  GLADE_HOOKUP_OBJECT (App, btn_num_1, "btn_num_1");
  GLADE_HOOKUP_OBJECT (App, btn_num_2, "btn_num_2");
  GLADE_HOOKUP_OBJECT (App, btn_num_3, "btn_num_3");
  GLADE_HOOKUP_OBJECT (App, btn_num_4, "btn_num_4");
  GLADE_HOOKUP_OBJECT (App, btn_num_5, "btn_num_5");
  GLADE_HOOKUP_OBJECT (App, btn_num_6, "btn_num_6");
  GLADE_HOOKUP_OBJECT (App, btn_num_7, "btn_num_7");
  GLADE_HOOKUP_OBJECT (App, btn_num_8, "btn_num_8");
  GLADE_HOOKUP_OBJECT (App, btn_num_9, "btn_num_9");
  GLADE_HOOKUP_OBJECT (App, btn_num_0, "btn_num_0");
  GLADE_HOOKUP_OBJECT (App, btn_num_dot, "btn_num_dot");
  GLADE_HOOKUP_OBJECT (App, btn_num_minus, "btn_num_minus");
  GLADE_HOOKUP_OBJECT (App, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (App, btn_num_bksp, "btn_num_bksp");
  GLADE_HOOKUP_OBJECT (App, btn_num_clear, "btn_num_clear");
  GLADE_HOOKUP_OBJECT (App, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (App, btn_about, "btn_about");
  GLADE_HOOKUP_OBJECT (App, btn_exit, "btn_exit");

  return App;
}

GtkWidget*
create_EditDlg (void)
{
  GtkWidget *EditDlg;
  GtkWidget *vbox6;
  GtkWidget *table2;
  GtkWidget *label14;
  GtkWidget *editdlg_entry_unit1;
  GtkWidget *label15;
  GtkWidget *editdlg_entry_value;
  GtkWidget *label16;
  GtkWidget *editdlg_entry_unit2;
  GtkWidget *hseparator2;
  GtkWidget *hbox9;
  GtkWidget *editdlg_btn_delete;
  GtkWidget *label17;
  GtkWidget *editdlg_btn_cancel;
  GtkWidget *editdlg_btn_ok;

  EditDlg = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (EditDlg), "Edit/Add Measure...");
  gtk_window_set_position (GTK_WINDOW (EditDlg), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_modal (GTK_WINDOW (EditDlg), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (EditDlg), FALSE);
  gtk_window_set_type_hint (GTK_WINDOW (EditDlg), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox6 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox6);
  gtk_container_add (GTK_CONTAINER (EditDlg), vbox6);
  gtk_container_set_border_width (GTK_CONTAINER (vbox6), 4);

  table2 = gtk_table_new (3, 2, FALSE);
  gtk_widget_show (table2);
  gtk_box_pack_start (GTK_BOX (vbox6), table2, FALSE, TRUE, 0);
  gtk_table_set_row_spacings (GTK_TABLE (table2), 4);

  label14 = gtk_label_new (" Measurement 1 : ");
  gtk_widget_show (label14);
  gtk_table_attach (GTK_TABLE (table2), label14, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label14), 0, 0.5);

  editdlg_entry_unit1 = gtk_entry_new ();
  gtk_widget_show (editdlg_entry_unit1);
  gtk_table_attach (GTK_TABLE (table2), editdlg_entry_unit1, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_max_length (GTK_ENTRY (editdlg_entry_unit1), 30);
  gtk_entry_set_width_chars (GTK_ENTRY (editdlg_entry_unit1), 30);

  label15 = gtk_label_new (" Equals This Many : ");
  gtk_widget_show (label15);
  gtk_table_attach (GTK_TABLE (table2), label15, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label15), 0, 0.5);

  editdlg_entry_value = gtk_entry_new ();
  gtk_widget_show (editdlg_entry_value);
  gtk_table_attach (GTK_TABLE (table2), editdlg_entry_value, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_max_length (GTK_ENTRY (editdlg_entry_value), 16);
  gtk_entry_set_width_chars (GTK_ENTRY (editdlg_entry_value), 16);

  label16 = gtk_label_new (" Measurement 2 : ");
  gtk_widget_show (label16);
  gtk_table_attach (GTK_TABLE (table2), label16, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label16), 0, 0.5);

  editdlg_entry_unit2 = gtk_entry_new ();
  gtk_widget_show (editdlg_entry_unit2);
  gtk_table_attach (GTK_TABLE (table2), editdlg_entry_unit2, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_max_length (GTK_ENTRY (editdlg_entry_unit2), 30);
  gtk_entry_set_width_chars (GTK_ENTRY (editdlg_entry_unit2), 30);

  hseparator2 = gtk_hseparator_new ();
  gtk_widget_show (hseparator2);
  gtk_box_pack_start (GTK_BOX (vbox6), hseparator2, FALSE, TRUE, 0);
  gtk_widget_set_size_request (hseparator2, -1, 8);

  hbox9 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox9);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox9, FALSE, TRUE, 0);

  editdlg_btn_delete = gtk_button_new_with_mnemonic ("Delete");
  gtk_widget_show (editdlg_btn_delete);
  gtk_box_pack_start (GTK_BOX (hbox9), editdlg_btn_delete, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (editdlg_btn_delete), 4);

  label17 = gtk_label_new ("  ");
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox9), label17, TRUE, TRUE, 4);

  editdlg_btn_cancel = gtk_button_new_with_mnemonic ("Cancel");
  gtk_widget_show (editdlg_btn_cancel);
  gtk_box_pack_start (GTK_BOX (hbox9), editdlg_btn_cancel, TRUE, TRUE, 4);
  gtk_container_set_border_width (GTK_CONTAINER (editdlg_btn_cancel), 4);
  gtk_widget_unset_state_flags(editdlg_btn_cancel, ATK_STATE_DEFAULT);

  editdlg_btn_ok = gtk_button_new_with_mnemonic ("OK");
  gtk_widget_show (editdlg_btn_ok);
  gtk_box_pack_start (GTK_BOX (hbox9), editdlg_btn_ok, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (editdlg_btn_ok), 4);
  gtk_widget_unset_state_flags(editdlg_btn_ok, ATK_STATE_DEFAULT);

  g_signal_connect ((gpointer) editdlg_entry_unit1, "changed",
                    G_CALLBACK (on_editdlg_entry_unit1_changed),
                    NULL);
  g_signal_connect ((gpointer) editdlg_entry_unit2, "changed",
                    G_CALLBACK (on_editdlg_entry_unit2_changed),
                    NULL);
  g_signal_connect ((gpointer) editdlg_btn_delete, "clicked",
                    G_CALLBACK (on_editdlg_btn_delete_clicked),
                    NULL);
  g_signal_connect ((gpointer) editdlg_btn_cancel, "clicked",
                    G_CALLBACK (on_editdlg_btn_cancel_clicked),
                    NULL);
  g_signal_connect ((gpointer) editdlg_btn_ok, "clicked",
                    G_CALLBACK (on_editdlg_btn_ok_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (EditDlg, EditDlg, "EditDlg");
  GLADE_HOOKUP_OBJECT (EditDlg, vbox6, "vbox6");
  GLADE_HOOKUP_OBJECT (EditDlg, table2, "table2");
  GLADE_HOOKUP_OBJECT (EditDlg, label14, "label14");
  GLADE_HOOKUP_OBJECT (EditDlg, editdlg_entry_unit1, "editdlg_entry_unit1");
  GLADE_HOOKUP_OBJECT (EditDlg, label15, "label15");
  GLADE_HOOKUP_OBJECT (EditDlg, editdlg_entry_value, "editdlg_entry_value");
  GLADE_HOOKUP_OBJECT (EditDlg, label16, "label16");
  GLADE_HOOKUP_OBJECT (EditDlg, editdlg_entry_unit2, "editdlg_entry_unit2");
  GLADE_HOOKUP_OBJECT (EditDlg, hseparator2, "hseparator2");
  GLADE_HOOKUP_OBJECT (EditDlg, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (EditDlg, editdlg_btn_delete, "editdlg_btn_delete");
  GLADE_HOOKUP_OBJECT (EditDlg, label17, "label17");
  GLADE_HOOKUP_OBJECT (EditDlg, editdlg_btn_cancel, "editdlg_btn_cancel");
  GLADE_HOOKUP_OBJECT (EditDlg, editdlg_btn_ok, "editdlg_btn_ok");

  return EditDlg;
}

GtkWidget*
create_AboutDlg (void)
{
  GtkWidget *AboutDlg;
  GtkWidget *vbox7;
  GtkWidget *scrolledwindow1;
  GtkWidget *aboutdlg_textview1;
  GtkWidget *hseparator3;
  GtkWidget *hbox10;
  GtkWidget *label18;
  GtkWidget *aboutdlg_btn_close;

  AboutDlg = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (AboutDlg), "About...");
  gtk_window_set_position (GTK_WINDOW (AboutDlg), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_type_hint (GTK_WINDOW (AboutDlg), GDK_WINDOW_TYPE_HINT_DIALOG);
  gtk_window_set_default_size(GTK_WINDOW(AboutDlg), 400, 200);	

  vbox7 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox7);
  gtk_container_add (GTK_CONTAINER (AboutDlg), vbox7);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (vbox7), scrolledwindow1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 4);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_SHADOW_IN);

  aboutdlg_textview1 = gtk_text_view_new ();
  gtk_widget_show (aboutdlg_textview1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), aboutdlg_textview1);
  gtk_widget_set_size_request (aboutdlg_textview1, 600, 400);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (aboutdlg_textview1), FALSE);
  gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW (aboutdlg_textview1), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (aboutdlg_textview1), GTK_WRAP_WORD);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (aboutdlg_textview1), FALSE);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (aboutdlg_textview1), 8);
  gtk_text_view_set_right_margin (GTK_TEXT_VIEW (aboutdlg_textview1), 8);
  gtk_text_buffer_set_text (gtk_text_view_get_buffer (GTK_TEXT_VIEW (aboutdlg_textview1)), "gMeasures v3.0\n(C)2024 Paul Schuurmans\n\n\nIntroduction\n\ngMeasures is a simple utility to convert weights and measures.  It can also convert Celsius / Fahrenheit temperatures.\n\n\nUsing gMeasures\n\nTo calculate weights and measures:\n1. Enter the amount in the first entry field (top left) and select the unit to convert in the first dropdown listbox.\n2. In the second dropdown listbox, select the unit to convert to.\n\nTo edit an existing conversion:\n1. Use the dropdown listboxes to select the conversion.\n2. Press the [Edit/Add] button.\n3. Edit the \"Equals\" field.\n4. Press the [OK] button.\n\nTo add a new conversion:\n1. Press the [Edit/Add] button.\n2. Edit any or all of the fields as necessary.  Note: if you edit only the \"Equals\" field, it counts as an edit (i.e., no new conversion is added).\n3. Press the [OK] button.\n\nTo delete a conversion:\nNote: Read \"The Edit/Add Dialog\" below before doing this for the first time.\n1. Use the dropdown listboxes to select the conversion.\n2. Press the [Edit/Add] button.\n3. Press the [Delete] button.\n\nTo calculate temperatures:\n1. Enter the amount of degrees in either the Celsius or Fahrenheit entry field.\n\n\nThe Edit/Add Dialog\n\nWhen you press the [OK] or [Delete] button, gMeasures will automatically write the current configuration to a file named gmeasures.cfg in your home config directory.  Note that there is no confirmation after pressing either of these buttons.  You can revert back to the original 101 built-in conversions by deleting the gmeasures.cfg file, but that won't restore any of your own conversions that you've added or edited.  So please be careful, especially before pressing the [Delete] button.\n\n\nLocales\n\nBy default, gMeasures uses the \"C\" locale.  If your locale uses a comma instead of a decimal point, and you want a localized version of this program, here are the steps to take:\n1. In the main.c file, go to main() and uncomment the gtk_set_locale() line.\n2. Also in the main.c file, go to AppReadWriteConfig() and replace the decimal points in the defs array with commas.\n3. Recompile the program.\n\n\nKnown Quirks\n\n- Limited accuracy.  Decimal fractions exceeding 5 digits may or may not be accurate.\n\n\nBug Reports\n\nAlthough some effort has been made to make this program as robust as possible, there may be bugs that I don't yet know about.  If you find any bugs, please let me know.  For information on how to contact me, see the README file on my website.\n\n", -1);

  hseparator3 = gtk_hseparator_new ();
  gtk_widget_show (hseparator3);
  gtk_box_pack_start (GTK_BOX (vbox7), hseparator3, FALSE, TRUE, 0);
  gtk_widget_set_size_request (hseparator3, -1, 8);

  hbox10 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox10);
  gtk_box_pack_start (GTK_BOX (vbox7), hbox10, FALSE, TRUE, 0);

  label18 = gtk_label_new ("  ");
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox10), label18, TRUE, TRUE, 0);

  aboutdlg_btn_close = gtk_button_new_with_mnemonic ("Close");
  gtk_widget_show (aboutdlg_btn_close);
  gtk_box_pack_start (GTK_BOX (hbox10), aboutdlg_btn_close, TRUE, TRUE, 4);
  gtk_container_set_border_width (GTK_CONTAINER (aboutdlg_btn_close), 4);

  g_signal_connect ((gpointer) aboutdlg_btn_close, "clicked",
                    G_CALLBACK (on_aboutdlg_btn_close_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (AboutDlg, AboutDlg, "AboutDlg");
  GLADE_HOOKUP_OBJECT (AboutDlg, vbox7, "vbox7");
  GLADE_HOOKUP_OBJECT (AboutDlg, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (AboutDlg, aboutdlg_textview1, "aboutdlg_textview1");
  GLADE_HOOKUP_OBJECT (AboutDlg, hseparator3, "hseparator3");
  GLADE_HOOKUP_OBJECT (AboutDlg, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (AboutDlg, label18, "label18");
  GLADE_HOOKUP_OBJECT (AboutDlg, aboutdlg_btn_close, "aboutdlg_btn_close");

  return AboutDlg;
}

