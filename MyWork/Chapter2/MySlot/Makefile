# Set compiler
CC = g++

# Flags
CFLAGS = -Wall -fPIC

# Source code directory
SRC_DIR = ./src

# Output directory
OUTPUT_DIR = ./bin

# Targets
all: $(OUTPUT_DIR)/main.exe $(OUTPUT_DIR)/main.def $(OUTPUT_DIR)/main.dll $(OUTPUT_DIR)/main.lib $(OUTPUT_DIR)/main.map

$(OUTPUT_DIR)/main.exe: $(SRC_DIR)/main.cpp $(SRC_DIR)/MySlot.cpp
	$(CC) $(CFLAGS) $^ -o $@ -Wl,-Map=$(OUTPUT_DIR)/main.map

$(OUTPUT_DIR)/main.def: $(OUTPUT_DIR)/main.dll
	dumpbin /EXPORTS $< > $@

$(OUTPUT_DIR)/main.dll: $(SRC_DIR)/main.cpp $(SRC_DIR)/MySlot.cpp
	$(CC) $(CFLAGS) -shared $^ -o $@

$(OUTPUT_DIR)/main.lib: $(OUTPUT_DIR)/main.dll
	lib /def:$(OUTPUT_DIR)/main.def /out:$@

$(OUTPUT_DIR)/main.map: $(OUTPUT_DIR)/main.exe

clean:
	rm -f $(OUTPUT_DIR)/*.exe $(OUTPUT_DIR)/*.def $(OUTPUT_DIR)/*.dll $(OUTPUT_DIR)/*.lib $(OUTPUT_DIR)/*.map
