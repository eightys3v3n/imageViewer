gcc=g++
args=-std=c++17 -Wall -Wextra -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -g -I/home/anonymous/source
part=$(gcc) $(args) -c
full=$(gcc) $(args)

all: tests main

tests: tmp/tests tmp/filesystem.o tmp/sorting.o
	$(full) $^ -o $@

tmp/tests: tests.cpp
	$(part) tests.cpp -o tmp/tests


main: tmp/main tmp/window.o tmp/image.o tmp/filesystem.o tmp/input.o tmp/sorting.o tmp/textbox.o tmp/graphics.o
	$(full) -o $@ $^

tmp/main: main.cpp image.hpp
	$(part) main.cpp -o tmp/main

tmp/%.o: %.cpp %.hpp
	$(part) -o $@ $(filter %.cpp,$^)

clean:
	rm -rf tmp/*.o tmp/main tmp/tests

install:
	cp main /bin/imageView
	chmod 755 /bin/imageView
	chown root:root /bin/imageView

uninstall:
	rm /bin/imageView