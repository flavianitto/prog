#include <stdio.h>
#include <stdlib.h>

//mini-prova 4 - construa um programa em linguagem C para ler do teclado as coordenadas de dois pontos, 
//isto é, (x1,y1) e (x2,y2), e apresentar na tela a equação da reta y = ax+b que passa por eles

int main ()
{
	int x1, y1, x2, y2, a, b;
	printf("Digite x1: ");
	scanf("%d",&x1);
	printf("Digite y1: ");
	scanf("%d",&y1);
	
	printf("\nDigite x2: ");
	scanf("%d",&x2);
	printf("Digite y2: ");
	scanf("%d",&y2);
	
	//calculo do coeficiente angular (valor de a)
	a = (y2-y1)/(x2-x1);
			
	if (a != 0)
	{
		//calculo do coeficiente linear (valor de b) substituindo (x1,y1) na formula
		//y1 = (a*x1) + b
		b = y1-(a*x1);
		
		if (b >= 0)
		{
			printf ("\nEquacao da reta que passa pelos pontos (%d,%d) e (%d,%d) e dada por y = %dx + %d\n", x1, y1, x2, y2, a, b);
		}
		else
		{
			printf ("\nEquacao da reta que passa pelos pontos (%d,%d) e (%d,%d) e dada por y = %dx %d\n", x1, y1, x2, y2, a, b);
		}
		
	}
	else 
	{
		printf("Valor de a nao pode ser 0!!!");
	}
	
	system("PAUSE");
	return(0);

}
