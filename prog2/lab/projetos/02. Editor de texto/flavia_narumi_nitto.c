#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define max 1501 //tamanho maximo do texto em um arquivo 

//prototipo das funcoes
void criaArquivo(FILE *arquivo, FILE *nomes, char nomeArquivo[25]);
void excluirArquivo(FILE *arquivo, char *excluir);
char *substituiPalavras(char *texto, char *antiga, char *substituir);
void buscaSimples(char *palavra, char *texto);
void printaTexto(FILE *arquivo, char *imprimir);

void criaArquivo(FILE *arquivo, FILE *nomes, char nomeArquivo[25])
{
	int tam;
	char texto[max];	
	
	//criando o arquivo com o nome escolhido
	arquivo = fopen(nomeArquivo, "w");
	
	//salvando o nome em um arquivo com os nomes
	nomes = fopen("nomes.txt", "a");
	//fseek(nomes, 0, SEEK_SET);
	fprintf(nomes, "%s\n", nomeArquivo);
			
	//escrevendo no arquivo
	printf("\nEscreva o texto de no maximo 1.500 caracteres \n(pressione Enter para terminar a escrita): ");
	scanf(" %[^\n]s", texto);
	//setbuf(stdin, NULL);
	tam = strlen(texto);
	if(tam<max)
	{
		fprintf(arquivo, "%s", texto);
		printf("\ntexto inteiro: \n%s", texto);		
	}
	else
	{
		printf("\nAVISO: texto ultrapassou o limite de caracteres!\n");
		printf("Confira ate onde o texto foi salvo: \n%s", texto);
		fprintf(arquivo, "%s", texto);
	}
	
	fclose(arquivo);
	fclose(nomes);	
}

//funcao vai apagar todas as informacoes do arquivo escolhido
void excluirArquivo(FILE *arquivo, char *excluir)
{
	int opExcluir;	
	
	printf("Tem certeza que deseja excluir o o arquivo [%s] inteiro?", excluir);
	printf("\n\t0- Nao\t\t1-Sim\nOpcao: ");
	scanf("%d", &opExcluir);
	switch(opExcluir)
	{
		case 1:
		{
			arquivo = fopen(excluir, "w");
			fprintf(arquivo, "[conteudo excluido]");
			//remove(excluir);
			printf("\nArquivo [%s] excluido!", excluir); 				
			fclose(arquivo);
		} break;
		case 0: printf("\nRetornando ao menu...\n\n"); break;
	}
}

//funcao para substituir as palavras na busca com substituicao 
char *substituiPalavras(char *texto, char *antiga, char *substituir)
{
	int i, cont=0;
	int tamS, tamA;
	char *textoFinal;
	tamS = strlen(substituir);
	tamA = strlen(antiga);
	
	//contando quantas vezes a palavra aparece
	for(i=0; texto[i]!='\0'; i++)
	{
		if(strstr(&texto[i], antiga) == &texto[i])
		{
			cont++;
			i += tamA-1;
		}
	}
	textoFinal = (char*)malloc(i+cont *(tamS-tamA)+1);
	
	i=0;
	while(*texto)
	{
		//comparando a palavra com o texto inteiro
		if(strstr(texto, antiga) == texto)
		{
			strcpy(&textoFinal[i], substituir);
			i += tamS;
			texto += tamA;
		}
		else
			textoFinal[i++] = *texto++;
	}
	
    //retorna o texto inteiro, ja modificado
	textoFinal[i] = '\0';
	return textoFinal;
}

//funcao para fazer a busca simples (metodo da força bruta) no texto do arquivo desejado
void buscaSimples(char *palavra, char *texto)
{
	int i, j;
	int tamP; 
	int tamT;
	tamP = strlen(palavra);
	tamT = strlen(texto);
	for(i=0; i<=tamT-tamP; i++)
	{
		for(j=0; j<tamP; j++)
		{
            //nao encontrou nenhuma ocorrencia no texto
			if(texto[i+j] != palavra[j])
			{
				break;
			}
		}
		//mostrando todas as ocorrencias encontradas
		if(j==tamP)
		{
			printf("Encontramos a palavra [%s] no indice [%d]\n", palavra, i);
		}
	}
}

