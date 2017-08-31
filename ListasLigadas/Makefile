all: main.o lista_ligada.o
	gcc main.o lista_ligada.o -o main

main.o: main.c lista_ligada.h
	gcc -c main.c -o main.o

lista_ligada.o: lista_ligada.c lista_ligada.h
	gcc -c lista_ligada.c -o lista_ligada.o

clean:
	rm -f *.o main

run:
	./main
