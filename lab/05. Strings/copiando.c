#include <stdio.h>
#include <string.h>

int main(){
    char x[] = "Laboratorio de Prog II";
    char y[25];
    char z[25];
    strcpy(y, x);
    strncpy(z, x, 11);
    z[11] = '\0';
    printf("A string x eh: %s\nA string y eh: %s\nA string z eh: %s\n", x, y, z);
    return 0;
}
