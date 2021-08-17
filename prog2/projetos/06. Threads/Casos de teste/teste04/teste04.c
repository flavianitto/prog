#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#define max 500000 //tamanho maximo do vetor de elementos
#define billion 1000000000

int tamVetor;
struct timespec inicioT, finalT; //variaveis para medicao de tempo

//insertion com uso de threads
void *insertionSortT(void *vet)
{
    double *vetor = (double*)vet;
    double aux;
    int i=1;
    int j=0;
    for(i=1; i<tamVetor; i++)
    {
        aux = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>aux)
        {
            vetor[j+1] = vetor[j];
            j=j-1;
        }
        vetor[j+1] = aux;
    }
}

//insertion sem uso de threads
void insertionSort(double *vetor)
{
    double aux;
    int i=1;
    int j=0;
    for(i=1; i<tamVetor; i++)
    {
        aux = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>aux)
        {
            vetor[j+1] = vetor[j];
            j=j-1;
        }
        vetor[j+1] = aux;
    }
}

//merge sort com uso de threads
void mergeSortT(double *vetor, double **partes, int numDiv, int numThr)
{
    //ponteiros para as partes dos vetores
    double *vet1, *vet2, *vet3, *vet4, *vet5, *vet6, *vet7, *vet8;
    int i=0, j=0;
    int maxMerge = max/numDiv;
    //criando as variaveis para usar as threads
    pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8;
    
    //dividido em 2 partes
    if(numDiv==2) 
    {
        //atribuindo as 2 partes para os 2 vetores
        vet1 = partes[0];
        vet2 = partes[1];

        //preenchendo os 2 vetores
        for(i=0; i<maxMerge; i++)
            vet1[i] = vetor[j];   j++;

        for(i=0; i<maxMerge; i++)
            vet2[i] = vetor[j];   j++;
        
        //sem usar threads - faz o insertion normal nos 2 vetores
        if(numThr==0)
        {
            insertionSort(vet1);
            insertionSort(vet2);
        }
        //usando 2 threads
        else
        {
            //criando as threads - faz elas executarem o insertionT nos 2 vetores
            pthread_create(&thread1, NULL, insertionSortT, vet1);
            pthread_create(&thread2, NULL, insertionSortT, vet2);

            //chamada das threads
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
        }
    }
    //dividido em 4 partes
    else if(numDiv==4)
    {
        //atribuindo as 4 partes para os 4 vetores 
        vet1 = partes[0];
        vet2 = partes[1];
        vet3 = partes[2];
        vet4 = partes[3];

        //preenchendo os 4 vetores
        for(i=0; i<maxMerge; i++)
            vet1[i] = vetor[j];     j++;
                
        for(i=0; i<maxMerge; i++)
            vet2[i] = vetor[j];     j++;
        
        for(i=0; i<maxMerge; i++)
            vet3[i] = vetor[j];     j++;
                
        for(i=0; i<maxMerge; i++)
            vet4[i] = vetor[j];     j++;

        //sem usar threads - faz o insertion normal nos 4 vetores
        if(numThr==0)
        {
            insertionSort(vet1);
            insertionSort(vet2);
            insertionSort(vet3);
            insertionSort(vet4);
        }
        //usando 2 threads - vai apenas 2 vetores de cada vez no insertionT
        else if(numThr==2)
        {
            //criando as threads - faz elas executarem o insertionT nos 4 vetores
            pthread_create(&thread1, NULL, insertionSortT, vet1);
            pthread_create(&thread2, NULL, insertionSortT, vet2);            
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL); 
            
            //espera os 2 primeiros vetores fazerem a ordenaçao 
            pthread_create(&thread3, NULL, insertionSortT, vet3);        
            pthread_create(&thread4, NULL, insertionSortT, vet4);                 
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);                     
        }
        //usando 4 threads - pode ir todos os vetores de uma só vez no insertionT
        else
        {
            //criando as threads - faz elas executarem o insertionT nos 4 vetores
            pthread_create(&thread1, NULL, insertionSortT, vet1);
            pthread_create(&thread2, NULL, insertionSortT, vet2);            
            pthread_create(&thread3, NULL, insertionSortT, vet3);        
            pthread_create(&thread4, NULL, insertionSortT, vet4);   
        
            //chamada das threads - vao todas juntas, pois tem threads o suficiente para cada vetor
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);                           
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);            
        }
    }
    //dividido em 8 partes
    else
    {
        //atribuindo as 8 partes para os 8 vetores
        vet1 = partes[0];
        vet2 = partes[1];
        vet3 = partes[2];
        vet4 = partes[3];
        vet5 = partes[4];
        vet6 = partes[5];
        vet7 = partes[6];
        vet8 = partes[7];    

        //preenchendo os 8 vetores
        for(i=0; i<maxMerge; i++)
            vet1[i] = vetor[j];     j++;
                
        for(i=0; i<maxMerge; i++)
            vet2[i] = vetor[j];     j++;
        
        for(i=0; i<maxMerge; i++)
            vet3[i] = vetor[j];     j++;
                
        for(i=0; i<maxMerge; i++)
            vet4[i] = vetor[j];     j++;
        
        for(i=0; i<maxMerge; i++)
            vet5[i] = vetor[j];     j++;
                
        for(i=0; i<maxMerge; i++)
            vet6[i] = vetor[j];     j++;
        
        for(i=0; i<maxMerge; i++)
            vet7[i] = vetor[j];     j++;
                
        for(i=0; i<maxMerge; i++)
            vet8[i] = vetor[j];     j++;   

        //sem usar threads - faz o insertion normal nos 8 vetores
        if(numThr==0)
        {
            insertionSort(vet1);
            insertionSort(vet2);
            insertionSort(vet3);
            insertionSort(vet4);            
            insertionSort(vet5);
            insertionSort(vet6);
            insertionSort(vet7);
            insertionSort(vet8);
        }    
        //usando 2 threads - vai apenas 2 vetores de cada vez no insertionT
        else if(numThr==2)
        {
            //criando as threads - faz elas executarem o insertionT nos 8 vetores
            pthread_create(&thread1, NULL, insertionSortT, vet1);
            pthread_create(&thread2, NULL, insertionSortT, vet2);            
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL); 
            
            //espera os vetores fazerem a ordenaçao 
            pthread_create(&thread3, NULL, insertionSortT, vet3);        
            pthread_create(&thread4, NULL, insertionSortT, vet4);                 
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);   
            
            //espera os vetores fazerem a ordenaçao 
            pthread_create(&thread5, NULL, insertionSortT, vet5);
            pthread_create(&thread6, NULL, insertionSortT, vet6);            
            pthread_join(thread5, NULL);
            pthread_join(thread6, NULL); 
            
            //espera os vetores fazerem a ordenaçao 
            pthread_create(&thread7, NULL, insertionSortT, vet7);        
            pthread_create(&thread8, NULL, insertionSortT, vet8);                 
            pthread_join(thread7, NULL);
            pthread_join(thread8, NULL);                           
        }
        //usando 4 threads - vai apenas 4 vetores de cada vez no insertionT
        else if(numThr==4)
        {
            //criando as threads - faz elas executarem o insertionT nos 8 vetores
            pthread_create(&thread1, NULL, insertionSortT, vet1);
            pthread_create(&thread2, NULL, insertionSortT, vet2);  
            pthread_create(&thread3, NULL, insertionSortT, vet3);        
            pthread_create(&thread4, NULL, insertionSortT, vet4);                                    
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);            
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);   
            
            //espera os vetores fazerem a ordenaçao
            pthread_create(&thread5, NULL, insertionSortT, vet5);
            pthread_create(&thread6, NULL, insertionSortT, vet6);  
            pthread_create(&thread7, NULL, insertionSortT, vet7);        
            pthread_create(&thread8, NULL, insertionSortT, vet8);                       
            pthread_join(thread5, NULL);
            pthread_join(thread6, NULL); 
            pthread_join(thread7, NULL);
            pthread_join(thread8, NULL); 
        }
        //usando 8 threads - pode ir todos os vetores de uma só vez no insertionT
        else
        {
            //criando as threads - faz elas executarem o insertionT nos 8 vetores
            pthread_create(&thread1, NULL, insertionSortT, vet1);
            pthread_create(&thread2, NULL, insertionSortT, vet2);  
            pthread_create(&thread3, NULL, insertionSortT, vet3);        
            pthread_create(&thread4, NULL, insertionSortT, vet4);  
            pthread_create(&thread5, NULL, insertionSortT, vet5);
            pthread_create(&thread6, NULL, insertionSortT, vet6);  
            pthread_create(&thread7, NULL, insertionSortT, vet7);        
            pthread_create(&thread8, NULL, insertionSortT, vet8);                                                 

            //chamada das threads - vao todas juntas
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);            
            pthread_join(thread3, NULL);
            pthread_join(thread4, NULL);          
            pthread_join(thread5, NULL);
            pthread_join(thread6, NULL); 
            pthread_join(thread7, NULL);
            pthread_join(thread8, NULL); 
        }
    }
    
    //agora que ja ordenamos todas as partes usando as threads, precisamos 
    //juntar todos os vetores em um vetor auxiliar e ordená-lo
    double *vetAux;
    vetAux = (double*)malloc(max*sizeof(double));
    
    j=0; //reseta o valor de j para usar ele no vetAux

    //dividido em 2 partes
    if(numDiv==2)
    {
        //preenchendo os 2 vetores
        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet1[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet2[i];   j++;        
    }
    //dividido em 4 partes
    else if(numDiv==4)
    {
        //preenchendo os 4 vetores
        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet1[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet2[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet3[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet4[i];   j++;            
    }
    //dividido em 8 partes
    else
    {
        //preenchendo os 4 vetores
        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet1[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet2[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet3[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet4[i];   j++; 

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet5[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet6[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet7[i];   j++;

        for(i=0; i<maxMerge; i++)
            vetAux[j] = vet8[i];   j++;                     
    }

    //aplicando o insertion normal no vetAux - que é a união de todas as partes
    insertionSort(vetAux);

    //copia os valores para o vetor original
    for(i=0; i<tamVetor; i++)
    {
        vetor[i] = vetAux[i];
        //printf("vetor[%d]: %lf\n", i, vetor[i]);
    }
    
    //liberando a memoria alocada de acordo com o numDiv - liberamos apenas os vetores que foram alocados
    if(numDiv==2)
    {
        free(vet1);
        free(vet2);
        free(vetAux);
    }
    else if(numDiv==4)
    {
        free(vet1);
        free(vet2);
        free(vet3);
        free(vet4);
        free(vetAux);        
    }
    else
    {
        free(vet1);
        free(vet2);
        free(vet3);
        free(vet4);
        free(vet5);
        free(vet6);
        free(vet7);
        free(vet8);        
        free(vetAux);          
    }

    //printf("\nVetor ordenado");
}

//merge sort normal - chama o merge que usa threads
void mergeSort(double *vetor, int numDiv, int numThr)
{
    //vetor de ponteiros - armazena o vetor em partes
    double *partes[numDiv];
    int i=0;
    
    //fazendo alocaçao para cada parte do vetor
    for(i=0; i<numDiv; i++)
    {
        partes[i] = (double*)malloc((max/numDiv)*sizeof(double));
    }

    //chamando a funcao que usa as threads para ordenar o vetor
    mergeSortT(vetor, partes, numDiv, numThr);

}

void alocaVetor(double *vetor)
{
    //abre o arquivo e passa os dados para um vetor local
    FILE *fpVetor = fopen("vetor.dat", "r");
    int i=0;
    while(!feof(fpVetor))
    {
        fscanf(fpVetor, "%lf\n", &vetor[i]);
        //printf("vetor[%d]: %lf\n", i, vetor[i]);
        i++;
    }
    //realocando o tamanho do vetor de acordo com os dados fornecidos
    tamVetor = i;
    vetor = (double*)realloc(vetor, tamVetor*sizeof(double));
    fclose(fpVetor);
}

//estrutura para calcular o tempo de execucao das funcoes
void calculaTempo(struct timespec inicioT, struct timespec finalT)
{
    double seg, nanoseg;
    seg = (finalT.tv_sec - inicioT.tv_sec);
    nanoseg = (finalT.tv_nsec - inicioT.tv_nsec);
    seg += (nanoseg/billion);
    //retornamos o tempo em segundos
    printf("\nTempo: %lf", seg);
}

void imprimeVetor(double *vetor)
{
    int i=0;
    for(i=0; i<tamVetor; i++)
    {
        printf("\n[%d]: %lf", i, vetor[i]);
    }
    printf("\n\n");
}

int main()
{
    int op;
    
    //inicializa o vetor de numeros reais com tamanho maximo 
    double *vetor = (double*)malloc(max*sizeof(double));
    //funcao para ler o arquivo e realocar o tamanho certo do vetor
    alocaVetor(vetor);

    do
    {
        puts("\n_________________________________________________");
        printf("\n\t\tMENU DE OPCOES");
        printf("\n_________________________________________________");
        printf("\n   1- Vetor dividido em 2 - sem threads"); 
        printf("\n   2- Vetor dividido em 2 - 2 threads"); 
        printf("\n   3- Vetor dividido em 4 - sem threads"); 
        printf("\n   4- Vetor dividido em 4 - 2 threads"); 
        printf("\n   5- Vetor dividido em 4 - 4 threads"); 
        printf("\n   6- Vetor dividido em 8 - sem threads"); 
        printf("\n   7- Vetor dividido em 8 - 2 threads"); 
        printf("\n   8- Vetor dividido em 8 - 4 threads"); 
        printf("\n   9- Vetor dividido em 8 - 8 threads"); 
        printf("\n   0- Fecha o programa");
        printf("\n=================================================\n Opcao: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: 
            {
                //vetor dividido em 2 - sem usar threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 2, 0);
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;

            case 2:
            {
                //vetor dividido em 2 - usando 2 threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 2, 2);                
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;

            case 3:
            {
                //vetor dividido em 4 - sem usar threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 4, 0);                
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;

            case 4:
            {
                //vetor dividido em 4 - usando 2 threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 4, 2);  
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;            
            
            case 5:
            {
                //vetor dividido em 4 - usando 4 threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 4, 4);  
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;

            case 6:
            {
                //vetor dividido em 8 - sem usar threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 8, 0);  
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;

            case 7:
            {
                //vetor dividido em 8 - usando 2 threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 8, 2);
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;            
            
            case 8:
            {
                //vetor dividido em 8 - usando 4 threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 8, 4);
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;

            case 9:
            {
                //vetor dividido em 8 - usando 8 threads
                clock_gettime(CLOCK_REALTIME, &inicioT);
                mergeSort(vetor, 8, 8);
                clock_gettime(CLOCK_REALTIME, &finalT);
                calculaTempo(inicioT, finalT);
                //imprimeVetor(vetor);

            }break;  

            case 0:
            {
                //fechando o programa
                printf("\nFechando o programa...");
                return 0;
            }break;
        }

    }while(op!=0);
    
    free(vetor);
    return 0;
}
