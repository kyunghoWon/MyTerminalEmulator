#ifndef _GTK_INTERNAL_H_
#define _GTK_INTERNAL_H_
#include <gtk/gtk.h>
#include <gdk/gdk.h>

void printA();
gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

#endif
