FUNC = gtk_internal.o gtk_external.o
OUTPUT = libfuncs.a

$(OUTPUT): $(FUNC)
	ar rv $(OUTPUT) $(FUNC)

gtk_internal.o: gtk_internal.c
	gcc `pkg-config --cflags gtk+-3.0` -c -g -I../include gtk_internal.c -o gtk_internal.o `pkg-config --libs gtk+-3.0`

gtk_external.o: gtk_external.c
	gcc `pkg-config --cflags gtk+-3.0` -c -g -I../include gtk_external.c -o gtk_external.o `pkg-config --libs gtk+-3.0`

clean:
	rm -f *.o *.c~ $(OUTPUT)
