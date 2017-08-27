#include <stdio.h>
 
#include "conjunto.h"

void inicializa(conjunto c)
{
	for (int i = 0; i < MAX; i++) 
		c[i] = 0;
}

void insere(conjunto c, int e)
{
	c[e] = 1;
}

void retira(conjunto c, int e)
{
	c[e] = 0;
}

int pertence(conjunto c, int e)
{
	// if (c[e]==1) return 1;
	// else return 0;
	return c[e];
}

void uniao(conjunto a, conjunto b, conjunto c)
{
	for (int i = 0; i < MAX; i++)
		c[i] = a[i] || b[i];
}

void interseccao(conjunto a, conjunto b, conjunto c)
{
	for (int i = 0; i < MAX; i++)
		c[i] = a[i] && b[i];
}

void diferenca(conjunto a, conjunto b, conjunto c)
{
	for (int i = 0; i < MAX; i++)
		if (a[i] == 1)
			c[i] = ! b[i];
		else
			c[i] = 0;
}

void imprime(conjunto c)
{
	for (int i = 0; i < MAX; i++)
		if (c[i])
			printf("%d ", i);
	printf("\n");
}
