#ifndef _GTK_INTERNAL_H_
#define _GTK_INTERNAL_H_
#include <gtk/gtk.h>

void printA();
gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data);
void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer userdata);
gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer userdata);

#endif
