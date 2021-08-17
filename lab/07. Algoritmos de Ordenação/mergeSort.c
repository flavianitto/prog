#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int vetor[], int p, int q, int r){//Intercala vetores ordenados
   int *aux;                                 
   aux = malloc ((r-p) * sizeof (int));      
   int i = p, j = q;                       
   int k = 0;                              
   while (i<q && j<r) {                
      if (vetor[i]<=vetor[j])  aux[k++] = vetor[i++];  
      else  aux[k++] = vetor[j++];               
   }                                       
   while (i < q)  aux[k++] = vetor[i++];         
   while (j < r)  aux[k++] = vetor[j++];         
   for (i = p; i < r; i++)  vetor[i] = aux[i-p]; 
   free (aux);                               
}

void mergeSort(int vetor[], int p, int r){//Merge sort
   if (p<r-1){                 
      int q = (p + r)/2;         
      mergeSort(vetor, p, q);       
      mergeSort(vetor, q, r);        
      intercala(vetor, p, q, r);     
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
    mergeSort(vetor, 0, n);
    imprimirVetor(vetor, n);   
    return 0;
}
