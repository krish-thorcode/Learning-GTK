# -*- Makefile -*-

all: first_table

first_table: first_table.c
	gcc first_table.c -o first_table `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_table