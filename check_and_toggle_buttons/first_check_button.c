#include<gtk/gtk.h>

static void toggle_status(GtkWidget *widget, gpointer data)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
		g_print("The button is printed!\n");

	else
		g_print("The button is not printed!\n");
}

static void check_status(GtkWidget *widget,gpointer data)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))) // strikingly, check and toggle use the same functions for this purpose. inheritence underlies this property.
		g_print("The box is checked!\n");

	else
		g_print("The box isn't checked!\n");
}

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *toggle, *check, *vbox;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);

	toggle = gtk_toggle_button_new_with_mnemonic("_Toggle");
	g_signal_connect(toggle,"toggled",G_CALLBACK(toggle_status),NULL);

	check = gtk_check_button_new_with_mnemonic("_Check");
	g_signal_connect(check,"toggled",G_CALLBACK(check_status),NULL);

	vbox = gtk_vbox_new(0,0);
	gtk_box_pack_start(GTK_BOX(vbox),check,0,0,0);
	gtk_box_pack_start(GTK_BOX(vbox),toggle,0,0,0);

	gtk_container_add(GTK_CONTAINER(window),vbox);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}