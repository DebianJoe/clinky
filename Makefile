CC = gcc
CFLAGS = -Wall 

main: clinky

install:
	mv clinky /usr/bin/clinky

clean:
	rm clinky
