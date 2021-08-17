//Flavia Narumi Nitto (RA: 201040743)
#include<stdio.h>
#include<stdlib.h>
#define radpi 0.0174532925199444

void interpola (float senotxt);
float grau[91], seno[91], cosseno[91], pradianos, pcos; //passar como parametro e nao como variavel global

int main()
{
	int i=0;
	float senotxt;
	
	//abrindo o arquivo trigo
	FILE *trigofp;
	trigofp = fopen("trigo.txt", "r");
		do
		{
			fscanf(trigofp, "%f %f %f\n", &grau[i], &seno[i], &cosseno[i]);
			i++;
		}
		while(!feof(trigofp));
	fclose(trigofp);
	
	//abrindo o arquivo seno
	FILE *senofp;
	senofp = fopen("seno.txt", "r");
	
	//crinado o arquivo senocosseno 
	FILE *senocosfp;
	senocosfp = fopen("senocossenoflavia.txt", "w");
		do
		{
			fscanf(senofp, "%f \n", &senotxt);
			
			interpola(senotxt);
			
			fprintf(senocosfp, "%f %f %f \n", pradianos, senotxt, pcos);
		}
		while(!feof(senofp));
	
	fclose(senofp);
	fclose(senocosfp);
	
	return 0;
}

//função de interpolação
void interpola (float senotxt)
{
	float angularseno1, angularseno2, angularcos, coeficiente;
	int i;
	
	for(i=0; i<=90; i++)
	{
		//caso o seno não seja de um angulo inteiro
		if(seno[i] != senotxt)
		{
			//utilizando o seno do angulo maior que senotxt
			if(seno[i] > senotxt)
			{
				//coeficiente angular do seno
				angularseno1 = seno[i]-seno[i-1];
				angularseno2 = seno[i] - senotxt;
				
				//repetindo o processo no cosseno
				angularcos = cosseno[i]-cosseno[i-1];
				
				coeficiente = (angularseno2) / angularseno1;
				
				//dados que serao printados
				pradianos = (i-coeficiente)*radpi;
				pcos = cosseno[i] - (angularcos * coeficiente);
				
				break;
			}
		}
		
		//caso o seno seja de um angulo inteiro
		else
		{
			//dados que serao printados
			pradianos = grau[i]*radpi;
			pcos = cosseno[i];
		}
	}
	
}

