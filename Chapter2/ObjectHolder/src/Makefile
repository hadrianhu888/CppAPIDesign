# remove the build/ prefix when copying to the build directory.

# Define compiler and linker flags
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -fPIC
LDFLAGS = -shared

# Define source and object files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Define header and DEF files
HDRS = $(wildcard *.h)
DEFS = $(HDRS:.h=.def)

# Define DLL, MAP, LIB, and EXE files (without build/ prefix)
DLLS = $(SRCS:.cpp=.dll)
MAPS = $(SRCS:.cpp=.map)
LIBS = $(SRCS:.cpp=.lib)
EXE = main.exe

# Define targets
all: compile move_to_build

compile: $(OBJS) $(DLLS) $(LIBS) $(EXE)

$(EXE): main.o Object.o ObjectHolder.o ObjectTaker.o
	g++ $^ -o $@

# General rule for other dlls
%.dll: %.o
	g++ $(LDFLAGS) -Wl,-Map,$*.map -o $@ $^

# Specific rule for main.dll to include all necessary object files.
main.dll: main.o Object.o ObjectHolder.o ObjectTaker.o
	g++ $(LDFLAGS) -Wl,-Map,main.map -o $@ $^

# Specific rule for ObjectHolder.dll
ObjectHolder.dll: ObjectHolder.o Object.o
	g++ $(LDFLAGS) -Wl,-Map,ObjectHolder.map -o $@ $^

ObjectTaker.dll: ObjectTaker.o ObjectHolder.o Object.o
	g++ $(LDFLAGS) -Wl,-Map,ObjectTaker.map -o $@ $^

Object.dll: Object.o
	g++ $(LDFLAGS) -Wl,-Map,Object.map -o $@ $^

%.lib: %.dll %.def
	dlltool -d $*.def -l $@

Object.a: Object.dll
	dlltool -d Object.def -l $@

ObjectHolder.a: ObjectHolder.dll
	dlltool -d ObjectHolder.def -l $@

ObjectTaker.a: ObjectTaker.dll
	dlltool -d ObjectTaker.def -l $@

%.map: %.dll
	g++ -Wl,-Map,$@ -o $*.dll $*.o

%.o: %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

%.def: %.h
	echo EXPORTS > $@
	grep -oP "(?<=virtual ).*? \w+(?=\()" $< | awk '{print $NF}' | sed 's/^/    /' >> $@

move_to_build:
	-mkdir -p build
	mv $(OBJS) build/
	mv $(DLLS) build/
	mv $(MAPS) build/
	mv $(LIBS) build/
	mv $(DEFS) build/
	mv $(EXE) build/

clean: 
	-if exist build\* del /q build\*
	-if exist build rmdir /s /q build
	-del /q *.o *.dll *.map *.lib *.def *.exe

# Ensure these aren't treated as file names
.PHONY: all compile clean move_to_build

