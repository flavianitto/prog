/*Criando e usando uma função definida pelo programador */
#include <stdio.h>

int square(int y); /* protótipo da função */
/* função main inicia execução do programa */
int main(void){
    int x; /* contador */
    /* loop 10 vezes e calcula e exibe quadrado de x a cada vez */
    for (x = 1; x <= 10; x++){
            printf("%d \t", square(x)); /* chamada da função */
    }/* fim do for */
    printf("\n");
    return 0; /* indica conclusão bem-sucedida */
} /* fim do main */
/* definição de função square retorna quadrado do parâmetro */
int square(int y){ /* y é uma cópia do argumento à função */
    return y * y; /* retorna o quadrado de y como um int */
} /* fim da função square */

