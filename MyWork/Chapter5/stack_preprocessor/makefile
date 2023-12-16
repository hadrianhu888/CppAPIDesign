# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Create build and bin directories if they don't exist
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Output files
EXE := $(BIN_DIR)/stack.exe
DLL := $(BIN_DIR)/stack.dll
DEF := $(BIN_DIR)/stack.def
LIB := $(BIN_DIR)/stack.lib
MAP := $(BIN_DIR)/stack.map

# Default target
all: $(EXE) $(DLL) $(DEF) $(LIB) $(MAP)

# Build the executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Build the dynamic link library
$(DLL): $(OBJS)
	$(CC) $(CFLAGS) -shared $^ -o $@

# Generate the DEF file
$(DEF): $(DLL)
	$(CC) $(CFLAGS) -Wl,--output-def,$@ -shared $^

# Generate the LIB file
$(LIB): $(DEF)
	dlltool -d $^ -l $@

# Generate the MAP file
$(MAP): $(EXE)
	$(CC) $(CFLAGS) -Wl,-Map=$@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)/*

# Clean all generated files
distclean: clean
	rm -rf $(BIN_DIR)/*

.PHONY: all clean distclean
