#include <stdio.h>

int main(){
    float a, b, c;
    float *aPonteiro, *bPonteiro, *cPonteiro; 
    printf("Digite o primeiro numero da soma: ");
    scanf("%f", &a);
    printf("\nDigite o segundo numero da soma: ");
    scanf("%f", &b);
    aPonteiro = &a;
    bPonteiro = &b;
    cPonteiro = &c;
    *cPonteiro = *aPonteiro + *bPonteiro;
    printf("\nO resultado de %f + %f = %f\n", *aPonteiro, *bPonteiro, c);
    return 0;
}
