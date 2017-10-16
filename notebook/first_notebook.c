#include<gtk/gtk.h>

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *notebook, *label, *label_1;

	gint i;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	notebook = gtk_notebook_new();
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook),GTK_POS_BOTTOM); //default position is top

	for(i=0;i<5;i++)
	{

		gchar str[100];

		sprintf(str,"This is Page %d\nhahahaha\nhahahaha",i+1);
		label = gtk_label_new(str);

		sprintf(str,"Page %d",i+1);
		label_1 = gtk_label_new(str);

		gtk_notebook_append_page(GTK_NOTEBOOK(notebook),label,label_1);
	}

	gtk_container_add(GTK_CONTAINER(window),notebook);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}