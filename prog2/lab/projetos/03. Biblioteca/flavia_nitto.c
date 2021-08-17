#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxU 10 //tamanho max de usuarios
#define maxL 100 //tamanho max de livros - cada usuario pode pegar no max 10 livros

//estruturas
typedef struct sdata
{
	int dia;
	int mes;
	int ano;	
	int invertida;
}Sdata;

typedef struct livro
{
	char titulo[30];
	char idLivro[10];
	char autor[20];
	char editora[20];
	Sdata data;
	int dataDev[maxL];
}Livro;

typedef struct usuario
{
	char nome[30];
	char id[10];
	char curso[30];
	Livro registroL[maxL]; 
}Usuario;

typedef struct reserv
{
	char rNome[30];
	char rTitulo[30];
	int rdia, rmes, rano;
	int rInvertida;
}Reserved;

Usuario registroU[maxU];

//prototipos
void criarUsuario();
void criarLivro();
void reservaLivro();
void devolveLivro(char devolveNome[30], char devolveTitulo[30]);
void mostraUsuario();
void mostraLivro();
void mostraReservado();
int inverteData(int dd, int mm, int aaaa);
void insertionSort(int vetor[], int n);
void mostraInsertionCresc(int vetor[], int n);
void mostraInsertionDecresc(int vetor[], int n);
void consultaCrescente();
void consultaDecrescente();
void deletaUsuario(char apagar[30]);
void deletaLivro(char apagar[30]);

