#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Descrição: Desenvolva um código na linguagem de programação C que calcule e exiba o número
de dias corridos entre duas datas, sendo para vários pares de datas e considerando a
possibilidade de ocorrência de anos bissextos. Sendo que:
• A primeira data é sempre a mais anAga;
• O ano é fornecido com 4 dígitos;
• A data fornecida com ZERO dias é o sinal para encerrar a entrada de dados.*/

int ContarDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
	bool bissexto1, bissexto2;
	int sum;
	if (ano1 % 4 == 0){ //todo: refazer colocando mais de uma checagem no mesmo if com or e and
		if (ano1 % 100 == 0){
			if(ano1 % 400 == 0){
				bissexto1 = true;
			}
			else{
				bissexto1 = false;
			}
		}
		else{
			bissexto1 = false;
		}
	}
	else{
		bissexto1 = false;
	}
	bool bissexto2;
	if (ano2 % 4 == 0){
		if (ano2 % 100 == 0){
			if(ano2 % 400 == 0){
				bissexto2 = true;
			}
			else{
				bissexto2 = false;
			}
		}
		else{
			bissexto2 = false;
		}
	}
	else{
		bissexto2 = false;
	}
	if(bissexto1 = true || bissexto2 = true ){
		sum = ((ano2 - ano1) * 365 ) + 1;
	}
	else if(bissexto1 = true && bissexto2 = true){
		sum = ((ano2 - ano1) * 365 ) + 2;
	}
	else{
		sum = ((ano2 - ano1) * 365 );
	}
}
void main(){
	int dia1, mes1, ano1, dia2, mes2, ano2;
	dia1 = 1;
	while (dia != 0)
	{
		printf("Insira o par de datas: dd/mm/aaaa dd/mm/aaaa");
		scanf("%d/%d/%d %d/%d/%d", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
		int dias = ContarDias(dia1, mes1, ano1, dia2, mes2, ano2);
		print("Entre as duas datas se passaram %d", dias);
	}
}
