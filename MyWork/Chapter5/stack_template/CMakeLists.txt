# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(STACK)

# Set the source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Create the executable
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Set the language for the executable
set_target_properties(MyExecutable PROPERTIES LINKER_LANGUAGE CXX)

# Create the map file
set_target_properties(MyExecutable PROPERTIES LINK_FLAGS "-Wl,-Map=MyExecutable.map")

# Create the DLL
add_library(MyLibrary SHARED ${SOURCES} ${HEADERS})

# Set the language for the DLL
set_target_properties(MyLibrary PROPERTIES LINKER_LANGUAGE CXX)

# Create the DEF file
set_target_properties(MyLibrary PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

# Create the LIB file
add_library(MyLibraryStatic STATIC ${SOURCES} ${HEADERS})

# Set the language for the static library
set_target_properties(MyLibraryStatic PROPERTIES LINKER_LANGUAGE CXX)

# Set the output directories
set_target_properties(MyExecutable MyLibrary MyLibraryStatic
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Clean up build products after successful build
add_custom_command(TARGET MyExecutable MyLibrary MyLibraryStatic POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/lib"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/bin"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/MyExecutable.map"
)

add_custom_target(clean_build_products
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/lib"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/bin"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/MyExecutable.map"
)

add_dependencies(clean_build_products MyExecutable MyLibrary MyLibraryStatic)
# Ensure the necessary directories exist
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
