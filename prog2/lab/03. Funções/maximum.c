#include <stdio.h>
int maximum(int x, int y, int z); /* protótipo de função */

int main(void){
    int number1; /* primeiro inteiro */
    int number2; /* segundo inteiro */
    int number3; /* terceiro inteiro */
    printf("Digite três inteiros: ");
    scanf("%d", &number1);
    scanf("%d", &number2);
    scanf("%d", &number3);
    /* number1, number2 e number3 são argumentos
    da chamada da função maximum */
    printf( "Máximo é: %d\n", maximum(number1, number2, number3));
    return 0; /* indica conclusão bem-sucedida */
} /* fim do main */
/* Definição da função maximum */
/* x, y e z são parâmetros */
int maximum(int x, int y, int z){
    int max = x; /* considera que x é o maior */
    if ( y > max ){ /* se y é maior que max, atribui y a max */
            max = y;
    } /* fim do if */
    if ( z > max ){ /* se z é maior que max, atribui z a max */
            max = z;
    } /* fim do if */
    return max; /* max é o maior valor */
} /* fim da função maximum */
