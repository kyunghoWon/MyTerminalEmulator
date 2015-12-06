#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gtk_external.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
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

   if(resp==GTK_RESPONSE_OK)
   {
     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
     gtk_window_set_title(GTK_WINDOW(window), "Image Viewer");
  
     image = gtk_image_new_from_file(_filename);

     gtk_container_add(GTK_CONTAINER(window), image);

     gtk_widget_show_all(window); 
   }

}

void open_txt(GtkWindow *win, GdkEventButton *event, gpointer user_data)
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

   int fp, rd;
   char buf[256];

   fp = open(_filename, O_RDONLY);
   if(fp == -1)
   {
      perror("open");
      exit(0);
   }

   GtkTextMark *mark;
   GtkTextIter iter;

   while((rd=read(fp,buf,256)>0))
   { 
     mark = gtk_text_buffer_get_insert(my->file_two);
     gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
     gtk_text_buffer_insert(my->file_two, &iter, buf, -1);
   }
   close(fp);

}

void save_txt(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
   struct my_gtk *my = (struct my_gtk *)user_data;
   GtkWidget *dialog;
   GtkFileChooser *chooser;
   GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
   gint res;

   dialog = gtk_file_chooser_dialog_new ("Save File",
                                      GTK_WINDOW(my->my_window),
                                      action,
                                      "Cancel",
                                      GTK_RESPONSE_CANCEL,
                                      "Save",
                                      GTK_RESPONSE_ACCEPT,
                                      NULL);
   chooser = GTK_FILE_CHOOSER (dialog);

   gtk_file_chooser_set_do_overwrite_confirmation (chooser, TRUE);

   res = gtk_dialog_run (GTK_DIALOG (dialog));
   char *filename;
   if (res == GTK_RESPONSE_ACCEPT)
   {
     

     filename = gtk_file_chooser_get_filename (chooser);
     //printf("\n%s\n", filename);
   }

   gtk_widget_destroy (dialog);

   gchar *text;
   GtkTextIter start;
   GtkTextIter end;
   int fp;
 
   if(res == GTK_RESPONSE_ACCEPT)
   {
      gtk_text_buffer_get_start_iter (my->file_two, &start);
      gtk_text_buffer_get_end_iter (my->file_two, &end);
      text = gtk_text_buffer_get_text (my->file_two, &start, &end, FALSE); 

      fp = open(filename, O_WRONLY|O_CREAT, 0666);
      if(fp == -1)
      {
         perror("open");
         exit(0);
      }
      write(fp, text, strlen(text));
      close(fp);
   }
   
}



