#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button, *table;

	table = gtk_table_new(2,2,0); //rows,columns,homogeneity
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_mnemonic("1. _Doesn't expand/shrink");
	gtk_table_attach(GTK_TABLE(table),button,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
	button = gtk_button_new_with_mnemonic("2. Expands/shrinks _vertically");
	gtk_table_attach(GTK_TABLE(table),button,0,1,1,2,GTK_FILL,GTK_EXPAND | GTK_FILL,0,0);
	button = gtk_button_new_with_mnemonic("3. _Expands and shrinks in both x and y");
	gtk_table_attach(GTK_TABLE(table),button,1,2,0,2,GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL,0,0);

		
	gtk_container_add(GTK_CONTAINER(window),table);

	gtk_widget_show_all(window);

	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	gtk_main();

	return 0;

}