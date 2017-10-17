#include<gtk/gtk.h>

static void scale_slide(GtkWidget *widget, gpointer data)
{
	g_print("%f\n",gtk_range_get_value(GTK_RANGE(widget)));
}

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
	gtk_scale_set_value_pos(GTK_SCALE(scale),GTK_POS_BOTTOM); //GTK_POS_TOP is default, LEFT and RIGHT also possible
	gtk_scale_set_digits(GTK_SCALE(scale),3); //increases the precision of value
	gtk_scale_set_draw_value(GTK_SCALE(scale),0); //setting 1 instead of 0 will make the value visible
	g_signal_connect(scale,"value-changed",G_CALLBACK(scale_slide),NULL);

	gtk_container_add(GTK_CONTAINER(window),scale);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}