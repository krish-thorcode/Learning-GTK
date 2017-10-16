# -*- MakeFile -*-

all: first_toggle_button first_check_button

first_toggle_button: first_toggle_button.c
	gcc first_toggle_button.c -o first_toggle_button `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

first_check_button: first_check_button.c
	gcc first_check_button.c -o first_check_button_button `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_toggle_button first_check_button