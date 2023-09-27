
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main()
{
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;

	// Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	// Veja um exemplo de alocação dinâmica a seguir

	int tamVetor = 10;
	int *vetor = malloc(tamVetor * sizeof(int));
	if (vetor == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	// Depois de alocado, o vetor pode ser utilizado normalmente
	// Não esqueça de desalocar no final do programa via free

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	// TEMPOS

	// Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end; // viáveis do tipo clock_t
	double total;

	srand((unsigned)time(NULL));

	printf("\nTempo de execucao(segundos):\n");

	// InsertionSort
	preencheVetor(vetor, tamVetor);
	start = clock();
	numComp = insertionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("\n\tinsertionSort:\n\t%f seg - Comparacoes: %d\n\t", total, numComp);
	imprimirVetor(vetor, tamVetor);

	// SelectionSort
	preencheVetor(vetor, tamVetor);
	start = clock();
	numComp = selectionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("\n\tselectionSort:\n\t%f seg - Comparacoes: %d\n\t", total, numComp);
	imprimirVetor(vetor, tamVetor);

	// MergeSort
	preencheVetor(vetor, tamVetor);
	start = clock();
	numComp = mergeSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("\n\tmergeSort:\n\t%f seg - Comparacoes: %d\n\t", total, numComp);
	imprimirVetor(vetor, tamVetor);

	// QuickSort
	preencheVetor(vetor, tamVetor);
	start = clock();
	numComp = quickSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("\n\tquickSort:\n\t%f seg - Comparacoes: %d\n\t", total, numComp);
	imprimirVetor(vetor, tamVetor);

	// BUSCA
	int VALORBUSCADO = rand() % 99;
	printf("\nBuscando o valor %d:\n", VALORBUSCADO);
	idxBusca = buscaSequencial(vetor, tamVetor, VALORBUSCADO, &numComp);
	printf("\n\tSequencial - posicao: [%d] \tComparacoes: %d\n", idxBusca, numComp);

	idxBusca = buscaBinaria(vetor, tamVetor, VALORBUSCADO, &numComp);
	printf("\tBinaria -    posicao: [%d] \tComparacoes: %d\n", idxBusca, numComp);

	free(vetor);

	return 0;
}
