#include "ordenacao.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Matheus Ferreira Marquesini", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20222541; }

void encheVetor(int *vetor, int tam, int n)
{
	for (int i = 0; i < tam; ++i)
		vetor[i] = rand() % n;
}

void imprimeVetor(int vetor[], int tam)
{

	for (int i = 0; i < tam; i++)
	{
		printf("[%d] ", vetor[i]);
	}
	printf("\n");
}

void trocar(int *vetor, int a, int b)
{
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

// ---------------------MERGE--------------------------------------
uint64_t mergeSort(int vetor[], size_t tam) 
{

    int a = 0;
	int b = tam - 1;
	int mergeComp = 0;

	int* vetorAux = (int*) malloc(tam * sizeof(int));

	if (vetorAux == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	auxMergeSort(vetor, vetorAux, a, b, &mergeComp);

	free(vetorAux);

	return mergeComp;

}

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, int *mergeComp)
{

	if (a >= b)
	{
		return;
	}

	int meio = (a + b) / 2;

	auxMergeSort(vetor, vetorAux, a, meio, mergeComp);
	auxMergeSort(vetor, vetorAux, meio + 1, b, mergeComp);

	return mergir(vetor, vetorAux, a, meio, b, mergeComp);
}

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, int *mergeComp)
{

	int k = 0;
	int i = a;
	int j = meio + 1;
	int aux;

	if (a >= b)
	{
		return;
	}

	for (k = 0; k <= b - a; k++)
	{
		if (j > b || (i <= meio && vetor[i] <= vetor[j]))
		{
			*mergeComp += 1;
			aux = i;
			i++;
		}
		else
		{
			*mergeComp += 1;
			aux = j;
			j++;
		}
		vetorAux[k] = vetor[aux];
	}

	return copiar(vetor, vetorAux, a, b);
}

void copiar(int *vetor, int *vetorAux, int a, int b)
{

	for (int i = 0; i <= b - a; i++)
	{

		vetor[a + i] = vetorAux[i];
	}
}

// ----------------------------------------------------------------

// ---------------------QUICK--------------------------------------

uint64_t quickSort(int vetor[], size_t tam) 
{

    int a = 0;
	int b = tam - 1;
	int quickComp = 0;

	auxQuickSort(vetor, a, b, &quickComp);

	return quickComp;
}

void auxQuickSort(int *vetor, int a, int b, int *quickComp)
{

	if (a >= b)
	{
		return;
	}

	int m = particiona(vetor, a, b, quickComp);

	auxQuickSort(vetor, a, m - 1, quickComp);
	auxQuickSort(vetor, m + 1, b, quickComp);

	return;
}

int particiona(int *vetor, int a, int b, int *quickComp)
{

	int pivo = vetor[b];
	int m = a;

	for (int i = a; i < b; ++i)
	{
		if (vetor[i] <= pivo)
		{
			*quickComp += 1;
			trocar(vetor, m, i);
			m++;
		}
		*quickComp += 1;
	}

	trocar(vetor, m, b);
	return m;
}

// ----------------------------------------------------------------

// ----------------------HEAP--------------------------------------

uint64_t heapSort(int vetor[], size_t tam) 
{

    int heapComp = 0;
    auxHeapSort(vetor, tam, &heapComp);

    return heapComp;
}

int auxHeapSort(int *vetor, int tam, int *heapComp)
{

    fazerMaxHeap(vetor, tam, heapComp);

    for (int i = tam - 1; i > 0; --i){
        trocar(vetor, 0, i);
        maxHeapfy(vetor, 0, i, heapComp);
    }

    return *heapComp;
}

void fazerMaxHeap(int *vetor, int tam, int *heapComp)
{

	for(int i=(tam/2) - 1; i>=0; i--)
			maxHeapfy(vetor, i, tam, heapComp);
	return;

}

void maxHeapfy(int *vetor, int i, int tam, int *heapComp)
{

	int fEsquerdo = 2*i+1;
	int fDireito = 2*i+2;
	int maior;
	
	if (fEsquerdo < tam && *(vetor + fEsquerdo) > *(vetor + i))
		maior = fEsquerdo;
	else
		maior = i;

	*heapComp += 1;

	if(fDireito < tam && *(vetor + fDireito) > *(vetor + maior)){
		*heapComp += 1;
		maior = fDireito;
	}

	if(maior != i){
		trocar(vetor, i, maior);
		maxHeapfy(vetor, maior, tam, heapComp);
	}

	return;

}

// ----------------------------------------------------------------

uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}