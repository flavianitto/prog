#include <stdio.h>
#include <string.h>

int main(){
    char s1[30] = "Laboratorio de Prog II";
    char s2[] = " - 2020";
    char s3[40] = "Aula de ";
    printf("s1: %s\ns2: %s\n\n", s1, s2);
    strcat(s1, s2);
    printf("strcat(s1,s2): %s\n", s1);
    strncat(s3, s1, 11);
    printf("strcat(s3,s1): %s\n", s3);
    return 0;
}
