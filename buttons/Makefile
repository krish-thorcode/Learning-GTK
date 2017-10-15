# -*- MakeFile -*-

all: first_button

first_button: first_button.c
	gcc first_button.c -o first_button `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

clean:
	rm first_button