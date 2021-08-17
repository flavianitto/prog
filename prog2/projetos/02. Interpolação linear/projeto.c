// Nome: Vitor Pelicer de Mesquita França

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{//struct para representar pontos cartesianos
	double x;
	double y;
}coordenada;

coordenada meio(coordenada *vetor, int N);// protótipo da função que encontra o ponto médio


double dist(coordenada centro, coordenada modelo);// protótipo da função que encontra a distância entre dois pontos


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
	coord[0] = meio(coord, N);// chamada de função para encontrar o centro das coordenadas
	
	for(i=1;i<=N;i++){
		x = dist(coord[0], coord[i]);
		if(x < menor){//determinação do ponto com menor distância até o centro das coordenadas
			menor = x;
			certo = i;//certo é o indice da coordenada mais próxima do centro
		}
	}
	
	printf("Ponto (%.1lf, %.1lf)", coord[certo].x, coord[certo].y );
	
	return 0;
	
}

coordenada meio(coordenada *vetor, int N){// função para encontrar o ponto central
	coordenada p;
	p.x = 0;
	p.y = 0;
	int i;
	for(i=1;i<=N;i++){// formula da média aritmética ou também formula do centro de massa
		p.x = p.x + vetor[i].x;// Somatória em X
		p.y = p.y + vetor[i].y;// Somatória em Y
	}
	p.x = p.x/N;
	p.y = p.y/N;
	return p;
}

double dist(coordenada centro, coordenada modelo){// função para encontrar a distância entre dois pontos (de um ponto até o ponto central)
	double distancia;
	modelo.x = modelo.x - centro.x;
	modelo.y = modelo.y - centro.y;
	distancia = sqrt(modelo.x*modelo.x + modelo.y*modelo.y);// formula de pitágoras para encontrar a distância
	return distancia;
}

