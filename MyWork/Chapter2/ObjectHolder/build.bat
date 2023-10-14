@echo off

REM Run make command
make

REM Generate output products with cmake
cmake -B build

echo "Build complete."
