main: main.o
	gcc -o main -L../lib main.o -lfuncs

main.o: main.c
	gcc -g -c -I../include main.c -o main.o

clean:
	rm -f main.o main
