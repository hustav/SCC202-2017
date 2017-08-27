#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_estatica.h"

void cria(t_lista *lista)
{
	lista->ultimo = -1;
}

void insere_ultimo(t_lista *lista, t_item item)
{
	if (lista->ultimo == MAXTAM - 1)
	{
		printf("Erro: lista cheia\n");
		exit(EXIT_FAILURE);
	}
	lista->item[++lista->ultimo] = item;
}

t_apontador pesquisa(t_lista *lista, t_chave chave)  // lista passador por endereco por eficiência
{
	for (int i = 0; i <= lista->ultimo; i++)
	{
		if (strcmp(lista->item[i].chave, chave) == 0)
			return i;
	}
	return NAO_ENCONTRADO;
}

void remove_posicao(t_lista *lista, t_apontador pos)
{
	if (pos < 0 || pos > lista->ultimo)
	{
		printf("Erro: posicao invalida\n");
		exit(EXIT_FAILURE);
	}	
	for (int i = pos; i <= lista->ultimo-1; i++)
		lista->item[i] = lista->item[i+1];
	lista->ultimo--;
}

t_item recupera(t_lista *lista, t_apontador pos)
{
	if (pos < 0 || pos > lista->ultimo)
	{
		printf("Erro: posicao invalida\n");
		exit(EXIT_FAILURE);
	}	
	return lista->item[pos];
}

int num_elementos(t_lista *lista)
{
	return lista->ultimo;
}

int lista_vazia(t_lista *lista)
{
	return lista->ultimo == 0;
}

int lista_cheia(t_lista *lista)
{
	return lista->ultimo == MAXTAM - 1;
}
