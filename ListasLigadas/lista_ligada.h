#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#define NAO_ENCONTRADO NULL

typedef char t_chave[50];

typedef struct {
	t_chave chave;
	char telefone[20];
} t_item;

typedef struct no {
	t_item item;
	struct no *prox;
} t_no;

typedef t_no *t_apontador;

typedef t_apontador t_lista;

void cria(t_lista *lista);
void insere_primeiro(t_lista *lista, t_item item);
t_apontador pesquisa(t_lista *lista, t_chave chave);
void remove_posicao(t_lista *lista, t_apontador pos);
t_item recupera(t_lista *lista, t_apontador pos);
int num_elementos(t_lista *lista);
int lista_vazia(t_lista *lista);
//int lista_cheia(t_lista *lista);

#endif
