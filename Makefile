gcc=g++
args=-std=c++17 -Wall -Wextra -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -g
part=$(gcc) $(args) -c
full=$(gcc) $(args)

all: main

main: tmp/main tmp/window.o tmp/image.o tmp/filesystem.o tmp/input.o
	$(full) tmp/*.o tmp/main -o main

tmp/main: main.cpp image.hpp
	$(part) main.cpp -o tmp/main

tmp/window.o: window.cpp
	$(part) window.cpp -o tmp/window.o

tmp/image.o: image.cpp filesystem.hpp tmp/filesystem.o
	$(part) image.cpp -o tmp/image.o

tmp/filesystem.o: filesystem.cpp
	$(part) filesystem.cpp -o tmp/filesystem.o

tmp/input.o: input.cpp
	$(part) input.cpp -o tmp/input.o

clean:
	if [[ -n tmp/*.o ]]; then rm tmp/*.o; fi
	if [ -f tmp/main ]; then rm tmp/main; fi

install:
	cp main /bin/imageView
	chmod 755 /bin/imageView
	chown root:root /bin/imageView