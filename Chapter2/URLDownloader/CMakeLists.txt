# FILEPATH: e:\GitHubRepos\CppAPIDesign\Chapter2\URLDownloader\CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(urldownloader)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES main.cpp URLDownloader.cpp)

add_library(urldownloader SHARED ${SOURCES})

target_compile_definitions(urldownloader PRIVATE BUILD_DLL)

if(WIN32)
    target_compile_definitions(urldownloader PRIVATE _WIN32)
    target_link_libraries(urldownloader PRIVATE ws2_32)
endif()
