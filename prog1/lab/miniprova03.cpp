#include <stdio.h>
#include <stdlib.h>

// mini-prova 3 - construa um algoritmo computacional para realizar a soma de dois valores de entrada e apresentá-la como saída.

int main ()
{
	float n1, n2;
	printf ("\nDigite o primeiro valor: ");
	scanf("%f", &n1);	
	printf ("\nDigite o segundo valor: ");
	scanf("%f", &n2);
	printf("\nResultado da soma de %2.1f + %2.1f = %2.1f \n", n1, n2, n1+n2);
	
	system("PAUSE");
	return(0);
}
