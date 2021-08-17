#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
/*
Mini-prova 9: construa um programa em linguagem C para ler uma string do teclado que contenha somente
caracteres maiúsculos. Enquanto o usuário não digitar uma string em tais condições, o programa deve
permanecer solicitando-a e relendo-a para, somente depois, prosseguir. Assim que uma string válida
for lida, deverá ser apresentada na tela a mesma string mas com todos os caracteres minúsculos 
correspondentes e, além disso, escrita de trás para frente
*/
int main()	
{
	setlocale(LC_ALL, "Portuguese");
	int tam, i, aux=0;
	char string[40];
	
	printf("Insira uma string válida: ");
	gets(string);
	setbuf(stdin, NULL);
		
	tam = strlen(string);
	for(i=0; i<tam; i++)
	{
		if(islower(string[i]))
		{
			printf("Insira uma string válida: ");
			gets(string);
			setbuf(stdin, NULL);			
		}
	}

	puts("Mostrando a string de trás para frente: ");
	for(i=tam-1; i>=0; i--)
	{
		strlwr(string);
		printf(" %c", string[i]);
	}	
	
	return 0;
}
