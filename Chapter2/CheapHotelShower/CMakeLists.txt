cmake_minimum_required(VERSION 3.10)

# set the project name
project(CheapHotelShower)

# add the library
add_library(CheapHotelShower SHARED CheapHotelShower.cpp)

# generate export header
include(GenerateExportHeader)
generate_export_header(CheapHotelShower)

# Specific settings for Windows and MSVC Compiler to generate DEF and LIB
if(WIN32 AND MSVC)
    # Generates a .def file with all symbols exported
    set_target_properties(CheapHotelShower PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

    # Generates a .lib (import library) along with the DLL
    install(TARGETS CheapHotelShower
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}
        LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}
        ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# add the executable
add_executable(main main.cpp)

# link the library
target_link_libraries(main PRIVATE CheapHotelShower)
