#include<stdio.h>
#include<stdlib.h>

/*
Mini-prova 10: construa um programa em linguagem C para ler um valor inteiro positivo (n) e em 
seguida imprima n linhas do tri�ngulo de Floyd desse n�mero. Esse tri�ngulo possui n linhas nas
quais a primeira tem 1 valor, a segunda tem 2, a terceira tem 3, e assim por diante, estando
todos os n�meros em sequ�ncia.
*/

int main()
{
	int n, i, j;
	int numeros=0; 
	
	printf("Informe um valor n: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++)	
	{
		for(j=1; j<=i; j++)
		{
			numeros++;
			printf("%d  ", numeros);
		}
		printf("\n");
	}
	
	return 0;
}
