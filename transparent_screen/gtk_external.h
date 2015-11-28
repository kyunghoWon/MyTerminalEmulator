#include <gtk/gtk.h>
#ifndef _GTK_EXTERNAL_H_
#define _GTK_EXTERNAL_H_

extern gboolean supports_alpha = FALSE;
static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer user_data);
static gboolean draw(GtkWidget *widget, cairo_t *new_cr, gpointer user_data);
static void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data);

#endif
