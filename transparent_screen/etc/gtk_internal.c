#include <gtk_internal.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

static gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    struct my_gtk *my = (struct my_gtk *)user_data;
    GtkTextMark *mark;
    GtkTextIter iter;
    g_printerr("%s\n", gdk_keyval_name (event->keyval));
    if(strcmp(gdk_keyval_name (event->keyval),"F12") == 0)
    {
       gtk_widget_hide(my->file_one);
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"F10") == 0)
    {
       gtk_widget_show(my->file_one);
    }
    else if(strcmp(gdk_keyval_name(event->keyval),"Return") == 0)
    {
        mark = gtk_text_buffer_get_insert(my->file_two);
        gtk_text_buffer_get_iter_at_mark(my->file_two, &iter, mark);
	
        if(gtk_text_buffer_get_char_count(my->file_two))
        {
           gtk_text_buffer_insert(my->file_two, &iter, "\n", 1);
        }
	
	gtk_text_buffer_insert(my->file_two, &iter, "User:$ ", -1);
    }


    return FALSE;
}

///Main code start

int main(int argc, char *argv[])
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


    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}



