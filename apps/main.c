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
};

static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer user_data);
static gboolean draw(GtkWidget *widget, cairo_t *new_cr, gpointer user_data);
static void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data);


int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    struct my_gtk mygtk;
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *box = gtk_box_new(1,0); // 1: vbox, 0:hbox
    GtkWidget* view;
    printA();
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
    gtk_text_view_set_left_margin (GTK_TEXT_VIEW ( view ) , 10 ) ;
    gtk_text_view_set_right_margin (GTK_TEXT_VIEW ( view ) , 10 ) ;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
    gtk_text_buffer_set_text(buffer, "User:$ ", -1);


    mygtk.file_one = view;
    mygtk.file_two = buffer;


    g_signal_connect(window, "key-release-event", G_CALLBACK(key_event), &mygtk);
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


static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer userdata)
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

static gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer userdata)
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

static void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    /* toggle window manager frames */
   // GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *font_dialog = gtk_font_chooser_dialog_new("haha", NULL);
    //gtk_container_add (GTK_CONTAINER (window), font_dialog);
    gtk_widget_show_all (font_dialog); 
    printA();
    /*
    if(i != 1)
    {
       
    }
    else
    {
       gtk_widget_show(user_data);
       i=0;
    }
     */
    //gtk_window_set_decorated(win, !gtk_window_get_decorated(win));
}





