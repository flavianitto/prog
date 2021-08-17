#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vetor[], int n){//Insertion sort
    int min, aux, j;
    for(int i=1; i<n; i++){
        aux = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>aux){
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = aux;
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
    imprimirVetor(vetor, n);
    insertionSort(vetor, n);
    imprimirVetor(vetor, n);   
    return 0;
}
