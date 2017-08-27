#ifndef CONJUNTO_H
 
#define CONJUNTO_H

#define MAX 100

typedef char conjunto[MAX];

void inicializa(conjunto c);
void insere(conjunto c, int e);
void retira(conjunto c, int e);
int pertence(conjunto c, int e);
void uniao(conjunto a, conjunto b, conjunto c);
void interseccao(conjunto a, conjunto b, conjunto c);
void diferenca(conjunto a, conjunto b, conjunto c);
void imprime(conjunto c);

#endif