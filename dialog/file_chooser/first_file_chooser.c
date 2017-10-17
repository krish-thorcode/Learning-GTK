#include<gtk/gtk.h>

static void file_chooser(GtkWidget *button, gpointer window)
{
	GtkWidget *file_chooser_dialog;
	gint response;

	/*arg1= title, arg2= mode, mode =GTK_FILE_CHOOSER_ACTION_OPEN,SAVE,SELECT_FOLDER, arg3= button/response pairs follow */
	file_chooser_dialog = gtk_file_chooser_dialog_new("Choose a file",GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

	
	gtk_widget_show_all(file_chooser_dialog);

	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(file_chooser_dialog),g_get_home_dir()); //optional

	response = gtk_dialog_run(GTK_DIALOG(file_chooser_dialog));

	if(response == GTK_RESPONSE_OK)
		g_print("File selected: %s\n",gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser_dialog)));
	else
		g_print("Operation cancelled\n");

	gtk_widget_destroy(file_chooser_dialog);

}

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);

	button = gtk_button_new_with_mnemonic("_Choose file");
	g_signal_connect(button,"clicked",G_CALLBACK(file_chooser),window);

	gtk_container_add(GTK_CONTAINER(window),button);
	gtk_container_set_border_width(GTK_CONTAINER(window),100);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}