#include<stdio.h>

/*
Mini-prova 14: construa um programa em linguagem C para solicitar e ler do teclado duas matrizes:
a primeira com 3 linhas e 4 colunas e a sgunda com 4 linhas e 5 colunas. Em seguida, o programa deve
apresentar na tela a matriz resultante da multiplicação da primeira pela segunda matriz.
*/
int main()
{
	float m1[3][4], m2[4][5], resultante[3][5], aux=0;
	int i, j, k;
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf(" Insira o elemento [%d][%d] da primeira matriz: ", i+1, j+1);
			scanf("%f", &m1[i][j]);
		}
	}
	printf("\n");
	for(i=0; i<4; i++)
	{
		for(j=0; j<5; j++)
		{
			printf(" Insira o elemento [%d][%d] da segunda matriz: ", i+1, j+1);
			scanf("%f", &m2[i][j]);
		}
	}
	printf("\n Matriz resultante: ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			for(k=0; k<4; k++)
			{
				aux = 0;
				aux += m1[i][k] * m2[k][j];
			}
			resultante[i][j] = aux;
			
			
			printf("\n [%.2f]", resultante[i][j]);
		}
	}
	
	return 0;
}
