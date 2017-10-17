#include<gtk/gtk.h>

static void activate_new(GtkWidget *new, gpointer data)
{
	g_print("You pressed new");
}

static void activate_about(GtkWidget *about, gpointer data)
{
	g_print("You pressed about");
}


int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);

	GtkWidget *window, *menu_bar, *menu, *menu_item, *aux_menu_item;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);

	menu_bar = gtk_menu_bar_new(); // a menu shell. in the present context, shell is something where you can append items

	menu = gtk_menu_new(); //this gives me an empty list where I can put different options

	menu_item = gtk_menu_item_new_with_label("File"); // creating the first menu item. But I want it to be a label for other options..
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),menu); //..I set the menu in line 13 as the submenu of menu_item. what i get is also a shell like menu bar
	aux_menu_item = gtk_menu_item_new_with_label("New");
	g_signal_connect(aux_menu_item,"activate",G_CALLBACK(activate_new),NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu),aux_menu_item);
	aux_menu_item = gtk_menu_item_new_with_label("Exit");
	g_signal_connect(aux_menu_item,"activate",G_CALLBACK(gtk_main_quit),NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu),aux_menu_item);

	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

	menu  = gtk_menu_new();

	menu_item = gtk_menu_item_new_with_label("Help");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),menu);
	aux_menu_item = gtk_menu_item_new_with_label("About");
	g_signal_connect(aux_menu_item,"activate",G_CALLBACK(activate_about),NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu),aux_menu_item);

	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

	gtk_container_add(GTK_CONTAINER(window),menu_bar);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}