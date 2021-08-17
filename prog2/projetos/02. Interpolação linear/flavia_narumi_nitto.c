//Flavia Narumi Nitto (RA: 201040743)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Coordenadas
{
	double x;
	double y;
}coordenadas;

//Prototipos das funcoes
coordenadas fcentro(coordenadas *vetor, int N);

double fdistancia(coordenadas centro, coordenadas dponto);

int main()
{
	int N, i, indice;
	coordenadas totcentro;
	double limite=1000000, totdistancia;
	
	//Abrindo o arquivo input.txt e recebendo os dados
	FILE *inputfp;
	inputfp = fopen("input.txt", "r");
	
	//primeira linha do arquivo -> numero de pares
	fscanf(inputfp, "%d\n", &N);
	coordenadas pares[N];
	for(i=0; i<N; i++)
	{
		fscanf(inputfp, "%lf %lf", &pares[i].x, &pares[i].y);	
	}
	fclose(inputfp);
/*
	fscanf(inputfp, "%d\n", &N);
	coordenadas pares[N];
	do
	{
		fscanf(inputfp, "%lf %lf", &pares[i].x, &pares[i].y);
		i++;
	}while(!feof(inputfp));
	fclose(inputfp);
*/
	
	//Atribuindo o resultado do calculo das coordenadas do ponto central
	totcentro = fcentro(pares, N);
	
	for(i=0; i<N; i++)
	{
		totdistancia = fdistancia(totcentro, pares[i]);
		
		//calculando qual a menor distancia entre as distancias dos pontos
		if(totdistancia<limite)
		{
			limite = totdistancia;
			indice = i;
		}
	}
	
	//Printando o ponto mais proximo do centro de massa no monitor
	printf("Ponto (%.1lf, %.1lf)", pares[indice].x, pares[indice].y);
	
	return 0;
}

//Funcao para calcular o centro das coordenadas (calculo da media aritmetica)
coordenadas fcentro(coordenadas *vetor, int N)
{
	int i;
	coordenadas ponto;
	ponto.x=0; ponto.y=0;
	
	//Calculando o centro de massa dos pontos
	for(i=0; i<N; i++)
	{
		//Somatoria 
		ponto.x = ponto.x + vetor[i].x;
		ponto.y = ponto.y + vetor[i].y;
	}
	ponto.x = ponto.x / N;
	ponto.y = ponto.y / N;
	
	return ponto;
}

//Funcao para calcular a distancia entre os pontos
double fdistancia(coordenadas centro, coordenadas dponto)
{
	double distancia;
	
	//Calculando a distancia entre os pontos do par ordenado ate o ponto central
	dponto.x = dponto.x - centro.x;
	dponto.y = dponto.y - centro.y;
	
	//Calculando a distancia entre dois pontos
	distancia = sqrt((dponto.x*dponto.x) + (dponto.y*dponto.y));
	
	return distancia;
}

