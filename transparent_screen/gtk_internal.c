//#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>
#include <stdlib.h>




gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{

  GtkTextIter insert_text;
  GdkEvent *event_bracket;

  event_bracket = gdk_event_new(GDK_bracketright);
  switch (event->keyval)
  {
 //keyconfig
    case GDK_p:
    printf("p key pressed!\n");
    break;
    case GDK_bracketleft:
    printf("Bracket key pressed!\n");
    gtk_text_buffer_insert(view,&insert_text,"}", 1);
    break;

    default:
      return FALSE;
  }
}



void subwindow()
{

    GtkWidget *box, *scroll, *widget;
    GtkWidget *window;
    GtkWidget *view;

    GtkAccelGroup *accel;
    GtkItemFactory *main_menu;

    gtk_init(&argc, &argv);  // gtk initialize

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 500);

    box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    accel = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window), accel);
    main_menu = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<TextView>", accel);

    widget = gtk_item_factory_get_widget(main_menu, "<TextView>");

    gtk_box_pack_start(GTK_BOX(box), widget, FALSE, FALSE, 0);
    scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(box), scroll, TRUE, TRUE, 0);

    view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scroll), view);

    g_signal_connect(G_OBJECT(view), "key-press-event",G_CALLBACK(key_event), view);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
/*
int main(int argc, char *argv[])
{
    GtkWidget *box, *scroll, *widget;
    GtkWidget *window;
    GtkWidget *view;

    GtkAccelGroup *accel;
    //GtkItemFactory *main_menu;

    gtk_init(&argc, &argv);  // gtk initialize

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 500);

    box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    accel = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window), accel);
    //main_menu = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<TextView>", accel);

    //widget = gtk_item_factory_get_widget(main_menu, "<TextView>");

    gtk_box_pack_start(GTK_BOX(box), widget, FALSE, FALSE, 0);
    scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(box), scroll, TRUE, TRUE, 0);

    view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scroll), view);

    g_signal_connect(G_OBJECT(view), "key-press-event",G_CALLBACK(key_event), view);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
*/


