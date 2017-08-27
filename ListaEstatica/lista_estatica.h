#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define MAXTAM 1000
#define NAO_ENCONTRADO -1

typedef int t_apontador;

typedef char t_chave[50];

typedef struct {
	t_chave chave;
	char telefone[10];
} t_item;

typedef struct {
	t_item item[MAXTAM];
	t_apontador ultimo;
} t_lista;

void cria(t_lista *lista);
void insere_ultimo(t_lista *lista, t_item item);
t_apontador pesquisa(t_lista *lista, t_chave chave);
void remove_posicao(t_lista *lista, t_apontador pos);
t_item recupera(t_lista *lista, t_apontador pos);
int num_elementos(t_lista *lista);
int lista_vazia(t_lista *lista);
int lista_cheia(t_lista *lista);

#endif





