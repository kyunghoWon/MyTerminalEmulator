#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
struct my_gtk
{
   GtkWidget *file_one;
   GtkTextBuffer *file_two;
};

void printA()
{
	printf("Hello, world!");
}


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

gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    GtkTextMark *mark;
    GtkTextIter iter;	
    //g_printerr("%s\n", gdk_keyval_name (event->keyval));    
    if(strcmp(gdk_keyval_name (event->keyval),"F12") == 0)
    {
       gtk_widget_hide(my->file_one);
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"F10") == 0)
    {
       gtk_widget_show(my->file_one);
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"Return") == 0)
    {
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
	/*
        if(gtk_text_buffer_get_char_count(my->file_two))
        {
           gtk_text_buffer_insert(my->file_two, &iter, "\n", 1);
        }
	*/
	gtk_text_buffer_insert(my->file_two, &iter, "User:$ ", -1);
    }

    return FALSE;
}
