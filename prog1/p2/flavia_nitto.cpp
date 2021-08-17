/*
Atividade avaliativa II ATPI
Nome do Aluno: FLAVIA NARUMI NITTO
RA: 201040743	
*/
#include <stdio.h>
#include <stdlib.h>
#define max 15

int main()
{
	//Definição do registro e seus respectivos campos
	//Variáveis permitidas
   int aux_qtd=0; 
   int indice, i;
   //Estruturas permitidas
    
   //Declaração do tipo struct modelo (modelo)
   	typedef struct model
	{
       char nome[20];
       char modelo[2];
       
    }Tmodel; 
    
   //Declaração do tipo struct data (d)
   	typedef struct d
	{
		int dia;
		int mes;
		int ano;		 	
	
	}Tdata;
	
   //Declaração do tipo struct resumo (resumo)
   	typedef struct resumo
	{ 
		int qtd;
		int estoque;
		Tmodel prod;
		Tdata data;	
		
	}Tresumo; 
  
  	Tresumo registro[max]; //declaração da variável registro do tipo Tresumo

//=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=   
   for (i=0;i<max;i++)
   {
	   	//Entrada dos dados
	   	puts("\n----------------------------------------------------------------------");
	   	puts("\tEntrada de dados: ");
	   	puts("----------------------------------------------------------------------");
	   	
	   	printf("\n Insira o nome do calcado: ");
		scanf("%s", registro[i].prod.nome);
	   	setbuf(stdin, NULL);
	   	
		printf("\n Insira o modelo do calcado: ");
		scanf("%s", registro[i].prod.modelo);
	   	setbuf(stdin, NULL);
	   		
	   	printf("\n Insira o dd/mm/aaaa da venda: ");
	   	scanf("%d %d %d", &registro[i].data.dia, &registro[i].data.mes, &registro[i].data.ano);
	   		
	   	printf("\n Insira a quantidade vendida: ");
	   	scanf("%d", &registro[i].qtd);
	   		
	   	printf("\n Insira o estoque disponivel: ");
	   	scanf("%d", &registro[i].estoque);	
   	}
   	
//=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=   	
	//solução item a) 
	puts("\n\n-------------------------------------------------------------------------------");
	puts("\t\t\tApresentando item a)");
   	puts("-------------------------------------------------------------------------------");
	
	for (i=0;i<max;i++)
	{
		if(registro[i].prod.modelo[0] == 'A') 
		{
			if(registro[i].data.dia > 0 && registro[i].data.dia <= 15 && registro[i].data.mes >= 3 && registro[i].data.mes <= 5)
			{	
				printf("\n  %d )\n  Nome dos calcados do modelo A: %s\n", i+1, registro[i].prod.nome);
				printf("\n  Total da venda do modelo A na primeira quinzena dos meses de 3 a 5: %d\n", registro[i].qtd);		
			}				
		}
	
	}
	
//=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=	
	//solução item b)
	puts("\n\n-------------------------------------------------------------------------------");
	puts("\t\t\tApresentando item b)");
   	puts("-------------------------------------------------------------------------------");	  	
	for (i=0;i<max;i++)
	{
		if(registro[i].prod.modelo[0] == 'C' && registro[i].qtd > aux_qtd)
		{
			aux_qtd = registro[i].qtd;
			indice = i;	
		}						
	}
	if (aux_qtd != 0)
	{
		printf("\n  Nome do calcado do modelo C que foi o mais vendido: %s", registro[indice].prod.nome);
	}
	
//=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=   
	//solução item c)  
	puts("\n\n-------------------------------------------------------------------------------");
	puts("\t\t\tApresentando item c)");
   	puts("-------------------------------------------------------------------------------");		 
	aux_qtd=0;  
	for (i=0;i<max;i++)
	{
		if(registro[i].data.mes == 12)
		{
			if(registro[i].qtd > aux_qtd)	
			{
				aux_qtd = registro[i].qtd;
				indice = i;
			}	
		}
	}
	if (aux_qtd != 0)
	{
		printf("\n  Nome do calcado mais vendido no mes 12: %s\n", registro[indice].prod.nome);
		printf("\n  Quantidade em estoque do calcado mais vendido no mes 12: %d", registro[indice].estoque);
	}	
	
//=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=	
	//solução item d)
	puts("\n\n-------------------------------------------------------------------------------");
	puts("\t\t\tApresentando item d)");
   	puts("-------------------------------------------------------------------------------");	
	for (i=0;i<max;i++)
	{
		if(registro[i].estoque == 0)
		{
		
			printf("\n\n  Nomes dos calcados com estoque zerado: %s\n", registro[i].prod.nome);
			printf("\n  Modelos dos calcados com estoque zerado: %c", registro[i].prod.modelo[0]);			
		
		}
	}
	
//=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=   	

   printf("\n\n");
   //system("PAUSE");	
   return 0; 
}

