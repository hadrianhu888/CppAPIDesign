@echo off
setlocal

REM Check if Makefile exists and use it to build
if exist Makefile (
    echo Building using Makefile...
    make
    if errorlevel 1 exit /b %errorlevel%
    echo Build completed using Makefile!

    REM Display Makefile build artifacts
    echo Displaying Makefile build artifacts:
    dir /b *.dll *.exe *.a *.lib
    echo.
    goto cmake 
)

REM go to CMake sequence next 


:cmake 
REM Check if CMakeLists.txt exists and use it to build
if exist CMakeLists.txt (
    echo Building using CMake...

    REM Create build directory if it doesn't exist
    if not exist build mkdir build
    cd build


    REM Configure and build the project
    cmake ..
    if errorlevel 1 exit /b %errorlevel%

    cmake --build .
    if errorlevel 1 exit /b %errorlevel%
    
    echo Build completed using CMake!

    REM Display CMake build artifacts
    echo Displaying CMake build artifacts:
    dir /b *.dll *.exe *.a *.lib
    echo.
    goto end
)

echo Neither Makefile nor CMakeLists.txt found!
exit /b 1

:end
