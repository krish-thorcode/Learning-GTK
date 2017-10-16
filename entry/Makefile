# -*- MakeFile -*-

all: first_entry

first_entry: first_entry.c
	gcc first_entry.c -o first_entry `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_entry