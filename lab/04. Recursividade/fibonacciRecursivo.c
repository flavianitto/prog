#include <stdio.h>

int fibonacci(int number);//prototipo

int main(){
    int i, entrada;//contador
    printf("Digite um numero: ");
    scanf("%d", &entrada);
    printf("\nfibonacci(%d) = %d\n",entrada,fibonacci(entrada));
    return 0;
}

int fibonacci(int number){
    if(number==0||number==1){
        return number;
    }
    else{
        return fibonacci(number-1)+fibonacci(number-2);
    }
}
