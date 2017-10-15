#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button, *table;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("1. Doesn't expand/shrink");
	button = gtk_button_new_with_label("2. Expands/shrinks vertically");
	button = gtk_button_new_label("3. Expands and shrinks in both x and y")

	gtk_table_attach
}