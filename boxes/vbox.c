#include<gtk/gtk.h>

static void change_label(GtkWidget *widget, gpointer data)
{
	gtk_label_set_text(GTK_LABEL(data),"You clicked the button!");
}

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *button, *vbox, *label;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("Click me to change the label");
	vbox = gtk_box_new(0,1);
	gtk_orientable_set_orientation(GTK_ORIENTABLE(vbox),GTK_ORIENTATION_VERTICAL);
	label = gtk_label_new("hello, world!");

	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_box_pack_start(GTK_BOX(vbox),button,1,1,0);
	gtk_container_add(GTK_CONTAINER(window),vbox);

	gtk_widget_show_all(window);

	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button, "clicked", G_CALLBACK(change_label),(gpointer)label);

	gtk_main();
	return 0;

}