int main()
{
	int op;

    do
    {
        puts("\n_________________________________________________");
        printf("\n\t\tSISTEMA BIBLIOTECA");
        puts("\n_________________________________________________");
        printf("\n   1- Cadastrar novo usuario"); 
        printf("\n   2- Cadastrar novo livro"); 
        printf("\n   3- Reservar livro"); //o livro e usuario tem que existir
        printf("\n   4- Devolver livro"); //o livro tem que ter sido reservado - dar baixa na ficha do aluno
        printf("\n   5- Consultar datas de devolucao (crescente)"); //mostra o numero de livros e usuarios total - ordenar pela data de devolucao
        printf("\n   6- Consultar datas de devolucao (decrescente)"); //mostra o numero de livros e usuarios total
        printf("\n   7- Deletar usuario"); //mostra todos os usuarios e quantos tem
        printf("\n   8- Deletar livro"); //mostra todos os livros e quantos tem
		printf("\n   9- Informacoes sobre o sistema da biblioteca");
        printf("\n   0- Fecha o programa");
        printf("\n=================================================\n Opcao: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: 
            {
                //cadastrar novo usuario - mostra quais usuarios ja existem
                mostraUsuario();
				puts("\n_________________________________________________");
		        puts("\tCadastrando novo usuario");
		        puts("_________________________________________________");

				criarUsuario();
            }break;            
            
            case 2: 
            {
                //cadastrar novo livro - mostra quais livros ja existem
				mostraLivro();      
				          
				puts("\n_________________________________________________");
		        puts("\tCadastrando novo livro");
		        puts("_________________________________________________");

                criarLivro();
            }break;
            
            case 3: 
            {
                //reservar livro
                //mostrar usuarios e livros ja cadastrados
				//considerando que os valores lidos existam nos arquivos
                mostraUsuario();
				mostraLivro();
				mostraReservado();
								
				puts("\n_________________________________________________");
		        puts("\tReservando livro");
		        puts("_________________________________________________");

				reservaLivro();
				
            }break;
            
            case 4: 
            {
				//variaveis para devolver livro
				char devolveNome[30], devolveTitulo[30];
				int opDevolve;

                //devolver livro - mostrar usuarios e livros ja cadastrados
				mostraUsuario();
				mostraLivro();
				mostraReservado();
				puts("\n_________________________________________________");
		        puts("\tDevolvendo livro");
		        puts("_________________________________________________");

				printf("Digite o nome do usuario a devolver o livro: ");
				scanf(" %[^\n]s", devolveNome);				
				printf("Digite o nome do livro a ser devolvido: ");
				scanf(" %[^\n]s", devolveTitulo);
				printf("\nTem certeza que deseja devolver o livro %s?", devolveTitulo);
				printf("\n\t0- Nao\n\t1-Sim\nOpcao: ");
				scanf("%d", &opDevolve);
				switch(opDevolve)
				{
					case 1:
					{
						devolveLivro(devolveNome, devolveTitulo);
						printf("\n%s devolveu o livro %s!", devolveNome, devolveTitulo);
					}break;

					case 0:  printf("\nRetornando ao menu...");  break;
				}
            }break;
                        
            case 5:
            {
                //consulta crescente - mais recente primeiro
				//so printa na tela
				mostraReservado();
				puts("\n_________________________________________________");
		        puts("\tConsulta crescente");
		        puts("_________________________________________________");				
				consultaCrescente();

            }break;

            case 6: 
            {
                //consulta decrescente - mais antigo primeiro 
				//pega do arquivo e ordena no local p printar
				mostraReservado();
				puts("\n_________________________________________________");
		        puts("\tConsulta decrescente");
		        puts("_________________________________________________");
				consultaDecrescente();

            }break;

            case 7: 
            {
				//variaveis para deletar usuario
				char apagarNome[30];
				int opUsuario;

                //deletar usuario - pergunta se tem certeza
				mostraUsuario();
				puts("\n_________________________________________________");
		        puts("\tDeletando usuario");
		        puts("_________________________________________________");

				printf("Digite o nome do usuario a ser apagado: ");
				scanf(" %[^\n]s", apagarNome);
				printf("\nTem certeza que deseja deletar o usuario %s?", apagarNome);
				printf("\n\t0- Nao\n\t1-Sim\nOpcao: ");
				scanf("%d", &opUsuario);
				switch(opUsuario)
				{
					case 1:
					{
						deletaUsuario(apagarNome);
						printf("\nUsuario apagado do sistema!");
					}break;

					case 0:  printf("\nRetornando ao menu...");  break;
				}

            }break;
                        
            case 8: 
            {
				//variaveis para deletar livro
				char apagarTitulo[30];
				int opLivro;

                //deletar livro - pergunta se tem certeza 
				mostraLivro();
				puts("\n_________________________________________________");
		        puts("\tDeletando livro");
		        puts("_________________________________________________");

				printf("Digite o titulo do livro a ser apagado: ");
				scanf(" %[^\n]s", apagarTitulo);
				printf("\nTem certeza que deseja deletar o livro %s?", apagarTitulo);
				printf("\n\t0- Nao\n\t1-Sim\nOpcao: ");
				scanf("%d", &opLivro);
				switch(opLivro)
				{
					case 1:
					{
						deletaLivro(apagarTitulo);
						printf("\nLivro apagado do sistema!");
					}break;

					case 0:  printf("\nRetornando ao menu...");  break;
				}
			}break;

			case 9:
			{
				//informacoes sobre o sistema da biblioteca
				puts("\n_________________________________________________");
		        puts("\tInformacoes sobre o sistema");
		        puts("_________________________________________________");
				printf("\n 1) O sistema consegue armazenar no maximo %d usuarios", maxU);
				printf("\n 2) O sistema consegue armazenar no maximo %d livros", maxL);
				printf("\n 3) Cada usuario pode pegar no maximo %d livros", maxL/maxU);
				printf("\n 4) Reservar apenas livros cadastrados para usuarios cadastrados");
				printf("\n 5) Deletar apenas livros e usuarios que estejam cadastrados");
				printf("\n 6) Nao cadastrar mais usuarios que o tamanho permitido");
				printf("\n 7) Nao cadastrar mais livros que o tamanho permitido");
			}break;

            case 0: 
            {
                //fechando o programa
                printf("\nFechando o sistema da biblioteca...");
                return 0;
            }break;                     
        }
    }while(op!=0);

	return 0;	
}

