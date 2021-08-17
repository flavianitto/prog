#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define A 5 //numero de alunos
#define T 1 //numero de turmas

//dados alunos
typedef struct alunos
{
    char nomeCompleto[50];
	int RA;
    float *notas;
    float mediaAluno; 
}Alunos;
Alunos reg1[A];
float mediasAlunos[A];
int tam;

//dados turma
typedef struct turma
{
    char nomeDisciplina[25], periodo[10];
    int qtdAlunos, codTurma;
    float mediaTurma[T];
    Alunos media[A];
}Turma;
Turma reg2[T];

//prot�tipos das fun��es
void criarAluno();
void criarTurma();
void consultaAluno();
void consultaTurma();
int lerArquivoT();
void salvarArquivoA();
void salvarArquivoT();
void atualizarNota();

void criarAluno()
{
	int i=0, j, N;
	printf("\nFazendo cadastro aluno novo....");
	FILE *arquivo, *aluno;
	if((arquivo = fopen("Turma.txt", "rb")) == NULL) printf("Warning: Crie uma turma primeiro!!!");
	else
	{
		//podemos incluir v�rios alunos de uma vez
		printf("\nQuantos alunos ser�o incluidos?: ");
		scanf("%d", &N);
		float soma[N];	
		
		//caso o numero ultrapasse o limite de alunos suportado (setamos um valor max no define)	
		if(N>A) printf("\nO sistema n�o suporta mais que %d alunos!!", A);
		else
		{
			//Abrimos o arquivo para gravar os dados recebidos
			aluno = fopen("Aluno.txt", "a+");
			while(i<N)
			{
				printf("\n\n_________________________________________________");
				printf("\n\tCadastrando aluno novo");
				printf("\n_________________________________________________");      
	    		fprintf(aluno, "%d", i+1);
	    		
				printf("\nDigite o nome: ");
				scanf(" %[^\n]s", reg1[i].nomeCompleto);
				fprintf(aluno, "\n%s", reg1[i].nomeCompleto);
			
				printf("Digite o RA: ");
				scanf("%d", &reg1[i].RA);
				fprintf(aluno, "\n%d", reg1[i].RA);
				
			    printf("Digite o c�digo da turma: ");
			    scanf("%d", &reg2[i].codTurma);    
				fprintf(aluno, "\n%d", reg2[i].codTurma);
				
				printf("Digite a quantidade de avalia��es: ");
			    scanf("%d", &tam);
			    
			    soma[i] = 0;
			    
			    //aloca��o dinamica para o vetor notas
				reg1[i].notas = (float*)malloc(tam*sizeof(float));
			    for(j=0; j<tam; j++)
			    {
			        printf("Nota %d: ", j+1);
			        scanf("%f", &reg1[i].notas[j]);
			        soma[i] += reg1[i].notas[j];
			    }  
				//Calculando a m�dia do aluno        
			    reg1[i].mediaAluno = soma[i] / tam;
			    printf("M�dia aluno: %.2f", reg1[i].mediaAluno);
			    fprintf(aluno, "\n%.2f", reg1[i].mediaAluno);
			
				//Consolidando o semestre para o aluno 
				if(reg1[i].mediaAluno <= 5)	
				{
					printf("\nStatus: REPROVADO\n");
			    	fprintf(aluno, "\nREPROVADO\n");
				}
				else
				{
					printf("\nStatus: APROVADO\n");
			    	fprintf(aluno, "\nAPROVADO\n");
				}			
				i++;

				//Libera o vetor din�mico de notas
				free(reg1[i].notas);	
			}					
		}		
	}
	fclose(aluno);
	fclose(arquivo);
}

void criarTurma()
{
	int i=0, N1;
	
	//Podemos incluir varias turmas de uma s� vez
	printf("\nQuantas turmas ser�o incluidas?: ");
	scanf("%d", &N1);
	
	//lendo o arquivo, come�amos a gravar novos elementos a partir do primeiro espa�o livre
	//i = lerArquivoT();
	
	//Fazemos esse teste para verificar se n�o estamos tentando inserir mais turmas que o suportado (declarado no define)
	if(N1>T) printf("\nO sistema n�o suporta mais que %d turmas", T);	
	else
	{
		while(i<N1)
		{
			printf("\n\n_________________________________________________");
			printf("\n\tCadastrando turma nova");
			printf("\n_________________________________________________");      
		    printf("\nNome da Disciplina: ");
		    scanf(" %[^\n]s", reg2[i].nomeDisciplina);
		    
			printf("Per�odo: ");
		    scanf(" %[^\n]s", reg2[i].periodo);
					    
			printf("Codigo da turma: ");
		    scanf("%d", &reg2[i].codTurma); 
			
			printf("Numero de alunos na turma: ");
			scanf("%d", &reg2[i].qtdAlunos);	    
			
			//Como ainda n�o temos alunos na turma rec�m-cadastrada
			//setamos todas as medias como -1 (inexistentes)
			reg2[i].mediaTurma[i] = -1;
		    i++;
		}		
	}
	//salvando no arquivo 
	salvarArquivoT();	
}

