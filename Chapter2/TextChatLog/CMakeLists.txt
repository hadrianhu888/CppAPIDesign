cmake_minimum_required(VERSION 3.0)
project(TextChatLog)

# Set the source files
set(SOURCES
    src/TextChatLog.cpp
    src/main.cpp
)

# Add the library target
add_library(TextChatLog SHARED ${SOURCES})

# Set the output directories for generated artifacts
set_target_properties(TextChatLog PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
    PDB_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Generate the DEF file for exporting symbols on Windows
if(WIN32)
    set_target_properties(TextChatLog PROPERTIES
        PREFIX ""
        OUTPUT_NAME "TextChatLog"
        SUFFIX ".dll"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
endif()
