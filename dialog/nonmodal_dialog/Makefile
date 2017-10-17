# -*- Makefile -*-

all: non_modal_dialog

non_modal_dialog: non_modal_dialog.c
	gcc non_modal_dialog.c -o non_modal_dialog `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm non_modal_dialog