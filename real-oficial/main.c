#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	long numComp;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int tamVetor = 7;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//Não esqueça de desalocar no final do programa via free
		
	vetor[0] = 121;
	vetor[1] = 1021;
	vetor[2] = 13;
	vetor[3] = 10;
	vetor[4] = 1030;
	vetor[5] = 10530;
	vetor[6] = 1;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;//variáveis do tipo clock_t
    double total;

	printf("vetor : \n ");
	for(int i=0; i < 7; i++){
		printf("[%d] ", vetor[i]);
	}
	printf("\n");

	//--------insertion sort---------
	printf("insertion sort\n");
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, 7);
	printf("n de comp : %ld\n",numComp);
	end = clock();//end recebe o "ciclo" corrente
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("\n");

	//-------------------------------

	numComp = selectionSort(vetor, 7);
	numComp = mergeSort(vetor, 7);
	numComp = quickSort(vetor, 7);
	numComp = heapSort(vetor, 7);

	printf("vetor : \n ");
	for(int i=0; i < 7; i++){
		printf("[%d] ", vetor[i]);
	}
	printf("\n");

	//--------busca sequencial---------
	printf("\n");
	printf("busca sequencial\n");
	printf("buscando o valor : 10 \n");
	idxBusca = buscaSequencial(vetor, 7, 10, &numComp);
	printf("no indice : %d\n",idxBusca);
	printf("n de comp : %ld\n",numComp);
	// ----------------------------

	//--------busca binaria---------
	printf("\n");
	printf("busca binaria\n");
	printf("buscando o valor : 10 \n");
	idxBusca = buscaBinaria(vetor,7, 10, &numComp);
	printf("no indice : %d\n",idxBusca);
	printf("n de comp : %ld\n",numComp);
	// ----------------------------




	free(vetor);

	return 0;
}
