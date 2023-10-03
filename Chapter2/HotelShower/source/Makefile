# Compiler to use
CC = g++

# Flags to use
CXXFLAGS = -Wall -g

# Target executable
TARGET = hotel_app

# Object files
OBJS = main.o hotelShower.o

# Rules

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp hotelShower.h
	$(CC) $(CXXFLAGS) -c main.cpp

hotelShower.o: hotelShower.cpp hotelShower.h
	$(CC) $(CXXFLAGS) -c hotelShower.cpp

clean:
	rm -f $(TARGET) $(OBJS)
