# -*- MakeFile -*-

all: first_window change_label_text

first_window: first_window.c
	gcc first_window.c -o first_window  `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

change_label_text: change_label_text.c
	gcc change_label_text.c -o change_label_text `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

clean:
	rm first_window change_label_text