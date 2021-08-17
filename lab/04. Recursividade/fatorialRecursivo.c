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
    if(number<=1){
        return 1;
    }
    else{
        return number*fatorial(number-1);
    }
}
