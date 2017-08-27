#include "conjunto2.hpp" 

int main()
{
	conjunto a, b, c;

	inicializa(a);
	inicializa(b);
	inicializa(c);
	insere(a, 1);
	insere(a, 2);
	insere(b, 1);
	insere(b, 3);
	uniao(a, b, c);
	imprime(c);
}