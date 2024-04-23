#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

int main()
{
	char nome[MAX_CHAR_NOME];
	size_t idxBusca;
	uint64_t numComp;

	// Dica: somente é posśivel criar vetores grandes utilizando alocação
	// dinâmica de memória Veja um exemplo de alocação dinâmica a seguir
	ssize_t tamVetor = 150000;
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

	// Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end; // variáveis do tipo clock_t
	double total;

	srand(time(NULL));

	printf("-------------------------------------------------------------\n");
	//--------insertion sort recursivo---------
	printf("insertion sort recursivo\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	start = clock(); // start recebe o "ciclo" corrente
	numComp = insertionSortRec(vetor, tamVetor);
	// printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("-------------------------------------------------------------\n");
	printf("\n");

	//--------insertion sort iterativo---------
	printf("insertion sort iterativo\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	start = clock(); // start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamVetor);
	// printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("-------------------------------------------------------------\n");
	printf("\n");

	//--------selection sort recursivo---------
	printf("selection sort recursivo\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	start = clock(); // start recebe o
	numComp = selectionSortRec(vetor, tamVetor);
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("-------------------------------------------------------------\n");
	printf("\n");

	//--------selection sort iterativo---------
	printf("selection sort iterativo\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	start = clock(); // start recebe o
	numComp = selectionSort(vetor, tamVetor);
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("-------------------------------------------------------------\n");
	printf("\n");

	//--------merge sort---------
	printf("merge sort\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	start = clock(); // start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamVetor);
	// printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("-------------------------------------------------------------\n");
	printf("\n");

	int numBusca = rand() % 9;
	printf("buscar o numero %d : \n", numBusca);
	printf("-------------------------------------------------------------\n");

	//--------busca sequencial recursivo---------
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca sequencial recursiva\n");
	idxBusca = buscaSequencialRec(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %ld\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	printf("-------------------------------------------------------------\n");
	// ----------------------------

	//--------busca sequencial iterativo---------
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca sequencial iterativa\n");
	idxBusca = buscaSequencial(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %ld\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	printf("-------------------------------------------------------------\n");
	// ----------------------------

	//--------busca binaria recursivo---------
	printf("\n");
	// printf("Vetor : \n");
	mergeSort(vetor, tamVetor);
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca binaria recursiva\n");
	idxBusca = buscaBinariaRec(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %ld\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	printf("-------------------------------------------------------------\n");
	// ----------------------------

	//--------busca binaria iterativo---------
	printf("\n");
	// printf("Vetor : \n");
	mergeSort(vetor, tamVetor);
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca binaria iterativa\n");
	idxBusca = buscaBinaria(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %ld\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	printf("-------------------------------------------------------------\n");
	// ----------------------------

	free(vetor);

	return 0;
}
