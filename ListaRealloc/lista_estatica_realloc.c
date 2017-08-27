#include <stdlib.h>
#include <stdio.h>
#include "lista_estatica_realloc.h"

void cria(t_lista *lista)
{
        lista->ultimo = -1;
        lista->tam = TAM_BLOCO;
        lista->item = (t_item*) malloc(TAM_BLOCO * sizeof(t_item));
}

void insere_ultimo(t_lista *lista, t_item item)
{
        if (lista->ultimo == lista->tam - 1)
        {
                lista->tam += TAM_BLOCO;
                t_item *aux = (t_item *) realloc(lista->item, lista->tam * sizeof(t_item));
                if (aux == NULL)
                {
                        printf("Erro: memoria indisponivel\n");
                        free(lista->item);
                        exit(EXIT_FAILURE);
                } else lista->item = aux;
        }
        lista->item[++lista->ultimo] = item;
}

t_apontador pesquisa(t_lista *lista, t_chave chave)  // lista passador por endereco por eficiência
{
        for (int i = 0; i <= lista->ultimo; i++)
        {
                if (lista->item[i].chave == chave)
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
        if (lista->ultimo % TAM_BLOCO == TAM_BLOCO - 1)
        {
                lista->tam -= TAM_BLOCO;
                t_item *aux = (t_item*) realloc(lista->item, lista->tam * sizeof(t_item));
                if (aux == NULL)
                {
                        free(lista->item);
                        printf("Erro: memoria indisponivel\n");
                        exit(EXIT_FAILURE);
                } else lista->item = aux;
        }
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

void destroi(t_lista *lista)
{
        free(lista->item);
}
