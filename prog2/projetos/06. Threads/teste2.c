#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam;

void intercala(double *vetor, int p, int q, int r);
void mergeSort(double *vetor, int p, int r);
void preencherVetor(double *vetor);
void imprimirVetor(double *vetor);

int main(){
    int n=50;
    double *vetor = (double*)malloc(n*sizeof(double));
    preencherVetor(vetor);
    //imprimirVetor(vetor, n);
    mergeSort(vetor, 0, n);
    imprimirVetor(vetor);   

    free(vetor);
    return 0;
}

void intercala(double *vetor, int p, int q, int r){//Intercala vetores ordenados
   double *aux;                                 
   aux = malloc ((r-p) * sizeof (double));      
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

void mergeSort(double *vetor, int p, int r){//Merge sort
   if (p<r-1){                 
      int q = (p + r)/2;         
      mergeSort(vetor, p, q);       
      mergeSort(vetor, q, r);        
      intercala(vetor, p, q, r);  
   }
}

void preencherVetor(double *vetor){//Função que preenche vetor automaticamente
    FILE *arquivo = fopen("vetor.dat", "r");
    int i=0;
    while(!feof(arquivo))
    {
        fscanf(arquivo, "%lf\n", &vetor[i]);
        printf("vetor[%d]: %lf\n", i, vetor[i]);
        i++;
    }
    tam = i;
    vetor = (double*)realloc(vetor, tam*sizeof(double));

    fclose(arquivo);
}

void imprimirVetor(double *vetor){//Função que imprime vetor
    int i=0;
    for(i=0; i<tam; i++){
        printf("\n%lf", vetor[i]);
    }
    printf("\n\n");
}

