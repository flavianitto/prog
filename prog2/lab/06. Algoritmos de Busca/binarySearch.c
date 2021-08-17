#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int binarySearch(int array[], int key, int low, int high);

int main(){
    int numeros[SIZE], pos, searchKey;
    for(int i=0; i<SIZE; i++){
        numeros[i] = i * 3;
        printf("%d\n", numeros[i]);
    }
    printf("Digite a chave inteira a ser buscada: ");
    scanf("%d", &searchKey);
    pos = binarySearch(numeros, searchKey, 0, SIZE-1);
    if(pos!=-1){
        printf("\n\nA chave %d foi encontrada na posicao %d do vetor 'numeros'\n", searchKey, pos);
    }
    else{
        printf("\n\nA chave %d não foi encontrada\n", searchKey);
    }
    return 0;
}

int binarySearch(int array[], int key, int low, int high){
    int middle; 
    while (low <= high) {
        middle = (low + high)/2;
        if (key == array[middle]){
            return middle;
        } 
        else if (key < array[middle]){
            high = middle - 1;
        } 
        else {
            low = middle + 1;
        } 
    } 
    return -1;
}
