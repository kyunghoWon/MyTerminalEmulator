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
};

void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("Font box", NULL);
    gtk_widget_show_all (font_dialog);
 
}

void clicked2(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    /* toggle window manager frames */
   GtkWidget *dialog;
   dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(my->my_window), GTK_FILE_CHOOSER_ACTION_OPEN, "Open", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
   gtk_widget_show_all(dialog);
   gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), "./");
   gint resp = gtk_dialog_run(GTK_DIALOG(dialog));

   if(resp==GTK_RESPONSE_OK)
      printf("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
   else
      printf("You pressed the cancel\n");
   
   gtk_widget_destroy(dialog);  

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

