##
# @file  Makefile
# @brief Build executables for homework 3, INF-221, 2018-10-15

CC	= gcc
CFLAGS	= -g -O2 -Wall

all: README.pdf 20182t3p1 20182t3p2 20182t3p3 20182t3p4

20182t3p1: main.o match.o
	$(CC) $(CFLAGS) -o $@ $^

20182t3p2: main.o match-2.o
	$(CC) $(CFLAGS) -o $@ $^

20182t3p3: main.o match-3.o
	$(CC) $(CFLAGS) -o $@ $^

20182t3p4: main.o match-4.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: match.h

match.o: match.h

match-2.o: match.h

match-3.o: match.h

match-4.o: match.h

%.pdf: %.md
	pandoc $< -o $@

clean:
	rm -f main.o match.o match-2.o match-3.o match-4.o 

clobber:
	rm -f 20182t3p1 20182t3p2 20182t3p3 20182t3p4 \
              README.pdf

.PHONY: all clean clobber

