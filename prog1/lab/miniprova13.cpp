#include<stdio.h>
#include<locale.h>
#define x 5

/*
Mini-prova 13: construa um programa em linguagem C para solicitar e ler do teclado uma matriz
quadrada de 5 linhas e 5 colunas e, em seguida, calcular o seu tra�o e, tamb�m a soma dos elementos
que n�o estejam na diagonal principal.
*/

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int matriz[x][x], traco=0, soma=0, i, j;
	for(i=0; i<x; i++)
	{
		for(j=0; j<x; j++)
		{
			printf("Insira o elemento [%d][%d]: ", i+1, j+1);
			scanf("%d", &matriz[i][j]);
			
			if(i==j)
			{
				traco += matriz[i][j];
			}
			if(i!=j)
			{
				soma += matriz[i][j];
			}
		}
	}
	printf("\n- Tra�o da matriz: %d", traco);
	printf("\n- Soma dos elementos que n�o est�o na diagonal principal: %d", soma);
	
	return 0;
}
