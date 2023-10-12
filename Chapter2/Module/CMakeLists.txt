cmake_minimum_required(VERSION 3.10)

project(ModuleAProject)

# Add the source files
set(MODULE_A_SOURCES
    ModuleA.cpp
)

# Create the shared library
add_library(ModuleALib SHARED ${MODULE_A_SOURCES})

# Generate a .def file for the shared library
set_target_properties(ModuleALib PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    OUTPUT_NAME "ModuleA"
)

# Generate a map file
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_options(ModuleALib PRIVATE -Wl,-Map,ModuleA.map)
elseif(MSVC)
    target_link_options(ModuleALib PRIVATE /MAP:ModuleA.map)
endif()

# Create the executable
add_executable(ModuleAExe main.cpp)

# Link the executable with the shared library
target_link_libraries(ModuleAExe ModuleALib)

# Ensure the shared library and executable are in the same directory (for running)
set_target_properties(ModuleAExe ModuleALib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
