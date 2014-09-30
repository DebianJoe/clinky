CC = gcc
CFLAGS = -Wall -lncurses

main: clinky

install:
	mv clinky /usr/bin/clinky

clean:
	rm clinky
