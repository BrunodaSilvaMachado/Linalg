
gcc -Wall -DBUILD_DLL -I./include -c -Iinclude ./src/*.c 
mkdir bin
gcc -shared -Wl,--output-def=bin/liblinalg.def -Wl,--out-implib=bin/liblinalg.a -Wl,--dll *.o -o bin/linalg.dll -lm
del *.o

