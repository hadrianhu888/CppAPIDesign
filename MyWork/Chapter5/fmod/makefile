# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c++11

# Project name
PROJECT_NAME = fmod

# Source directory
SRC_DIR = src

# Object directory
OBJ_DIR = obj

# Target executable
TARGET = $(PROJECT_NAME)

# DLL file
DLL = $(PROJECT_NAME).dll

# MAP file
MAP = $(PROJECT_NAME).map

# LIB file
LIB = $(PROJECT_NAME).lib

# DEF file
DEF = $(PROJECT_NAME).def

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Rule to compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to build the DLL file
$(DLL): $(OBJS)
	$(CC) $(CFLAGS) -shared $^ -o $@

# Rule to build the MAP file
$(MAP): $(TARGET)
	$(CC) $(CFLAGS) -Wl,-Map,$@ $^

# Rule to build the LIB file
$(LIB): $(DLL)
	dlltool -d $(DEF) -l $@

# Rule to clean the object files, target executable, DLL, MAP, LIB, and DEF files
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(DLL) $(MAP) $(LIB) $(DEF)
