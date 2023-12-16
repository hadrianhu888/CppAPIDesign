
# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Output files
EXE := $(BIN_DIR)/app.exe
DLL := $(BIN_DIR)/app.dll
DEF := $(BIN_DIR)/app.def
LIB := $(BIN_DIR)/app.lib
MAP := $(BIN_DIR)/app.map

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
