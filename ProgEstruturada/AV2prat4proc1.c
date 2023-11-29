#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*Descrição: Desenvolva um código na linguagem de programação C que calcule e exiba o número
de dias corridos entre duas datas, sendo para vários pares de datas e considerando a
possibilidade de ocorrência de anos bissextos. Sendo que:
• A primeira data é sempre a mais anAga;
• O ano é fornecido com 4 dígitos;
• A data fornecida com ZERO dias é o sinal para encerrar a entrada de dados.*/

bool bissexto(int ano)
{
    if (ano % 4 == 0 && ano % 100 != 0)
    {
        return true;
    }
    else if (ano % 4 == 0 && ano % 100 == 0 && ano % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int contardias(int d, int m)
{
    int contador = d;
    int mes = m;
    mes--;
    if (mes > 0)
    {
        for (int i = mes; i > 0; i--)
        {
            int dias;
            if (i == 2)
            {
                dias = 28;
            }
            else if (i % 2 == 0 || i == 1)
            {
                dias = 31;
            }
            else if (i % 2 != 0)
            {
                dias = 30;
            }
            contador = contador + dias;
        }
        return contador;
    }
    else
    {
        return contador;
    }
}
int main()
{
    int d1, m1, a1, d2, m2, a2; //entradas
    int da1, da2; //contador dos dias no ano de entrada p/ referencia
    int deltano;
    printf("Programa de contagem de dias\n");
    do
    {
        int cont = 0;
        printf("Insira o par de datas: (dd/mm/aaaa dd/mm/aaaa) (zero para sair)");
        scanf("%d/%d/%d %d/%d/%d", &d1, &m1, &a1, &d2, &m2, &a2);
        if (d1 == 0)
        {
            exit(0);
        }
        da1 = contardias(d1, m1);
        da2 = contardias(d2, m2);
        deltano = a2 - a1;
        if(a1 == a2)
        {
            cont = da2 - da1;
        }
        else
        {
            cont = da2 - da1;
            for (int i = deltano; i > 0 ; i--)
            {
                int ano = a1 + i;
                switch (bissexto(ano))
                {
                case true:
                    cont = cont + 366;
                    break;
                default:
                    cont = cont + 365;
                    break;
                }
            }
        }
        printf("\nDias decorridos: %d\n", cont);
    }
    while(d1 != 0);
    return 0;
}