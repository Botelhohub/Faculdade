#include <stdio.h>
#include <stdlib.h>
/*Desenvolva um código na linguagem de programação C que simule uma calculadora,
que realiza as quatro operações matemáAcas básicas: soma, subtração, divisão e mulAplicação.
Ao escolher uma das opções, o programa solicita dois números para que a opção escolhida seja
executada e o resultado da operação deve ser exibido na tela. Em seguida, o menu deve ser
exibido novamente para que o usuário escolha outra opção.
O programa deve ficar executando até que o usuário escolha a opção 5. Nesse caso o programa
deve finalizar. Caso o usuário escolha uma opção diferente das exibidas, o sistema deve emiAr uma mensagem: “Opção inválida!”.*/

int main(){
    float n1,n2,result;
    int op;
    do{
        printf("Operações:\n1.Soma\n2.Subtração\n3.Divisão\n4.Multiplicação\n5.sair do Programa\nDigite a opção:");
        scanf("%d",&op);
        if(op == 5){ //a opção de fechar o programa e detectar numero de opção errado só funcionam se ficarem antes do switch da operação
            exit(0); // senão ele faz a operação mesmo assim e inventa um valor de resultado antes de reagir como deveria
        }
        if(op > 5){
            printf("\n\nOpção Inválida! Escolha uma opção de 1 a 5\n");
            continue;
        }
        printf("Selecione o primeiro numero:");
        scanf("%f",&n1);
        printf("Selecione o segundo numero:");
        scanf("%f",&n2);
        switch(op){
            case 1: result = n1+n2;
                break;
            case 2: result = n1-n2;
                break;
            case 3: result = n1/n2;
                break;
            case 4: result = n1*n2;
                break;
        }
        printf("\n\n>>>>>>O resultado é %.1f\n\n",result);
    }
    while(op != 5);
    return 0;
}
