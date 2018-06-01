main: bin/main

bin/main: build/main.o build/menu.o build/add_task.o build/view_list.o build/mark_done.o build/delete_task.o build/delete_list.o bin
	gcc -Wall -Werror build/main.o build/menu.o build/add_task.o build/view_list.o build/mark_done.o build/delete_task.o build/delete_list.o -o bin/main
	
build/add_task.o: source/add_task.c build
	gcc -Wall -Werror -c source/add_task.c -o build/add_task.o

build/view_list.o: source/view_list.c build
	gcc -Wall -Werror -c source/view_list.c -o build/view_list.o
	
build/mark_done.o: source/mark_done.c build
	gcc -Wall -Werror -c source/mark_done.c -o build/mark_done.o

build/delete_task.o: source/delete_task.c build
	gcc -Wall -Werror -c source/delete_task.c -o build/delete_task.o

build/delete_list.o: source/delete_list.c build
	gcc -Wall -Werror -c source/delete_list.c -o build/delete_list.o
	
build/main.o: source/main.c build
	gcc -Wall -Werror -c source/main.c -o build/main.o

build/menu.o: source/menu.c build
	gcc -Wall -Werror -c source/menu.c -o build/menu.o
	
build:
	mkdir build

bin: 
	mkdir bin
