#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
struct my_gtk
{
   GtkWidget *file_one;
   GtkTextBuffer *file_two;
   GtkWidget *btns[8];
   GtkWidget *my_window;
   int bashflag;
};

void printA()
{
	printf("Hello, world!");
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
       gtk_widget_hide(my->btns[0]);
       gtk_widget_hide(my->btns[1]);
       gtk_widget_hide(my->btns[2]);
       gtk_widget_hide(my->btns[3]);
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"F10") == 0)
    {
       gtk_widget_show(my->file_one);
       gtk_widget_show(my->btns[0]);
       gtk_widget_show(my->btns[1]);
       gtk_widget_show(my->btns[2]);
       gtk_widget_show(my->btns[3]);
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
        
        // **********************************************Don't touch here. 
	if(my->bashflag == 1)
   	{
               // Only Kyungho can edit
       		
  	}
        else
        {
		// You can modify here
		gtk_text_buffer_insert(my->file_two, &iter, "User:$ ", -1);
        }
	// ****************************************************************
    }

    return FALSE;
}
