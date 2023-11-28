#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Desenvolva um código na linguagem de programação C que simule uma calculadora,
que realiza as quatro operações matemáAcas básicas: soma, subtração, divisão e mulAplicação.
Ao escolher uma das opções, o programa solicita dois números para que a opção escolhida seja
executada e o resultado da operação deve ser exibido na tela. Em seguida, o menu deve ser
exibido novamente para que o usuário escolha outra opção.
O programa deve ficar executando até que o usuário escolha a opção 5. Nesse caso o programa
deve finalizar. Caso o usuário escolha uma opção diferente das exibidas, o sistema deve emiAr uma mensagem: “Opção inválida!”.*/

// atenção: o teclado de input deve ser restringido a números!.
int main(){
    do
    {
        float n1, n2, result;
        int op;
        printf("\nSelecione o primeiro numero: ");
        scanf("%f",&n1);
        printf("\nSelecione o segundo numero: ");
        scanf("%f",&n2);
        printf("\nOperações:\n1.Soma\n2.Subtração\n3.Divisão\n4.Multiplicação\n5.sair do Programa\nDigite a opção: ");
        op:
        scanf("%d",&op);
        switch(op)
        {
            case 1: result = n1+n2;
                break;
            case 2: result = n1-n2;
                break;
            case 3: result = n1/n2;
                break;
            case 4: result = n1*n2;
                break;
            case 5:
                printf("Saindo do Programa...");
                exit(0);
                break;
            default: printf("\nOperação inválida!\nSelecione de 1 a 5:");
                goto op;
        }
        printf(">>> O resultado da operação é: %.1f\n",result);
    } while(1);
    return 0;
}
