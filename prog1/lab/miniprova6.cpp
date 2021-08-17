#include<stdio.h>
#include<stdlib.h>

/*Mini-prova 6  construa um programa em linguagem C para ler um valor inteiro do teclado e apresentar na tela cada
um dos seus d�gitos em separado, sejam eles quantos forem. */

int main()
{
	int contadordigitos=0, valor, contador=0, vetor[15];	
	printf("Digite um valor inteiro valido: ");
	scanf("%d", &valor);
	
	if ((valor < 2147483648)&&(valor > -2147483648)) //valor maximo e minimo de um inteiro
	{
		//contando os valores do numero digitado
		do 
		{
			contadordigitos++;
			vetor[contador]= valor % 10;
			valor = valor/10;
			contador++;
		}
		while (valor > 9);
		
		vetor[contador] = valor;
		
		for (int i=contador; i>=0; i--)
		{
			printf("\n%do digito: %d", contador-i+1,vetor[i]);
		}
	}
	
	else
	{
		printf("Valor inteiro invalido!!!");
	}
	printf("\n\n");
	return 0;
}

/* O contadordigitos ir� contar a quantidade de d�gitos que o valor inserido tem;
 * O vetor de tamanho maior ou igual a quantidade maxima de digitos de um inteiro (10) ir� armazenar cada 
 resto da divis�o por 10 ou seja, vai quebrando o d�gito de um em um pois est� em decimal;
 * A vari�vel valor armazena seu valor sendo dividido por 10, enquanto seu valor for um inteiro (9/10 n�o � inteiro)
 * O contador armazena quantas vezes esse processo foi repetido (n�mero de digitos)
 * Atribuir os dados armazenados em na vari�vel valor para o vetor[contador] facilita o processo de imprim�-los na tela depois
 * Como os valores do vetor foram colocados ao contr�rio (o �ltimo ocupa a primeira posi��o), precisamos inverter a ordem por meio
 das condi��es de i no la�o de repeti��o
 */
