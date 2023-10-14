cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HotelShowerApp)

# Add executable
add_executable(hotel_app main.cpp hotelShower.cpp)

# Specify include directories
target_include_directories(hotel_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Compiler flags
target_compile_options(hotel_app PRIVATE -Wall -g)
