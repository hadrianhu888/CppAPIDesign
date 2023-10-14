cmake_minimum_required(VERSION 3.10)

# Project name
project(MainProject)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add source code
set(SOURCES
    src/main.cpp
    src/MySlot.cpp
)

# Create executable
add_executable(main ${SOURCES})

# Generate MAP file
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${CMAKE_BINARY_DIR}/main.map")

# Create DLL
add_library(maindll SHARED ${SOURCES})

# Create static library (.lib)
add_library(mainlib STATIC ${SOURCES})

# Generate DEF file from DLL
add_custom_command(
    OUTPUT main.def
    COMMAND dumpbin /EXPORTS $<TARGET_FILE:maindll> > main.def
    DEPENDS maindll
)

# Custom target for DEF file
add_custom_target(generateDEF DEPENDS main.def)
