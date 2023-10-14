@echo off
setlocal enabledelayedexpansion
del *.txt /q >nul 2>&1
:: Generate a timestamp for the new log file
for /f "tokens=2 delims==" %%I in ('"wmic os get localdatetime /value"') do set datetime=%%I
set "datestamp=!datetime:~0,4!!datetime:~4,2!!datetime:~6,2!"
set "timestamp=!datetime:~8,2!!datetime:~10,2!!datetime:~12,2!"
set "new_fullstamp=%datestamp%-%timestamp%"
set "new_logfile=build_log_%new_fullstamp%.txt"

:: Delete the previous log file if it exists
if defined prev_logfile del !prev_logfile!

:: Run make and save output to build_log with current date-time stamp
make > "!new_logfile!" 2>&1

:: Open the log file for inspection
start notepad.exe "!new_logfile!"

:: Store the name of the log file to delete it next time
set "prev_logfile=!new_logfile!"

endlocal
