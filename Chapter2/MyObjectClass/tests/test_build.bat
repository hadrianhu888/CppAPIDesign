@echo off
setlocal

REM Check if Makefile exists and use it to build
if exist Makefile (
    echo Building tests using Makefile...
    make
    if errorlevel 1 exit /b %errorlevel%
    echo Tests built using Makefile!
    exit /b 0
)

REM Check if CMakeLists.txt exists and use it to build
if exist CMakeLists.txt (
    echo Building tests using CMake...
    
    REM Create build directory if it doesn't exist
    if not exist build mkdir build
    cd build

    REM Configure and build the tests
    cmake ..
    if errorlevel 1 exit /b %errorlevel%
    
    cmake --build .
    if errorlevel 1 exit /b %errorlevel%
    
    echo Tests built using CMake!
    exit /b 0
)

echo Neither Makefile nor CMakeLists.txt found for tests!
exit /b 1
