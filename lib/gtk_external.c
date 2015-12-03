#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gtk_external.h>
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

void select_font(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("Font box", GTK_WINDOW(my->my_window));
    gtk_widget_show_all (font_dialog);
    gint resp = gtk_dialog_run(GTK_DIALOG(font_dialog));

    if(resp==GTK_RESPONSE_OK)
   {
      gtk_widget_override_font(GTK_WIDGET(my->file_one),gtk_font_chooser_get_font_desc(GTK_FONT_CHOOSER(font_dialog)));
   }
   else
      printf("You pressed the cancel\n");
   
   gtk_widget_destroy(font_dialog);
    
}

void open_image(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    char *_filename;

   GtkWidget *window;
    GtkWidget *image;
   GtkWidget *dialog;
   dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(my->my_window), GTK_FILE_CHOOSER_ACTION_OPEN, "Open", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
   gtk_widget_show_all(dialog);
   gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), "./");
   gint resp = gtk_dialog_run(GTK_DIALOG(dialog));

   if(resp==GTK_RESPONSE_OK)
   {
      printf("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
      _filename = (char *)malloc(256);
      sprintf(_filename, "%s", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
   }
   else
      printf("You pressed the cancel\n");
   
   gtk_widget_destroy(dialog);


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Red Rock");
  
  printf("%s\n", _filename);
  image = gtk_image_new_from_file(_filename);

  gtk_container_add(GTK_CONTAINER(window), image);

  gtk_widget_show_all(window);  

}

void open_bash(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    if(my->bashflag == 0)
    {
       gtk_button_set_label(GTK_BUTTON(my->btns[2]), "Open Editor");
       my->bashflag = 1;
    }
    else
    {
       gtk_button_set_label(GTK_BUTTON(my->btns[2]), "Open Bash");
       my->bashflag = 0;
    }
    
}

void insert_image(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
   struct my_gtk *my = (struct my_gtk *)user_data;
   char *_filename;
   GtkWidget *image;
   GtkTextMark *mark;
   GtkTextIter iter;
   GdkPixbuf *pixbuf;
   GError *gerror;
 
   GtkWidget *dialog;
   dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(my->my_window), GTK_FILE_CHOOSER_ACTION_OPEN, "Open", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
   gtk_widget_show_all(dialog);
   gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), "./");
   gint resp = gtk_dialog_run(GTK_DIALOG(dialog));

   if(resp==GTK_RESPONSE_OK)
   {
      printf("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
      _filename = (char *)malloc(256);
      sprintf(_filename, "%s", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
   }
   else
      printf("You pressed the cancel\n");
   
   gtk_widget_destroy(dialog);
   
  // pixbuf = gdk_pixbuf_new_from_file(_filename, &gerror);
   
   
  // mark = gtk_text_buffer_get_insert(my->file_two);
  // gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
      
  // gtk_text_buffer_insert_pixbuf (my->file_two, &iter, pixbuf);
}



