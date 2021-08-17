#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int linearSearch(int array[], int key, int size);

int main(){
    int numeros[SIZE], pos, searchKey;
    for(int i=0; i<SIZE; i++){
        numeros[i] = i * (rand() % 100);
        printf("%d\n", numeros[i]);
    }
    printf("Digite a chave inteira a ser buscada: ");
    scanf("%d", &searchKey);
    pos = linearSearch(numeros, searchKey, SIZE);
    if(pos!=-1){
        printf("\n\nA chave %d foi encontrada na posicao %d do vetor 'numeros'\n", searchKey, pos);
    }
    else{
        printf("\n\nA chave %d não foi encontrada\n", searchKey);
    }
    return 0;
}

int linearSearch(int array[], int key, int size){
    int n;
    for(n=0; n<size; n++){
        if(array[n]==key){
            return n;
        }
    }
    return -1;
}
