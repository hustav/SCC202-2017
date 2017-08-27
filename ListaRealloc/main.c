#include <stdio.h>

#include "lista_estatica_realloc.h"

int main()
{
        t_lista lista;
        t_item item;

        cria(&lista);

        for (int i = 0; i < 100; i++)
        {
                item.chave = i;
                insere_ultimo(&lista, item);
                printf("tam: %d\n", lista.tam);
                printf("ultimo: %d\n", lista.ultimo);
        }

        printf("Pos: %d\n", pesquisa(&lista, 0));
        printf("Pos: %d\n", pesquisa(&lista, 1));
        printf("Pos: %d\n", pesquisa(&lista, 99));

        for (int i = 0; i < 100; i++)
        {
                item.chave = i;
                remove_posicao(&lista, 0);
                printf("tam: %d\n", lista.tam);
                printf("ultimo: %d\n", lista.ultimo);
        }

        destroi(&lista);
        return 0;
}
