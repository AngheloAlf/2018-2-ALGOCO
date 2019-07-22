CC      = gcc
CFLAGS  = -Wall -Wpedantic -std=gnu11
OPTIMIZ = -O2
INCLUDE = -I../common -I../2

NAME    = tarea-3-2


all: tarea install

tarea:
	$(CC) *.c ../common/*.c -o $(NAME) $(CFLAGS) $(OPTIMIZ) $(INCLUDE)

install:
	sudo install $(NAME) /usr/bin/

clean:
	rm $(NAME)