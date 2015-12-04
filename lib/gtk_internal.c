#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>
#include <stdlib.h>

#define GDK_F12 0xffc9
#define GDK_F10 0xffc7
#define GDK_bracketleft 0x05b
#define GDK_bracketright 0x05d
#define GDK_KEY_MASK 0xffe1

struct my_gtk
{
   GtkWidget *file_one;
   GtkTextBuffer *file_two;
   GtkWidget *btns[8];
   GtkWidget *my_window;
   int bashflag;
};


gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
struct my_gtk *my = (struct my_gtk *)user_data;


GtkTextMark *mark;
GtkTextIter iter;

switch (event->keyval)
 {
    case GDK_F12:
      printf("key pressed: %s\n", "F12");
       gtk_widget_hide(my->file_one);
       gtk_widget_hide(my->btns[0]);
       gtk_widget_hide(my->btns[1]);
       gtk_widget_hide(my->btns[2]);
       gtk_widget_hide(my->btns[3]);
      break;
    case GDK_F10:
       gtk_widget_show(my->file_one);
       gtk_widget_show(my->btns[0]);
       gtk_widget_show(my->btns[1]);
       gtk_widget_show(my->btns[2]);
       gtk_widget_show(my->btns[3]);
       break;

     case GDK_bracketleft:
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);

        // **********************************************Don't touch here.
	if(my->bashflag == 1)
   	{
               //Kyungho Field
  	}
        else
        {
	    gtk_text_buffer_insert(my->file_two, &iter, "]", -1);
        }

	break;
	//case GDK_:
	//여기는 중괄호에관한 걸로 넣고,에딧트 모드 추가할 예정
	//break;
}
}

/*
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
    else if(strcmp(gdk_keyval_name(event->keyval),"bracketleft") == 0)
    {
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);

        if(gtk_text_buffer_get_char_count(my->file_two))
        {
           gtk_text_buffer_insert(my->file_two, &iter, "\n", 1);
        }


        // **********************************************Don't touch here.
	if(my->bashflag == 1)
   	{
               // Only Kyungho can edit

  	}
        else
        {
		gtk_text_buffer_insert(my->file_two, &iter, "}", -1);
        }
	// ****************************************************************
    }

    return FALSE;
}
*/

