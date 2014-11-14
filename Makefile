CFLAGS=-std=c99 -Wall

all:
	$(CC) $(CFLAGS) -o hunt hunt.c
