#include <stdio.h>

#include "pilha_estatica.h"

int main()
{
  char linha[1000];
  int pos, r, c;
  char op;
  float op1, op2, num;
  t_pilha pilha;

  while (gets(linha) != NULL)
  {
    cria(&pilha);
    pos = 0;
    while ((r = sscanf(&linha[pos], "%f%n", &num, &c)) != EOF)
    {
      // printf("%d %f %d\n", r, num, c);
      if (r == 1)
      {
        push(&pilha, num);
        //imprime(&pilha);
        pos += c;
      }
      if (r == 0)
      {
        r = sscanf(&linha[pos], " %c%n", &op, &c);
        // printf("%d %c %d\n", r, op, c);

        pos += c;
        op1 = pop(&pilha);
        op2 = pop(&pilha);
        switch (op)
        {
          case '+':
            push(&pilha, op2 + op1);
            break;
          case '-':
            push(&pilha, op2 - op1);
            break;
          case '*':
            push(&pilha, op2 * op1);
            break;
          case '/':
            push(&pilha, op2 / op1);
            break;
        }
      }
    }
    printf("==> %f\n", pop(&pilha));
  }
  return 0;
}
