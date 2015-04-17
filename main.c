#include <gtk/gtk.h>
#include <string.h>
#include <time.h>
#include <math.h>

GtkWidget *window, *allbox, *scoreshow, *mainbox2, *timelabel;
int score=0;
int count=0;
static gboolean start_timer = FALSE;
static gboolean continue_timer = FALSE;
static int sec_expired = 0;

int main(int argc, char *argv[]);
int create_contact(GtkWidget *widget, gpointer allbox);
int create_howto(GtkWidget *widget, gpointer allbox);
int firstpage(GtkWidget *widget, gpointer allbox);
int create_play(GtkWidget *widget, gpointer allbox);
void setvalue(GtkWidget *widget, gpointer pre);

GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   return pixbuf;
}

int widget_destroy(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(data);
}

/*-------------------------time-----------------------------------*/
static gboolean _check_update(gpointer data)
{
    GtkLabel *timelabel = (GtkLabel*)data;
    ++sec_expired;
    printf("%d\n", sec_expired);
    if(count >= 15)
    {
        start_timer = TRUE;
        continue_timer = FALSE;
    }
    return continue_timer;
}
static void _start_timer(GtkWidget *button, gpointer data)
{
    (void)button;
    GtkWidget *timelabel = data;
    if(!start_timer)
    {
        g_timeout_add_seconds(1, _check_update, timelabel);
        start_timer = TRUE;
        continue_timer = TRUE;
    }
}

/*----------------------------------------------------------------*/

void create_score(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *mainbox, *vbox1, *vbox2, *vbox3, *hbox4;
    GtkWidget *timeshow, *scoreshow, *playagain, *quit;
    GtkWidget *space1, *space2, *space3, *space4;
    GtkWidget *imageplayagain, *imagequit;

    /*--------- CSS -----------*/
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*-------------------------*/

    char timeuse[10];
    char scoreget[10];

    mainbox = gtk_vbox_new(0,0);
    vbox1 = gtk_vbox_new(0,0);
    vbox2 = gtk_vbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    hbox4 = gtk_hbox_new(0,0);
    space1 = gtk_hbox_new(0,0);
    space2 = gtk_hbox_new(0,0);
    space3 = gtk_hbox_new(0,0);
    space4 = gtk_hbox_new(0,0);

    int min, sec;
    min = sec_expired/60;
    sec = sec_expired%60;

    sprintf(timeuse,"%.2d min %.2d sec", min,sec);
    timeshow = gtk_label_new(timeuse);
    gtk_widget_modify_font (timeshow,pango_font_description_from_string ("Cordia New 30"));

    sprintf(scoreget,"%d / 1500",score);
    scoreshow = gtk_label_new(scoreget);
    gtk_widget_modify_font (scoreshow,pango_font_description_from_string ("Cordia New 30"));

    playagain = gtk_button_new();
    imageplayagain = gtk_image_new_from_file("image/playagain.png");
    gtk_button_set_image(GTK_BUTTON(playagain), imageplayagain);
    g_signal_connect(playagain, "clicked",G_CALLBACK(setvalue), allbox);
    g_signal_connect(playagain, "clicked",G_CALLBACK(widget_destroy), mainbox);

    quit = gtk_button_new();
    imagequit = gtk_image_new_from_file("image/quit.png");
    gtk_button_set_image(GTK_BUTTON(quit), imagequit);
    g_signal_connect(G_OBJECT(quit), "clicked",G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    gtk_box_pack_start(GTK_BOX(allbox), mainbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox1,1,1,100);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox2,1,1,10);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox3,1,1,100);
    gtk_box_pack_start(GTK_BOX(mainbox), hbox4,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox2), timeshow,1,1,0);
    gtk_box_pack_start(GTK_BOX(vbox3), scoreshow,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space1,1,1,20);
    gtk_box_pack_start(GTK_BOX(hbox4), playagain,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space2,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), quit,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space3,1,1,20);

     //------------- CSS  --------------------------------------------------------------------------------------------------
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen,GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                         " GtkWindow {\n"
                                         "   background-image: url('image/background5.jpg');\n"
                                         "}\n", -1, NULL);
      g_object_unref (provider);
    //----------------------------------------------------------------------------------------------------------------------
    gtk_widget_show_all(allbox);
}