void consultaAluno()
{
	int consultaRA, i;
    printf("\nInsira o RA do aluno: ");
    scanf("%d", &consultaRA);
    for(i=0; i<A; i++)
    {
	    if(consultaRA == reg1[i].RA)
	    {
		 	printf("\n\n_________________________________________________");  
			printf("\n\tDados do aluno");
			printf("\n_________________________________________________");     	
	        printf("\nNome: %s", reg1[i].nomeCompleto);
	        printf("\nRA: %d", reg1[i].RA);
	        printf("\nCodigo da turma: %d", reg2[i].codTurma);
	        printf("\nMedia: %.2f", reg1[i].mediaAluno);
	        if(reg1[i].mediaAluno >= 5) printf("\nStatus: APROVADO\n");
	        else printf("\nStatus: REPROVADO\n");
	    }
	    //else ("\nAVISO: ALUNO NAO ENCONTRADO!!!\n");
	}
}

void consultaTurma()
{
    int consultaCodigo, i, j, k;
    float somaT[T];	
	printf("\nFazendo consulta por turma....");	
    printf("\nInsira o codigo da turma: ");
    scanf("%d", &consultaCodigo);   
    
    for(i=0; i<T; i++)
    {
    	somaT[i]=0;
		if(consultaCodigo==reg2[i].codTurma)
		{
		 	printf("\n\n_________________________________________________");  
			printf("\n\tDados da Turma");
			printf("\n_________________________________________________"); 
	        printf("\nDisciplina: %s", reg2[i].nomeDisciplina);
	        printf("\nCodigo da turma: %d", reg2[i].codTurma);
	        printf("\nTotal de alunos: %d", reg2[i].qtdAlunos);
			
			//calculando media turma
	        for(j=0; j<A; j++)
	        {
			    somaT[i] += reg1[j].mediaAluno;
				reg2[i].mediaTurma[i] = somaT[i] / reg2[i].qtdAlunos;   	
			}		
	        printf("\nMedia Turma[%d]: %.2f", reg2[i].codTurma, reg2[i].mediaTurma);
	    }
		//else printf("\nAVISO: ALUNO NAO ENCONTRADO!!!\n");  	
	}	
}

int lerArquivoT()
{
	int k, indiceT; 
	FILE *arquivoT;
    if((arquivoT = fopen("Turma.txt", "rb"))==NULL) 
	{
		printf("N�o � possivel abrir o arquivo"); 
		return 0;			
	}
	else
	{
		do
		{
			fscanf(arquivoT, "%d", &indiceT);
			fscanf(arquivoT, "%[^\n]s", reg2[k].nomeDisciplina);
			fscanf(arquivoT, "%[^\n]s", reg2[k].periodo);
			fscanf(arquivoT, "%d", &reg2[k].codTurma);
			fscanf(arquivoT, "%d", &reg2[k].qtdAlunos);
			k++;
		}while(!feof(arquivoT));
		fclose(arquivoT);
		
		//Retornamos o indice de onde parou o ultimo elemento
		//Assim, n�o escreve em cima dos dados j� existentes no arquivo		
		return indiceT;		
	}	
}

void salvarArquivoA()
{
	int i;
	FILE *arquivoA;
	arquivoA = fopen("Aluno.txt", "a+");
	for(i=0; i<A; i++)
	{
		fprintf(arquivoA, "%d", i+1); //posi��o do dado no vetor
		fprintf(arquivoA, "\n%s", reg1[i].nomeCompleto);
		fprintf(arquivoA, "\n%d", reg1[i].RA);
		fprintf(arquivoA, "\n%d", reg2[i].codTurma);
		fprintf(arquivoA, "\n%.2f", reg1[i].mediaAluno);
		
		//Consolidando o semestre no arquivo
		if(reg1[i].mediaAluno>=5) fprintf(arquivoA, "\nAPROVADO\n");
		else fprintf(arquivoA, "\nREPROVADO\n");
	}
	fclose(arquivoA);
}

