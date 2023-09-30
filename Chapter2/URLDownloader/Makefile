CC=g++
LDFLAGS=-shared -Wl,--output-def,liburldownloader.def,--out-implib,liburldownloader.a,--export-all-symbols
SOURCES=main.cpp URLDownloader.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=urldownloader_no_lib
DLLFILE=urldownloader.dll

# Common Flags
CFLAGS=-c -Wall -DBUILD_DLL

# OS-specific flags
ifeq ($(OS),Windows_NT)
    CFLAGS += -D_WIN32
    LDFLAGS += -lws2_32
endif

all: $(SOURCES) $(DLLFILE)

$(DLLFILE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -Wl,-Map,urldownloader.map

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
