/*
Uma sorveteria vende cinco produtos diferentes, cada um com um preço de acordo
com a tabela abaixo
Desenvolva um código na linguagem de programação C que processe diversas vendas,
lembrando que cada venda efetuada pode ser composta por diversas unidades de diversos
produtos. O programa deverá ualizar:
a. uma função que apresente na tela um menu indicando os preços dos produtos. Esse
menu deve ser apresentado no início de cada venda;
b. uma função que processe cada venda individual e forneça o valor a pagar;
c. uma terceira função que emita um relatório no final do dia, informando dados gerais
das vendas do dia (número total de itens vendidos de cada produto, total pago para cada
produto, total caixaado e valor médio de cada compra).
*/
#include <stdio.h>
#include <stdlib.h>
#define ITEM 5

static char itens[ITEM][20] = {"Refrigerante", "Casquinha Simples", "Casquinha Dupla", "Sundae", "Banana Split"};
static float precos[ITEM] = {3.50, 4.00, 5.50, 7.50, 9.00};

int venda[ITEM]; //somador de preços
int contVenda = 0; //contador de vendas do dia
float vendaDia[ITEM]; //somador de preços do dia todo
float caixa = 0; //valor total recebido

void exibirItens()
{
    printf("\n---Tabela de Precos---\n");
    printf("Codigo --- Produto --- Valor\n");
    for (int i = 0; i < ITEM; i++)
    {
        char cod = 1 + i;
        printf("%d -- %s -- R$: %.2f \n", cod, itens[i], precos[i]);
    }
}
void registrar(int qty, int itm)
{
	int id = itm - 1;
	venda[id] = venda[id] + qty;
}
void totalizar()
{
	printf("\nVenda finalizada. Itens:\n");
	float sum;
	for (int i = 0; i < ITEM; i++)
	{
		if(venda[i]>0)
		{
			float total = venda[i] * precos[i];
			sum = sum + total;
			printf(">>%s x%d : %.2f\n" ,itens[i], venda[i], total);
			vendaDia[i] = vendaDia[i] + total;
			venda[i] = 0;
		}
	}
	printf(">>Total: R$ %.2f\n", sum);
	caixa = caixa + sum;
	contVenda++;
}
void relatorio()
{
	printf("Numero de vendas no dia: %d\n", contVenda);
	printf("Caixa medio por venda: R$ %.2f\n", caixa/contVenda);
	printf("Total recebido por item:\n");
	for (int i = 0; i < ITEM; i++)
	{
		printf("%s : R$%.2f\n", itens[i], vendaDia[i]);
	}
	printf("Caixa total do dia: R$ %.2f\n", caixa);
}
void main()
{
	int qty, itm;
	int flag = 1;
	printf("Software de caixa automatico V1.0\nFuncoes: ");
	printf("Digite 0 no codigo de item para finalizar a venda ou Digite a senha do supervisor para emitir o relatorio de vendas\n"); //1234
	itens:
	system("pause");
	exibirItens();
    while (flag)
    {
		printf("Digite o codigo do item: "); //senha 1234
    	scanf("%d",&itm);
		if (itm == 0)
		{
			totalizar();
			goto itens;
		}
    	else if (itm > 0 && itm <= ITEM)
    	{
			printf("Quantidade: ");
			scanf("%d", &qty);
    		registrar(qty, itm);
		}
		else if (itm == 1234)
		{
			flag = 0;
			printf("\nFinalizando e emitindo relatorio...\n");
			relatorio();
			system("pause");
		}
		else
		{
			printf("\nEntrada invalida");
		}
	}
}
