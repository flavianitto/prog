#include<stdio.h>
#include<stdlib.h>

/*
Mini-prova 8 - Construa um programa em linguagem C para solicitar e ler valores inteiros do teclado
at� que o n�mero 0 seja digitado. Quando isso ocorrer, dever� ser exibido na tela a soma dos valores
anteriormente digitados.
*/

int main()
{
	int num, soma=0;
	while(num!=0)
	{
		printf("\nInsira um numero: ");
		scanf("%d", &num);
		soma += num;
	}
	printf("\n Soma dos numeros: %d", soma);
	
	return 0;
}
