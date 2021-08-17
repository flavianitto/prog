#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxV 500000 //quantidade maxima de elementos do vetor
#define maxB 100000 //quantidade maxima de elementos da busca
#define billion 1000000000

int tamVetor, tamBusca;

struct timespec inicioT, finalT;

void insertionSort(double *vetor)
{
    double aux;
    int i=1, j=0;
    for(i=1; i<tamVetor; i++)
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

int pivo (double *vetor, int esq, int dir)
{
    int pivo = vetor[dir];
    int t, k, j=esq;
    for(k=esq; k<dir; k++)
    {
        if(vetor[k] <= pivo)
        {
            t = vetor[j];
            vetor[j] = vetor[k];
            vetor[k] = t;
            j++;
        }
    }
    t = vetor[j];
    vetor[j] = vetor[dir];
    vetor[dir] = t;
    return j;
}

void quickSort(double *vetor, int esq, int dir)
{
    if(esq < dir)
    {
        int j;
        j = pivo(vetor, esq, dir);
        quickSort(vetor, esq, j-1);
        quickSort(vetor, j+1, dir);
    }
}

void shellSort(double *vetor)
{
    int i, j, k, passo;
    double valor;
    passo = 1;
    while(passo < tamVetor/2)
    {
        passo = 3*passo + 1;
    }
    while(passo != 1)
    {
        passo = passo/3;
        for(k=0; k<passo; k++)
        {
            for(i=k+passo; i<tamVetor; i=i+passo)
            {
                valor = vetor[i];
                j=i;
                while(j-passo>=0 && vetor[j-passo]>valor)
                {
                    j=j-passo;
                }
                vetor[j] = valor;
            }
        }
    }
}

void buscaBinaria(double *vetor, double elem, int low, int high)
{
	FILE *fpResultado = fopen("resultado.dat", "a");
    int middle;
    while(low <=high)
    {
        middle = (low+high)/2;
        if(elem == vetor[middle])
        {
        	fprintf(fpResultado, "%d %lf %lf\n", middle, vetor[middle], elem);
        }
        else if(elem<vetor[middle])
        {
            high = middle-1;
        	fprintf(fpResultado, "%d %lf %lf\n", high, vetor[high], elem);
        }
        else
        {
            low = middle+1;
        	fprintf(fpResultado, "%d %lf %lf\n", low, vetor[low], elem);            
        }
    }
    //nao encontramos o elemento
    fprintf(fpResultado, "-1 0.0 %lf\n", elem);
    fclose(fpResultado);
}

void buscaSequencial(double *vetor, double elem)
{
    int i=0;
    double soma;
    FILE *fpResultado = fopen("resultado.dat", "a");
    for(i=0; i<tamVetor; i++)
    {
        if(vetor[i]<0 && elem<0)
        {
            if(vetor[i]>elem)
            {
                soma = (elem * -1) - (vetor[i] * -1);
            }
            else
            {
                soma = (vetor[i] * -1) - (elem * -1);
            }
        }
        else
        {
            if(vetor[i]<elem)
            {
                soma = elem - vetor[i];
            }
            else
            {
                soma = vetor[i] - elem;
            }
        }
        //encontramos o elemento
        if(soma < 0.0001)
        {
            fprintf(fpResultado, "%d %lf %lf\n", i, vetor[i], elem);
        }
    }
    //nao encontramos o elemento buscado
    fprintf(fpResultado, "-1 0.0 %lf\n", elem);
    fclose(fpResultado);
}

void alocaVetor(double *vetor)
{
	//alocando vetor
	FILE *fpVetor;
	fpVetor = fopen("vetor.dat", "r");
	int i=0;
	do
	{
		fscanf(fpVetor, "%lf \n", &vetor[i]);
		//printf("vetor[%d]: %lf\n", i, vetor[i]);
		i++;
	}while(!feof(fpVetor));
	tamVetor = i;
	vetor  = (double*)realloc(vetor, tamVetor*sizeof(double)); //fazendo o realloc do vetor
	fclose(fpVetor);	
}

void alocaBusca(double *busca)
{
	//alocando vetor busca
	FILE *fpBusca;
	fpBusca = fopen("busca.dat", "r");
	int i=0;
	do
	{
		fscanf(fpBusca, "%lf \n", &busca[i]);
		//printf("busca[%d]: %lf\n", i, busca[i]);
		i++;
	}while(!feof(fpBusca));
	tamBusca = i;
	busca  = (double*)realloc(busca, tamBusca*sizeof(double)); //fazendo o realloc da busca
	fclose(fpBusca);		
}

double calculaTempo(struct timespec inicio, struct timespec final)
{
	double seg, nanoseg;
	seg = (final.tv_sec - inicio.tv_sec);
	nanoseg = (final.tv_nsec - inicio.tv_nsec);
	seg += (nanoseg/billion);
	return seg;
}

int main()
{	
	int op;
	double *vetor = (double*)malloc(maxV*sizeof(double));
	double *busca = (double*)malloc(maxB*sizeof(double));
	
	alocaVetor(vetor);
	alocaBusca(busca);

    do
    {
        puts("\n_________________________________________________");
        printf("\n\t\tMENU DE OPCOES");
        puts("\n_________________________________________________");
        printf("\n   1- Busca sem ordenacao"); 
        printf("\n   2- Busca sequencial - insertion sort"); 
        printf("\n   3- Busca sequencial - shell sort"); 
        printf("\n   4- Busca sequencial - quicksort"); 
        printf("\n   5- Busca binaria - insertion sort"); 
        printf("\n   6- Busca binaria - shell sort"); 
        printf("\n   7- Busca binaria - quicksort"); 
        printf("\n   0- Fecha o programa");
        printf("\n=================================================\n Opcao: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: 
            {
                //busca sem ordenacao	
                remove("resultado.dat");
                int i=0;
                double elemento1, tempoBS;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)		                
                {
                    elemento1 = busca[i];
                    buscaSequencial(vetor, elemento1);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoBS = calculaTempo(inicioT, finalT);
                printf("\nTempo total: %lf", tempoBS);
                
            }break;            
            
            case 2: 
            {
                //busca sequencial - insertion 
                remove("resultado.dat");
                int i=0;
                double elemento2, tempoI, tempoIBS;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                insertionSort(vetor);
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoI = calculaTempo(inicioT, finalT);
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)
                {
                    elemento2 = busca[i];
                    buscaSequencial(vetor, elemento2);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoIBS = calculaTempo(inicioT, finalT);

                printf("\nTempo ordenacao: %lf", tempoI);   
                printf("\nTempo busca: %lf", tempoIBS); 
                printf("\nTempo total: %lf", tempoI+tempoIBS);

            }break;
            
            case 3: 
            {
				//busca sequencial - shell
                remove("resultado.dat");
                int i=0;
                double elemento3, tempoS, tempoSBS;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                shellSort(vetor);
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoS = calculaTempo(inicioT, finalT);
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)
                {
                    elemento3 = busca[i];
                    buscaSequencial(vetor, elemento3);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoSBS = calculaTempo(inicioT, finalT);

                printf("\nTempo ordenacao: %lf", tempoS);   
                printf("\nTempo busca: %lf", tempoSBS); 
                printf("\nTempo total: %lf", tempoS+tempoSBS);

            }break;
            
            case 4: 
            {
                //busca sequencial - quick
                remove("resultado.dat");
                int i=0;
                double elemento4, tempoQ, tempoQBS;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                quickSort(vetor, 0, tamVetor-1);
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoQ = calculaTempo(inicioT, finalT);
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)
                {
                    elemento4 = busca[i];
                    buscaSequencial(vetor, elemento4);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoQBS = calculaTempo(inicioT, finalT);

                printf("\nTempo ordenacao: %lf", tempoQ);   
                printf("\nTempo busca: %lf", tempoQBS); 
                printf("\nTempo total: %lf", tempoQ+tempoQBS);
            }break;
                        
            case 5:
            {
                //busca binaria - insertion
                remove("resultado.dat");
                int i=0;
                double elemento5, tempoIB, tempoIBB;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                insertionSort(vetor);
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoIB = calculaTempo(inicioT, finalT);
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)
                {
                    elemento5 = busca[i];
                    buscaBinaria(vetor, elemento5, 0, tamVetor-1);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoIBB = calculaTempo(inicioT, finalT);

                printf("\nTempo ordenacao: %lf", tempoIB); 
                printf("\nTempo busca: %lf", tempoIBB); 
                printf("\nTempo total: %lf", tempoIB+tempoIBB);
            }break;

            case 6: 
            {
                //busca binaria - shell
                remove("resultado.dat");
                int i=0;
                double elemento6, tempoSB, tempoSBB;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                shellSort(vetor);
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoSB = calculaTempo(inicioT, finalT);
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)
                {
                    elemento6 = busca[i];
                    buscaBinaria(vetor, elemento6, 0, tamVetor-1);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoSBB = calculaTempo(inicioT, finalT);

                printf("\nTempo ordenacao: %lf", tempoSB); 
                printf("\nTempo busca: %lf", tempoSBB); 
                printf("\nTempo total: %lf", tempoSB+tempoSBB);
            }break;

            case 7: 
            {
                //busca binaria - quick
                remove("resultado.dat");
                int i=0;
                double elemento7, tempoQB, tempoQBB;
                clock_gettime(CLOCK_REALTIME, &inicioT);
                quickSort(vetor, 0, tamVetor-1);
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoQB = calculaTempo(inicioT, finalT);
                clock_gettime(CLOCK_REALTIME, &inicioT);
                for(i=0; i<tamBusca; i++)
                {
                    elemento7 = busca[i];
                    buscaBinaria(vetor, elemento7, 0, tamVetor-1);
                }
                clock_gettime(CLOCK_REALTIME, &finalT);
                tempoQBB = calculaTempo(inicioT, finalT);

                printf("\nTempo ordenacao: %lf", tempoQB); 
                printf("\nTempo busca: %lf", tempoQBB); 
                printf("\nTempo total: %lf", tempoQB+tempoQBB);
            }break;

            case 0: 
            {
                //fecha o programa - libera a memoria
                free(vetor);
                free(busca);
                return 0;
            }break;                     
        }
    }while(op!=0);

    free(vetor);
    free(busca);
    return 0;
    
}
