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

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;
  GtkWidget *image;
  GtkWidget *layout;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Monkey Trio");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 500);
  gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("C:/Users/Miki/Monkey-Trio/icon.png"));

  /*image = gtk_image_new_from_file("C:/Users/Miki/Pictures/haha oppa/7870744793.jpg");
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);*/

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
