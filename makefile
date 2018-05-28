main: bin/main

bin/main: build/main.o build/menu.o bin
	gcc -Wall -Werror build/main.o build/menu.o -o bin/main

build/main.o: source/main.c build
	gcc -Wall -Werror -c source/main.c -o build/main.o

build/menu.o: source/menu.c build
	gcc -Wall -Werror -c source/menu.c -o build/menu.o

build:
	mkdir build

bin: 
	mkdir bin

.PHONY: clear
	
clear:
	rm -rf bin build

