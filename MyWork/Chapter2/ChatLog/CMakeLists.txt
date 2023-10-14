cmake_minimum_required(VERSION 3.10)

# Project Name
project(ChatLibrary)

# Ensure -fPIC flag in Unix
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# List of source files (adjusted for the CMakeLists.txt being outside of src)
set(SOURCE_FILES
    src/main.cpp
    src/ChatUser.cpp
    src/TextChatLog.cpp
)

# Add library to be built from the source files
add_library(chatlib SHARED ${SOURCE_FILES})

# Set output directories for runtime, library, and archive targets
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output")
set_target_properties(chatlib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/bin
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/lib
)

# Create a .def file on Windows
if(WIN32)
    set_target_properties(chatlib PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
        OUTPUT_NAME chatlib
        ARCHIVE_OUTPUT_NAME chatlib
    )
endif()

# Output a .map file
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Map,${OUTPUT_DIRECTORY}/lib/chatlib.map")

# Custom post-build command to move files (optional, based on your specific requirements)
add_custom_command(TARGET chatlib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Moving build products to ${OUTPUT_DIRECTORY}"
    COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIRECTORY}
)

# Specify where to install the library
install(TARGETS chatlib
    RUNTIME DESTINATION ${OUTPUT_DIRECTORY}/bin
    LIBRARY DESTINATION ${OUTPUT_DIRECTORY}/lib
    ARCHIVE DESTINATION ${OUTPUT_DIRECTORY}/lib
)
