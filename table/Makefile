# -*- Makefile -*-

all: first_table same_name_for_buttons

first_table: first_table.c
	gcc first_table.c -o first_table `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

same_name_for_buttons: same_name_for_buttons.c
	gcc same_name_for_buttons.c -o same_name_for_buttons `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_table