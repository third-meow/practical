CC = g++
CFLAGS = -g -Wall
practical: main.o board.o property.o player.o
	$(CC) $(CFLAGS) -o practical main.cpp board.cpp property.cpp player.o

clean:
	$(RM) practical *.o
