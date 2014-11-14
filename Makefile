CFLAGS=-std=c99 -Wall -lm
CC=gcc

all:
	$(CC) $(CFLAGS) -o hunt hunt.c
