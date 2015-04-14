#include <gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
GtkWidget *main_page,*casebox;

int widget_destroy(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
}

int page2(GtkWidget *widget, gpointer casebox)
{
    GtkWidget *vbox2, *label;

    vbox2 = gtk_vbox_new(0,0);
    label = gtk_label_new("HOW TO PLAY");
    gtk_box_pack_start(GTK_BOX(casebox), vbox2,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox2), label,1,1,0);

    gtk_widget_show_all(casebox);
}


int main(int argc, char *argv[])
{

    GtkWidget *vbox,*label,*button,*bg;
    gtk_init(&argc, &argv);

    main_page = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    casebox = gtk_vbox_new(0,0);
    vbox = gtk_vbox_new(0,0);
    label = gtk_label_new("------labellll-------------");
    button = gtk_button_new_with_label("button");


    gtk_box_pack_start(GTK_BOX(casebox), vbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox), label,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox), button,1,1,0);

    g_signal_connect(button, "clicked",G_CALLBACK(page2), casebox);
    g_signal_connect(button, "clicked",G_CALLBACK(widget_destroy), vbox);

    gtk_container_add(GTK_CONTAINER(main_page),casebox);
    gtk_widget_show_all(main_page);

    gtk_main();

    return 0;
}
