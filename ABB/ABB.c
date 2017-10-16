#include<stdio.h>
#include<stdlib.h>

#define NAO_ENCONTRADO NULL

typedef int t_chave;

typedef struct {
    t_chave chave;
    // demais campos
} t_item;

typedef struct no {
    t_item item;
    struct no *esq, *dir;
} t_no;

typedef t_no *t_apontador;
typedef t_apontador t_arvore;

void criaArvore(t_arvore *A) {
    *A = NULL;
}

void criaRaiz(t_arvore *A, t_item item) {
    *A = (t_apontador) malloc(sizeof(t_no));
    (*A)->dir = NULL;
    (*A)->esq = NULL;
    (*A)->item = item;
}

void insereDireita(t_arvore A, t_item item) {
    criaRaiz(&A->dir, item);
}

void insereEsquerda(t_arvore A, t_item item) {
    criaRaiz(&A->esq, item);
}

void visita(t_apontador A)
{
    printf("%d", A->item.chave);
}

void emOrdem(t_apontador A) {
    if (A != NULL) {
        emOrdem(A->esq);
        visita(A);
        emOrdem(A->dir);
    }
}

void preOrdem(t_apontador A) {
    if (A != NULL) {
        visita(A);
        preOrdem(A->esq);
        preOrdem(A->dir);
    }
}

void posOrdem(t_apontador A) {
    if (A != NULL) {
        posOrdem(A->esq);
        posOrdem(A->dir);
        visita(A);
    }
}

void insere(t_arvore *A, t_item item) {
  t_apontador *p;

  p = A;
  while (*p != NULL) {
    if (item.chave < (*p)->item.chave)
      p = &(*p)->esq;
    else if (item.chave > (*p)->item.chave)
      p = &(*p)->dir;
    else {
      printf("Erro: chaves duplicadas\n");
      exit(EXIT_FAILURE);
    }
  }
  criaRaiz(p, item);
}

t_apontador pesquisa(t_arvore A, t_chave chave) {
  if (A == NULL)
    return NAO_ENCONTRADO;
  if (A->item.chave == chave)
    return A;
  if (chave < A->item.chave)
    return pesquisa(A->esq, chave);
  else
    return pesquisa(A->dir, chave);
}

void encontraMaxMin(t_apontador A, t_apontador *R);

void apaga(t_arvore *A, t_chave C) {
    t_apontador p;

    if (*A == NULL)
        printf("Erro: chave nao encontrada");
    else
        if (C < (*A)->item.chave)
            apaga(&(*A)->esq, C);
        else if (C > (*A)->item.chave)
                apaga(&(*A)->dir, C);
            else
                if ((*A)->dir == NULL) {
                    p = *A;
                    (*A) = (*A)->esq;
                    free(p);
                } else
                    if ((*A)->esq == NULL) {
                        p = *A;
                        (*A) = (*A)->dir;
                        free(p);
                    } else
                        encontraMaxMin(*A, &(*A)->esq);
}

void encontraMaxMin(t_apontador A, t_apontador *R) {
    if ((*R)->dir != NULL)
        encontraMaxMin(A, &(*R)->dir);
    else {
        A->item = (*R)->item;
        A = (*R);
        (*R) = (*R)->esq;
        free(A);
    }
}

int main()
{
	t_apontador raiz = NULL;
	t_item i;

	i.chave = 5;
	insere(&raiz, i);
	i.chave = 3;
	insere(&raiz, i);
	i.chave = 1;
	insere(&raiz, i);
	i.chave = 7;
	insere(&raiz, i);
	i.chave = 2;
	insere(&raiz, i);
	i.chave = 9;
	insere(&raiz, i);
	emOrdem(raiz);
  printf("\n");
	return 0;
}
