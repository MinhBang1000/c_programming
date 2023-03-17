# Sample makefile 
CC=gcc
AR=ar rcs

all: main

main: MinhMinh.o MinhMinh.h queue.a
	$(CC) -o main MinhMinh.o -L. -l:queue.a

MinhMinh.o: MinhMinh.c MinhMinh.h
	$(CC) -c MinhMinh.c -o MinhMinh.o

queue.a: queue.o
	$(AR) queue.a queue.o

queue.o: queue.c
	$(CC) -c queue.c -o queue.o

clean:
	rm -r *.o *.a main