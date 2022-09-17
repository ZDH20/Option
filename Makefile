# CFLAGS=-Wall -Wextra -std=c99 -pedantic
CFLAGS=-std=c99 -pedantic
main: main.c option.c
	gcc $(CFLAGS) -o main main.c option.c option.h
