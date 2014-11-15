CFLAGS=-std=c99 -Wall -lm -Iinclude
CC=gcc

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst src/%.c,src/%.o,$(SOURCES))

all: $(OBJECTS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o hunt $(OBJECTS)
