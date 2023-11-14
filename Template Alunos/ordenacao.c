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

void getNomeAlgoritmoExtra(char nomeAlg[]) {
    // substitua pelo nome do algoritmo que você escolheu
    strncpy(nomeAlg, "IntroSort", MAX_CHAR);
    nomeAlg[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() { return 20222541; }


void encheVetor(int *vetor, int tam)
{
	for (int i = 0; i < tam; ++i)
		vetor[i] = rand() % 99;
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

void copiar(int *vetor, int *vetorAux, int a, int b)
{

	for (int i = 0; i <= b - a; i++)
	{

		vetor[a + i] = vetorAux[i];
	}
}

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, unsigned long *mergeComp)
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

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, unsigned long *mergeComp)
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

unsigned long mergeSort(int vetor[], int tam)
{

	int a = 0;
	int b = tam;
	unsigned long mergeComp = 0;

	int *vetorAux = malloc(tam * sizeof(int));

	if (vetorAux == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	auxMergeSort(vetor, vetorAux, a, b, &mergeComp);

	free(vetorAux);

	return mergeComp;
}


// ----------------------------------------------------------------

// ----------------------------QUICK-------------------------------

int particiona(int *vetor, int a, int b, unsigned long *quickComp)
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

void auxQuickSort(int *vetor, int a, int b, unsigned long *quickComp)
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

unsigned long quickSort(int vetor[], int tam)
{

	int a = 0;
	int b = tam;
	unsigned long quickComp = 0;

	auxQuickSort(vetor, a, b, &quickComp);

	return quickComp;
}


// ----------------------------------------------------------------


//----------------------------------------------------HEAP SORT

void maxHeapfy(int *vetor, int i, int tam, long *heapComp){

	int fEsquerdo = 2*i+1;
	int fDireito = 2*i+2;
	int maior;
	
	if (fEsquerdo <= tam && *(vetor+fEsquerdo) > *(vetor+i))
		maior = fEsquerdo;
	else
		maior = i;

	*heapComp += 1;

	if(fDireito <= tam && *(vetor+fDireito) > *(vetor+maior)){
		*heapComp += 1;
		maior = fDireito;
	}

	if(maior != i){
		trocar(vetor, i, maior);
		maxHeapfy(vetor, maior, tam, heapComp);
	}
	return;
}

void fazerMaxHeap(int *vetor, int tam, long *heapComp){

	for(int i=(tam/2); i>=0; i--)
			maxHeapfy(vetor, i, tam, heapComp);
	return;
}

long auxHeapSort(int *vetor, int tam, long *heapComp){

	fazerMaxHeap(vetor, tam, heapComp);

	for (int i=tam; i>0; --i){
		trocar(vetor, 0, i);
		maxHeapfy(vetor, 0, i-1, heapComp);
	}
printf ("AUXheapComp %ln\n",heapComp);
	return *heapComp;
}

unsigned long heapSort(int vetor[], int tam){

	long heapComp = auxHeapSort(vetor, tam, &heapComp);
    printf ("heapComp %ld\n",heapComp);

	return heapComp;
}

// ----------------------------------------------------------------

void countingSort(unsigned int vetor[], int tam, int maxVal) {
    vetor[0] = 99;
    return;
}

unsigned long algoritmoExtra(int vetor[], int tam) {
    vetor[0] = 99;
    return -1;
}