/*
O Zodíaco Chinês é composto por animais com ciclo de 12 anos. Uma maneira
simplificada de idenaficá-los é verificando-se apenas o ano de seu nascimento
Desenvolva um programa na linguagem de programação com as itens solicitados, abaixo:
a. Crie um vetor com os signos;
b. Crie um vetor com o ano de nascimento dos membros de sua família;
c. Faça um código que, usando os vetores criados nos itens a e b, mostre o signo
de cada membro de sua família.
*/
#include <stdio.h>
#include <stdlib.h>
#define  10 //numero máximo de membros da familia

static char ano[12][10] = {"Macaco", "Galo", "Cao", "Porco", "Rato", "Boi", "Tigre", "Coelho", "Dragao", "Serpente", "Cavalo", "Carneiro"};

void obterAno(int vetor[])
{
    printf("\nO signo chinês dos familiares sao: \n");
	for (int i = 0; i < ; i++)
	{
		if (vetor[i]==0)
		{
			break;
		}
		printf("Membro %d: %s\n", i+1, ano[vetor[i]%12]);
	}
}
void main()
{
	int anos[];
	printf("Entre o ano de nascimento dos membros de sua família:(digite 0 para terminar)\n");
	for (int i = 0; i < ; i++)
	{
		printf("Membro %d: ", i + 1);
		scanf("%d", &anos[i]);
		if (anos[i] == 0 || i ==  - 1 )
		{
			obterAno(anos);
			system("pause");
			exit(0);
		}
	}
}