@echo off

if exist .\build (
    rmdir .\build /s /q
) else (
    mkdir build
)

start /wait cmake_build.bat
timeout /t 1 /nobreak

if exist .\bin (
    rmdir .\bin /s /q
) else (
    mkdir bin
)

start /wait make_build.bat
exit /b 0
