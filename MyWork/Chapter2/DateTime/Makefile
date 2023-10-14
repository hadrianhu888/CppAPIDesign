# Compiler settings - Can be customized
CC = g++
CFLAGS = -std=c++11 -Wall

# Build rules
all: main

main: main.o DateTimeAPI.o
	$(CC) $(CFLAGS) -o main main.o DateTimeAPI.o

main.o: main.cpp DateTimeAPI.h
	$(CC) $(CFLAGS) -c main.cpp

DateTimeAPI.o: DateTimeAPI.cpp DateTimeAPI.h
	$(CC) $(CFLAGS) -c DateTimeAPI.cpp

clean:
	rm -f *.o main
