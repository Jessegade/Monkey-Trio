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

    char answer[100]="";
    static int score=0;
    strcat(answer,(char*)pre);
    printf("||     %s          ||",(char*)pre);
    if(((answer[0]=='e')&&(answer[3]=='p')) || ((answer[0]=='o')&&(answer[3]=='b')) || ((answer[0]=='m')&&(answer[3]=='v')))
    {
        if((answer[0]==answer[7]) && (answer[3]==answer[10]))
        {
            score+=100;
            printf(" > if1");
        }
    }

    else
    {
        if((answer[0]!=answer[7]) && (answer[3]!=answer[10]))
        {
            score+=100;
            printf(" > if2");
        }
    }
    printf(" point: %d\n",score);


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
    char click1[16],click2[16],click3[16];
    srand(time(0));
    strcpy(random,monkey[rand()%9]);
    printf( "%s\n",random );
    strcat(pic,random);
    strcat(pic,".png");
    printf( "%s\n",pic );

    image = gtk_image_new_from_file (pic);
    gtk_layout_put(GTK_LAYOUT(layout), image, 320, 50);

    imagecard1 = gtk_image_new_from_file("image/card/earpink.png");

    card1 = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), card1, 50, 320);
    gtk_button_set_image(GTK_BUTTON(card1), imagecard1);
    strcpy(click1,random);
    strcat(click1,"earpink");
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(ii), (gpointer) click1);


    imagecard2 = gtk_image_new_from_file("image/card/optblue.png");

    card2 = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), card2, 320, 320);
    gtk_button_set_image(GTK_BUTTON(card2), imagecard2);
    strcpy(click2,random);
    strcat(click2,"optblue");
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(ii), (gpointer) click2);

    imagecard3 = gtk_image_new_from_file("image/card/mouviol.png");

    card3 = gtk_button_new_with_label("");
    gtk_layout_put(GTK_LAYOUT(layout), card3, 590, 320);
    gtk_button_set_image(GTK_BUTTON(card3), imagecard3);
    strcpy(click3,random);
    strcat(click3,"mouviol");
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(ii),(gpointer) click3);


    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
