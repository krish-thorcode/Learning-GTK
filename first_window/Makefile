# -*- MakeFile -*-

all: first_window

first_window: first_window.c
	gcc first_window.c -o first_window  `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

clean:
	rm first_window