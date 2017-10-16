# -*- MakeFile -*-

all: first_button default_button_from_stock

first_button: first_button.c
	gcc first_button.c -o first_button `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

default_button_from_stock: default_button_from_stock.c
	gcc default_button_from_stock.c -o default_button_from_stock `pkg-config --libs gtk+-2.0` `pkg-config --cflags gtk+-2.0`

clean:
	rm first_button