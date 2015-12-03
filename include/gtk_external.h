#ifndef _GTK_EXTERNAL_H_
#define _GTK_EXTERNAL_H_
#include <gtk/gtk.h>
void select_font(GtkWindow *win, GdkEventButton *event, gpointer user_data);
void open_image(GtkWindow *win, GdkEventButton *event, gpointer user_data);
void open_bash(GtkWindow *win, GdkEventButton *event, gpointer user_data);
void insert_image(GtkWindow *win, GdkEventButton *event, gpointer user_data);
#endif
