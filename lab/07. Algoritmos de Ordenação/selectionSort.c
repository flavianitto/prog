#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int n){//Selection sort
    int min, aux;
    for(int i=0; i<n; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(vetor[j]<vetor[min]) min = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

void preencherVetor(int vetor[], int n){//Função que preenche vetor automaticamente
    srand((unsigned)time(NULL)); //Utilizada para renovar a semente do random
    for(int i=0; i<n; i++){
        vetor[i] = rand() % 10000000; //Random de 0 a 99999
    }
}

void imprimirVetor(int vetor[], int n){//Função que imprime vetor
    printf("\n\t----------------VETOR----------------\n");
    for(int i=0; i<n; i++){
        printf("[%d]  ", vetor[i]);
    }
    printf("\n");
}
int main(){
    int n = 1000000;
    int vetor[n];
    preencherVetor(vetor, n);
    //imprimirVetor(vetor, n);
    selectionSort(vetor, n);
    //imprimirVetor(vetor, n);   
    return 0;
}
