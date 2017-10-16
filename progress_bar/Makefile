# -*- Makefile -*-

all: first_progress_bar

first_progress_bar: first_progress_bar.c
	gcc first_progress_bar.c -o first_progress_bar `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_progress_bar