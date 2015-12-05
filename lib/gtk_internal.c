#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <gtk_external.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>
#include <stdlib.h>

#define GDK_F12 0xffc9
#define GDK_F10 0xffc7
#define GDK_bracketleft 0x05b
#define GDK_bracketright 0x05d
#define GDK_KEY_MASK 0xffe1
#define GDK_braceleft 0x07b
#define GDK_leftsinglequotemark 0xad0
#define GDK_leftdoublequotemark 0xad2


#define GDK_KEY_S 0x053
#define GDK_KEY_I 0x049
#define GDK_KEY_D 0x044

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


	    gtk_text_buffer_insert(my->file_two, &iter, " ]", -1);
        
	break;

	case GDK_braceleft:
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
        gtk_text_buffer_insert(my->file_two, &iter, " }", -1);
	break;
/*
        case S:

	break;

	case GDK_I:

	break;
*/
	default:
		printf("key pressed: %s\n", gdk_keyval_name(event->keyval));
		// if you want to handle keyval by name, use gdk_keyval_name
	break;

}


}
