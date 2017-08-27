#include <stdio.h>

#define MAX 100

typedef char conjunto[MAX];

void inicializa(conjunto c)
{
	for (int i = 0; i < MAX; i++) 
		c[i] = 0;
}

void insere(conjunto c, int e)
{
	c[e] = 1;
}

void remove(conjunto c, int e)
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
	diferenca(a, b, c);
	imprime(c);
}