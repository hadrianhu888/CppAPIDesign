cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Observer)

# Add source files
file(GLOB SOURCES "src/*.c" "src/*.cpp")
file(GLOB HEADERS "src/*.h" "src/*.hpp")

# Build executable
add_executable(MyProgram ${SOURCES})

# Build DLL
# add_library(Observer SHARED ${SOURCES})

# Generate DEF file
set_target_properties(Observer PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    OUTPUT_NAME "my_library"
)

# Generate LIB file
set_target_properties(Observer PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Generate MAP file
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=output.map")

# Cleanup build artifacts
add_custom_target(clean-cmake-files
    COMMAND ${CMAKE_COMMAND} -P clean-all.cmake
)

# Create clean-all.cmake
file(WRITE clean-all.cmake "
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/CMakeCache.txt)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/CMakeFiles)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/MyProgram)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/Observer)
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/output.map)
")
