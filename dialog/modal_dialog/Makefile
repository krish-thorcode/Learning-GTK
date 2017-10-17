# -*- Makefile -*-

all: dialog_modal

dialog_modal: dialog_modal.c
	gcc dialog_modal.c -o dialog_modal `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean: 
	rm dialog_modal