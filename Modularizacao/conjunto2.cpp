#include <cstdio>
#include <set>
 
#include "conjunto2.hpp"

void inicializa(conjunto &c)
{
	c.clear();
}

void insere(conjunto &c, int e)
{
	c.insert(e);
}

void retira(conjunto &c, int e)
{
	c.erase(e);
}

int pertence(conjunto c, int e)
{
	return c.count(e);
}

void uniao(conjunto a, conjunto b, conjunto &c)
{
	set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
}

void interseccao(conjunto a, conjunto b, conjunto &c)
{
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
}

void diferenca(conjunto a, conjunto b, conjunto &c)
{
	set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
}

void imprime(conjunto c)
{
	conjunto::iterator it;
	for (it = c.begin(); it != c.end(); it++)
		printf("%d", *it);
	printf("\n");
}
