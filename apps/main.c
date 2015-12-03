/*
 * Original code by: Mike - http://plan99.net/~mike/blog (now a dead link--unable to find it).
 * Modified by karlphillip for StackExchange:
 *     (http://stackoverflow.com/questions/3908565/how-to-make-gtk-window-background-transparent)
 * Re-worked for Gtk 3 by Louis Melahn, L.C., January 30, 2014.
 */

#include <gtk/gtk.h>
#include <gtk_internal.h>
#include <gtk_external.h>
#include <string.h>
#include <stdlib.h>

gboolean supports_alpha = FALSE;
struct my_gtk
{
   GtkWidget *file_one;
   GtkTextBuffer *file_two;
   GtkWidget *btns[8];
};

void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer userdata)
{
    /* To check if the display supports alpha channels, get the visual */
    GdkScreen *screen = gtk_widget_get_screen(widget);
    GdkVisual *visual = gdk_screen_get_rgba_visual(screen);

    if (!visual)
    {
        printf("Your screen does not support alpha channels!\n");
        visual = gdk_screen_get_system_visual(screen);
        supports_alpha = FALSE;
    }
    else
    {
        printf("Your screen supports alpha channels!\n");
        supports_alpha = TRUE;
    }

    gtk_widget_set_visual(widget, visual);
}

gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer userdata)
{
   cairo_t *new_cr = gdk_cairo_create(gtk_widget_get_window(widget));

    if (supports_alpha)
    {
        cairo_set_source_rgba (new_cr, 0.5, 1.0, 0.50, 0.5); /* transparent */
    }
    else
    {
        cairo_set_source_rgb (new_cr, 1.0, 1.0, 1.0); /* opaque white */
    }

    /* draw the background */
    cairo_set_operator (new_cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint (new_cr);
    cairo_destroy(new_cr);

    return FALSE;
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    struct my_gtk mygtk;
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *box = gtk_box_new(1,0); // 1: vbox, 0:hbox
    GtkWidget *box_btns = gtk_box_new(0,0); // 1: vbox, 0:hbox
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

    GtkWidget* button = gtk_button_new_with_label("Font box");
    GtkWidget* button2 = gtk_button_new_with_label("File box");
    GtkWidget* button3 = gtk_button_new_with_label("File box");
    GtkWidget* button4 = gtk_button_new_with_label("File box");


    view = gtk_text_view_new();
    gtk_text_view_set_left_margin (GTK_TEXT_VIEW ( view ) , 10 ) ;
    gtk_text_view_set_right_margin (GTK_TEXT_VIEW ( view ) , 10 ) ;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
    gtk_text_buffer_set_text(buffer, "\nUser:$ ", -1);


    mygtk.file_one = view;
    mygtk.file_two = buffer;
    mygtk.btns[0] = button;
    mygtk.btns[1] = button2;
    mygtk.btns[2] = button3;
    mygtk.btns[3] = button4;

    g_signal_connect(window, "key-release-event", G_CALLBACK(key_event), &mygtk);
    g_signal_connect(G_OBJECT(button), "button-press-event", G_CALLBACK(clicked), &mygtk);
    g_signal_connect(G_OBJECT(button2), "button-press-event", G_CALLBACK(clicked2), &mygtk);
    g_signal_connect(G_OBJECT(button3), "button-press-event", G_CALLBACK(clicked3), &mygtk);
    g_signal_connect(G_OBJECT(button4), "button-press-event", G_CALLBACK(clicked4), &mygtk);

    gtk_widget_set_size_request(view, 800,550);
    gtk_widget_set_size_request(button, 100, 50);
    
    gtk_container_add(GTK_CONTAINER(box_btns), button);
    gtk_container_add(GTK_CONTAINER(box_btns), button2);
    gtk_container_add(GTK_CONTAINER(box_btns), button3);
    gtk_container_add(GTK_CONTAINER(box_btns), button4);
    gtk_container_add(GTK_CONTAINER(box), box_btns);
    gtk_container_add(GTK_CONTAINER(box), view);

    screen_changed(window, NULL, NULL);


    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}








