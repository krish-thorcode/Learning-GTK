# -*- Makefile -*-

all: first_file_chooser

first_file_chooser: first_file_chooser.c
	gcc first_file_chooser.c -o first_file_chooser `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean: 
	rm first_file_chooser