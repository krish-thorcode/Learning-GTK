#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv); //initialise gtk first of all

	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //toplevel window
	g_signal_connect(window,"close_window",G_CALLBACK(gtk_main_quit),NULL);
	gtk_widget_show(window);

	gtk_main();
	return 0;
}