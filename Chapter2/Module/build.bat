@echo on 

mkdir vs
cmake .
cmake --build . 

make .
xcopy /Y *.vcxproj vs\
xcopy /Y *.filters vs\
xcopy /Y *.cmake vs\
xcopy /Y *.sln vs\
xcopy /Y *.vcxproj.user vs\
xcopy /Y *.vcxproj.filter vs\
xcopy /Y *.filters vs\
xcopy /Y CMakeCache.txt vs\

del /Q /S *.vcxproj.user
del /Q /S *.vcxproj.filter
del /Q /S *.filters
del /Q /S *.sln
del /Q /S *.cmake
del /Q /S *.vcxproj
del /Q /S *.vcxproj.user
del /Q /S CMakeCache.txt