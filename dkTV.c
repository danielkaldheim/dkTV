
/**
 *
 *	dkTV.c
 *	Created on 5.1.2014.
 *
 *	@author Daniel Rufus Kaldheim <daniel@kaldheim.org>
 *	@copyright 2010 - 2014 Crudus Media
 *	@version 1.0.0
 *
 */

#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include "gtkplayer.h"


static gint quit(GtkWidget *widget, GdkEventAny *event,
                                 gpointer data)
{
	GtkPlayer * p = (GtkPlayer *)data;
	gtk_player_stop(p);
	exit(0);
}

int main(int argc,char *argv[])
{
	/*we need a window*/
	GtkWidget *main_window, *box;
	/*and a player*/
	GtkPlayer *player;

	/* and a close something */
	GtkWidget *close = NULL;

	if(argc < 2) {
		printf("usage: %s file\n",argv[0]);
		exit(-1);
	}
	/*standard gtk stuff*/
	gtk_init(&argc,&argv);
	main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width (GTK_CONTAINER (main_window), 10);
	gtk_widget_realize (main_window);
    gtk_window_fullscreen(main_window);

    /* create closebutton */
    close = gtk_button_new_with_label("Close Window");



	box = gtk_vbox_new(FALSE,2);
	/*create player and integrate it*/
	player = gtk_player_new(argv[1]);

	gtk_container_add(GTK_CONTAINER(main_window), box);
	/* you could also don't use a box
	 * or use gtk_container_add(GTK_CONTAINER(box), player->widget);
	 */
	gtk_box_pack_start(GTK_BOX(box), player->widget,TRUE,TRUE,0);

        gtk_signal_connect(GTK_OBJECT(main_window), "delete_event",
                           GTK_SIGNAL_FUNC(quit), player);

	/*init player*/
	gtk_player_init(player);
	gtk_widget_show(main_window);
	gtk_widget_show(box);
	/*show player (the parent tree has to show)*/
	gtk_player_show(player);
	/*start player*/
	gtk_player_start(player);

	gtk_container_add(main_window, close);
	gtk_widget_show(close);

    /*** Callbacks ***/
    g_signal_connect (close, "clicked", gtk_main_quit, NULL);
    g_signal_connect (main_window, "destroy", gtk_main_quit, NULL);

	gtk_main();
}


/* End of file dkTV.c */
/* Location: ./dkTV.c */
