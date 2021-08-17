// Nome: Vitor Pelicer de Mesquita Fran�a

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{//struct para representar pontos cartesianos
	double x;
	double y;
}coordenada;

coordenada meio(coordenada *vetor, int N);// prot�tipo da fun��o que encontra o ponto m�dio


double dist(coordenada centro, coordenada modelo);// prot�tipo da fun��o que encontra a dist�ncia entre dois pontos


int main(){
	
	int N, i, certo = 0;
	double menor = 9999999, x;
	FILE *inputfile;
	inputfile = fopen("input.txt", "r");// abertura do arquivo de input
	fscanf(inputfile, "%d\n", &N);// leitura de N
	coordenada coord[N];
	for(i=1;i<=N;i++){
		fscanf(inputfile, "%lf %lf\n", &coord[i].x, &coord[i].y);// leitura dos pontos (x,y)
	}
	fclose(inputfile);// fecha do arquivo
	coord[0] = meio(coord, N);// chamada de fun��o para encontrar o centro das coordenadas
	
	for(i=1;i<=N;i++){
		x = dist(coord[0], coord[i]);
		if(x < menor){//determina��o do ponto com menor dist�ncia at� o centro das coordenadas
			menor = x;
			certo = i;//certo � o indice da coordenada mais pr�xima do centro
		}
	}
	
	printf("Ponto (%.1lf, %.1lf)", coord[certo].x, coord[certo].y );
	
	return 0;
	
}

coordenada meio(coordenada *vetor, int N){// fun��o para encontrar o ponto central
	coordenada p;
	p.x = 0;
	p.y = 0;
	int i;
	for(i=1;i<=N;i++){// formula da m�dia aritm�tica ou tamb�m formula do centro de massa
		p.x = p.x + vetor[i].x;// Somat�ria em X
		p.y = p.y + vetor[i].y;// Somat�ria em Y
	}
	p.x = p.x/N;
	p.y = p.y/N;
	return p;
}

double dist(coordenada centro, coordenada modelo){// fun��o para encontrar a dist�ncia entre dois pontos (de um ponto at� o ponto central)
	double distancia;
	modelo.x = modelo.x - centro.x;
	modelo.y = modelo.y - centro.y;
	distancia = sqrt(modelo.x*modelo.x + modelo.y*modelo.y);// formula de pit�goras para encontrar a dist�ncia
	return distancia;
}

