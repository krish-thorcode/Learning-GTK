# -*- Makefile -*-

all: first_notebook

first_notebook: first_notebook.c
	gcc first_notebook.c -o first_notebook `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_notebook