#include<stdio.h>
#include<stdlib.h>

/*Mini-prova 6  construa um programa em linguagem C para ler um valor inteiro do teclado e apresentar na tela cada
um dos seus dígitos em separado, sejam eles quantos forem. */

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

/* O contadordigitos irá contar a quantidade de dígitos que o valor inserido tem;
 * O vetor de tamanho maior ou igual a quantidade maxima de digitos de um inteiro (10) irá armazenar cada 
 resto da divisão por 10 ou seja, vai quebrando o dígito de um em um pois está em decimal;
 * A variável valor armazena seu valor sendo dividido por 10, enquanto seu valor for um inteiro (9/10 não é inteiro)
 * O contador armazena quantas vezes esse processo foi repetido (número de digitos)
 * Atribuir os dados armazenados em na variável valor para o vetor[contador] facilita o processo de imprimí-los na tela depois
 * Como os valores do vetor foram colocados ao contrário (o último ocupa a primeira posição), precisamos inverter a ordem por meio
 das condições de i no laço de repetição
 */
