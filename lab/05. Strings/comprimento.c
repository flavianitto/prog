#include <stdio.h>
#include <string.h>

int main(){
    char *s1 = "Laboratorio de Prog II";
    char *s2 = "Algoritmos e Tecnicas de Prog II";
    char *s3 = "UNESP - Rio Preto";
    printf("s1: '%s' -> tamanho %d\ns2: '%s'-> tamanho %d\ns3: '%s'-> tamanho %d\n", s1, strlen(s1), s2, strlen(s2), s3, strlen(s3));
    return 0;
}
