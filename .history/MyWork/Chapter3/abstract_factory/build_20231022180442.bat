@echo on 

mkdir vs
cmake .
cmake --build . 

set "cd=%cd%\"

make .
xcopy /Y *.vcxproj vs\
xcopy /Y *.filters vs\
xcopy /Y *.cmake vs\
xcopy /Y *.sln vs\
xcopy /Y *.vcxproj.user vs\
xcopy /Y *.vcxproj.filter vs\
xcopy /Y *.filters vs\
xcopy /Y CMakeCache.txt vs\
xcopy /Y *.map vs\

cd %cd%

g++ -o MyProgram -Wl,-T,linker_script.ld /src 