void criarUsuario()
{
	//criando usuario
	int tamArquivoU;
	Usuario auxU;
	FILE *arquivoU = fopen("usuarios.txt", "a");
	fseek(arquivoU, 0, SEEK_END);
	tamArquivoU = ftell(arquivoU);

	//entrada de dados
	printf("Insira o nome: ");
	scanf(" %[^\n]s", auxU.nome);
	printf("Insira o ID: ");
	scanf(" %[^\n]s", auxU.id);
	printf("Insira o curso: ");
	scanf(" %[^\n]s", auxU.curso);

	if(tamArquivoU == 0) //fazendo isso, a ultima linha do arquivo nao fica vazia
	{
		fprintf(arquivoU, "%s\n", auxU.nome);
		fprintf(arquivoU, "%s\n", auxU.id);
		fprintf(arquivoU, "%s", auxU.curso);
	}
	else
	{
		//printf("\ncriando usuario...");
	
		fprintf(arquivoU, "\n%s\n", auxU.nome);
		fprintf(arquivoU, "%s\n", auxU.id);
		fprintf(arquivoU, "%s", auxU.curso);		
	}
	fclose(arquivoU);
}

void criarLivro()
{
	//criando livro 
	int tamArquivoL;
	Livro auxL;
	
	FILE *arquivoL = fopen("livros.txt", "a");
	fseek(arquivoL, 0, SEEK_END);
	tamArquivoL = ftell(arquivoL);	

	//entrada de dados
	printf("Insira o titulo: ");
	scanf(" %[^\n]s", auxL.titulo);
	printf("Insira o ID do livro: ");
	scanf(" %[^\n]s", auxL.idLivro);
	printf("Insira o nome do(a) autor(a): ");
	scanf(" %[^\n]s", auxL.autor);
	printf("Insira o nome da editora: ");
	scanf(" %[^\n]s", auxL.editora);
	
	//fazendo esse procedimento, nao temos uma linha vazia no final
	if(tamArquivoL == 0)
	{
		fprintf(arquivoL, "%s\n", auxL.titulo);
		fprintf(arquivoL, "%s\n", auxL.idLivro);
		fprintf(arquivoL, "%s\n", auxL.autor);
		fprintf(arquivoL, "%s", auxL.editora);		
	}
	else
	{
		fprintf(arquivoL, "\n%s\n", auxL.titulo);
		fprintf(arquivoL, "%s\n", auxL.idLivro);
		fprintf(arquivoL, "%s\n", auxL.autor);
		fprintf(arquivoL, "%s", auxL.editora);				
	}

	fclose(arquivoL);
}

int inverteData(int dd, int mm, int aaaa)
{
	//calculo para transformar a data dd mm aaaa em aaaammdd
	int dataInvertida;
	dataInvertida = aaaa*10000 + mm*100 + dd;
	return dataInvertida;
}

void reservaLivro()
{
	//reservando livro
	int tamArquivoR;
	FILE *arquivoR = fopen("reservados.txt", "a");
	fseek(arquivoR, 0, SEEK_END);
	tamArquivoR = ftell(arquivoR);
	
	//variaveis auxiliares
	char auxNome[30];
	char auxTitulo[30];
	Sdata auxD;
	
	//entrada de dados
	printf("Insira o nome do usuario: ");
	scanf(" %[^\n]s", auxNome);
	printf("Insira o titulo do livro: ");
	scanf(" %[^\n]s", auxTitulo);
	printf("Insira a data de devolucao no formato: dd mm aaaa: ");
	scanf("%d %d %d", &auxD.dia, &auxD.mes, &auxD.ano);
	auxD.invertida = inverteData(auxD.dia, auxD.mes, auxD.ano);
	
	//fazendo esse procedimento, impedimos que a ultima linha do arquivo fique em branco
	if(tamArquivoR == 0)
	{
		fprintf(arquivoR, "%s\n", auxNome);
		fprintf(arquivoR, "%s\n", auxTitulo);
		fprintf(arquivoR, "%d %d %d\n", auxD.dia, auxD.mes, auxD.ano);
		fprintf(arquivoR, "%d", auxD.invertida);
	}
	else
	{
		fprintf(arquivoR, "\n%s\n", auxNome);
		fprintf(arquivoR, "%s\n", auxTitulo);
		fprintf(arquivoR, "%d %d %d\n", auxD.dia, auxD.mes, auxD.ano);		
		fprintf(arquivoR, "%d", auxD.invertida);
	}
	fclose(arquivoR);
}

