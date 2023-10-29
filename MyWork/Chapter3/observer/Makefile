CC = gcc
CXX = g++
CFLAGS = -Wall -O2
CXXFLAGS = $(CFLAGS)

# Executable name
EXE = main.exe

# Dynamic Link Library
DLL = Observer.dll

# Library Def file
DEF = Observer.def

# Static Library
LIB = Observer.lib

# Map File
MAP = Observer.map

# Source files
C_HEADERS = $(wildcard src/*.h)
CPP_HEADERS = $(wildcard src/*.hpp)
HEADERS = $(C_HEADERS) $(CPP_HEADERS)

# Object files
OBJ = $(C_SOURCES:.c=.o) $(CPP_SOURCES:.cpp=.o)

all: $(EXE) $(DLL)

# EXE
$(EXE): $(OBJ)
	$(CXX) -o $@ $^ -Wl,-Map=$(MAP)

# DLL
$(DLL): $(OBJ)
	$(CXX) -shared -o $@ $^ -Wl,--out-implib,$(LIB) -Wl,--output-def,$(DEF)

# C Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# CPP Object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE) $(DLL) $(DEF) $(LIB) $(MAP)
