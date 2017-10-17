# -*- Makefile -*-

all: first_adjustment_scale

first_adjustment_scale: first_adjustment_scale.c
	gcc first_adjustment_scale.c -o first_adjustment_scale `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_adjustment_scale