void devolveLivro(char devolveNome[30], char devolveTitulo[30])
{
	FILE *arquivoR = fopen("reservados.txt", "r");
	int i=0, j=0; 
	char auxNome[30], auxTitulo[30];
	int auxDia, auxMes, auxAno, auxInvertido;
	Reserved auxR[maxL];
	
	do
	{
		fscanf(arquivoR, " %[^\n]s", auxNome);
		fscanf(arquivoR, " %[^\n]s", auxTitulo);
		fscanf(arquivoR, "%d %d %d\n", &auxDia, &auxMes, &auxAno);
		fscanf(arquivoR, "%d", &auxInvertido);
		
		//verifica se o nome e o titulo digitado existem
		if(strcmp(auxNome, devolveNome) != 0 && strcmp(auxTitulo, devolveTitulo) != 0)
		{
			strcpy(auxR[i].rNome, auxNome);
			strcpy(auxR[i].rTitulo, auxTitulo);
			auxR[i].rdia = auxDia;
			auxR[i].rmes = auxMes;
			auxR[i].rano = auxAno;
			auxR[i].rInvertida = auxInvertido;

			i++;
		}
	}while(!feof(arquivoR));
	fclose(arquivoR);

	//abrindo o arquivo novamente, mas em modo w para apagar o elemento desejado
	FILE *aux = fopen("reservados.txt", "w");
	for(j=0; j<i; j++)
	{
		if(j==0) //com isso, o arquivo nao fica com uma linha vazia no final
		{
			fprintf(aux, "%s\n", auxR[j].rNome);
			fprintf(aux, "%s\n", auxR[j].rTitulo);
			fprintf(aux, "%d %d %d\n", auxR[j].rdia, auxR[j].rmes, auxR[j].rano);
			fprintf(aux, "%d", auxR[j].rInvertida);			
		}
		else
		{
			fprintf(aux, "\n%s\n", auxR[j].rNome);
			fprintf(aux, "%s\n", auxR[j].rTitulo);
			fprintf(aux, "%d %d %d\n", auxR[j].rdia, auxR[j].rmes, auxR[j].rano);
			fprintf(aux, "%d", auxR[j].rInvertida);						
		}
	}
	fclose(aux);
}

void deletaUsuario(char apagar[30])
{
	//deletando usuario
	FILE *arquivoU = fopen("usuarios.txt", "r");
	int i=0, j=0;
	char auxNome[30], auxId[10], auxCurso[30];
	Usuario auxU[maxU];

	do
	{
		fscanf(arquivoU, " %[^\n]s", auxNome);
		fscanf(arquivoU, " %[^\n]s", auxId);
		fscanf(arquivoU, " %[^\n]s", auxCurso);
		
		//verifica se o nome digitado existe no arquivo
		if(strcmp(auxNome, apagar) != 0)
		{
			strcpy(auxU[i].nome, auxNome);
			strcpy(auxU[i].id, auxId);
			strcpy(auxU[i].curso, auxCurso);
			i++;
		}
	
	}while(!feof(arquivoU));
	fclose(arquivoU);
	
	//abrindo o mesmo arquivo, mas agora em modo w para apagar o usuario desejado
	FILE *aux = fopen("usuarios.txt", "w");
	
	for(j=0; j<i; j++)
	{
		if(j==0) //para que a ultima linha nao fique vazia
		{
			fprintf(aux, "%s\n", auxU[j].nome);
			fprintf(aux, "%s\n", auxU[j].id);
			fprintf(aux, "%s", auxU[j].curso);			
		}
		else
		{
			fprintf(aux, "\n%s\n", auxU[j].nome);
			fprintf(aux, "%s\n", auxU[j].id);
			fprintf(aux, "%s", auxU[j].curso);			
		}
	}
	fclose(aux);
	
}

