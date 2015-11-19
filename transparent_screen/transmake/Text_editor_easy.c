#include <stdlib.h>
#include <gtk/gtk.h>
/*
int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *window = NULL;
  GtkWidget *vbox = NULL;
  GtkWidget *entry=NULL;
  GtkWidget *draw =NULL;



  //Initialize GTK+
  gtk_init (&argc, &argv);

  //Create the main window
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_border_width(GTK_CONTAINER(vbox),200);
  gtk_container_set_border_width (GTK_CONTAINER (window),300);
  gtk_window_set_title (GTK_WINDOW (window), "Editor");
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
  gtk_widget_realize (window);

  entry = gtk_entry_new();

  //Create a vertical box with buttons
  vbox = gtk_vbox_new (TRUE, 6);

  gtk_container_add(GTK_CONTAINER(vbox), entry);
  gtk_container_add(GTK_CONTAINER(vbox), draw);
  gtk_container_add(GTK_CONTAINER(vbox),button);
  gtk_container_add (GTK_CONTAINER(window), vbox);

  //Enter the main loop
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}
*/

