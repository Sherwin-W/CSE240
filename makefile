OBJS	= zombie_wang.o hw5_wang_sherwin.o
SOURCE	= zombie_wang.cpp hw5_wang_sherwin.cpp
HEADER	= linkedList_wang.hpp zombie_wang.h
OUT	= exe
CC	= g++
FLAGS	= -g -c -Wall
LFLAGS	=

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

zombie_wang.o: zombie_wang.cpp
	$(CC) $(FLAGS) zombie_wang.cpp

hw5_wang_sherwin.o: hw5_wang_sherwin.cpp
	$(CC) $(FLAGS) hw5_wang_sherwin.cpp

clean:
	rm -f $(OBJS) $(OUT)