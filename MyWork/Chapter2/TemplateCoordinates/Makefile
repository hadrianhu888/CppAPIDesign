# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -std=c++11 -fPIC

# Linker Flags
LDFLAGS = -shared

# Target executable name
TARGET = main
LIB_TARGET = libcoordinates.a
DLL_TARGET = libcoordinates.dll
DEF_TARGET = libcoordinates.def
MAP_TARGET = main.map

# Source and object files
SRCS = main.cpp coordinates.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET) $(LIB_TARGET) $(DLL_TARGET) $(DEF_TARGET) $(MAP_TARGET)

# Generating DEF file (mostly used on Windows, dummy here)
$(DEF_TARGET):
	echo "EXPORTS" > $(DEF_TARGET)

# Generating LIB file (static library)
$(LIB_TARGET): coordinates.o
	ar rcs $(LIB_TARGET) coordinates.o

# Generating DLL file (dynamic library)
$(DLL_TARGET): coordinates.o
	$(CXX) $(LDFLAGS) -o $(DLL_TARGET) coordinates.o

# Generating MAP file
$(MAP_TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -Wl,-Map=$(MAP_TARGET) -o $(TARGET) $(OBJS)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET) $(LIB_TARGET) $(DLL_TARGET) $(DEF_TARGET) $(MAP_TARGET)
