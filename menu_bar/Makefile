# -*- MakeFile -*-

all: first_menu_bar cppguycode

first_menu_bar: first_menu_bar.c
	gcc first_menu_bar.c -o first_menu_bar `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

cppguycode: cppguycode.c
	gcc cppguycode.c -o cppguycode `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_menu_bar cppguycode