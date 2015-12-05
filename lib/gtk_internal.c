#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <gtk_external.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>
#include <stdlib.h>

#define GDK_F12 0xffc9
#define GDK_F10 0xffc7

#define GDK_bracketleft 0x05b

#define GDK_braceleft 0x07b



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


switch (event->keyval)
 {
       case GDK_F12:
       screen_control(my,1);
       break;
     
       case GDK_F10:
        screen_control(my,2);     
       break;

       case GDK_bracketleft:
	edit_control(my,1);
	break;

	case GDK_braceleft:
	edit_control(my,2);
	break;

/*
	default:
		printf("key pressed: %s\n", gdk_keyval_name(event->keyval));
		// if you want to handle keyval by name, use gdk_keyval_name
	break;
*/

}

}
void screen_control(struct my_gtk *val,int i)
{

GtkTextMark *mark;
GtkTextIter iter;
switch (i)
 {
    case 1:

       gtk_widget_hide(val->file_one);
       gtk_widget_hide(val->btns[0]);
       gtk_widget_hide(val->btns[1]);
       gtk_widget_hide(val->btns[2]);
       gtk_widget_hide(val->btns[3]);
      break;
     
     case 2:
       gtk_widget_show(val->file_one);
       gtk_widget_show(val->btns[0]);
       gtk_widget_show(val->btns[1]);
       gtk_widget_show(val->btns[2]);
       gtk_widget_show(val->btns[3]);
       break;
 }

}


void edit_control(struct my_gtk *my,int i)
{

GtkTextMark *mark;
GtkTextIter iter;
switch (i)
 {
        case 1:
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
	gtk_text_buffer_insert(my->file_two, &iter, " ]", -1);
	break;

	case 2:
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
        gtk_text_buffer_insert(my->file_two, &iter, " }", -1);

	break;

 }
}







