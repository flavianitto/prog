//FLAVIA NARUMI NITTO		RA: 201040743
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define n 4
#define m 8

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int i, j, resultado[n], melhor=0, maior=0;
	char prova[n][m];
	char gabarito[m]={'a', 'a', 'a', 'a', 'a', 'a', 'a', 'd'};
	
	for(i=0; i<n; i++)
	{
		//zerando o vetor resultado
		resultado[i] = 0;
		
		printf("\nAluno %d\n", i+1);
		for(j=0; j<m; j++)	
		{
			printf("\tResposta da questão %d: ", j+1);
			scanf("%s", &prova[i][j]);	
			if(prova[i][j] == gabarito[j])
			{
				resultado[i]++;
			}					
		}
	}
	for(i=0; i<n; i++)
	{
		if(resultado[i]>maior)
		{
			maior = resultado[i];
			melhor = i;
		}
		printf("\n\n Aluno %d\n -Total de acertos: %d\n\n", i+1, maior);
	}
	printf("\nAluno %d foi o primeiro a obter a maior nota: %d", melhor+1, maior);

	
	return 0;
}
