#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
void ii(GtkWidget *widget, gpointer pre)
{
    char randomcolor, randomorgan, anscolor, ansorgan;
    char answer[8]="";
    int len;
    //len = strlen(pre);
    //pre[len]='\0';
    strcat(answer,(char*)pre);
    printf("||     %s          ||\n", (char*) pre);
    randomcolor = answer[3];
    randomorgan = answer[0];
    g_print(":=]      %s       :=]", answer);
//    g_print("%s", random);
    anscolor = answer[10];
    ansorgan = answer[7];
    printf( "%c\n",anscolor);

}
int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *image,*imagemaincard,*imagecard1,*imagecard2,*imagecard3;
    GtkWidget *maincard,*card1,*card2,*card3;
    GtkWidget *imagebutton;
    GtkWidget *button;
    char monkey[9][8] = {"earpink","earblue","earviol","optpink","optblue","optviol","moupink","moublue","mouviol"};
    char answer[8];
    int i;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("image/icon.png"));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);

    static char random[8];
    char pic[15] = "image/card/";
    int len;
    char pass[15];
    srand(time(0));
    strcpy(random,monkey[rand()%9]);
    printf( "%s\n",random );
    strcat(pic,random);
    strcat(pic,".png");
    printf( "%s\n",pic );
    strcpy(pass,random);
    len = strlen(pass);
    pass[len] = '\0';

    image = gtk_image_new_from_file (pic);
    gtk_layout_put(GTK_LAYOUT(layout), image, 320, 50);

    imagecard1 = gtk_image_new_from_file("image/card/earpink.png");

    card1 = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), card1, 50, 320);
    gtk_button_set_image(GTK_BUTTON(card1), imagecard1);
    //g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(ii), (gpointer) "earpink");


    imagecard2 = gtk_image_new_from_file("image/card/optblue.png");

    card2 = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), card2, 320, 320);
    gtk_button_set_image(GTK_BUTTON(card2), imagecard2);
    //g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(ii), (gpointer) "optblue");

    imagecard3 = gtk_image_new_from_file("image/card/mouviol.png");

    card3 = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), card3, 590, 320);
    gtk_button_set_image(GTK_BUTTON(card3), imagecard3);
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(ii),(gpointer) strcat(pass, "mouviol"));




//    if(random==monkey[0] || random==monkey[4] || random==monkey[8])
//    {
//
//    }



    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
