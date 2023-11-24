#include<stdio.h>
#include<stdlib.h>

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
• A média salarial dos torcedores de cada Ame;
• O número de pessoas nascidas em Niterói e que não torcem para nenhum dos
principais clubes do Rio;
• O número de pessoas entrevistadas.*/

int main(){

float slfla=0.0,slva=0.0,slflu=0.0,slbo=0.0,slout=0.0,salario;
int fla=0,va=0,flu=0,bo=0,out=0;
do{
	int op;
	
	printf("1.Flamengo");
	printf("2.Vasco");
	printf("3.Fluminense");
	printf("4.Botafogo");
	printf("5.Outros");
	print("0.sair");
	
	printf("Qual e o seu clube de futebol de preferencia?");
	scanf("%d",&op);
	
	printf("Qual o seu salario?");
	scanf("%f",&salario);
	
	switch(op){
		case 1: fla = fla+1 and slfla = slfla+salario;
		break;
		case 2: va=va+1 and slva=slva+salario;
		break;
		case 3: flu =flu+1 and slflu=slflu+salario;
		break;
		case 4: bo=bo+1 and slbo=slbo+salario;
		break;
		case 5: out=out+1 and slout=slout+salario;
		break;
		case 0: exit(0);
		default: printf("Opcao invalida!");
	}
	
	
	
}while (op!=0);
}
