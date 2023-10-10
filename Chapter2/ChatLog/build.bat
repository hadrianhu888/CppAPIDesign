@echo off

REM Set the log file path
set "LOG_FILE=log_%date:~-4%-%date:~3,2%-%date:~0,2%_%time:~0,2%%time:~3,2%.txt"

REM Run CMake
echo Running CMake...
cmake . 
cmake --build . 

REM Add log file to Git ignore list
echo /log_* >> .gitignore

echo Done.
