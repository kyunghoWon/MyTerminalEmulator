#include <gtk_external.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("haha", NULL);
    gtk_widget_show_all (font_dialog); 
}


void clicked2(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("haha", NULL);
    gtk_widget_show_all (font_dialog); 
}


void clicked3(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("haha", NULL);
    gtk_widget_show_all (font_dialog); 
}


void clicked4(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("haha", NULL);
    gtk_widget_show_all (font_dialog); 
}

