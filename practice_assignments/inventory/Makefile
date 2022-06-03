CC = g++
CFLAGS = -Wall -g -o inventory.exe

inventory: inventory.o item.o cll.o
	$(CC) $(CFLAGS) -o inventory inventory.o item.o cll.o

inventory.o: inventory.cpp item.h cll.h

item.o: item.h

cll.o: cll.h item.h
