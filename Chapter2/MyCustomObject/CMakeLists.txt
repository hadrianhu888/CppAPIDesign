# FILEPATH: /e:/GitHubRepos/CppAPIDesign/Chapter2/MyCustomObject/src/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(MyCustomObject)

# Set the source files for the library
set(SOURCES
    src/MyCustomObject.cpp
)

# Set the header files for the library
set(HEADERS
    src/MyCustomObject.h
)

# Set the name of the library
set(LIBRARY_NAME MyCustomObject)

# Set the output directory for the library
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/lib)

# Set the output directory for the DLL
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build/bin)

# Add the library target
add_library(${LIBRARY_NAME} SHARED ${SOURCES} ${HEADERS})

# Set the version and soversion for the library
set_target_properties(${LIBRARY_NAME} PROPERTIES VERSION 1.0 SOVERSION 1)

# Generate the DEF file
set(DEF_FILE ${LIBRARY_NAME}.def)
file(WRITE ${DEF_FILE} "LIBRARY ${LIBRARY_NAME}\nEXPORTS\n")

# Generate the MAP file
set(MAP_FILE ${LIBRARY_NAME}.map)
set_target_properties(${LIBRARY_NAME} PROPERTIES LINK_FLAGS "-Wl,-Map=${MAP_FILE}")

# Generate the LIB file
set(LIB_FILE ${LIBRARY_NAME}.lib)
add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD COMMAND lib /DEF:${DEF_FILE} /OUT:${LIB_FILE})

# Set the output name for the DLL
set_target_properties(${LIBRARY_NAME} PROPERTIES OUTPUT_NAME ${LIBRARY_NAME} PREFIX "")

# Generate the DLL file
add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${LIBRARY_NAME}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
