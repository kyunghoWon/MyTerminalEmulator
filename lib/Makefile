FUNC = func1.o func2.o
OUTPUT = libfuncs.a

$(OUTPUT): $(FUNC)
	ar rv $(OUTPUT) $(FUNC)

func1.o: func1.c
	gcc -c -g -I../include func1.c -o func1.o

func2.o: func2.c
	gcc -c -g -I../include func2.c -o func2.o

clean:
	rm -f *.o $(OUTPUT)
