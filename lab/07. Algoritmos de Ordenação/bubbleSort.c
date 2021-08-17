#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vetor[], int n){//Bubble Sort
    int i, j, aux, trocou;
    for (i=1; i<n; i++) {
        trocou = 0;
        for (j=0; j<n-1; j++){
            if (vetor[j] > vetor[j+1]){
                trocou = 1;
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
        if(trocou==0) break;
    }
}

void preencherVetor(int vetor[], int n){//Função que preenche vetor automaticamente
    srand((unsigned)time(NULL)); //Utilizada para renovar a semente do random
    for(int i=0; i<n; i++){
        vetor[i] = rand() % 100000; //Random de 0 a 99999
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
    int n = 10;
    int vetor[n];
    preencherVetor(vetor, n);
    imprimirVetor(vetor, n);
    bubbleSort(vetor, n);
    imprimirVetor(vetor, n);   
    return 0;
}
