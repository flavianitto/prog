#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 40 //tamanho do buffer

//struct para os elementos
typedef struct no
{
	char pal[20];
	int urg;
	struct no *prox;
}Elem;

//prototipo das funções
Elem *criaElemento(char pal[20], int urg);
void criaLista(Elem **W, Elem **R);
void preencheLista(Elem **W, Elem **R, Elem *elemento);
void addElemento(Elem **W, Elem **R, char pal[20], int urg);
void rmvElemento(Elem **W, Elem **R, Elem **removido);
void liberaBuffer(Elem **W, Elem **R);

int main()
{	
    //declara os principais ponteiros do programa: W e R
    Elem *W;
    Elem *R;

    //variaveis para armazenar os dados do arquivo
    int intA;
    int intB;
	char word[20];

    //declarar as auxiliares para remover
    Elem *prevR;
    Elem *valor = (Elem*)malloc(sizeof(Elem));

    //cria a lista vazia com os ENDEREÇOS dos ponteiros - passagem por referência altera o conteúdo original
    criaLista(&W, &R);

    //abrindo arquivo de entrada e saida
    FILE *arquivoL = fopen("lidos.dat", "w");
    FILE *arquivoP;
    if((arquivoP = fopen("pacotes.dat", "r"))== NULL)
    {
        printf("Não foi possível abrir o arquivo pacotes.dat\nFechando o programa...");
        fclose(arquivoP);
        return 0;
    }

    //percorre todo o arquivo fazendo leitura dos dados e copiando para as variaveis locais
    while(!feof(arquivoP))
    {
        fscanf(arquivoP, "%d %s %d\n", &intA, word, &intB);
        //printf("%d %s %d\n", intA, word, intB);

        //logo que aparecer a palavra NULL, já fechamos o programa
        if(strcmp(word, "NULL") == 0)   
        {        
            break;        
        }
        
        //Verificando qual operaçao será feita - 0: write, 1: read (remove)
        if(intA == 0)
        {
            //adiciona o elemento na lista
            addElemento(&W, &R, word, intB);
        }
        else
        {
            //guardamos a posiçao anterior ao ponteiro R (tail) na auxiliar prevR
            prevR = R;

            //armazena o elemento removido na variavel auxiliar valor
            rmvElemento(&W, &R, &valor);
            
            //ponteiro R nunca pode ser ultrapassado
            if(prevR != R)
            {
                //printamos no arquivo de saida
                fprintf(arquivoL, "%s\n", valor->pal);
            }
        }
    }	

    //fechando os arquivos
    fclose(arquivoP);        
    fclose(arquivoL);   

    //ao final, precisamos liberar a memoria alocada para o buffer circular
    //usamos passagem por referência pois precisa liberar a variável original e não apenas uma copia
    liberaBuffer(&W, &R);

	return 0;
}

//cria novo elemento
Elem *criaElemento(char pal[20], int urg)
{
    //alocamos dinamicamente a memoria para o novo elemento
    Elem *novo = (Elem*)malloc(sizeof(Elem));

    //copia todos os dados para a estrutura 
    strcpy(novo->pal, pal);
    novo->urg = urg;
    novo->prox = NULL;

    //ao fim, retornamos o endereço do novo elemento
    return novo;
}

//cria lista com todos os campos como 0
void criaLista(Elem **W, Elem **R)
{
    //inicializando as variaveis dos ponteiros como NULL
    int i;
    (*W) = NULL;
    (*R) = NULL;
    
    //preenche todos os campos da lista com 0
    for(i=0; i<N; i++)
    {
        preencheLista(W, R, criaElemento("0", 0));
    }
    //arruma os ponteiros de modo que a lista permaneça ligada
    (*R) = (*R)->prox;   
}

//preenche a lista com os valores indicados pelo vetor
void preencheLista(Elem **W, Elem **R, Elem *elemento)
{
    //preenche a lista com os novos elementos
    if(!(*W)) //lista vazia
    {
        //W e R começam apontando para o mesmo elemento
        (*W) = elemento;
        (*R) = elemento;

        //o proximo elemento de elemento é ele mesmo - deixa a lista circular, mesmo que ela tenha apenas 1 elemento
        elemento->prox = elemento;
    }
    else //lista não vazia
    {
        //arruma os ponteiros para que os novos elementos inseridos mantenham a circularidade 
        (*R)->prox = elemento;
        elemento->prox = (*W);
        (*R) = elemento;
    }
}

//operação de escrita (intA = 0)
void addElemento(Elem **W, Elem **R, char pal[20], int urg)
{
    //auxprox simula o próximo elemento de W, para que possamos prosseguir com o teste
    Elem *auxprox = (*W)->prox;
    
    //o ponteiro W nunca pode se encontrar com o ponteiro R - sempre uma posição antes
    if(auxprox == *R)
    {
        return; 
        //printf("\nLista cheia!"); //nao recebe mais elementos
    }

    //copia todos os dados para a estrutura
    strcpy((*W)->pal, pal);
    (*W)->urg = urg;
    (*W) = auxprox;
}

//operação de remoção/leitura (intA = 1)
void rmvElemento(Elem **W, Elem **R, Elem **removido)
{
    //inicializando as variáveis locais
    int i;
    int salto;

    //auxprox simula o próximo elemento de R - R não pode passar de W, mas pode ficar em cima
    Elem *auxprox = (*R)->prox;

    if(*R == *W) //caso os ponteiros R e W fiquem na mesma posição
    {
        return; 
    }
    
    //copia todos os dados do elemento removido na variavel removido
    strcpy((*removido)->pal, (*R)->pal);
    (*removido)->urg = (*R)->urg;
    (*removido)->prox = NULL;

    //caso o elemento lido seja do tipo PRTY, pulamos no máximo urg posiçoes
    if((strcmp((*R)->pal, "PRTY")) == 0)
    {
        //pega o tamanho do salto de PRTY 
        salto = (*R)->urg;
        for(i=0; i<salto; i++)
        {
            if(*R == *W) //caso os ponteiros R e W cheguem na mesma posição 
            {
                break;
            }
            //vai rodando com R
            (*R) = (*R)->prox;
        }
    }
    //caso não seja um elemento do tipo PRTY, fazemos a remoçao normal - ponteiro R anda uma posição
    else
    {
        (*R) = auxprox;
    }
}

//libera a memoria ocupada pelo buffer circular dinâmico
void liberaBuffer(Elem **W, Elem **R)
{
    //atual pega o valor de W
    Elem *atual = (*W);
    Elem *auxprox;

    //enquanto não ultrapassarmos o ponteiro W, podemos fazer a liberação - ponteiro R nao pode chegar no W
    while(atual->prox != (*W))
    {
        //auxprox permite que a memoria seja liberada sem desconectar a lista
        auxprox = atual->prox;
        free(atual);
        atual = auxprox;
    }
    //saindo do while, setamos W e R como NULL
    (*W) = NULL;
    (*R) = NULL;
}
