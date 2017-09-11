#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

typedef int t_item;

typedef struct no {
  t_item item;
  struct no *prox;
} t_no;

typedef t_no *t_apontador;

typedef t_apontador t_pilha;

void cria(t_pilha *pilha);
void push(t_pilha *pilha, t_item item);
t_item pop(t_pilha *pilha);
t_item topo(t_pilha *pilha);
int conta(t_pilha *pilha);
int vazia(t_pilha *pilha);
//int cheia(t_pilha *pilha);

#endif
