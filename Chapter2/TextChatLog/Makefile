CC = g++
CFLAGS = -Wall -Werror

# Set the source files
SOURCES := $(wildcard src/*.cpp)

# Set the object files
OBJECTS := $(SOURCES:.cpp=.o)

# Set the output directories for generated artifacts
OUTPUT_DIR := bin
LIB_DIR := lib

# Generate the DLL
$(OUTPUT_DIR)/TextChatLog.dll: $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

# Generate the DEF file for exporting symbols on Windows
ifeq ($(OS),Windows_NT)
	DEF_FILE := $(LIB_DIR)/TextChatLog.dll
	LDFLAGS += -Wl,--output-def,$(DEF_FILE)
endif

# Generate the LIB file from the DLL
$(LIB_DIR)/TextChatLog.lib: $(OUTPUT_DIR)/TextChatLog.def $(OUTPUT_DIR)/TextChatLog.dll
	dlltool -D $(OUTPUT_DIR)/TextChatLog.dll -d $(DEF_FILE) -l $@

# Generate the MAP file for debugging information
$(LIB_DIR)/TextChatLog.map: $(OUTPUT_DIR)/TextChatLog.dll
	objdump -x $(OUTPUT_DIR)/TextChatLog.dll | grep '^\[\.\]' > $@

# Rule to compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(OUTPUT_DIR)/TextChatLog.dll $(LIB_DIR)/TextChatLog.lib $(LIB_DIR)/TextChatLog.map
