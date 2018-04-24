gcc -Wall -fpic -DBUILD_DLL -I./include -c -Iinclude ./src/*.c
gcc -shared -Wl,--dll *.o -o bin/linalg.dll -lm
del *.o
