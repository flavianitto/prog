//Flavia Narumi Nitto (RA: 201040743)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//declarando as variaveis globais
int tabuleiro[33];
int contador; 

//declarando os prototipos das funcoes
void imprimir(int N);
int verificador(int linha, int coluna);
void backtracking(int N, int linha);

int main(void)
{
    int N;

    //abrindo e salvando o arquivo rainha.out
    FILE *arquivo;
    arquivo = fopen("rainha.out", "w");
    fprintf(arquivo, "\n"); //colocar varios caracteres em branco 20/30
    fclose(arquivo);

    //entrada de N
    printf(" Insira N: ");
    scanf("%d", &N);

    //abrindo o arquivo no modo r+
    arquivo = fopen("rainha.out", "r+");

    //fazendo a chamada do backtracking
    backtracking(N, 1);

    //seta o ponteiro para o começo do arquivo
    fseek(arquivo, 0, SEEK_SET);
    
    //mostra o total de soluções encontradas
    fprintf(arquivo, "%d", contador);
    
    //fecha o arquivo
    fclose(arquivo);    

    return 0;
}

//funcao para imprimir o tabuleiro
void imprimir(int N)
{
    int i, j;

    //abrindo o arquivo no modo append
    FILE *arquivo;
    arquivo = fopen("rainha.out", "a");
    fprintf(arquivo, "\n\n");

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            //verifica a posição (i,j)
            if(tabuleiro[i] == j)
            {
                fprintf(arquivo, "1 "); //ponto com rainha
            }
            else
            {
                fprintf(arquivo, "0 "); //ponto sem rainha
            }
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

//funcao para saber se podemos ou nao posicionar a rainha
int verificador(int linha, int coluna)
{
    int i;
    
    //verifica rainhas na mesma coluna e na mesma diagonal
    for(i=1; i<=linha-1; i++)
    {
        if(tabuleiro[i] == coluna) //mesma coluna
        {
            return 0;
        }
        else
        {
            //abs é o valor absoluto do numero (sempre positivo)
            if(abs(tabuleiro[i]-coluna) == abs(i-linha)) //mesma diagonal (olha para ambos os lados)
            {
                return 0;
            }
        }
    }
    //caso nao tenha rainhas na mesma coluna nem na mesma diagonal, podemos inserir
    return 1;
}

//funcao para colocar a rainha no tabuleiro e checar as solucoes (uso do backtracking)
void backtracking(int N, int linha)
{
    int j;

    for(j=1; j<=N; j++)
    {
        if(verificador(linha, j))
        {
            //coloca a rainha onde é seguro
            tabuleiro[linha] = j;
            
            //se chegou ao final do tabuleiro, podemos imprimir
            if(linha == N)
            {
                imprimir(N);
                contador++;
            }
            //se nao, fazemos a chamada recursiva da funcao backtracking
            else
            {
                backtracking(N, linha+1);
            }
        }
    }
}
