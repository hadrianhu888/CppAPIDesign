# FILEPATH: /e:/GitHubRepos/CppAPIDesign/MyWork/Chapter4/named_parameters/CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(FMOD)

# Set the source files
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Create the executable
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Create the map file
set_target_properties(MyExecutable PROPERTIES LINK_FLAGS "-Wl,-Map=MyExecutable.map")

# Create the DLL
add_library(MyLibrary SHARED ${SOURCES} ${HEADERS})

# Create the DEF file
set_target_properties(MyLibrary PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

# Create the LIB file
add_library(MyLibraryStatic STATIC ${SOURCES} ${HEADERS})

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
