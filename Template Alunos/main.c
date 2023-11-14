#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR];
    // char nomeAlg[MAX_CHAR];
    long numComp;

    int tamVetor = 20;
    int* vetor = (int*)malloc(tamVetor * sizeof(int));
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

	printf("-------------------------------------------------------------\n");





    // numComp = heapSort(vetor, 3);

    // getNomeAlgoritmoExtra(nomeAlg);
    // printf("Executando %s\n", nomeAlg);
    // numComp = algoritmoExtra(vetor, 3);

    // printf("NumComp: %d\n", numComp);

    // unsigned int vetorUnsigned[3] = {5, 4, 3};
    // countingSort(vetorUnsigned, 3, 12);

    // for (int i = 0; i < 3; ++i) printf("%d ", vetor[i]);

    // printf("\n");

    // for (int i = 0; i < 3; ++i) printf("%d ", vetorUnsigned[i]);

    // printf("\n");

    free(vetor);

    return 0;
}
