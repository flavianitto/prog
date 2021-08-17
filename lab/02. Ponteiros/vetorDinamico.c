#include<stdio.h>
#include<stdlib.h>

int main(){
    int tamanho;
    int *vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    vetor = (int*) malloc(tamanho*sizeof(int));
    for(int i=0; i<tamanho; i++){
        vetor[i] = 0;
    }
    for(int i=0; i<tamanho; i++){
        printf("vetor[%d]: %d\n", i,vetor[i]);
    }
    for(int i=0; i<tamanho; i++){
        vetor[i] = i;
    }
    for(int i=0; i<tamanho; i++){
        printf("vetor[%d]: %d\n", i,vetor[i]);
    }
    free(vetor);
    
    return 0;
}
