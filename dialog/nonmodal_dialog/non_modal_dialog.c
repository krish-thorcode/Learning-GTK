#include<gtk/gtk.h>


static void dialog_response(GtkWidget *dialog, gint response, gpointer data)
{
	if(response == GTK_RESPONSE_OK)
		g_print("OK\n");
	else
		gtk_widget_destroy(dialog);
}

static void open_dialog(GtkWidget *widget,gpointer window)
{
	GtkWidget *dialog,*label, *image, *hbox;

	dialog = gtk_dialog_new_with_buttons("Dialog",GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

	label = gtk_label_new("It is a non-modal dialog");

	image = gtk_image_new_from_stock(GTK_STOCK_INFO,GTK_ICON_SIZE_DIALOG);

	hbox = gtk_hbox_new(0,0);

	gtk_box_pack_start(GTK_BOX(hbox),image,0,0,0);
	gtk_box_pack_start(GTK_BOX(hbox),label,0,0,0);

	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),hbox,0,0,0);

	gtk_widget_show_all(dialog);

	/*gint response = gtk_dialog_run(GTK_DIALOG(dialog));*/ /*gtk_dialog_run is used in modal dialogs */
	g_signal_connect(dialog,"response",G_CALLBACK(dialog_response),NULL);


}	


int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	button = gtk_button_new_with_mnemonic("_Click to open dialog");
	g_signal_connect(button,"clicked",G_CALLBACK(open_dialog),window);

	gtk_container_add(GTK_CONTAINER(window),button);
	gtk_container_set_border_width(GTK_CONTAINER(window),100);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;

}