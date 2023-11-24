#include <stdio.h>
#include <stdbool.h>
/* Um urso chegou a uma Floresta e se escondeu atrás de uma das 100 árvores
existentes, quando em determinado momento viu um caçador. O caçador só Anha 5 balas em
sua espingarda. Cada vez que ele aArava, e não acertava, o urso dizia: estou mais à direita ou
mais à esquerda.
Caso o caçador não consiga acertar o urso, ele será imediatamente levado para Polo Norte.
Desenvolva um código na linguagem de programação C, para implementar este jogo. Ele
deve ser jogado por dois jogadores, onde um escolhe a árvore em que o urso irá se esconder, e o
outro tenta acertar.*/
void main(){
    int tpos; // tree position
    int spos; // shot position
    int shells = 5; //balas na escopeta
    bool flag = true;
    printf("Urso, selecione a árvre pra se esconder (número de 1 a 100):\n");
    scanf("%d", &tpos);
    printf("Um caçador apareceu!\n");
    while (flag = true)
    {
        printf("Escolha uma árvore de 1 a 100\n");
        scanf("%d", &spos);
        printf("Você atirou na árvore %d\n", spos);
        shells = shells - 1;
        if (spos == tpos)
        {
            printf("AIAI\nO Caçador Acertou o miserável\n");
            flag = false;
        }
        else if (spos < tpos)
        {
            printf("Urso says... : Seu ruim, tenta mais pra direita\n");
        }
        else if (spos > tpos)
        {
            printf("Urso says....: Seu ruim, tenta mais pra esquerda\n");
        }
        if (shells == 0)
        {
            printf("O caçador atirou toda sua munição mas não acertou nem de raspão\nentão, chocaco, o comissário da compania não pensou duas vezes\nComissário says...: Иди в ГУЛАГ\n\nVocê é enviado para apodrecer no polo norte\n");
            flag = false;
        }
    }
}
