# Compiler and Linker
CC = g++
LD = g++

# Compiler flags
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

# Directories
SRCDIR = src
BUILDDIR = build
TARGETDIR = bin

# Files
SOURCES = $(SRCDIR)/ModuleA.cpp
OBJECTS = $(BUILDDIR)/ModuleA.o
TARGETLIB = $(TARGETDIR)/libModuleA.dll
TARGETEXE = $(TARGETDIR)/ModuleAExe
TARGETMAP = $(TARGETDIR)/ModuleA.map
TARGETDEF = $(TARGETDIR)/ModuleA.def

# Make all
all: directories $(TARGETLIB) $(TARGETEXE)

# Create necessary directories
directories:
	mkdir -p $(BUILDDIR)
	mkdir -p $(TARGETDIR)

# Compile the library
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGETLIB): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@ -Wl,--output-def,$(TARGETDEF),-Map,$(TARGETMAP)

# Compile and link the executable
$(TARGETEXE): $(SRCDIR)/main.cpp $(TARGETLIB)
	$(CC) $(CFLAGS) $< -L$(TARGETDIR) -lModuleA -o $@

# Clean objects and targets
clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)
