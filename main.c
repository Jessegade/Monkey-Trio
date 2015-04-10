#include <gtk/gtk.h>
GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

int main( int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image;
    GtkWidget *imagebutton;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("image/icon.png"));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    image = gtk_image_new_from_file("image/01.jpg");
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

    imagebutton = gtk_image_new_from_file("image/icon.png");
    gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);

    button = gtk_button_new_with_label("Quit");
    gtk_layout_put(GTK_LAYOUT(layout), button, 150, 50);
    gtk_button_set_image(GTK_BUTTON(button), imagebutton);
    gtk_widget_set_size_request(button, 80, 35);

    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
