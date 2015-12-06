#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <gtk_external.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>
#include <stdlib.h>

#define GDK_F4 0xffc1
#define GDK_F12 0xffc9
#define GDK_F10 0xffc7
#define GDK_bracketleft 0x05b
#define GDK_braceleft 0x07b


extern GtkWidget *view;
GtkWidget *text_view;
GtkWidget *search_entry;

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
       case GDK_F4:
       textfind();
       break;
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




void find (GtkTextView *text_view, const gchar *text, GtkTextIter *iter)
{
  GtkTextIter mstart, mend;
  GtkTextBuffer *buffer;
  gboolean found;

  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(text_view));
  found = gtk_text_iter_forward_search (iter, text, 0, &mstart, &mend, NULL);

  if (found)
    {
      gtk_text_buffer_select_range (buffer, &mstart, &mend);
      gtk_text_buffer_create_mark (buffer, "last_pos", &mend, FALSE);
    }

}

void win_destroy (void)
{
  gtk_main_quit();
}

void next_button_clicked (GtkWidget *next_button)
{
  const gchar *text;
  GtkTextBuffer *buffer;
  GtkTextMark *last_pos;
  GtkTextIter iter;

  text = gtk_entry_get_text (GTK_ENTRY (search_entry));
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text_view));
  last_pos = gtk_text_buffer_get_mark (buffer, "last_pos");
  
    if (last_pos == NULL)
    {
      GtkWidget *window1;
      GtkWidget *label;
      
      window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
      gtk_window_set_title (GTK_WINDOW (window1), "Search");
      gtk_window_set_default_size(GTK_WINDOW(window1), 50, 300);
     
      
      label = gtk_label_new ("Search End\n\n");
      
      gtk_container_add (GTK_CONTAINER (window1), label); 
      
      gtk_widget_show_all (window1);
      
      return;
      
    }
  
  gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos);
  find (GTK_TEXT_VIEW (text_view),(gchar *)gtk_entry_get_text((GtkEntry *)search_entry), &iter);
}

void search_button_clicked (GtkWidget *search_button)
{
  GtkTextIter iter;
  GtkTextBuffer *buffer;

  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
  gtk_text_buffer_get_start_iter(buffer, &iter);
  
  find(GTK_TEXT_VIEW(text_view),(gchar *)gtk_entry_get_text((GtkEntry *)search_entry),&iter);
}


void textfind(void)
{
  GtkWidget *win;
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *search_button;
  GtkWidget *next_button;


  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  vbox = gtk_vbox_new (FALSE, 2);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  hbox = gtk_hbox_new (FALSE, 2);

  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
  
  text_view = view;
  search_entry = gtk_entry_new();
  
  gtk_box_pack_start (GTK_BOX (hbox),search_entry, TRUE, TRUE, 0);

  search_button = gtk_button_new_with_label ("Search");
  gtk_box_pack_start (GTK_BOX (hbox), search_button, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT (search_button), "clicked",G_CALLBACK (search_button_clicked), NULL);
  
  next_button = gtk_button_new_with_label ("Next");
  gtk_box_pack_start (GTK_BOX (hbox), next_button, FALSE, FALSE, 0);
  g_signal_connect (G_OBJECT (next_button), "clicked",G_CALLBACK (next_button_clicked), NULL);

  

   gtk_widget_show_all(win);
}







