#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*
Mini-prova 11: construa um programa em linguagem C para calcular o tempo necessário para que a massa
de um elemento, que deve ser solicitada e lida do teclado, se torne menor 0,5 grama, sabendo que as 
propriedades radioativas desse elemento fazem com que ele reduza metade da sua massa a cada 50
segundos. Ao final, o programa deve escrever a massa inicial, a massa final e o tempo necessário em
horas, minutos e segundos.
*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	float massa;
	int hora=0, minuto=0, segundo=0;
	
	printf("Informe a massa do elemento: ");
	scanf("%f", &massa);
	
	printf(" Massa inicial: %.2fg\n", massa);
	do
	{
		massa=massa/2;
		segundo = segundo+50;
		
		if(segundo>=60)
		{
			minuto++;
			segundo=segundo-60;
		}
		if(minuto>=60)
		{
			hora++;
			minuto=minuto-60;
		}
	}while(massa>=0.5);
	puts("----------------------------------------------");	
	puts("\tAPRESENTAÇÃO DOS DADOS");
	puts("----------------------------------------------");	
	printf(" Massa final: %.2fg", massa);
	printf("\n Tempo para que Massa Final < 0.5g: \n\t%dhoras %dminutos %dsegundos", hora, minuto, segundo);
	
	return 0;
}
