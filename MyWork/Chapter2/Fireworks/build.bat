@echo off
setlocal

:: Set Compiler and Linker
set CC=g++
set LD=g++

:: Set Compiler and Linker Flags
set CFLAGS=-Wall -O3 -fPIC
set LDFLAGS_EXE=-Wl,-Map,fireworks.map
set LDFLAGS_DLL=-shared
set LDFLAGS_LIB=-Wl,--out-implib,output.lib -Wl,--output-def,output.def

:: Set Executable and DLL Names
set TARGET_EXE=fireworks_main.exe
set TARGET_DLL=fireworks_main.dll

:: Source and Object Files
set SRCS=fireworks_main.cpp fireparticle.cpp fireworks.cpp
set OBJS=fireworks_main.o fireparticle.o fireworks.o

:: Compile Source Files to Object Files
for %%S in (%SRCS%) do (
    %CC% %CFLAGS% -c %%S -o %%~nS.o
)

:: Link to Create the Executable (.exe)
%LD% %LDFLAGS_EXE% -o %TARGET_EXE% %OBJS%

:: Link to Create the DLL (.dll), LIB (.lib), and DEF (.def)
%LD% %LDFLAGS_DLL% %LDFLAGS_LIB% -o %TARGET_DLL% %OBJS%

:: Clean up Object Files (Optional)
:: del *.o

:: End
endlocal
echo Build Complete!
