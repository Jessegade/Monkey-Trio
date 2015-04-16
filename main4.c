#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
GtkWidget *window,*allbox;
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

int widget_destroy(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
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
    page2(widget, allbox);
    //main();
}

int page2(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *mainbox, *vbox1, *vbox2, *vbox3, *vbox4;
    GtkWidget *lefthbox, *righthbox ,*playhbox,*howhbox,*conhbox,*quithbox;
    GtkWidget *space1, *space2,*space3,*space4;
    GtkWidget *label;
    GtkWidget *layout;
    GtkWidget *image,*imagemaincard,*imagecard1,*imagecard2,*imagecard3;
    GtkWidget *maincard,*card1,*card2,*card3;
    GtkWidget *imagebutton;

    vbox2 = gtk_vbox_new(0,0);
    label = gtk_label_new("HOW TO PLAY");
    gtk_box_pack_start(GTK_BOX(allbox), vbox2,1,1,0);
    //gtk_box_pack_start(GTK_BOX(vbox2), label,1,1,0);

    char monkey[9][8] = {"earpink","earblue","earviol","optpink","optblue","optviol","moupink","moublue","mouviol"};

    mainbox = allbox;
    vbox1 = gtk_vbox_new(0,0);
    vbox2 = gtk_hbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    vbox4 = gtk_hbox_new(0,0);
    lefthbox = gtk_hbox_new(0,0);
    playhbox = gtk_hbox_new(0,0);
    righthbox = gtk_hbox_new(0,0);
    howhbox = gtk_hbox_new(0,0);
    conhbox = gtk_hbox_new(0,0);
    quithbox = gtk_hbox_new(0,0);
    space1 = gtk_hbox_new(0,0);
    space2 = gtk_hbox_new(0,0);
    space3 = gtk_hbox_new(0,0);
    space4 = gtk_hbox_new(0,0);

    char random[8],click[16];
    char pic[15] = "image/card/";
    int len;
    static char click1[16],click2[16],click3[16];
    srand(time(0));
    strcpy(random,monkey[rand()%9]);
    strcpy(click,random);
    printf( "%s\n",random );
    strcat(pic,random);
    printf("click----------------%s\n", click);
    strcat(pic,".png");
    printf( "%s\n",pic );

    image = gtk_image_new_from_file (pic);
    //gtk_layout_put(GTK_LAYOUT(layout), image, 320, 50);

    imagecard1 = gtk_image_new_from_file("image/card/earpink.png");

    card1 = gtk_button_new_with_label("");
    //gtk_layout_put(GTK_LAYOUT(layout), card1, 50, 320);
    gtk_button_set_image(GTK_BUTTON(card1), imagecard1);
    strcpy(click1, random);
    strcat(click1,"earpink");
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(ii), (gpointer) click1);
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(widget_destroy),vbox1);
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(widget_destroy),vbox2);
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(widget_destroy),vbox3);
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(widget_destroy),vbox4);



    imagecard2 = gtk_image_new_from_file("image/card/optblue.png");

    card2 = gtk_button_new_with_label("");
    //gtk_layout_put(GTK_LAYOUT(layout), card2, 320, 320);
    gtk_button_set_image(GTK_BUTTON(card2), imagecard2);
    strcpy(click2, random);
    strcat(click2,"optblue");
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(ii), click2);
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(widget_destroy),vbox1);
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(widget_destroy),vbox2);
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(widget_destroy),vbox3);
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(widget_destroy),vbox4);


    imagecard3 = gtk_image_new_from_file("image/card/mouviol.png");

    card3 = gtk_button_new_with_label("");
    //gtk_layout_put(GTK_LAYOUT(layout), card3, 590, 320);
    gtk_button_set_image(GTK_BUTTON(card3), imagecard3);
    strcpy(click3, random);
    strcat(click3,"mouviol");
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(ii),click3);
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(widget_destroy),vbox1);
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(widget_destroy),vbox2);
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(widget_destroy),vbox3);
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(widget_destroy),vbox4);

