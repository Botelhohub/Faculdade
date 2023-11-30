/*PROBLEMA: Desenvolva um código na linguagem de programação C que simule uma calculadora,
que realiza as quatro operações matemáticas básicas: soma, subtração, divisão e multuplicação.
Ao escolher uma das opções, o programa solicita dois números para que a opção escolhida seja
executada e o resultado da operação deve ser exibido na tela. Em seguida, o menu deve ser
exibido novamente para que o usuário escolha outra opção.
O programa deve ficar executando até que o usuário escolha a opção 5. Nesse caso o programa
deve finalizar. Caso o usuário escolha uma opção diferente das exibidas, o sistema deve emiAr uma mensagem: “Opção inválida!”.*/

#include <stdio.h>
#include <stdlib.h>

float calcular(float n1, float n2, int op)
{
    float result;
    switch(op)
    {
        case 1:
            result = n1+n2;
            break;
        case 2:
            result = n1-n2;
            break;
        case 3:
            result = n1/n2;
            break;
        case 4:
            result = n1*n2;
            break;
    }
    return result;
}

int main(){
    float n1, n2, result;
    int op;
    printf("Calculadora básica v1.0\n");
    do
    {
        printf("\nOperações:\n1.Soma\n2.Subtração\n3.Divisão\n4.Multiplicação\n5.sair do Programa\nDigite a opção: ");
        op:
        scanf("%d",&op);
        if (op < 1 || op > 5)
        {
            printf("Opção Invalida. Selecione um número de 1 a 5: ");
            goto op;
        }
        else if (op == 5)
        {
            printf("Saindo do programa...");
            exit(0);
        }
        else
        {
            printf("\nDigite o primeiro número: ");
            scanf("%f", &n1);
            printf("\nDigite o segundo número: ");
            scanf("%f", &n2);
            result = calcular(n1,n2,op);
        }
        printf("\n>>> O resultado da operação é: %.2f\n",result);
    } while(op != 5);
    return 0;
}