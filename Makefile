CC = g++
CFLAGS = -g -Wall
practical: main.o board.o property.o player.o
	$(CC) $(CFLAGS) -o practical main.o board.o property.o player.o

clean:
	$(RM) practical *.o
