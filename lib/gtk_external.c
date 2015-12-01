#include <gtk_external.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("haha", NULL);
    //gtk_container_add (GTK_CONTAINER (window), font_dialog);
    gtk_widget_show_all (font_dialog); 
    printA();
    /*
    if(i != 1)
    {
       
    }
    else
    {
       gtk_widget_show(user_data);
       i=0;
    }
     */
    //gtk_window_set_decorated(win, !gtk_window_get_decorated(win));
}



