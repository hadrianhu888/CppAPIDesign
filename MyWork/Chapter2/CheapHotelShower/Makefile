# Compiler to be used
CC = g++

# Compiler flags
CFLAGS = -Wall -c

# Linker flags for creating DLL and DEF
LFLAGS_DLL = -shared -o
LFLAGS_DEF = -Wl,--output-def
LFLAGS_LIB = -Wl,--out-implib

# Target files
DLL = CheapHotelShower.dll
DEF = CheapHotelShower.def
LIB = libCheapHotelShower.a
EXE = main.exe
OBJ = CheapHotelShower.o main.o

all: $(EXE)

# Link to create executable
$(EXE): main.o $(DLL)
	$(CC) main.o -L. -lCheapHotelShower -o $(EXE)

# Create DLL, DEF, and LIB
$(DLL): CheapHotelShower.o
	$(CC) $(LFLAGS_DLL) $(DLL) CheapHotelShower.o $(LFLAGS_DEF) $(DEF) $(LFLAGS_LIB) $(LIB)

# Compile CheapHotelShower.cpp into object file
CheapHotelShower.o: CheapHotelShower.cpp
	$(CC) $(CFLAGS) -DBUILD_DLL -o $@ $<

# Compile main.cpp into object file
main.o: main.cpp
	$(CC) $(CFLAGS) -o $@ $<

# Clean up
clean:
	rm -rf $(EXE) $(DLL) $(DEF) $(LIB) $(OBJ)
