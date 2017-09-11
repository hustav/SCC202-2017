#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#define MAXTAM 1000

typedef int t_apontador;

typedef float t_item;

typedef struct {
  t_item item[MAXTAM];
  t_apontador topo;
} t_pilha;

void cria(t_pilha *pilha);
void push(t_pilha *pilha, t_item item);
t_item pop(t_pilha *pilha);
t_item topo(t_pilha *pilha);
int conta(t_pilha *pilha);
int vazia(t_pilha *pilha);
int cheia(t_pilha *pilha);
void imprime(t_pilha *pilha);

#endif