void deletaLivro(char apagar[30])
{
	//deletando livro
	FILE *arquivoL = fopen("livros.txt", "r");
	int i=0, j=0;
	char auxTitulo[30], auxIdLivro[10], auxAutor[20], auxEditora[20];
	Livro auxL[maxL];

	do
	{
		fscanf(arquivoL, " %[^\n]s", auxTitulo);
		fscanf(arquivoL, " %[^\n]s", auxIdLivro);
		fscanf(arquivoL, " %[^\n]s", auxAutor);
		fscanf(arquivoL, " %[^\n]s", auxEditora);

		//verifica se o titulo digitado existe no arquivo de livros
		if(strcmp(auxTitulo, apagar) != 0)
		{
			strcpy(auxL[i].titulo, auxTitulo);
			strcpy(auxL[i].idLivro, auxIdLivro);
			strcpy(auxL[i].autor, auxAutor);
			strcpy(auxL[i].editora, auxEditora);

			i++;
		}
	}while(!feof(arquivoL));
	fclose(arquivoL);
	
	//abrindo o mesmo arquivo, mas agora em modo w para apagar o livro desejado
	FILE *aux = fopen("livros.txt", "w");
	
	for(j=0; j<i; j++)
	{
		if(j==0) //para evitar que a ultima linha fique vazia
		{
			fprintf(aux, "%s\n", auxL[j].titulo);
			fprintf(aux, "%s\n", auxL[j].idLivro);
			fprintf(aux, "%s\n", auxL[j].autor);
			fprintf(aux, "%s", auxL[j].editora);
		}
		else
		{
			fprintf(aux, "\n%s\n", auxL[j].titulo);
			fprintf(aux, "%s\n", auxL[j].idLivro);
			fprintf(aux, "%s\n", auxL[j].autor);
			fprintf(aux, "%s", auxL[j].editora);			
		}
	}
	fclose(aux);
	
}

void insertionSort(int vetor[], int n)
{
	//algoritmo de ordenacao insertion sort
	int aux, i, j;
	for(i=1; i<n; i++)
	{
		aux = vetor[i];
		j = i-1;
		while(j>=0 && vetor[j]>aux)
		{
			vetor[j+1] = vetor[j];
			j = j-1;
		}
		vetor[j+1] = aux;
	}
}

void mostraInsertionCresc(int vetor[], int n)
{
	//printa o vetor ordenado no formato de data correto
	int i;
	int auxDia[n], auxMes[n], auxAno[n];
	
	for(i=0; i<n; i++)
	{
		auxAno[i] = vetor[i]/10000;
		auxMes[i] = vetor[i]/100 - auxAno[i]*100;	
		auxDia[i] = vetor[i] - (auxAno[i]*10000 + auxMes[i]*100);
			
		printf("\nData: %d / %d / %d", auxDia[i], auxMes[i], auxAno[i]);
		//printf("\nvetor cresc[%d]: %d", i, vetor[i]);
	}
}

void mostraInsertionDecresc(int vetor[], int n)
{
	//printa o vetor ordenado no formato de data correto
	int i;
	int auxDia[n], auxMes[n], auxAno[n];
	for(i=n-1; i>=0; i--)
	{
		auxAno[i] = vetor[i]/10000;
		auxMes[i] = vetor[i]/100 - auxAno[i]*100;	
		auxDia[i] = vetor[i] - (auxAno[i]*10000 + auxMes[i]*100);		
		printf("\nData: %d / %d / %d", auxDia[i], auxMes[i], auxAno[i]);
		//printf("\nvetor decres[%d]: %d", i, vetor[i]);
	}
}

