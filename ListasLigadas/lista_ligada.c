#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"

void cria(t_lista *lista)
{
  *lista = NULL;
}

void insere_primeiro(t_lista *lista, t_item item)
{
  t_apontador p = (t_apontador) malloc(sizeof(t_no));
  if (p == NULL)
  {
    printf("Erro: memoria insuficiente\n");
    exit(EXIT_FAILURE);
  }
  p->prox = *lista;
  *lista = p;
  p->item = item;
}

t_apontador pesquisa(t_lista *lista, t_chave chave)
{
  t_apontador p = *lista;
  while (p != NULL)
    if (strcmp(p->item.chave, chave) != 0)
      p = p->prox;
    else
      break;
  return p;
}

void remove_posicao(t_lista *lista, t_apontador pos)
{
  if (pos == *lista)
  {
    *lista = pos->prox;
    free(pos);
  }
  else
  {
    t_apontador p = *lista;
    while (p != NULL && p->prox != pos)
      p = p->prox;
    if (p != NULL)
    {
      p->prox = pos->prox;
      free(pos);
    }
  }
}

void remove_posicao2(t_lista *lista, t_apontador pos)
{
  t_apontador *p = lista;

  while (*p != NULL && *p != pos)
    p = &((*p)->prox);
  if (p != NULL)
  {
    *p = pos->prox;
    free(pos);
  }
}

t_item recupera(t_lista *lista, t_apontador pos)
{
  if (pos == NULL)
  {
    printf("Erro: posicao invalida\n");
    exit(EXIT_FAILURE);
  }
  return pos->item;
}

int num_elementos(t_lista *lista)
{
  int cont = 0;
  t_apontador p = *lista;
  while (p != NULL)
  {
    p = p->prox;
    cont++;
  }
  return cont;
}

int lista_vazia(t_lista *lista)
{
  return *lista == NULL;
}

// int lista_cheia(t_lista *lista)
// {
// }
