#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
/*
Mini-prova 9: construa um programa em linguagem C para ler uma string do teclado que contenha somente
caracteres mai�sculos. Enquanto o usu�rio n�o digitar uma string em tais condi��es, o programa deve
permanecer solicitando-a e relendo-a para, somente depois, prosseguir. Assim que uma string v�lida
for lida, dever� ser apresentada na tela a mesma string mas com todos os caracteres min�sculos 
correspondentes e, al�m disso, escrita de tr�s para frente
*/
int main()	
{
	setlocale(LC_ALL, "Portuguese");
	int tam, i, aux=0;
	char string[40];
	
	printf("Insira uma string v�lida: ");
	gets(string);
	setbuf(stdin, NULL);
		
	tam = strlen(string);
	for(i=0; i<tam; i++)
	{
		if(islower(string[i]))
		{
			printf("Insira uma string v�lida: ");
			gets(string);
			setbuf(stdin, NULL);			
		}
	}

	puts("Mostrando a string de tr�s para frente: ");
	for(i=tam-1; i>=0; i--)
	{
		strlwr(string);
		printf(" %c", string[i]);
	}	
	
	return 0;
}
