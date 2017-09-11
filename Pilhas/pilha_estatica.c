#include <stdlib.h>
#include <stdio.h>
#include "pilha_estatica.h"

void cria(t_pilha *pilha)
{
  pilha->topo = -1;
}

void push(t_pilha *pilha, t_item item)
{
  if (cheia(pilha))
    exit(EXIT_FAILURE);
  pilha->item[++pilha->topo] = item;
}

t_item pop(t_pilha *pilha)
{
  if (vazia(pilha))
    exit(EXIT_FAILURE);
  return pilha->item[pilha->topo--];
}

t_item topo(t_pilha *pilha)
{
  if (vazia(pilha))
    exit(EXIT_FAILURE);
  return pilha->item[pilha->topo];
}

int conta(t_pilha *pilha)
{
  return pilha->topo + 1;
}

int vazia(t_pilha *pilha)
{
  return pilha->topo == -1;
}

int cheia(t_pilha *pilha)
{
  return pilha->topo == (MAXTAM - 1);
}

void imprime(t_pilha *pilha)
{
  if (vazia(pilha))
    printf("Pilha vazia\n");
  else
  {
    for (int i = 0; i <= pilha->topo; i++)
      printf("%f, ", pilha->item[i]);
    printf("\n");
  }
}
