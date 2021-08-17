#include<stdio.h>
#include<locale.h>
#define x 10

/*
Mini-prova 15: construa um programa em linguagem C para solicitar e ler do teclado um conjunto de 
informações sobre 10 indivíduos. Para cada um deles, registrar-se-á o nome, com no máximo 30
caracteres, a idade em anos e o peso em kilos. Ao final, o programa deverá listar na tela todos os
nomes e as idades dos indivíduos que pesam mais do que x kilos, sendo que x deve ser solicitado e 
lido do teclado.
*/

int main()
{
	setlocale(LC_ALL, "Portuguese");
	typedef struct dados
	{
		char nome[30];
		int idade;
		float peso;
	}Dados;
	Dados vetor[x];
	
	int i;
	float pesox;
	for(i=0; i<x; i++)
	{
	   	puts("\n----------------------------------------------------------------------");
	   	puts("\tEntrada de dados: ");
	   	puts("----------------------------------------------------------------------");	
	   	
		printf("\n Nome: ");
		scanf("%s", vetor[i].nome);
		setbuf(stdin, NULL);
		
		printf("\n Idade: ");
		scanf("%d", &vetor[i].idade);
		
		printf("\n Peso (kg): ");
		scanf("%f", &vetor[i].peso);
	}
		
	printf("\n Selecione um peso mínimo: ");
	scanf("%f", &pesox);
	
	for(i=0; i<x; i++)
	{
		if(vetor[i].peso > pesox)
		{
			puts("\n\n-------------------------------------------------------------------------------");
			printf("\t\tApresentando dados de quem pesa mais que %.2fkg", pesox);
		   	puts("\n-------------------------------------------------------------------------------");			
		   	
		   	printf("\n Nome: %s", vetor[i].nome);
		   	printf("\n Idade: %d", vetor[i].idade);
		}
	}
	
	return 0;
}
