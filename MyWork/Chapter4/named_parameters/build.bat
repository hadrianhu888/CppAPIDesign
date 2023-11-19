
@echo off

REM Run make
make

REM Run cmake
cmake .
cmake --build .

REM Pause at the end to see the output
pause
