# alvo: pre-requisitos
#	receita

CC=g++

all: main 

main: main.o conjunto2.o
	$(CC) main.o conjunto2.o -o main

main.o: main.cpp conjunto2.hpp
	$(CC) -c main.cpp -o main.o

conjunto.o: conjunto2.cpp conjunto2.hpp
	$(CC) -c conjunto2.cpp -o conjunto2.o

clean:
	rm -f *.o main