//    gtk_box_pack_start(GTK_BOX(vbox2), image,1,1,0);
//    gtk_box_pack_start(GTK_BOX(vbox2), card1,1,1,0);
//    gtk_box_pack_start(GTK_BOX(vbox2), card2,1,1,0);
//    gtk_box_pack_start(GTK_BOX(vbox2), card3,1,1,0);
   // gtk_box_pack_start(GTK_BOX(allbox), mainbox,1,1,0);
    //gtk_box_pack_start(GTK_BOX(mainbox), vbox1,1,1,120);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox2,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox3,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox4,1,1,100);
    gtk_box_pack_start(GTK_BOX(vbox2), lefthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox2), playhbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(playhbox), image,0,1,0);
    gtk_box_pack_start(GTK_BOX(vbox2), righthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space1,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), howhbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(howhbox), card1,0,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space2,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), conhbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(conhbox), card2,0,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space3,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), quithbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(quithbox), card3,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space4,1,1,0);

    gtk_widget_show_all(allbox);
    return 0;
}
/*
int create_contact(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *vbox, *labelname, *label;

    vbox2 = gtk_vbox_new(0,0);
    labelname = gtk_label_new("Contact us");

    gtk_box_pack_start(GTK_BOX(allbox), vbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox), labelname,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox), label,1,1,0);

    gtk_widget_show_all(allbox);
}
*/

int main(int argc, char *argv[])
{

    GtkWidget *mainbox, *vbox1, *vbox2, *vbox3, *vbox4;
    GtkWidget *lefthbox, *righthbox ,*playhbox,*howhbox,*conhbox,*quithbox;
    GtkWidget *label,*label2,*label3,*label4,*label5,*label6;
    GtkWidget *space1, *space2,*space3,*space4;
    GtkWidget *imageplay, *imagehowto, *imagecontact, *imagequit;
    GtkWidget *play, *howto, *contact, *quit;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("image/icon.png"));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    /*----- CSS ----------- */
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*-----------------------*/

    allbox = gtk_vbox_new(0,0);
    mainbox = gtk_vbox_new(0,0);
    vbox1 = gtk_vbox_new(0,0);
    vbox2 = gtk_hbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    vbox4 = gtk_hbox_new(0,0);
    lefthbox = gtk_hbox_new(0,0);
    playhbox = gtk_hbox_new(0,0);
    righthbox = gtk_hbox_new(0,0);
    howhbox = gtk_hbox_new(0,0);
    conhbox = gtk_hbox_new(0,0);
    quithbox = gtk_hbox_new(0,0);
    space1 = gtk_hbox_new(0,0);
    space2 = gtk_hbox_new(0,0);
    space3 = gtk_hbox_new(0,0);
    space4 = gtk_hbox_new(0,0);

    label = gtk_label_new("---vbox1---");
    label2 = gtk_label_new("---vbox2---");
    label3 = gtk_label_new("---vbox3---");
    label4 = gtk_label_new("---vbox4---");
    label5 = gtk_label_new("---left---");
    label6 = gtk_label_new("---right---");

    play = gtk_button_new();
    imageplay = gtk_image_new_from_file("image/play.png");
    gtk_button_set_image(play,imageplay);

    howto = gtk_button_new();
    imagehowto = gtk_image_new_from_file("image/howto.png");
    gtk_button_set_image(howto,imagehowto);

    contact = gtk_button_new();
    imagecontact = gtk_image_new_from_file("image/contact.png");
    gtk_button_set_image(contact,imagecontact);

    quit = gtk_button_new();
    imagequit = gtk_image_new_from_file("image/quit.png");
    gtk_button_set_image(quit,imagequit);

    gtk_box_pack_start(GTK_BOX(allbox), mainbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox1,1,1,120);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox2,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox3,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox4,1,1,100);
    gtk_box_pack_start(GTK_BOX(vbox2), lefthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox2), playhbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(playhbox), play,0,1,0);
    gtk_box_pack_start(GTK_BOX(vbox2), righthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space1,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), howhbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(howhbox), howto,0,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space2,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), conhbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(conhbox), contact,0,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space3,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), quithbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(quithbox), quit,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox4), space4,1,1,0);

    /*------------- CSS  --------------------------------------------------------------------------------------------------*/
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen,GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                         " GtkWindow {\n"
                                         "   background-image: url('image/background2.jpg');\n"
                                         "}\n", -1, NULL);
      g_object_unref (provider);
    /*----------------------------------------------------------------------------------------------------------------------*/

    g_signal_connect(play, "clicked",G_CALLBACK(page2), allbox);
    g_signal_connect(play, "clicked",G_CALLBACK(widget_destroy), mainbox);



    gtk_container_add(GTK_CONTAINER(window),allbox);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
