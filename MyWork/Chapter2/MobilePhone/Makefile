# Specify compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -fPIC

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Sources, Objects, and Directories
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/MobilePhone.cpp
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

EXE = $(BINDIR)/MobilePhoneApp
DLL = $(BINDIR)/libMobilePhone.dll
LIB = $(BINDIR)/libMobilePhone.a
DEF = $(BINDIR)/libMobilePhone.def
MAP = $(EXE).map

# Main targets
all: $(EXE) $(DLL) $(LIB)

# Ensure the output directories exist
$(OBJECTS): | $(OBJDIR)
$(EXE) $(DLL) $(LIB): | $(BINDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

# Pattern rule for object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executable
$(EXE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -Wl,-Map=$(MAP)

# DLL
$(DLL): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ -Wl,--output-def=$(DEF)

# Static Library
$(LIB): $(OBJECTS)
	ar rcs $@ $^

# Clean up
clean:
	rm -f $(OBJECTS) $(EXE) $(DLL) $(LIB) $(DEF) $(MAP)
	rmdir $(OBJDIR) $(BINDIR)

# Note:
# .o files are generated using the built-in implicit rules in make