void consultaCrescente()
{
	FILE *arquivoR = fopen("reservados.txt", "r");

	//variaveis auxiliares
	Livro auxD[maxL];
	Sdata auxS[maxL];

	char auxNome[30];
	int tamArquivoR, i=0; 

	fseek(arquivoR, 0, SEEK_END);
	tamArquivoR = ftell(arquivoR);
	
	if((arquivoR = fopen("reservados.txt", "r"))==NULL || tamArquivoR==0)
	{
		printf("Arquivo [reservados.txt] vazio!");
	}
	else
	{
		//recebendo valores do arquivo reservados.txt
		while(!feof(arquivoR))
		{
			fscanf(arquivoR, " %[^\n]s", auxNome);
			fscanf(arquivoR, " %[^\n]s", auxD[i].titulo);
			fscanf(arquivoR, "%d %d %d\n", &auxS->dia, &auxS->mes, &auxS->ano);
			fscanf(arquivoR, "%d\n", &auxD->dataDev[i]);

			//mostramos todos os dados dentro do arquivo	
			printf("\nNome[%d]: %s\n", i, auxNome);
			printf("Livro[%d]: %s\n", i, auxD[i].titulo);
			printf("Data[%d]: %d / %d / %d\n", i, auxS->dia, auxS->mes, auxS->ano);
			
			i++;
		}
		//mostrando as datas de devolucao em ordem crescente
		printf("\nOrdem crescente: ");
		insertionSort(auxD->dataDev, i);
		mostraInsertionCresc(auxD->dataDev, i);		
	}
	fclose(arquivoR);
}

void consultaDecrescente()
{
	FILE *arquivoR = fopen("reservados.txt", "r");

	//variaveis auxiliares
	Livro auxD[maxL];
	Sdata auxS[maxL];

	char auxNome[30];
	int tamArquivoR, i=0; 

	fseek(arquivoR, 0, SEEK_END);
	tamArquivoR = ftell(arquivoR);
	
	if((arquivoR = fopen("reservados.txt", "r"))==NULL || tamArquivoR==0)
	{
		printf("Arquivo [reservados.txt] vazio!");
	}
	else
	{
		//recebendo os dados do arquivo reservados.txt 
		while(!feof(arquivoR))
		{
			fscanf(arquivoR, " %[^\n]s", auxNome);
			fscanf(arquivoR, " %[^\n]s", auxD[i].titulo);
			fscanf(arquivoR, "%d %d %d\n", &auxS->dia, &auxS->mes, &auxS->ano);
			fscanf(arquivoR, "%d\n", &auxD->dataDev[i]);
			
			//printando os valores encontrados dentro do arquivo - menos o formato de data usado na ordenacao
			printf("\nNome[%d]: %s\n", i, auxNome);
			printf("Livro[%d]: %s\n", i, auxD[i].titulo);
			printf("Data[%d]: %d / %d / %d\n", i, auxS->dia, auxS->mes, auxS->ano);
			
			i++;	
		}
		//mostrando o vetor de datas de devolucao de forma decrescente
		printf("\nOrdem decrescente: ");
		insertionSort(auxD->dataDev, i);
		mostraInsertionDecresc(auxD->dataDev, i);		
	}
	fclose(arquivoR);
}

