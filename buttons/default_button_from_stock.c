#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	button =gtk_button_new_from_stock(GTK_STOCK_APPLY);

	gtk_container_add(GTK_CONTAINER(window),button);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}