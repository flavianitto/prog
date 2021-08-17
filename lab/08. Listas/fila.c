#include <stdio.h>
#include <stdlib.h>

typedef struct no{//Estrutura de um nó
    int conteudo;
    struct no *prox;
}no;

no *insere(int x, no *lista){//Insere no final da lista
    no *novoNo;
    no *aux = lista;
    novoNo = (no*) malloc(sizeof(no));//Aloca memória para o novo nó
    novoNo->conteudo = x;
    novoNo->prox = NULL;
    if(lista==NULL){//Verifica se a lista está vazia
        lista = novoNo;
    }
    else{
        while(aux->prox!=NULL){//Percorre até o final da lista
                aux = aux->prox;
        }
        aux->prox = novoNo;
        aux = novoNo;
    }
    return lista;
}

void imprime(no *lista){//Imprime TODA lista
    no *aux = lista;
    if(lista==NULL) printf("Lista vazia!\n"); //Verifica se a lista está vazia
    else{
        while(aux!=NULL){//Percorre até o final da lista
            printf("%d ->\t", aux->conteudo);
            aux = aux->prox;
        }
    }
}

no *remover(no *lista){ //Remove sempre a cabeça da lista
    no *aux = lista;
    if(lista==NULL) printf("Lista vazia!\n");//Verifica se a lista está vazia
    else{
        lista = aux->prox;
        free(aux);
    }
    return lista;
}

int main(){ //Função principal para teste das funções de inserir, remover e imprimir
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
