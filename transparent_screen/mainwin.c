/*
To make Text editor in easy gtk function,enviroment
*/


#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *box = gtk_box_new(1,0); // 1: vbox, 0:hbox
    GtkWidget* view;

    GtkTextBuffer* buffer = NULL;
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Our Editor");
    g_signal_connect(G_OBJECT(window), "delete-event", gtk_main_quit, NULL);

    gtk_widget_set_app_paintable(window, TRUE);

    g_signal_connect(G_OBJECT(window), "draw", G_CALLBACK(draw), NULL);
    g_signal_connect(G_OBJECT(window), "screen-changed", G_CALLBACK(screen_changed), NULL);

    gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
    gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

    gtk_container_add(GTK_CONTAINER(window), box);
    GtkWidget* button = gtk_button_new_with_label("Make the screen trasparent");


    view = gtk_text_view_new();

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
    gtk_text_buffer_create_tag (buffer, "heading",
			      "weight", PANGO_WEIGHT_BOLD,
			      "size", 15 * PANGO_SCALE,
			      NULL);
    gtk_text_buffer_set_text(buffer, "User:$", -1);


    mygtk.file_one = view;
    mygtk.file_two = buffer;


    g_signal_connect(window, "key-release-event", G_CALLBACK(key_event), view);
    g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(clicked), view);

    gtk_widget_set_size_request(view, 800,550);
    gtk_widget_set_size_request(button, 100, 50);


    gtk_container_add(GTK_CONTAINER(box), button);
    gtk_container_add(GTK_CONTAINER(box), view);


    screen_changed(window, NULL, NULL);





    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
