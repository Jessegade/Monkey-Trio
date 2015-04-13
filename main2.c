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

void create_play(GtkWidget *button, gpointer window)
{
    GtkWidget *play_window, *label;

    label = gtk_label_new("PLAY");
    play_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_add(GTK_CONTAINER(play_window), label);

    gtk_widget_show_all(play_window);
}

void create_howto(GtkWidget *button, gpointer window)
{
    GtkWidget *play_window, *label;

    label = gtk_label_new("HOW TO PLAY");
    play_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_add(GTK_CONTAINER(play_window), label);

    gtk_widget_show_all(play_window);
}

void create_contact(GtkWidget *button, gpointer window)
{
    GtkWidget *play_window, *label;

    label = gtk_label_new("CONTACT US");
    play_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_add(GTK_CONTAINER(play_window), label);

    gtk_widget_show_all(play_window);
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *bg;
    GtkWidget *imageplay, *imagehowto, *imagecontact, *imagequit;
    GtkWidget *play, *howto, *contact, *quit;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("image/icon.png"));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    bg = gtk_image_new_from_file("image/bg.jpg");
    gtk_layout_put(GTK_LAYOUT(layout), bg, 0, 0);

/////////////////////////////////////PLAY/////////////////////////////////////////
    imageplay = gtk_image_new_from_file("image/play.png");
    gtk_layout_put(GTK_LAYOUT(layout), imageplay, 0, 0);

    play = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout),  play, 320, 300);
    gtk_button_set_image(GTK_BUTTON(play), imageplay);
    gtk_widget_set_size_request(play, 80, 35);
    g_signal_connect(play, "clicked",G_CALLBACK(create_play), window);

/////////////////////////////////////HOW TO PLAY/////////////////////////////////////////
    imagehowto = gtk_image_new_from_file("image/howto.png");
    gtk_layout_put(GTK_LAYOUT(layout), imagehowto, 0, 0);

    howto = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout),  howto, 120, 400);
    gtk_button_set_image(GTK_BUTTON(howto), imagehowto);
    gtk_widget_set_size_request(howto, 80, 35);
    g_signal_connect(howto, "clicked",G_CALLBACK(create_howto), window);

/////////////////////////////////////Contact us/////////////////////////////////////////
    imagecontact = gtk_image_new_from_file("image/contact.png");
    gtk_layout_put(GTK_LAYOUT(layout), imagecontact, 0, 0);

    contact = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), contact, 320, 400);
    gtk_button_set_image(GTK_BUTTON(contact), imagecontact);
    gtk_widget_set_size_request(contact, 80, 35);
    g_signal_connect(contact, "clicked",G_CALLBACK(create_contact), window);

/////////////////////////////////////QUIT/////////////////////////////////////////
    imagequit = gtk_image_new_from_file("image/quit.png");
    gtk_layout_put(GTK_LAYOUT(layout), imagequit, 0, 0);

    quit = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), quit, 520, 400);
    gtk_button_set_image(GTK_BUTTON(quit), imagequit);
    gtk_widget_set_size_request(quit, 80, 35);
    g_signal_connect(G_OBJECT(quit), "clicked",G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    //g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
