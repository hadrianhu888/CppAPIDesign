CC=g++
CFLAGS=-std=c++23 -Wall -Isource
LDFLAGS=-L.

all: main.exe MyObject.dll

main.exe: source/main.o MyObject.lib
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -lMyObject

MyObject.dll: source/MyObject.o
	$(CC) $(CFLAGS) -shared -o $@ $< -Wl,--out-implib,libMyObject.a -Wl,--output-def,MyObject.def,--add-stdcall-alias

MyObject.lib: MyObject.dll

MyObject.map: MyObject.map

MyObject.def: MyObject.def

source/%.o: source/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.exe *.dll *.lib *.map *.def
