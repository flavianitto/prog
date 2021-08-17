#include <stdio.h>

long fatorial(long number);//prototipo

int main(){
    int i, entrada;//contador
    printf("Calcule o fatorial de: ");
    scanf("%d", &entrada);
    printf("\n%d\n", fatorial(entrada));
    return 0;
}

long fatorial(long number){
    long cont = number, resultado=1;
    for(cont = number; cont>=1; cont--){
        resultado = resultado * cont;
    }
    return resultado;
}
