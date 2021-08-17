#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *prox;
    struct no *ant;
}no;


no *insere(int x, no *lista){//Insere no inicio da lista
    no *novoNo;
    no *aux = lista;
    novoNo = (no*) malloc(sizeof(no));//Aloca memoria para o novo no
    novoNo->conteudo = x;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    if(lista==NULL){//Verifica se a lista esta vazia
        lista = novoNo;
    }
    else{
        novoNo->prox = aux;
        aux->ant = novoNo;
        aux = novoNo;
        lista = aux;
    }
    return lista;
}

void imprime(no *lista){//Imprime TODA lista
    no *aux = lista;
    if(lista==NULL) printf("Lista vazia!\n"); //Verifica se a lista esta vazia
    else{
        while(aux!=NULL){//Percorre ate o final da lista
            printf("%d ->\t", aux->conteudo);
            aux = aux->prox;
        }
    }
}

no *remover(no *lista){ //Remove sempre a cabeca da lista
    no *aux = lista;
    if(lista==NULL) printf("Lista vazia!\n");//Verifica se a lista esta vazia
    else if(aux->prox==NULL){//Se e o ultimo elemento, libera e lista=NULL
        free(aux);
        lista = NULL;
    }
    else{//Se tem mais de um elemento, apenas remove a cabeca
        lista = aux->prox;
        lista->ant = NULL;
        free(aux);
    }
    return lista;
}

int main(){ //Funcao principal para teste das funcoes de inserir, remover e imprimir
    no *minhaLista = NULL;
    int numero=0;
    printf("Digite um numero para inserir (exit=-1): ");
    scanf("%d", &numero);
    while(numero!=-1){
        minhaLista = insere(numero, minhaLista);
        imprime(minhaLista);
        printf("\nDigite um numero para inserir (exit=-1): ");
        scanf("%d", &numero);
    }
    imprime(minhaLista);
    while(minhaLista!=NULL){
        minhaLista = remover(minhaLista);
        printf("\n");
        imprime(minhaLista);
    }
    return 0;
}
