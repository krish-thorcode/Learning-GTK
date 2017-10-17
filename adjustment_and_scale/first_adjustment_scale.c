#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *scale;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	/* gtk_adjustment_new() takes 6 parameters: default_value,minimum value,maximum value,change per unit arrow press, change per 
	unit page up/down press,width of the window */
	GtkObject *adjustment = gtk_adjustment_new(0,0,10,1,1,0);

	/* gtk_hscale(or vscale)_new takes only one argument, which GtkAdjustment variable */
	scale = gtk_hscale_new(GTK_ADJUSTMENT(adjustment));

	gtk_container_add(GTK_CONTAINER(window),scale);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}