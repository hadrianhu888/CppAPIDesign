cmake_minimum_required(VERSION 3.10)

# Set the project name
project(AbstractFactory)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/main.cpp
    src/WindowsFactory.cpp
    src/WindowsButton.cpp
    src/WindowsCheckBox.cpp
    src/LinuxFactory.cpp
    src/LinuxButton.cpp
    src/LinuxCheckBox.cpp

    # ... add other source files here
)

set(HEADERS
    src/WindowsFactory.h
    src/WindowsButton.h
    src/WindowsCheckBox.h
    src/LinuxFactory.h
    src/LinuxButton.h
    src/LinuxCheckBox.h

    # ... add other header files here
)

# Build executable
add_executable(MyProgram ${SOURCES} ${HEADERS})

# Build DLL
add_library(AutoTimer SHARED ${SOURCES} ${HEADERS})

# Generate DEF file
set_target_properties(AutoTimer PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    OUTPUT_NAME "my_library"
)

# Generate LIB file
set_target_properties(AutoTimer PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Generate MAP file
if(UNIX)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=output.map")
endif()

# Cleanup build artifacts
add_custom_target(clean-cmake-files
    COMMAND ${CMAKE_COMMAND} -P clean-all.cmake
)

# Create clean-all.cmake
file(WRITE clean-all.cmake "
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/CMakeCache.txt)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/CMakeFiles)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/MyProgram)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/AutoTimer)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/output.map)
")
