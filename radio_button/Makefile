# -*- Makefile -*-

all: radio_button

radio_button: radio_button.c
	gcc radio_button.c -o radio_button `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm radio_button