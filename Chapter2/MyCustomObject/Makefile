# Compiler and linker settings
CC = g++
CFLAGS = -Wall -c -fPIC
LDFLAGS = -shared -Wl,--out-implib,libMyCustomObject.a

# Source and object files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Output files
TARGET = MyCustomObject.dll
MAPFILE = MyCustomObject.map
DEFFILE = MyCustomObject.def
LIBFILE = libMyCustomObject.a

# Targets
all: bin/release/$(TARGET) bin/release/$(MAPFILE) bin/release/$(DEFFILE) bin/release/$(LIBFILE)

bin/release:
	mkdir -p $@

bin/release/$(TARGET): $(OBJS) | bin/release
	$(CC) $(LDFLAGS) -o $@ $^

bin/release/$(MAPFILE): bin/release/$(TARGET)
	nm -gC --defined-only $< > $@

bin/release/$(DEFFILE): bin/release/$(TARGET)
	dlltool -z $@ -d $< -l libMyCustomObject.a

bin/release/$(LIBFILE): $(OBJS) | bin/release
	ar rcs $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) bin/release/$(TARGET) bin/release/$(MAPFILE) bin/release/$(DEFFILE) bin/release/$(LIBFILE)
