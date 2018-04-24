gcc -c -fpic -Iinclude ./src/*.c -I./include
mkdir bin
gcc -shared -o ./bin/liblinalg.so *.o -lm
rm *.o
