# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(MyProject)

# Set C++ standard and add compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
    add_compile_options(/W4 /MP)
else()
    add_compile_options(-Wall -Wextra -pedantic -fPIC)
endif()

# Gather all .cpp files
file(GLOB SRCS "*.cpp")
file(GLOB SRCS "*.cpp")
list(REMOVE_ITEM SRCS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Gather all .h files and generate .def files
file(GLOB HDRS "*.h")

# Remove main.cpp from the SRCS list to avoid creating a shared library for it
list(REMOVE_ITEM SRCS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

foreach(header ${HDRS})
    get_filename_component(base_name ${header} NAME_WE)
    set(def_file ${CMAKE_CURRENT_BINARY_DIR}/${base_name}.def)
    file(WRITE ${def_file} "EXPORTS\n")
    file(STRINGS ${header} virtual_functions REGEX "virtual .*[^;]$")

    foreach(func ${virtual_functions})
        string(REGEX REPLACE ".* ([^ (]+).*$" "    \\1" func_name ${func})
        file(APPEND ${def_file} "${func_name}\n")
    endforeach()

    list(APPEND DEFS ${def_file})
endforeach()

# Create shared libraries (DLLs) for each .cpp file, excluding main.cpp
set(EXCLUDE_FILES "main.cpp") # List files you want to exclude

foreach(src ${SRCS})
    get_filename_component(base_name ${src} NAME_WE)

    if(NOT "${src}" IN_LIST EXCLUDE_FILES)
        set(target_name ${base_name})
        add_library(${target_name} SHARED ${src} ${DEFS})
        set_target_properties(${target_name} PROPERTIES LINK_FLAGS "/MAP:${base_name}.map")
        list(APPEND MAPS ${base_name}.map)
    endif()
endforeach()

# Create an executable
add_executable(main main.cpp)

# Ensure output directories are set properly
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binaries)

foreach(src ${SRCS})
    get_filename_component(base_name ${src} NAME_WE)
    set_target_properties(${base_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binaries)
    set_target_properties(${base_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binaries)
endforeach()

# Custom target for clean
add_custom_target(clean-cmake-files
    COMMAND ${CMAKE_COMMAND} -P clean-all.cmake
)

# Create a cleanup script for the custom target
file(WRITE clean-all.cmake "
    file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/binaries)
    file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt)
    file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles)
    file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/Makefile)
    file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake)
")

# clean the build directory of vcxproj files
file(GLOB_RECURSE vcxproj_files "${CMAKE_CURRENT_BINARY_DIR}/*.vcxproj")
foreach(vcxproj_file ${vcxproj_files})
    file(REMOVE ${vcxproj_file})
endforeach()
