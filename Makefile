CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall -v

OBJS = main.o photo.o
LIBS = -ljansson -lulfius

server: $(OBJS)
	mkdir -p bin
	$(CC) $(LFLAGS) $(OBJS) -o ./bin/server $(LIBS)
	rm *.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

photo.o: ./include/photo.h ./src/photo.c
	$(CC) $(CFLAGS) ./src/photo.c
	
clean:
	rm ./bin/server