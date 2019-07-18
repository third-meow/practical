CC = g++
CFLAGS = -g -Wall
practical: main.o board.o property.o
	$(CC) -o practical main.cpp board.cpp property.cpp

board.o: board.cpp board.h
	$(CC) $(CFLAGS) -c board.cpp

property.o: property.cpp property.h
	$(CC) $(CFLAGS) -c property.cpp

clean:
	$(RM) practical *.o
