CC = gcc
CFLAGS = -Wall -g -c
LFLAGS = -Wall

OBJS = main.o photo.o lights.o doors.o
LIBS = -ljansson -lulfius

server: $(OBJS)
	mkdir -p bin
	$(CC) $(LFLAGS) $(OBJS) -o ./bin/server $(LIBS)
	rm *.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

photo.o: ./include/photo.h ./src/photo.c
	$(CC) $(CFLAGS) ./src/photo.c

lights.o: ./include/lights.h ./src/lights.c
	$(CC) $(CFLAGS) ./src/lights.c

doors.o: ./include/doors.h ./src/doors.c
	$(CC) $(CFLAGS) ./src/doors.c
	
clean:
	rm ./bin/server