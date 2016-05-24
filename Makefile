gcc=g++
args=-std=c++17 -Wall -Wextra -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -g
part=$(gcc) $(args) -c
full=$(gcc) $(args)

all: main

main: tmp/main tmp/image.o tmp/filesystem.o tmp/input.o
	$(full) tmp/*.o tmp/main -o main

tmp/main: main.cpp image.hpp
	$(part) main.cpp -o tmp/main

tmp/image.o: image.cpp filesystem.hpp tmp/filesystem.o
	$(part) image.cpp -o tmp/image.o

tmp/filesystem.o: filesystem.cpp
	$(part) filesystem.cpp -o tmp/filesystem.o

tmp/input.o: input.cpp
	$(part) input.cpp -o tmp/input.o

clean:
	if [[ -n tmp/*.o ]]; then rm tmp/*.o; fi
	if [ -f tmp/main ]; then rm tmp/main; fi