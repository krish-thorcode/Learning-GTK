# -*- MakeFile -*-

all: first_add_img

first_add_img: first_add_img.c
	gcc first_add_img.c -o first_add_img `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_add_img