//funcao para facilitar a impressao do texto inteiro do arquivo desejado
void printaTexto(FILE *arquivo, char *imprimir)
{
	arquivo = fopen(imprimir, "r");
	char auxprintaT[max];
	while(!feof(arquivo))
	{
		fscanf(arquivo, "%[^\n]s", auxprintaT);
		printf("\ntexto do arquivo %s: \n%s", imprimir, auxprintaT);
	}
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;

    //variaveis criar novo arquivo
    FILE *arquivo;
    FILE *nomes; //arquivo com os nomes dos arquivos
    char nomeArquivo[25];

    //variaveis editar arquivo
    int tamEditar, tamDisponivel;
    char nomeEditar[25]; 
    char auxEditar[max];

    //variaveis excluir arquivo
    char nomeExclui[25];

    //variaveis busca com substituicao
    char antiga[20], substituir[20], nomeBuscaSubs[25];
    char auxSubstituir[max];
    char *textoFinal = NULL;

    //variaveis busca simples
    char nomeBusca[25], palavra[20];
    char auxTexto[max];    

    do
    {
        printf("\n_________________________________________________");
        printf("\n\t\tMENU DE OPCOES");
        printf("\n_________________________________________________");
        printf("\n   1- Criar novo arquivo"); //cria e ja começa a escrever
        printf("\n   2- Editar arquivo"); 
        printf("\n   3- Excluir arquivo"); //escolhe qual arquivo excluir
        printf("\n   4- Busca e substituicao no arquivo");
        printf("\n   5- Busca simples no arquivo");
        printf("\n   0- Fecha o programa");
        printf("\n=================================================\n Opcao: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                //cria novo arquivo e ja comeca a escrever nele
		        printf("\n\n___________________________________________");
		        printf("\n\tCriando novo arquivo");
		        printf("\n___________________________________________");

                //escolhe o nome do arquivo 
                printf("\nDigite o nome do arquivo a ser criado: ");
                scanf(" %[^\n]s", nomeArquivo);

                //abrindo arquivos
                arquivo = fopen(nomeArquivo, "w");
                nomes = fopen("nomes.txt", "a");

                //chamada da funcao criaArquivo() - ela cria e ja começa a escrever
                criaArquivo(arquivo, nomes, nomeArquivo);   

                fclose(nomes);
                fclose(arquivo);

            }break;

            case 2:
            {
                //edita o arquivo e coloca o novo trecho no final do texto ja existente
		        printf("\n\n___________________________________________");
		        printf("\n\tEditando arquivo");
		        printf("\n___________________________________________");
                
                //escolhemos qual arquivo abrir para editar
                printf("\nDigite o nome do arquivo a ser editado: ");
                scanf("%[^\n]s", nomeEditar);
                
                //passando as informacoes para uma variavel local
                arquivo = fopen(nomeEditar, "r+");
                while(!feof(arquivo))
                {
                    fscanf(arquivo, "%[^\n]s", auxEditar);
                }	
                fclose(arquivo);
                
                //mostra o texto todo para o usuario
				printf("Conteudo de [%s]: \n%s", nomeEditar, auxEditar);
                
                //calculando o tamanho disponivel no arquivo, lembrando que o tamanho max sao 1500 caracteres
                tamEditar = strlen(auxEditar);
                //printf("\ntamanho editar: %d", tamEditar);
                tamDisponivel = max-tamEditar-1;
                
                //cria uma variavel com o tamanho disponivel e escrevemos nela
                char novoTrecho[tamDisponivel];
                printf("\nEscreva o novo trecho de texto (no maximo %d caracteres): ", tamDisponivel);
                scanf(" %[^\n]s", novoTrecho);
                
                //concatena ambos textos e imprime como ficou o texto finalizado
                strcat(auxEditar, novoTrecho);
                printf("\nMostrando o arquivo inteiro agora: %s", auxEditar);
                
                //salvamos as alteracoes no arquivo
                arquivo = fopen(nomeEditar, "w");
                fprintf(arquivo, "%s", auxEditar);
                
                fclose(arquivo);

            }break;

            case 3:
            {
                //perguntar se quer realmente excluir o arquivo inteiro
		        printf("\n\n___________________________________________");
		        printf("\n\tExcluindo arquivo");
		        printf("\n___________________________________________");

                //escolhemos qual arquivo vai ter seus dados deletados
                printf("\nDigite o nome do arquivo a ser deletado: ");
                scanf(" %[^\n]s", nomeExclui);

                //abre o arquivo e chama a funcao que deleta os dados
                arquivo = fopen(nomeExclui, "r+");	
                excluirArquivo(arquivo, nomeExclui);

                fclose(arquivo);

            }break;            
            
            case 4:
            {
                //busca com substituicao - escolhe o arquivo e as palavras que eu quero trocar
		        printf("\n\n___________________________________________");
		        printf("\n\tBusca com substituicao no arquivo");
		        printf("\n___________________________________________");

                //escolhemos qual arquivo vai ser buscado e editado 
                printf("\nDigite o nome do arquivo a ser buscado: ");
                scanf("%[^\n]s", nomeBuscaSubs);

                //passa os dados do arquivo para uma variavel local
                arquivo = fopen(nomeBuscaSubs, "r+");
                while(!feof(arquivo))
                {
                    fscanf(arquivo, "%[^\n]s", auxSubstituir);
                }
                fclose(arquivo);
                
                //mostra o conteudo do arquivo para o usuario
                printf("Conteudo de [%s]: \n%s", nomeBuscaSubs, auxSubstituir);   
                
                //entrada dos dados 
				printf("\n\nDigite a palavra a ser trocada: ");
                scanf(" %[^\n]s", antiga);	
                printf("\nDigite a palavra a ser escrita em seu lugar: ");
                scanf(" %[^\n]s", substituir);	
                
                //chamada da funcao que faz a substituicao das palavras no texto e imprimimos o resultado na tela
                textoFinal = substituiPalavras(auxSubstituir, antiga, substituir);
                printf("\nTexto final: \n%s", textoFinal);
                
                //salvamos as alteracoes no arquivo 
                arquivo = fopen(nomeBuscaSubs, "w");
                fprintf(arquivo, "%s", textoFinal);
                
                fclose(arquivo);
                free(textoFinal);

            }break;

            case 5:
            {
                //busca simples - escolhe o arquivo e a palavra que eu quero encontrar - mostra todas as ocorrencias
		        printf("\n\n___________________________________________");
		        printf("\n\tBusca simples no arquivo");
		        printf("\n___________________________________________");
                //nomes = fopen("nomes.txt", "r"); //o intuito era mostrar o nome de todos os arquivos disponiveis

                //escolhemos o arquivo que vai ser buscado                    
                printf("\nDigite o nome do arquivo a ser buscado: ");
                scanf(" %[^\n]s", nomeBusca);
                
                //mostra todo o conteudo do arquivo escolhido para o usuario
                printaTexto(arquivo, nomeBusca);
                
                //entrada de dados
                printf("\nDigite a palavra a ser buscada: ");
                scanf(" %[^\n]s", palavra);
                
                //abre o arquivo e busca a palavra desejada por meio da funcao buscaSimples
                arquivo = fopen(nomeBusca, "r+");
                while(!feof(arquivo))
                {
                    fscanf(arquivo, "%[^\n]s", auxTexto);
                    buscaSimples(palavra, auxTexto);
                }

                //fclose(nomes);	
                fclose(arquivo);                

            }break;

            case 0:
            {
                //como salvamos a cada interação, todos os dados ja estao salvos
                printf("\nSalvando alteracoes e fechando o programa..."); 
                return 0;
            }break;            
        }
    }while (op != 0);
    
    return 0;
}