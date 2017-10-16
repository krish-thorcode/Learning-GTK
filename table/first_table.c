#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button_1, *button_2, *button_3, *table;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button_1 = gtk_button_new_with_mnemonic("1. _Doesn't expand/shrink");
	button_2 = gtk_button_new_with_mnemonic("2. Expands/shrinks _vertically");
	button_3 = gtk_button_new_with_mnemonic("3. _Expands and shrinks in both x and y");
	table = gtk_table_new(2,2,0); //rows,columns,homogeneity
	gtk_table_attach(GTK_TABLE(table),button_1,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
	gtk_table_attach(GTK_TABLE(table),button_2,0,1,1,2,GTK_FILL,GTK_EXPAND | GTK_FILL,0,0);
	gtk_table_attach(GTK_TABLE(table),button_3,1,2,0,2,GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL,0,0);

	gtk_container_add(GTK_CONTAINER(window),table);

	gtk_widget_show_all(window);

	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	gtk_main();

	return 0;

}