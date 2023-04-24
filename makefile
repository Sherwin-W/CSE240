CC=g++
CFLAGS=-c -Wall

all: program

program: hw5_wang_sherwin.o zombie_wang.o
	$(CC) hw5_wang_sherwin.o zombie_wang.o -o program

hw5_wang_sherwin.o: hw5_wang_sherwin.cpp linkedList_wang.hpp
	$(CC) $(CFLAGS) hw5_wang_sherwin.cpp

zombie_wang.o: zombie_wang.cpp zombie_wang.h
	$(CC) $(CFLAGS) zombie_wang.cpp

clean:
	rm -rf *o program