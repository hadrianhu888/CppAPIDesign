# Define variables
SRC_DIR := ./src
OBJ_DIR := ./build/obj
BIN_DIR := ./build/bin
RELEASE_DIR := ./release

# Define source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Define compiler and linker flags
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11
LDFLAGS := -shared -Wl,--out-implib,$(BIN_DIR)/libObjectHolder.a

# Define targets
all: $(BIN_DIR)/ObjectHolder.dll $(BIN_DIR)/libObjectHolder.a

$(BIN_DIR)/ObjectHolder.dll: $(OBJS)
	mkdir -p $(BIN_DIR)  # Ensure the directory exists before linking
	$(CXX) $(LDFLAGS) -o $@ $^

$(BIN_DIR)/libObjectHolder.a: $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR) # Ensure the directory exists before compilation
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJS) $(BIN_DIR)/ObjectHolder.dll $(BIN_DIR)/libObjectHolder.a

release: all
	mkdir -p $(RELEASE_DIR)
	cp $(BIN_DIR)/ObjectHolder.dll $(RELEASE_DIR)/ObjectHolder.dll
	cp $(BIN_DIR)/libObjectHolder.a $(RELEASE_DIR)/libObjectHolder.a

# Indicate that the targets do not represent files
.PHONY: all clean release
