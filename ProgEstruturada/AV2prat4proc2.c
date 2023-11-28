#include <stdio.h>
#include <stdlib.h>
/* Um urso chegou a uma Floresta e se escondeu atrás de uma das 100 árvores
existentes, quando em determinado momento viu um caçador. O caçador só Anha 5 balas em
sua espingarda. Cada vez que ele aArava, e não acertava, o urso dizia: estou mais à direita ou
mais à esquerda.
Caso o caçador não consiga acertar o urso, ele será imediatamente levado para Polo Norte.
Desenvolva um código na linguagem de programação C, para implementar este jogo. Ele
deve ser jogado por dois jogadores, onde um escolhe a árvore em que o urso irá se esconder, e o
outro tenta acertar.*/
void main(){
    int tpos; // Posição da arvore
    int shells = 5; //balas na escopeta
    printf("O Urso deve selecionar em qual das 100 árvores vai se esconder (número de 1 a 100):\n");
    scanf("%d", &tpos);
    printf("Um caçador apareceu!\nVocê caçador teve um dia ruim de caça, não conseguiu nada e só está com 5 munições no seu rifle, escolha bem o seu alvo!.\nOu o urso vai te levar com ele pro polo norte! (dentro da barriga)");
    do
    {
        int spos; // Alvo do tiro
        printf("\nCaçador: Escolha em qual árvore vai atirar: ");
        scanf("%d", &spos);
        if (spos < tpos)
        {
            printf("\nUrso Says...: Seu ruim! tenta mais para a direita!");
        }
        else if (spos > tpos)
        {
            printf("\nUrso Says...: Seu ruim! tenta mais para a esquerda!");
        }
        else
        {
            printf("\nCaçador Says...: Peguei você!\nO caçador acertou um tiro no urso, que agoniza terrivelmente e cai morto.\nVITÓRIA DO CAÇADOR! encerrando programa...");
            exit(0);
        }
        shells--;

    } while (shells > 0);
    printf("\nVocê gastou toda sua munição!\nMas o tiroteio atraiu a atenção do urso diretamente para sua localização, é... e ele te comeu.");
    printf("VITÓRIA DO URSO! encerrando programa...");
}
