# -*- Makefile -*-

all: hbox vbox

hbox: hbox.c
	gcc hbox.c -o hbox `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

vbox: vbox.c
	gcc vbox.c -o vbox `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

clean:
	rm hbox