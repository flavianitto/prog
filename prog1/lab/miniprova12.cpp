#include<stdio.h>
#include<math.h>
#define tam 30

/*
Mini-prova 12: construa um programa em linguagem C para solicitar e ler do teclado 30 valores reais e
armazená-los em um vetor. Em seguida, apresentar na tela o maior valor inteiro que seja menor que
todos os valores reais contidos no vetor.
*/

int main()
{
	float vetor[tam], piso=0, menor=0;
	int i;

	printf("Insira %d valores reais: ", tam);	
	for(i=0; i<tam; i++)
	{	
		scanf("%f", &vetor[i]);
		if (i==0) menor = vetor[i];
		if (vetor[i] < menor) menor = vetor[i];
		piso = floor(menor);
	}
	printf("\n- Maior valor inteiro menor que todos os valores reais do vetor: %.2f", piso);
	
	return 0;
}
