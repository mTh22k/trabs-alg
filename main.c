#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp;

    // Dica: somente é posśivel criar vetores grandes utilizando alocação
    // dinâmica de memória Veja um exemplo de alocação dinâmica a seguir
    ssize_t tamVetor = 10;
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }
    // Depois de alocado, o vetor pode ser utilizado normalmente
    // Não esqueça de desalocar no final do programa via free

    // vetor[0] = 1;
    // vetor[1] = 10;
    // vetor[2] = 12;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    // Para medir o tempo, inclua time.h, e siga o exemplo:
    clock_t start, end;  // variáveis do tipo clock_t
    double total;

    srand(time(NULL));

    printf("-------------------------------------------------------------\n");
	//--------insertion sort---------
	printf("insertion sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	numComp = insertionSortRec(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
    printf("-------------------------------------------------------------\n");
	printf("\n");


    printf("-------------------------------------------------------------\n");
	//--------selection sort---------
	printf("selection sort\n");
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o 
	imprimeVetor(vetor, tamVetor);
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
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	start = clock(); // start recebe o "ciclo" corrente
	numComp = mergeSort(vetor, tamVetor);
	printf("Vetor ordenado : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("n de comp : %ld\n", numComp);
	end = clock(); // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
    printf("-------------------------------------------------------------\n");
	printf("\n");

    printf("-------------------------------------------------------------\n");
	int numBusca = rand() % 9;
	printf("buscar o numero %d : \n", numBusca);

	//--------busca sequencial---------
	printf("\n");
	encheVetor(vetor, tamVetor);
	printf("Vetor : \n");
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca sequencial\n");
	idxBusca = buscaSequencialRec(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %ld\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	// ----------------------------

    //--------busca binaria---------
	printf("\n");
	printf("Vetor : \n");
	mergeSort(vetor, tamVetor);
	imprimeVetor(vetor, tamVetor);
	printf("\n");
	printf("busca binaria\n");
	idxBusca = buscaBinariaRec(vetor, tamVetor, numBusca, &numComp);
	printf("no indice : %ld\n", idxBusca);
	printf("n de comp : %ld\n", numComp);
	// ----------------------------

    free(vetor);

    return 0;
}
