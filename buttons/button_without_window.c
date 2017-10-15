/* button without window doesn't show up */

#include<gtk/gtk.h>

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *button;
	button = gtk_button_new_with_label("Krishna");

	gtk_widget_show(button);

	gtk_main();
	return 0;
}