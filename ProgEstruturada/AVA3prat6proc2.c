/*
O objeavo do jogo "Batalha Naval" é destruir as embarcações do adversário. A frota é
composta por 3 apos de embarcações, que serão posicionadas no tabuleiro:
f - fragata (tamanho 2) ff -- = i e i+1 angulo i e j+1
c - cruzador (tamanho 3)ccc
s - submarino (tamanho 4)ssss
o programa deverá ler o tamanmho do tabuleiro, o tabuleiro, a quantidade de jogadas e as jogadas
e emitir a quantidade de acertos e navios destruídos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define FRAGATA 'f'
#define CRUZADOR 'c'
#define SUBMARINO 's'
#define AGUA '~'
int tTab = 10;
void exibirTabuleiro(char tabuleiro[tTab][tTab])
{
    // imprime um tabuleiro com números indicando as linhas e colunas
    for (int i = 0; i <= tTab; i++)
    {
        if(i == tTab)
        {
            printf("x  ");
        }
        else
        {
            if (i >= 10)
            {
                printf("%d ",i - 10);
            }
            else
            {
                printf("%d ",i);
            }
        }
        for (int j = 0; j < tTab; j++)
        {
            if (i == tTab)
            {
                if (j>=10)
                {
                    printf("%d  ", j - 10);
                }
                else
                {
                    printf("%d  ", j);
                }
            }
            else
            {
                printf(" %c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}
int posicaoValida(char tabuleiro[tTab][tTab], int linha, int coluna, int tamanho, char direcao)
{   /*verifica as regras de posicionamento de embarcações como requisitado no problema da pratica pega a posição que foi gerada
e passa por essas condicionais para checar se aquele ponto pode receber um navio. raramente o jogo entra em loop infinito aqui,
pra evitar é só ajustar bem a quantidade de navios por tamanho de mapa*/
    if (linha < 0 || coluna < 0 || linha >= tTab || coluna >= tTab) {
        return 0;
    }

    int i, j;

    if (direcao == 'h') {
        if (coluna + tamanho > tTab) {
            return 0;
        }

        for (i = linha - 1; i <= linha + 1; i++) {
            for (j = coluna - 1; j < coluna + tamanho + 1; j++) {
                if (i >= 0 && i < tTab && j >= 0 && j < tTab && tabuleiro[i][j] != AGUA) {
                    return 0;
                }
            }
        }
    } else if (direcao == 'v') {
        if (linha + tamanho > tTab) {
            return 0;
        }

        for (i = linha - 1; i < linha + tamanho + 1; i++) {
            for (j = coluna - 1; j <= coluna + 1; j++) {
                if (i >= 0 && i < tTab && j >= 0 && j < tTab && tabuleiro[i][j] != AGUA) {
                    return 0;
                }
            }
        }
    } else if (direcao == 'd') {
        if (linha + tamanho > tTab || coluna + tamanho > tTab ) {
            return 0;
        }

        for (i = linha - 1; i < linha + tamanho + 1; i++) {
            for (j = coluna - 1; j < coluna + tamanho + 1; j++) {
                if (i >= 0 && i < tTab && j >= 0 && j < tTab && tabuleiro[i][j] != AGUA) {
                    return 0;
                }
            }
        }
    }

    return 1;
}
void colocarEmbarcacao(char tabuleiro[tTab][tTab], char tipo, int tamanho)
{
    //codigo coloca navios em posições aleatorias no mapa e também aleatoriza a orientação do navio
    int linha, coluna;
    char direcao;
    srand(time(NULL));
    do {
        linha = rand() % tTab;
        coluna = rand() % tTab;
        direcao = rand() % 3;  // 0 para horizontal, 1 para vertical, 2 para diagonal
    } while (!posicaoValida(tabuleiro, linha, coluna, tamanho, (direcao == 0) ? 'h' : (direcao == 1) ? 'v' : 'd'));

    if (direcao == 0) {
        for (int i = coluna; i < coluna + tamanho; i++) {
            tabuleiro[linha][i] = tipo;
        }
    } else if (direcao == 1) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = tipo;
        }
    } else if (direcao == 2) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna + i] = tipo;
        }
    }
}
int fazerJogada(char tabuleiro[tTab][tTab], int x, int y)
{
    //verifica se o tiro do jogador acertou ou não
    if (x < 0 || x > tTab || y < 0 || y > tTab)
    {
        printf("*Coordenadas invalidas!*\n");
        return 0; // Jogada inválida
    }
    else if (tabuleiro[x][y] == FRAGATA || tabuleiro[x][y] == CRUZADOR || tabuleiro[x][y] == SUBMARINO)
    {
        printf("*Voce acertou um navio!*\n");
        return 1; // Jogada válida e acerto
    } else
    {
        printf("*Voce errou*\n");
        return 2; // Jogada válida e erro
    }
}
void pontuacao(char tabuleiro[tTab][tTab], int fr, int cr, int ss)
{
    /*conta o score do jogador, a função faz isso contando o numero de acertos
    e conta o número de 'partes' de navios ainda restantes no mapa, para contar o numero de navios restantes, o numero total de partes é
    dividido pelo tamanho do navio e arredondado para baixo para descontar navios navios danificados
    então a diferença é tirada com o numero inicial de navios e assim obtemos quantos navios foram destruídos
    no final fiz um sistema de score que não foi requerido na prática, que simplesmente multiplica a quantidade de acertos pela quantidade
    de navios afundados colocando um peso diferente em cada um*/
    int acertos = 0;
    int r_fr = 0, r_cr = 0, r_ss = 0; //navios restantes
    printf("Pontuacao:\n");
    for (int i = 0; i < tTab; i++)
    {
        for (int j = 0; j < tTab; j++)
        {
            if (tabuleiro[i][j] == 'X')
            {
                acertos++;
            }
            else if (tabuleiro[i][j] == 'f')
            {
                r_fr++;
            }
            else if (tabuleiro[i][j] == 'c')
            {
                r_cr++;
            }
            else if (tabuleiro[i][j] == 's')
            {
                r_ss++;
            }
            else
            {
                continue;
            }
        }
    }
    fr = fr - (floor(r_fr) / 2);
    cr = cr - (floor(r_cr) / 3);
    ss = ss - (floor(r_ss) / 4);
    int total = fr + cr + ss;
    printf("Voce acertou %d alvos e afundou %d navios!\n",acertos,total);
    printf("Navios destruidos:\nFragatas: %d\nCruzadores: %d\nSubmarinos %d\n", fr, cr, ss);
    printf("Pontuacao total: %.0f\n", (acertos * ((fr * 1) + (cr * 1.5) + (ss * 2))));
}
int main()
{
    int n_jogadas;
    printf("Batalha Naval v1.0\n");
    tamanho:
    printf("Digite o tamanho dos lados tabuleiro quadrado (10 - 20) para iniciar o jogo e 0 para sair: ");
    scanf("%d", &tTab);
    //numero de navios no mapa, cresce com o tamanho do mapa
    int fr = 4 + round((tTab - 10));
    int cr = 2 + round((tTab - 10)/2);
    int ss = 2 + round((tTab - 10)/2);
    if (tTab == 0)
    {
        exit(0);
    }
    else if (tTab < 10 || tTab > 20)
    {
        printf("tamanho invalido, selecione um valor entre 10 e 20\n");
        goto tamanho;
    }
    else
    {
        printf("Digite a quantidade de jogadas: ");
        scanf("%d",&n_jogadas);
    }
    char campo[tTab][tTab]; //matriz usada para calcular acertos e amarzenar posição dos navios
    char campoPlayer[tTab][tTab]; //matriz 'vazia' só com as marcas de acertos que o player vê
    //inicialização das matrizes
    for (int i = 0; i < tTab; i++)
    {
        for (int j = 0; j < tTab; j++)
        {
            campo[i][j] = AGUA;
        }
    }
    for (int i = 0; i < tTab; i++)
    {
        for (int j = 0; j < tTab; j++)
        {
            campoPlayer[i][j] = AGUA;
        }
    }
    printf("Adcionando navios...\n");
    for (int i = 0; i < fr; i++)
    {
        colocarEmbarcacao(campo, FRAGATA, 2);
    }
    for (int i = 0; i < cr; i++)
    {
        colocarEmbarcacao(campo, CRUZADOR, 3);
    }
    for (int i = 0; i < ss; i++)
    {
        colocarEmbarcacao(campo, SUBMARINO, 4);
    }
    printf("O Radar detectou uma frota de %d Fragatas, %d Cruzadores e %d Submarinos se aproximando da area\n", fr, cr, ss);
    exibirTabuleiro(campoPlayer);
    //gameloop
    do
    {
        int x, y;
        tiro:
        printf("\nEscolha a cordenada para atirar: L C (%d torpedos restantes)\n", n_jogadas);
        scanf("%d %d", &x, &y);
        int resultado = fazerJogada(campo, x, y);
        if (resultado == 1)
        {
            campoPlayer[x][y] = 'X'; // acerto
            campo[x][y] = 'X';
            n_jogadas--;
        }
        else if (resultado == 2)
        {
            campoPlayer[x][y] = 'o'; // erro
            n_jogadas--;
        }
        else
        {
            goto tiro;
        }
        exibirTabuleiro(campoPlayer);
    } while (n_jogadas > 0);
    printf("Voce esgotou sua municao!\nGame over...\n");
    exibirTabuleiro(campo);
    pontuacao(campo, fr, cr, ss);
    printf("\n");
    system("pause");
    return 0;
}