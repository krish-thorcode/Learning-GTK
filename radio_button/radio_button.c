#include<gtk/gtk.h>
#include<string.h>

static void radio_clicked(GtkWidget *widget, gpointer data)
{
	char *radio = (char*)data;
	int i=0;

	if(strcmp(radio,"1")==0)
		i=1;
	if(strcmp(radio,"2")==0)
		i=2;
	if(strcmp(radio,"3")==0)
		i=3;

	switch(i)
	{
		case 1:
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
				g_print("Radio 1 clicked\n");
			else
				g_print("Radio 1 unclicked\n");
			break;

		case 2:
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
				g_print("Radio 2 clicked\n");
			else
				g_print("Radio 2 unclicked\n");
			break;

		case 3:
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
				g_print("Radio 3 clicked\n");
			else
				g_print("Radio 3 unclicked\n");
			break;
	}
}
int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	gint i;

	GtkWidget *window, *main_radio, *other_radio, *vbox;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	vbox = gtk_vbox_new(0,0);

	main_radio = gtk_radio_button_new_with_mnemonic(NULL,"Option 1"); //first arg is the group to which main_radio belongs
	g_signal_connect(main_radio,"toggled",G_CALLBACK(radio_clicked),(gpointer)"1");
	gtk_box_pack_start(GTK_BOX(vbox),main_radio,0,0,0);

	other_radio = gtk_radio_button_new_with_mnemonic(gtk_radio_button_get_group(GTK_RADIO_BUTTON(main_radio)),"Option 2");
	gtk_box_pack_start(GTK_BOX(vbox),other_radio,0,0,0);
	g_signal_connect(other_radio,"toggled",G_CALLBACK(radio_clicked),(gpointer)"2");

	other_radio = gtk_radio_button_new_with_mnemonic(gtk_radio_button_get_group(GTK_RADIO_BUTTON(main_radio)),"Option 3");
	gtk_box_pack_start(GTK_BOX(vbox),other_radio,0,0,0);
	g_signal_connect(other_radio,"toggled",G_CALLBACK(radio_clicked),(gpointer)"3");

	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show_all(window) ;

	gtk_main();
	return 0;
}