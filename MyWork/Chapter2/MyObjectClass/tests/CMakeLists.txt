cmake_minimum_required(VERSION 3.10)

project(TestMyObject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the source directory and the directory where the library is
include_directories(${CMAKE_SOURCE_DIR}/source)

# Link the test to the MyObject library
add_executable(test_MyObject test_MyObject.cpp)
target_link_libraries(test_MyObject PRIVATE MyObject)
