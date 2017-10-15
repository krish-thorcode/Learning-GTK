# -*- MakeFile -*-

all: first_window

first_window: first_window.c
	gcc `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0` first_window.c -o first_window

clean:
	rm first_window