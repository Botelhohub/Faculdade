#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


/*Desenvolva um código que exiba um menu com as seguintes
informações abaixo:
1. Qual o seu clube de futebol de preferência (1–Flamengo, 2–Vasco, 3–Fluminense, 4–
Botafogo, 5–Outros);
2. Qual o seu salário;
3. Qual a sua cidade natal (1 – Niterói, 2 – Outra).
Para finalizar a entrevista o usuário deve digitar o valor 0 (zero).
Caso o usuário escolha uma opção diferente das exibidas, o sistema deve emiAr uma mensagem:
“Opção inválida!”.
Escreva um programa que colete os dados de acordo com a opção escolhida pelo usuário e
informe:
• O número de torcedores por clube;
• A média salarial dos torcedores de cada time;
• O número de pessoas nascidas em Niterói e que não torcem para nenhum dos
principais clubes do Rio;
• O número de pessoas entrevistadas.*/
void exibirresultado(int n, int times[], float totalTime[], int ntorce)
{
	char nomesT[5][10] = {"Flamengo", "Vasco", "Fluminense", "Botafogo", "Outro Time"};
	printf("\n-- Resultados da Pesquisa --\nNúmero de entrevistados: %d\nNumero de torcedores dos principais times: ", n);
	for (int i = 0; i < 5 ; i++)
	{
		printf("%s: %d ", nomesT[i], times[i]);
	}
	printf("\nSalário Médio entre os torcedores do times:\n");
	for (int i = 0; i < 5; i++)
	{
		float m = totalTime[i] / times[i];
		printf("%s: R$ %.2f ",nomesT[i], m);
	}
	printf("\nMoradores de Nireroi que não torcem para nenhum dos principais times do RJ: %d", ntorce);
}

int main()
{
	int times[5] = {0, 0, 0, 0, 0}; //vetor index dos times no vetor: 0 - Fla, 1 - Vas, 2 - Flu, 3 - Bot, 4 - outros
	float salarioTim[5] = {0, 0, 0, 0, 0}; //mesmo index dos times[]
	int n = 0; //contador
	int nTorce = 0;
	printf("\nBem vindo ao programa de pesquisa\n");
	do
	{
		int idTime;
		int input;
		float salario;
		n++;
		printf("Selecione o time de futebol para qual você torce?\n");
		printf("1 - Flamengo\n2 - Vasco\n3 - Fluminense\n4 - Botafogo\n5 - Outro Time\nSelecione: "); //não confundir o numero aqui com o ID do time no times[]
		tim:
		scanf("%d", &input);
		if (input > 0 && input <= 5)
		{
			idTime = input - 1;
			times[idTime]++;
		}
		else
		{
			printf("Opção inválida! Selecione um numero de 1 a 5: ");
			goto tim;
		}
		printf("Em que região você mora?\n1 - Niteroi\n2 - Outra\nSelecione: ");
		cid:
		scanf("%d", &input);
		if (input <= 2 && input > 0) //primeiro if checa o input, o segundo verifica qual foi o input
		{
			if (input == 2 && idTime == 4)
			{
				nTorce++;
			}
		}
		else
		{
			printf("Opção inválida! Selecione 1 ou 2: ");
			goto cid;
		}
		printf("Qual a sua renda mensal?\nDigite apenas números: ");
		scanf("%f", &salario);
		salarioTim[idTime] = salarioTim[idTime] + salario;
		printf("Pesquisa concluída!\nDigite 0 para exibir resultados e finalizar o programa ou qualquer tecla para continuar com outro entrevistado: ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			exibirresultado(n, times, salarioTim, nTorce);
			exit(0);
			break;
		default: printf("\nPróximo entrevistado...\n");
			break;
		}
	} while (n >= 0);
	return -1; //se ene ficar negativo por algum motivo, o programa quebrou.
}

