main: main.o lista_estatica_realloc.o
	gcc main.o lista_estatica_realloc.o -o main

main.o: main.c lista_estatica_realloc.h
	gcc -c main.c -o main.o

lista_estatica_realloc.o: lista_estatica_realloc.c lista_estatica_realloc.h
	gcc -c lista_estatica_realloc.c -o lista_estatica_realloc.o

clean:
	rm -f *.o main
