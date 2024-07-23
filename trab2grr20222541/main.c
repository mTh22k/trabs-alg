#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main()
{
	char nome[MAX_CHAR];
	int numComp;

	int tamVetor = 1048976;
	int n = 1048976;
	int *vetor = (int *)malloc(tamVetor * sizeof(int));
	if (vetor == NULL)
	{
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
	encheVetor(vetor, tamVetor, n);
	printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock();
	numComp = mergeSort(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %d\n", numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;
	printf("\n");
	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	printf("quick sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor, n);
	printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock();
	numComp = quickSort(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %d\n", numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;
	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	printf("heap sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor, n);
	printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock();
	numComp = heapSort(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %d\n", numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;
	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	printf("merge sort SR\n");
	printf("\n");
	encheVetor(vetor, tamVetor, n);
	printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock();
	numComp = mergeSortSR(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %d\n", numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;
	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	printf("quick sort SR\n");
	printf("\n");
	encheVetor(vetor, tamVetor, n);
	printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock();
	numComp = quickSortSR(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %d\n", numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;
	printf("-------------------------------------------------------------\n");

	printf("-------------------------------------------------------------\n");
	printf("heap sort SR\n");
	printf("\n");
	encheVetor(vetor, tamVetor, n);
	printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock();
	numComp = heapSortSR(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %d\n", numComp);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	numComp = 0;
	printf("-------------------------------------------------------------\n");

	free(vetor);

	return 0;
}