int create_howto(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *mainbox, *vbox1, *hbox2, *vbox3, *hbox4, *vbox5;
    GtkWidget *image1, *image2, *labelname, *label, *back, *imageback;
    GtkWidget *space1, *space2;

     /*----- CSS ----------- */
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*-----------------------*/

    mainbox = gtk_vbox_new(0,0);
    vbox1 = gtk_vbox_new(0,0);
    hbox2 = gtk_hbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    hbox4 = gtk_hbox_new(0,0);
    vbox5 = gtk_vbox_new(0,0);
    space1 = gtk_hbox_new(0,0);
    space2 = gtk_hbox_new(0,0);

    labelname = gtk_label_new("Contact us");

    image1 = gtk_image_new_from_file("image/exam1.png");
    gtk_widget_set_size_request(image1, 299, 249);

    image2 = gtk_image_new_from_file("image/exam2.png");
    gtk_widget_set_size_request(image2, 299, 249);

    label = gtk_label_new("new");
    back = gtk_button_new();
    imageback = gtk_image_new_from_file("image/back.png");
    gtk_button_set_image(back,imageback);

    /*------------- CSS  --------------------------------------------------------------------------------------------------*/
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen,GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                         " GtkWindow {\n"
                                         "   background-image: url('image/background3.jpg');\n"
                                         "}\n", -1, NULL);
      g_object_unref (provider);
    /*----------------------------------------------------------------------------------------------------------------------*/
    gtk_label_set_markup( labelname,"<span font='20' foreground='#000000' size='large'><b>How to play</b></span>");
    gtk_label_set_markup( label,"<span font='10' foreground='#000000' size='large'>Click the same shape of monkey and color.\n      If none, a completely one.</span>");
    gtk_box_pack_start(GTK_BOX(allbox), mainbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox1,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), hbox2,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox3,1,0,20);
    gtk_box_pack_start(GTK_BOX(mainbox), hbox4,1,0,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox5,1,1,20);
    gtk_box_pack_start(GTK_BOX(vbox1), labelname,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox2), image1,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox2), image2,1,0,0);
    gtk_box_pack_start(GTK_BOX(vbox3), label,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space1,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox4), back,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space2,1,0,0);

    g_signal_connect(back, "clicked",G_CALLBACK(firstpage), allbox);
    g_signal_connect(back, "clicked",G_CALLBACK(widget_destroy), mainbox);

    gtk_widget_show_all(mainbox);
}

int create_contact(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *mainbox, *vbox1, *hbox2, *vbox3, *vbox4, *space1, *space2;
    GtkWidget *labelname, *label, *back, *imageback;

    /*----- CSS ----------- */
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*-----------------------*/

    mainbox = gtk_vbox_new(0,0);
    vbox1 = gtk_vbox_new(0,0);
    hbox2 = gtk_hbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    vbox4 = gtk_vbox_new(0,0);
    space1 = gtk_hbox_new(0,0);
    space2 = gtk_hbox_new(0,0);

    labelname = gtk_label_new("Contact us");
    label = gtk_label_new("name");
    back = gtk_button_new();
    imageback = gtk_image_new_from_file("image/back.png");
    gtk_button_set_image(back,imageback);

    gtk_label_set_markup( labelname,"<span font='20' foreground='#000000' size='large'><b>Contact us</b></span>");
    gtk_label_set_markup( label,"<span font='10' foreground='#000000' size='large'><b>1.Thananya Thamrongthanyawong</b>\n    s7070048@kmitl.ac.th\n<b>2.Thanapa Thamrongthanyawong</b>\n    s7070049@kmitl.ac.th\n<b>3.Tharathip Malaimarn</b>\n    s7070054@kmitl.ac.th\n<b>4.Pawarisa Thong-ngoen</b>\n    s7070068@kmitl.ac.th\n<b>5.Palit Wiboonlit</b>\n    s7070085@kmitl.ac.th</span>");
    gtk_box_pack_start(GTK_BOX(allbox), mainbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox1,1,1,100);
    gtk_box_pack_start(GTK_BOX(mainbox), hbox2,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox3,1,1,30);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox4,1,1,20);
    gtk_box_pack_start(GTK_BOX(vbox1), labelname,1,0,0);
    gtk_box_pack_start(GTK_BOX(vbox1), label,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox2), space1,0,0,0);
    gtk_box_pack_start(GTK_BOX(hbox2), back,1,0,0);
    gtk_box_pack_start(GTK_BOX(hbox2), space1,1,0,0);

    /*------------- CSS  --------------------------------------------------------------------------------------------------*/
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen,GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                         " GtkWindow {\n"
                                         "   background-image: url('image/background3.jpg');\n"
                                         "}\n", -1, NULL);
      g_object_unref (provider);
    /*----------------------------------------------------------------------------------------------------------------------*/
    g_signal_connect(back, "clicked",G_CALLBACK(firstpage), allbox);
    g_signal_connect(back, "clicked",G_CALLBACK(widget_destroy), mainbox);

    gtk_widget_show_all(mainbox);
}

