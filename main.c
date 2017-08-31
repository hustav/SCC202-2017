#include <stdio.h>
#include "lista_ligada.h"

int main() {
    t_lista l;
    t_item i;
    t_apontador pos;
    t_chave nome;
    char c;

    cria(&l);                                                           /**/
    do {
        printf("Menu\n\n");
        printf("1 - Insere contato\n");
        printf("2 - Busca contato\n");
        printf("3 - Remove contato\n");
        printf("4 - Sair\n\n");

        scanf(" %c", &c);
        switch(c) {
            case '1':
                printf("Nome: ");
                scanf("\n%s", i.chave);
                printf("Telefone: ");
                scanf("%s", i.telefone);
                insere_primeiro(&l, i);                                 /**/
                break;
            case '2':
                printf("Nome: ");
                scanf("\n%s", nome);
                pos = pesquisa(&l, nome);                               /**/
                if (pos == NAO_ENCONTRADO)
                    printf("Nome nao existente\n");
                else {
                    i = recupera(&l, pos);                              /**/
                    printf("%s\n", i.chave);
                    printf("%s\n", i.telefone);
                }
                break;
            case '3':
                printf("Nome: ");
                scanf("\n%s", nome);
                pos = pesquisa(&l, nome);                               /**/
                if (pos == NAO_ENCONTRADO)
                    printf("Nome nao existente\n");
                else {
                    remove_posicao(&l, pos);                            /**/
                    printf("Nome: %s removido!\n", nome);
                }
                break;
            case '4':
                printf("Tchau!\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (c != '4');
    return 0;
}
