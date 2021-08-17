#include <stdio.h>
#include <string.h>

int forcaBruta(char *padrao, char *texto) {
    int j, M = strlen(padrao);
    int i, N = strlen(texto);
    for (i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++)
            if (padrao[j]!=texto[i+j])
                break;
        if (j == M) return i;
    }
    return -1;
}

int main(){
    char txt[] = "Meu nome eh Alvaro Magri Nogueira da Cruz, terceiro de seu nome, filho de Claudia A professora.";
    char palavra[] = "Alvaro";
    int posicao = 0;
    printf("Busca do padrão '%s' no texto\n", palavra);
    posicao = forcaBruta(palavra, txt);
    if(posicao!=-1){
        printf("Palavra encontrada na posicao %d!\n\n", posicao);
    }
    else{
        printf("Palavra não encontrada!\n\n");
    }
    return 0;
}

