#include<gtk/gtk.h>

static void change_label(GtkWidget *widget,gpointer data)
{
	gtk_label_set_text(GTK_LABEL(data),"You clicked the button!");
}

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *label, *button, *hbox;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	label = gtk_label_new("hello, dude");
	button = gtk_button_new_with_label("Click to change the label");

	hbox = gtk_box_new(0,1); //gtk_hbox_new is now deprecated. gtk_box_new by default produces horizontal box
	gtk_box_pack_start(GTK_BOX(hbox),label,1,1,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,1,1,0);
	gtk_container_add(GTK_CONTAINER(window),hbox);
	
	g_signal_connect(button,"clicked",G_CALLBACK(change_label),(gpointer)label);

	gtk_widget_show_all(window);
	gtk_main();
	return 0;

}