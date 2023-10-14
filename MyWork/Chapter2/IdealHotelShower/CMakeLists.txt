cmake_minimum_required(VERSION 3.10)

# Project name
project(IdealHotelShower)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Generate a shared library
add_library(IdealHotelShowerLib SHARED IdealHotelShower.cpp)

# Add an executable that uses the shared library
add_executable(IdealHotelShower main.cpp)

# Link the executable to the shared library
target_link_libraries(IdealHotelShower IdealHotelShowerLib)
