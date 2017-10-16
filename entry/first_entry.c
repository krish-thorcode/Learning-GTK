#include<gtk/gtk.h>

static void write_on_console(GtkWidget *widget, gpointer data)
{
	g_print("%s\n",gtk_entry_get_text(GTK_ENTRY(data)));
	gtk_entry_set_text(GTK_ENTRY(data),"Printed on the console!");
	gtk_editable_select_region(GTK_EDITABLE(data),0,-1);
	gtk_editable_copy_clipboard(GTK_EDITABLE(data)); //copies the content of the GTK_EDITABLE in the argument to tthe clipboard (independent of the select_region)
}

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button, *entry, *hbox;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);
	button = gtk_button_new_with_mnemonic("_Click to print on console");
	entry = gtk_entry_new();
	g_signal_connect(button,"clicked",G_CALLBACK(write_on_console),(gpointer)entry);
	g_signal_connect(entry,"activate",G_CALLBACK(write_on_console),(gpointer)entry);
	hbox = gtk_hbox_new(0,0);

	gtk_box_pack_start(GTK_BOX(hbox),entry,0,0,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,0,0,0);

	gtk_container_add(GTK_CONTAINER(window),hbox);
	gtk_window_set_title(GTK_WINDOW(window),"Entry field");

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}