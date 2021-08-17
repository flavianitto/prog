#include<stdio.h>
#include<stdlib.h>

//mini-prova 5 - construa um programa em linguagem C para ler três valores reais do teclado e apresentar na tela o menor deles, 
//o maior deles, a média artimética deles e, por fim, a amplitude deles, ou seja, a diferença entre o maior e o menor.

int main()
{
	float n1, n2, n3, maior=0, menor=0, media, amp;
	printf("Digite o primeiro numero: ");
	scanf("%f",&n1);
	printf("Digite o segundo numero: ");
	scanf("%f",&n2);
	printf("Digite o terceiro numero: ");
	scanf("%f",&n3);
	
	//maior
	if (n1!=n2 && n2!=n3 && n1!=n3)
	{
		if(n1>n2 && n1>n3)
		{
			maior = maior+n1;
			printf("\nMaior numero: %2.2f", maior);
		}
		if(n2>n1 && n2>n3)
		{
			maior = maior+n2;
			printf("\nMaior numero: %2.2f", maior);
		}
		if(n3>n1 && n3>n2)
		{
			maior = maior+n3;
			printf("\nMaior numero: %2.2f", maior);
		}
	}
	if(n1==n2 && n2==n3 && n1==n3)
	{
		maior = maior+n1;
		printf("\nMaior numero: %2.2f", maior);
	}
	
	//menor
	if(n1!=n2 && n2!=n3 && n1!=n3)
	{
		if(n1<n2 && n1<n3)
		{
			menor = menor+n1;
			printf("\nMenor numero: %2.2f", menor);
		}
		if(n2<n1 && n2<n3)
		{
			menor = menor+n2;
			printf("\nMenor numero: %2.2f", menor);
		}
		if(n3<n1 && n3<n2)
		{
			menor = menor+n3;
			printf("\nMenor numero: %2.2f", menor);
		}
	}
	if (n1==n2 && n2==n3 && n1==n3)
	{
		menor = menor+n1;
		printf("\nMenor numero: %2.2f", menor);
	}
	
	//media aritmetica
	media = (n1+n2+n3)/3;
	printf ("\nMedia aritmetica: %2.2f", media);
	
	//amplitude
	amp = maior-menor;
	printf ("\nAmplitude: %2.2f\n", amp);
	
	system("PAUSE");
	return(0);
}
