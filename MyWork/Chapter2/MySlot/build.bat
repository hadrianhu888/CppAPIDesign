@echo off

setlocal

make

mkdir build
cmake .
cmake --build . 
make clean 

mkdir vs

xcopy CMakeCache.txt vs /y
xcopy *.vcxproj vs /y
xcopy *.vcxproj.filters vs /y
xcopy *.sln vs /y
xcopy *.vcxproj.user vs /y
xcopy *.vcxproj.vspscc vs /y
xcopy *.vcxproj.filters vs /y
xcopy *.vcxproj.user vs /y
xcopy cmake_install.cmake vs /y

del cmake_install.cmake
del CMakeCache.txt
del *.vcxproj.filters
del *.vcxproj.user
del *.vcxproj.vspscc

del *.vcxproj
del *.sln

endlocal
