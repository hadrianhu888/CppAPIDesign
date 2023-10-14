# Compiler to use
CC = g++

# Linker to use
LD = g++

# Compiler flags
CFLAGS = -Wall -O3 -fPIC

# Linker flags for generating the .exe
LDFLAGS_EXE = -Wl,-Map=output.map

# Linker flags for generating the .dll
LDFLAGS_DLL = -shared

# Linker flags for generating .lib and .def
LDFLAGS_LIB = -Wl,--out-implib=output.lib -Wl,--output-def,output.def

# Executable name
TARGET_EXE = fireworks_main.exe
TARGET_DLL = fireworks_main.dll

# List of source files
SRCS = fireworks_main.cpp fireparticle.cpp fireworks.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Main target for .exe
$(TARGET_EXE): $(OBJS)
	$(LD) $(LDFLAGS_EXE) -o $(TARGET_EXE) $(OBJS)

# Main target for .dll
$(TARGET_DLL): $(OBJS)
	$(LD) $(LDFLAGS_DLL) $(LDFLAGS_LIB) -o $(TARGET_DLL) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET_EXE) $(TARGET_DLL) output.lib output.def output.map
