CC=g++
CFLAGS=-std=c++23 -Wall -Isource
LDFLAGS=-L. -lMyObject

all: test_MyObject.exe

test_MyObject.exe: test_MyObject.o libMyObject.a
	$(CC) $(CFLAGS) -o $@ test_MyObject.o $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.exe