void setvalue(GtkWidget *widget, gpointer allbox)
{
    start_timer = FALSE;
    continue_timer = FALSE;
    count = 0;
    score = 0;
    sec_expired = 0;
    create_play(widget, allbox);
}

void checkanswer(GtkWidget *widget, gpointer pre)
{
    count+=1;
    char answer[100]="";
    strcat(answer,(char*)pre);
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

    if(count>=2)
    {
        start_timer = TRUE;
        continue_timer = FALSE;
        gtk_widget_destroy(mainbox2);
        create_score(widget, allbox);
    }
    else
        create_play(widget, allbox);
}

int create_play(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *mainbox, *hbox1, *hbox2, *vbox3, *hbox4;
    GtkWidget *lefthbox, *righthbox, *maincard, *card1, *card2, *card3;
    GtkWidget *space1, *space2, *space3, *space4;
    GtkWidget *imagemaincard, *imagecard1, *imagecard2, *imagecard3;

    /*----- CSS ----------- */
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*-----------------------*/

    char monkey[9][8] = {"earpink","earblue","earviol","optpink","optblue","optviol","moupink","moublue","mouviol"};
    char str[10];
    char random[8],click[16];
    char pic[15] = "image/card/";
    static char click1[16],click2[16],click3[16];

    mainbox2= gtk_vbox_new(0,0);
    hbox1 = gtk_hbox_new(0,0);
    hbox2 = gtk_hbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    hbox4 = gtk_hbox_new(0,0);
    lefthbox = gtk_hbox_new(0,0);
    maincard = gtk_hbox_new(0,0);
    righthbox = gtk_hbox_new(0,0);
    card1 = gtk_hbox_new(0,0);
    card2 = gtk_hbox_new(0,0);
    card3 = gtk_hbox_new(0,0);
    space1 = gtk_hbox_new(0,0);
    space2 = gtk_hbox_new(0,0);
    space3 = gtk_hbox_new(0,0);
    space4 = gtk_hbox_new(0,0);

    sprintf(str,"%d",score);
    scoreshow = gtk_label_new(str);
    gtk_widget_modify_font (scoreshow,pango_font_description_from_string ("Cordia New 30"));

    srand(time(0));
    strcpy(random,monkey[rand()%9]);
    strcpy(click,random);
    strcat(pic,random);
    strcat(pic,".png");

    imagemaincard = gtk_image_new_from_file (pic);

    card1 = gtk_button_new();
    imagecard1 = gtk_image_new_from_file("image/card/earpink.png");
    gtk_button_set_image(GTK_BUTTON(card1), imagecard1);
    strcpy(click1, random);
    strcat(click1,"earpink");
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(checkanswer), (gpointer) click1);
    g_signal_connect(G_OBJECT(card1), "clicked",G_CALLBACK(widget_destroy),mainbox2);

    card2 = gtk_button_new();
    imagecard2 = gtk_image_new_from_file("image/card/optblue.png");
    gtk_button_set_image(GTK_BUTTON(card2), imagecard2);
    strcpy(click2, random);
    strcat(click2,"optblue");
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(checkanswer), click2);
    g_signal_connect(G_OBJECT(card2), "clicked",G_CALLBACK(widget_destroy),mainbox2);

    card3 = gtk_button_new();
    imagecard3 = gtk_image_new_from_file("image/card/mouviol.png");
    gtk_button_set_image(GTK_BUTTON(card3), imagecard3);
    strcpy(click3, random);
    strcat(click3,"mouviol");
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(checkanswer),click3);
    g_signal_connect(G_OBJECT(card3), "clicked",G_CALLBACK(widget_destroy),mainbox2);

    gtk_box_pack_start(GTK_BOX(allbox), mainbox2,0,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox2), hbox1,0,1,10);
    gtk_box_pack_start(GTK_BOX(mainbox2), hbox2,0,0,0);
    gtk_box_pack_start(GTK_BOX(mainbox2), vbox3,0,0,0);
    gtk_box_pack_start(GTK_BOX(mainbox2), hbox4,1,1,10);
    gtk_box_pack_start(GTK_BOX(hbox1), scoreshow,1,1,25);
    gtk_box_pack_start(GTK_BOX(hbox2), lefthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox2), maincard,0,1,0);
    gtk_box_pack_start(GTK_BOX(maincard), imagemaincard,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox2), righthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space1,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), card1,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space2,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), card2,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space3,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), card3,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space4,1,1,0);

    /*------------- CSS  --------------------------------------------------------------------------------------------------*/
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen,GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider),
                                         " GtkWindow {\n"
                                         "   background-image: url('image/background4.jpg');\n"
                                         "}\n", -1, NULL);
      g_object_unref (provider);
    /*----------------------------------------------------------------------------------------------------------------------*/

    g_timeout_add_seconds(1, _start_timer, timelabel);
    continue_timer = TRUE;

    gtk_widget_show_all(allbox);
    return 0;

}
int firstpage(GtkWidget *widget, gpointer allbox)
{
    GtkWidget *mainbox, *vbox1, *hbox2, *vbox3, *hbox4;
    GtkWidget *lefthbox, *righthbox, *playhbox, *howhbox, *conhbox, *quithbox;
    GtkWidget *space1, *space2, *space3, *space4;
    GtkWidget *imageplay, *imagehowto, *imagecontact, *imagequit;
    GtkWidget *play, *howto, *contact, *quit;

    /*----- CSS ----------- */
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    /*-----------------------*/

    mainbox = gtk_vbox_new(0,0);
    vbox1 = gtk_vbox_new(0,0);
    hbox2 = gtk_hbox_new(0,0);
    vbox3 = gtk_vbox_new(0,0);
    hbox4 = gtk_hbox_new(0,0);
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
    gtk_box_pack_start(GTK_BOX(mainbox), hbox2,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), vbox3,1,1,0);
    gtk_box_pack_start(GTK_BOX(mainbox), hbox4,1,1,100);
    gtk_box_pack_start(GTK_BOX(hbox2), lefthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox2), playhbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(playhbox), play,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox2), righthbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space1,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), howhbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(howhbox), howto,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space2,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), conhbox,1,1,0);
    gtk_box_pack_start(GTK_BOX(conhbox), contact,0,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space3,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), quithbox,0,1,0);
    gtk_box_pack_start(GTK_BOX(quithbox), quit,1,1,0);
    gtk_box_pack_start(GTK_BOX(hbox4), space4,1,1,0);

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

    g_signal_connect(play, "clicked",G_CALLBACK(setvalue), allbox);
    g_signal_connect(play, "clicked",G_CALLBACK(widget_destroy), mainbox);
    g_signal_connect(howto, "clicked",G_CALLBACK(create_howto), allbox);
    g_signal_connect(howto, "clicked",G_CALLBACK(widget_destroy), mainbox);
    g_signal_connect(contact, "clicked",G_CALLBACK(create_contact), allbox);
    g_signal_connect(contact, "clicked",G_CALLBACK(widget_destroy), mainbox);
    g_signal_connect(G_OBJECT(quit), "clicked",G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    gtk_widget_show_all(allbox);

}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("image/icon.png"));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    allbox = gtk_vbox_new(0,0);

    firstpage(window, allbox);

    gtk_container_add(GTK_CONTAINER(window),allbox);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