void mostraUsuario()
{
	//mostrando arquivo usuarios.txt
	FILE *arquivoU = fopen("usuarios.txt", "r");
	
	//variaveis auxiliares
	Usuario auxU;
	int tamArquivoU, i=0;

	fseek(arquivoU, 0, SEEK_END);
	tamArquivoU = ftell(arquivoU);	
	
	puts("\n-------------------------------------------------");
    puts("\tConteudo de usuarios.txt");
    puts("-------------------------------------------------");	
	
	if((arquivoU = fopen("usuarios.txt", "r"))==NULL || tamArquivoU==0)
	{
		printf("\tArquivo [usuarios.txt] vazio!");
	}
	else
	{
		//lendo o arquivo e printando todos os valores encontrados
		while(!feof(arquivoU)) 
		{
			fscanf(arquivoU, " %[^\n]s", auxU.nome);
			fscanf(arquivoU, " %[^\n]s", auxU.id);
			fscanf(arquivoU, " %[^\n]s", auxU.curso);
			
			printf("\n\tNome[%d]: %s\n", i, auxU.nome);
			printf("\tId[%d]: %s\n", i, auxU.id);
			printf("\tCurso[%d]: %s\n", i, auxU.curso);
			
			i++;
		}		
		fclose(arquivoU);
	}
    //puts("-------------------------------------------------");	
}

void mostraLivro()
{
	//mostrando arquivo livros.txt
	FILE *arquivoL = fopen("livros.txt", "r");

	//variaveis auxiliares
	Livro auxL;
	int tamArquivoL, i=0;
	
	fseek(arquivoL, 0, SEEK_END);
	tamArquivoL = ftell(arquivoL);

	puts("\n-------------------------------------------------");
    puts("\tConteudo de livros.txt");
    puts("-------------------------------------------------");	
		
	if((arquivoL = fopen("livros.txt", "r"))==NULL || tamArquivoL==0)
	{
		printf("\tArquivo [livros.txt] vazio!");
	}
	else
	{
		//lendo o arquivo e printando todos os valores encontrados
		while(!feof(arquivoL))
		{
			fscanf(arquivoL, " %[^\n]s", auxL.titulo);
			fscanf(arquivoL, " %[^\n]s", auxL.idLivro);
			fscanf(arquivoL, " %[^\n]s", auxL.autor);
			fscanf(arquivoL, " %[^\n]s", auxL.editora);
			
			printf("\n\tTitulo[%d]: %s\n", i, auxL.titulo);
			printf("\tId[%d]: %s\n", i, auxL.idLivro);
			printf("\tAutor[%d]: %s\n", i, auxL.autor);
			printf("\tEditora[%d]: %s\n", i, auxL.editora);
			
			i++;
		}
		fclose(arquivoL);
	}
    //puts("-------------------------------------------------");		
}

void mostraReservado()
{
	//mostrando arquivo reservados.txt
	FILE *arquivoR = fopen("reservados.txt", "r");
	
	//variaveis auxiliares
	Sdata auxD;
	char auxNome[30];
	char auxTitulo[30];
	int tamArquivoR, i=0;
	
	fseek(arquivoR, 0, SEEK_END);
	tamArquivoR = ftell(arquivoR);
	
	puts("\n-------------------------------------------------");
    puts("\tConteudo de reservados.txt");
    puts("-------------------------------------------------");
	
	if((arquivoR = fopen("reservados.txt", "r"))==NULL || tamArquivoR==0)
	{
		printf("\tArquivo [reservados.txt] vazio!\n");
	}
	else
	{
		//lendo o arquivo e printando todos os valores encontrados
		while(!feof(arquivoR))
		{
			fscanf(arquivoR, " %[^\n]s", auxNome);
			fscanf(arquivoR, " %[^\n]s", auxTitulo);
			fscanf(arquivoR, "%d %d %d\n", &auxD.dia, &auxD.mes, &auxD.ano);
			fscanf(arquivoR, "%d", &auxD.invertida);
			
			printf("\n\tNome[%d]: %s\n", i, auxNome);
			printf("\tLivro[%d]: %s\n", i, auxTitulo);
			printf("\tData devolucao[%d]: %d/%d/%d\n", i, auxD.dia, auxD.mes, auxD.ano);
			//printf("\treservado[%d]: %d\n", i, auxD.invertida);		
			
			i++;
		}
		fclose(arquivoR);
	}
    //puts("-------------------------------------------------");	
}