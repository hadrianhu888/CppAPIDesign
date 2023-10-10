# Makefile for the 'src' directory

# Compiler and linker settings
CXX = g++
CXXFLAGS = -Wall -fPIC

# Directories
SRCDIR = src
OBJDIR = obj
LIBDIR = lib

# Files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/ChatUser.cpp $(SRCDIR)/TextChatLog.cpp
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

TARGET_DLL = $(LIBDIR)/chatlib.dll
TARGET_DEF = $(LIBDIR)/chatlib.def
TARGET_LIB = $(LIBDIR)/chatlib.lib
TARGET_MAP = $(LIBDIR)/chatlib.map

all: directories $(TARGET_DLL) $(TARGET_LIB)

directories:
	@mkdir -p $(OBJDIR) $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET_DLL): $(OBJECTS)
	$(CXX) -shared -o $@ $^ -Wl,--out-implib,$(TARGET_LIB) -Wl,--output-def,$(TARGET_DEF) -Wl,-Map,$(TARGET_MAP)

$(TARGET_LIB): $(TARGET_DLL)

clean:
	rm -rf $(OBJDIR) $(LIBDIR)

