#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window,*button;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("hello, world");

	gtk_container_add(GTK_CONTAINER(window),button);
	g_signal_connect(window,"delete-event",(G_CALLBACK(gtk_main_quit)),NULL);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}