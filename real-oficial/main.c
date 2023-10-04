#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main()
{
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	long numComp;

	// Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	// Veja um exemplo de alocação dinâmica a seguir
	int tamVetor = 100;
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
	//--------insertion sort---------
	printf("insertion sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
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

	printf("\n");

	printf("-------------------------------------------------------------\n");
	//--------selection sort---------
	printf("selection sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" correntegit@github.com:mTh22k/trabs-alg.git
	numComp = selectionSort(vetor, tamVetor);
	// printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("\n");

	printf("-------------------------------------------------------------\n");
	//--------merge sort---------
	printf("merge sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
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

	printf("\n");

	printf("-------------------------------------------------------------\n");
	//--------quick sort---------
	printf("quick sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	numComp = quickSort(vetor, tamVetor);
	// printf("Vetor ordenado : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);

	printf("-------------------------------------------------------------\n");
	int numBusca = rand() % 999;
	printf("buscar o numero %d : \n", numBusca);
	//--------busca sequencial---------
	printf("\n");
	encheVetor(vetor, tamVetor);
	// printf("Vetor : \n");
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca sequencial\n");
	idxBusca = buscaSequencial(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %d\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	// ----------------------------

	//--------busca binaria---------
	printf("\n");
	printf("Vetor : \n");
	quickSort(vetor, tamVetor);
	// imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca binaria\n");
	idxBusca = buscaBinaria(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %d\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	// ----------------------------

	free(vetor);

	return 0;
}
