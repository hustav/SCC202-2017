#ifndef CONJUNTO2_HPP

#define CONJUNTO2_HPP

#include <set>

using namespace std;

typedef set<int> conjunto;

void inicializa(conjunto &c);
void insere(conjunto &c, int e);
void retira(conjunto &c, int e);
int pertence(conjunto c, int e);
void uniao(conjunto a, conjunto b, conjunto &c);
void interseccao(conjunto a, conjunto b, conjunto &c);
void diferenca(conjunto a, conjunto b, conjunto &c);
void imprime(conjunto c);

#endif