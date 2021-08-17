#include <stdio.h>
#include <string.h>

int main(){
    char *s1 = "Laboratorio de Prog II";
    char *s2 = "Laboratorio de Prog II";
    char *s3 = "Laboratorio de Prog I";
    printf("s1: %s\ns2: %s\ns3: %s\n\n", s1, s2, s3);
    printf("strcmp(s1, s2): %d\nstrcmp(s1, s3): %d\nstrcmp(s3, s2): %d\n",strcmp(s1, s2), strcmp(s1, s3), strcmp(s3, s2));
    printf("\nstrncmp(s1, s2, 8): %d\nstrncmp(s1, s3, 22): %d\nstrncmp(s3, s2, 22): %d\n",strncmp(s1, s2, 8), strncmp(s1, s3, 22), strncmp(s3, s2, 22));
    return 0;
}
