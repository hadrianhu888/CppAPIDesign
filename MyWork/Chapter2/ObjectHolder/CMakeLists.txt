# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(ObjectHolderProject)

# Include the src directory for clarity in subsequent commands
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Specify the source files
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ObjectHolder.cpp

    # Add other source files here as needed
)

# Create a shared library using the source files
add_library(ObjectHolder SHARED ${SOURCE_FILES})

# Set properties for the shared library
set_target_properties(ObjectHolder PROPERTIES OUTPUT_NAME "ObjectHolder")
set_target_properties(ObjectHolder PROPERTIES PREFIX "")
set_target_properties(ObjectHolder PROPERTIES SUFFIX ".dll")
set_target_properties(ObjectHolder PROPERTIES
    LINK_FLAGS "/DEF:\"${CMAKE_CURRENT_SOURCE_DIR}/src/ObjectHolder.def\" /MAP:\"${CMAKE_CURRENT_SOURCE_DIR}/src/ObjectHolder.map\""
)

# If you have additional setup, add it below
