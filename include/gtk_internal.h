#ifndef _GTK_INTERNAL_H_
#define _GTK_INTERNAL_H_
#include <gtk/gtk.h>
#include <gdk/gdk.h>


GtkWidget* view;


void printA();
gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
gboolean key_event();
void screen_control();
void search_button_clicked();
void edit_control();
void find();
void win_destroy();
void next_button_clicked();
void search_button_clicked(); 
void textfind();
#endif
