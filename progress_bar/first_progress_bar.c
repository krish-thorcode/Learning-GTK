#include<gtk/gtk.h>

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *progress;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "delete-event",G_CALLBACK(gtk_main_quit),NULL);

	progress = gtk_progress_bar_new();

	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress),0.23);
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress),"23%");
	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(progress),GTK_PROGRESS_TOP_TO_BOTTOM);

	gtk_container_add(GTK_CONTAINER(window),progress);
	
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}