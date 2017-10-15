#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv); //initialise gtk first of all

	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //toplevel window

	GtkWidget *label = gtk_label_new("Hello, world!");

	gtk_container_add(GTK_CONTAINER(window),label);

	g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL); //delete_event can be replaced by delete-event
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}