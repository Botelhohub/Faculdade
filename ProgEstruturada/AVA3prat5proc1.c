/*
Desenvolva um código na linguagem de programação C para preencher um vetor de
50 posições com valores aleatórios entre 0 e 20. Em seguida o programa deve exibir:
1. a soma dos valores armazenados no vetor;
2. o número de ocorrências do valor 9;
3. o maior valor armazenado no vetor;
4. as posições onde aparecem o maior valor encontrado em (c) – notar que aqui o programa
possivelmente imprimirá mais de uma posição
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand(time(NULL));
	int vetor[50], maiorPos;
	int ocorrencias9 = 0;
	int maior = 0;
	printf("Vetor gerado: \n");
	for(int i=0; i<50; i++){
		vetor[i]= rand()%21;
		printf("|%d",vetor[i]);
		if(vetor[i] == 9){
			ocorrencias9++;
		}
	}
	printf("\nOcorrencias do numero 9: %d", ocorrencias9);
	for (int i = 0; i < 50; i++)
	{
		if (vetor[i] > maior)
		{
			maiorPos = i;
			maior = vetor[i];
		}
	}
	printf("\nO maior valor armazenado: %d", maior);
	printf("\nPosicao(oes) do maior valor: %d", maiorPos);
	for (int i = 0; i < 50; i++) //loop para imprimir mais de um id se tiver vários numeros maiores
	{
		if (vetor[i] == maior && i != maiorPos)
		{
			printf(" %d", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}