#include <stdio.h>
#include <stdbool.h>

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
