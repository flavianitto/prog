#include <stdio.h>

int main(){
    int valor; 
    int *valorPonteiro; 
    valor = 25;
    valorPonteiro = &valor; 
    printf("O ENDERECO de 'valor' eh %p\n", &valor);
    printf("O VALOR de valorPonteiro eh %p\n", valorPonteiro);
    printf("\nO VALOR de 'valor' eh %d\n", valor);
    printf("O VALOR de *valorPonteiro (indirecao) eh %d\n", *valorPonteiro);
    printf("\n\nMostrando que * e & sao complementos um do outro\n&*valorPonteiro = %p\n*&valorPonteiro = %p\n", &*valorPonteiro, *&valorPonteiro);
    return 0;
}
