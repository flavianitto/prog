#include<stdio.h>
#include<stdlib.h>

void imprimirMatriz(int **matriz, int n, int m){
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}

void zerarMatriz(int **matriz, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matriz[i][j] = 0;
        }
    }
}
void preencherMatriz(int **matriz, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matriz[i][j] = i+j;
        }
    }
}
int main(){
    int **matriz, n, m;
    printf("Digite o numero de linhas da sua matriz: ");
    scanf("%d", &n);
    printf("Digite o numero de colunas da sua matriz: ");
    scanf("%d", &m);
    matriz = (int**) malloc(n*sizeof(int*));
    for(int j=0; j<n; j++){
        matriz[j] = (int*) malloc(m*sizeof(int));
    }
    zerarMatriz(matriz,n,m);
    imprimirMatriz(matriz,n,m);
    preencherMatriz(matriz,n,m);
    imprimirMatriz(matriz,n,m);
    return 0;
}
