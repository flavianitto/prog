#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* 
Mini-prova 7 - Construa um programa em linguagem C para ler uma senha de no m�ximo 10 caracteres
do teclado e informar posteriormente na tela se ela � v�lida ou n�o. S�o consideradas v�lidas as
senhas para as quais o primeiro e o ultimo caracteres s�o iguais ou para as quais o n�mero de 
letras maiusculas � igual ao de min�sculas
*/

//fun��o para pegar o tamanho da senha
int strlen(char*str)
{
	int cont=0;
	for(;*str;str++)
	{
		cont++;
	}
	return cont;
}

int main()
{
	int i, tamanho, maiuscula=0, minuscula=0;
	char senha[11];

	gets(senha);
	tamanho = strlen(senha);

	for(i=0; i<tamanho+1; i++)
	{
		if(islower(senha[i]))
		{
			minuscula++;
		}
		
		if(isupper(senha[i]))
		{
			maiuscula++;
		}
	}

	if(senha[0]==senha[tamanho-1] || maiuscula==minuscula)
	{
		printf("\nSenha valida!!!");
	}

    if(senha[0]!=senha[tamanho-1] && maiuscula!=minuscula)		
	{
		printf("\nSenha invalida!!!");
	}
	
	return 0;
}
