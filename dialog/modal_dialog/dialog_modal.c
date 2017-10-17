#include<gtk/gtk.h>

static void open_dialog(GtkWidget *button, gpointer window)
{
	GtkWidget *dialog, *label;

	/*arg1= title of dialog, arg2= parent window of dialog, arg3= flag(modal/non-modal, arg4,arg5...= buttons and response pairs. last arg has to be NULL */
	dialog = gtk_dialog_new_with_buttons("Dialog",GTK_WINDOW(window),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
	label = gtk_label_new("You opened the dialog");

	/* adding label to the dialog. dialog itself contains a vbox which can be used to fill widgets into */
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),label,0,0,0);
	gtk_widget_show_all(dialog);

	gint response = gtk_dialog_run(GTK_DIALOG(dialog)); //gtk_dialog_run listens to the signals emmited by the buttons in the dialog

	if(response == GTK_RESPONSE_OK)
		g_print("OK was pressed. Response Code: %d\n",GTK_RESPONSE_OK);
	else
		g_print("Cancel was pressed. Response code: %d\n",GTK_RESPONSE_CANCEL);

	gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, * button;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	button = gtk_button_new_with_label("Click to open dialog");
	g_signal_connect(button,"clicked",G_CALLBACK(open_dialog),window);

	gtk_container_set_border_width(GTK_CONTAINER(window),100);
	gtk_container_add(GTK_CONTAINER(window),button);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}