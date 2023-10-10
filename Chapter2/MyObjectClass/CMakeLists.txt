cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the source directory
include_directories(${CMAKE_SOURCE_DIR}/source)

# Create the MyObject library
add_library(MyObject SHARED source/MyObject.cpp)

# Generate .def and .lib files for MyObject.dll
set_target_properties(MyObject PROPERTIES
    OUTPUT_NAME "MyObject"
    PREFIX ""
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)

# Link main to the MyObject library
add_executable(main source/main.cpp)
target_link_libraries(main PRIVATE MyObject)
