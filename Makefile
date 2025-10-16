# Makefile for the 'integrate' module and its test program.


CFLAGS = -Wall -pedantic -std=c11 -lm

all: test1 test2

test1: test1.o integrate.o
	gcc $(CFLAGS) test1.o integrate.o -o test1

test2: test2.o integrate.o
	gcc $(CFLAGS) test2.o integrate.o -o test2

test1.o: test1.c integrate.h
	gcc $(CFLAGS) -c test1.c

test2.o: test2.c integrate.h
	gcc $(CFLAGS) -c test2.c

integrate.o: integrate.c integrate.h
	gcc $(CFLAGS) -c integrate.c

clean:
	rm -f test1 test2 *.o