void salvarArquivoT()
{
	int i;
	FILE *arquivoT;
	arquivoT = fopen("Turma.txt", "a+");
	for(i=0; i<T; i++)
	{
		fprintf(arquivoT, "%d", i+1); //posi��o do dado no vetor
		fprintf(arquivoT, "\n%s", reg2[i].nomeDisciplina);
		fprintf(arquivoT, "\n%s", reg2[i].periodo);
		fprintf(arquivoT, "\n%d", reg2[i].codTurma);
		fprintf(arquivoT, "\n%d", reg2[i].qtdAlunos);
		
		//caso exista uma media da turma v�lida (n�o negativa), mostramos ela
		if(reg2[i].mediaTurma>0)
		fprintf(arquivoT, "\n%.2f\n", reg2[i].mediaTurma);
	}
	fclose(arquivoT);
}

void atualizarNota()
{
	int atualizarRA, i, j, escolha;
	float nnota, soma[tam], mediaAtt;
	printf("\nAtualizando nota...")		;
	printf("\nInsira o RA do aluno desejado: ");
	scanf("%d", &atualizarRA);
	for(i=0; i<A; i++)
	{
		if(reg1[i].RA == atualizarRA)
		{
			printf("Selecione qual nota alterar: ");
			for(j=0; j<tam; j++)
				printf("\nNota [%d]: %.2f", j+1, reg1[i].notas[j]);
		}
		//else printf("RA n�o encontrado!");
	}
	//Escolhendo qual nota iremos alterar
	printf("\nOp��o: ");
	scanf("%d", &escolha);
	printf("\nNova nota[%d]: ", escolha);
	scanf("%f", &nnota);
	
	//alterando a nota
	for(i=0; i<A; i++)
	{
		reg1[i].notas[escolha-1] = nnota;
		for(j=0; j<tam; j++)
		{
			printf("\nNota[%d]: %.2f", j+1, reg1[i].notas[j]);
			
			//atualizando a media
			soma[j] = reg1[i].notas[j];
			mediaAtt = soma[j]/tam;
		}	
	}
	//Mostra a nova media no terminal
	printf("\nNova m�dia: %.2f", mediaAtt);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int op, op1, op3;
	
	//Criando os arquivos (caso n�o existam)
	FILE *aluno, *turma;
	aluno = fopen("Aluno.txt", "a+");
	fclose(aluno);
	turma = fopen("Turma.txt", "a+");
	fclose(turma);
    do
    {
        printf("\n_________________________________________________");
        printf("\n\t\tMENU DE OPCOES");
        printf("\n_________________________________________________");
        printf("\n   1 - Novo cadastro"); // por aluno e por turma
        printf("\n   2 - Atualizar notas"); // por aluno 
        printf("\n   3 - Fazer uma consulta"); //por aluno e por turma
        printf("\n   0 - Salvar e sair"); 
        printf("\n=================================================\n Opcao: ");        
        scanf("%d", &op);   
        switch(op)
        {
            case 1:
            {
		        printf("\n\n_________________________________________________");
		        printf("\n\t\tNovo cadastro");
		        printf("\n_________________________________________________");      
                printf("\n   1 - Cadastrar novo aluno");
                printf("\n   2 - Cadastrar nova turma");
                printf("\n   Lembrete: � preciso cadastrar uma turma primeiro!");
        		printf("\n=================================================\n Opcao: ");        
                scanf("%d", &op1);
                switch(op1) 
				{
					case 1: criarAluno(); break;
					case 2: criarTurma(); break;
					default: puts("Opcao invalida cadastro\n");
				}
            }break;

            case 2: 
            {
		        printf("\n\n_________________________________________________");
		        printf("\n\t\tAtualizar notas");
        		printf("\n=================================================\n");                
				atualizarNota(); break;
            }break;

            case 3:
            {
		        printf("\n\n_________________________________________________");
		        printf("\n\t\tFazer uma consulta");
		        printf("\n_________________________________________________");      
                printf("\n   1 - Consulta por aluno");
                printf("\n   2 - Consulta por turma");
        		printf("\n=================================================\n Opcao: ");                              
                scanf("%d", &op3);
                switch(op3) 
				{
					case 1: consultaAluno(); break;
					case 2: consultaTurma(); break;
					default: puts("Consulta: op��o inv�lida\n");
				}
            }break;
						
			//Como eu salvo os dados a cada itera��o, no case 0 apenas fechamos o programa
			//pois j� esta tudo salvo
            case 0: printf("\nSalvando alteracoes e fechando......"); return 0; break; 
        }
    }while(op != 0);	
    
    return 0;
}

