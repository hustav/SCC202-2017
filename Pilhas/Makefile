all: posfixa.o pilha_estatica.o
	gcc posfixa.o pilha_estatica.o -o posfixa

posfixa.o: posfixa.c pilha_estatica.h
	gcc -c posfixa.c -o posfixa.o

pilha_estatica.o: pilha_estatica.c pilha_estatica.h
	gcc -c pilha_estatica.c -o pilha_estatica.o

clean:
	rm -f *.o posfixa

run:
	./posfixa
