#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR];
    // char nomeAlg[MAX_CHAR];
    unsigned long numComp = 0;

    int tamVetor = 24;
    int* vetor = (int*)malloc(tamVetor * sizeof(int));
	unsigned int* vetor_count = (unsigned int*)malloc((tamVetor+1) * sizeof(unsigned int));
	
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    // vetor[0] = 1;
    // vetor[1] = 10;
    // vetor[2] = 12;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    clock_t start, end; // variáveis do tipo clock_t
	double total;

    srand(time(NULL));

    printf("-------------------------------------------------------------\n");
    printf("merge sort\n");
	printf("\n");
    encheVetor(vetor, tamVetor);
    printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
    printf("\n");
    start = clock();
    numComp = mergeSort(vetor, tamVetor);
    printf("Vetor ordenado : \n");
	imprimeVetor(vetor, tamVetor);
    printf("\n");
	printf("n de comp : %ld\n", numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;

	printf("\n");
	printf("-------------------------------------------------------------\n");

    printf("-------------------------------------------------------------\n");
	//--------quick sort---------
	printf("quick sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;

	printf("-------------------------------------------------------------\n");


    printf("-------------------------------------------------------------\n");
	//--------heap sort---------
	printf("heap sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	numComp = heapSort(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %lu\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;

	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	//--------tim sort---------
	printf("tim sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	numComp = algoritmoExtra(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %lu\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;

	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	//--------counting sort---------
	int k = 10;
	printf("couting sort\n");
	printf("\n");
	for (int i = 0; i < tamVetor+1; ++i)
		vetor_count[i] = rand() % k;
	printf("Vetor : \n");
	for (int i = 0; i < tamVetor+1; i++)
	{
		printf("[%d] ", vetor_count[i]);
	}
	printf("\n");
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	countingSort(vetor_count, tamVetor, k);
	// printf("Vetor ordenado : \n");
	// imprimeVetor(vetor_count, tamVetor);
	printf("\n");
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("-------------------------------------------------------------\n");


    free(vetor);
	free(vetor_count);

    return 0;
}
