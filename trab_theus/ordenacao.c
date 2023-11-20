#include "ordenacao.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define RUN 32

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Matheus Ferreira Marquesini", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

void getNomeAlgoritmoExtra(char nomeAlg[]) {
    // substitua pelo nome do algoritmo que você escolheu
    strncpy(nomeAlg, "Timsort", MAX_CHAR);
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

void maxHeapfy(int *vetor, int i, int tam, int *heapComp){

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

void fazerMaxHeap(int *vetor, int tam, int *heapComp){

	for(int i=(tam/2); i>=0; i--)
			maxHeapfy(vetor, i, tam, heapComp);
	return;
}

int auxHeapSort(int *vetor, int tam, int *heapComp){
    fazerMaxHeap(vetor, tam, heapComp);

    for (int i = tam; i > 0; --i){
        trocar(vetor, 0, i);
        maxHeapfy(vetor, 0, i - 1, heapComp);
    }

    return *heapComp;
}

unsigned long heapSort(int vetor[], int tam){
    int heapComp = auxHeapSort(vetor, tam, &heapComp);

    return heapComp;
}


// ----------------------------------------------------------------

//----------------------------------------------------TIM SORT

void insertionSort(int vetor[], int esq, int dir, int *tim_comp)
{
	for (int i = esq + 1; i <= dir; i++)
	{
		int key = vetor[i];
		int j = i - 1;

		while (j >= esq && vetor[j] > key)
		{
			vetor[j + 1] = vetor[j];
			j--;
			(*tim_comp)++;
		}
		vetor[j + 1] = key;
	}
}

void merge_tim(int vetor[], int l, int m, int r, int *tim_comp)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = vetor[l + i];
	for (j = 0; j < n2; j++)
		R[j] = vetor[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vetor[k] = L[i];
			i++;
		}
		else
		{
			vetor[k] = R[j];
			j++;
		}
		k++;
		(*tim_comp)++;
	}

	while (i < n1)
	{
		vetor[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vetor[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

unsigned int timSort(int vetor[], int n, int *tim_comp)
{

	for (int i = 0; i < n; i += RUN)
	{
		insertionSort(vetor, i, (i + RUN - 1 < n - 1) ? (i + RUN - 1) : (n - 1), tim_comp);
	}

	for (int tam = RUN; tam < n; tam = 2 * tam)
	{
		for (int esq = 0; esq < n; esq += 2 * tam)
		{
			int meio = esq + tam - 1;
			int dir = (esq + 2 * tam - 1 < n - 1) ? (esq + 2 * tam - 1) : (n - 1);

			if (meio < dir)
			{
				merge_tim(vetor, esq, meio, dir, tim_comp);
			}
		}
	}
	return (*tim_comp);
}

unsigned long algoritmoExtra(int vetor[], int tam)
{
	int tim_comp = 0;
	return timSort(vetor, tam, &tim_comp);
}

// -------------------------------------------------------COUNTING SORT
void countingSort(unsigned int vetor[], int tam, int maxVal) 
{

    int *vetorAux = (int *)malloc((maxVal+1) * sizeof(int));
	if(vetorAux == NULL)
    {
		printf("Falha fatal. Impossível alocar memoria.");
        return;
	}

    int* vetorAuxR = (int*)malloc((tam+1) * sizeof(int));
	if(vetorAuxR == NULL)
    {
		printf("Falha fatal. Impossível alocar memoria.");
        return;
	}

    for (int i = 0; i <= maxVal; i++) {
        vetorAux[i] = 0;
    }

    for(int i = 1; i <= tam; i++)
    {
       vetorAux[vetor[i]] = vetorAux[vetor[i]] + 1; 
    }

    for(int i = 1; i <= maxVal; i++)
    {
        vetorAux[i] = vetorAux[i] + vetorAux[i-1];
    }


    for(int i = tam; i >= 1; i--)
    {
        vetorAuxR[vetorAux[vetor[i]]] = vetor[i];
        vetorAux[vetor[i]] = vetorAux[vetor[i]] - 1;
    }

	printf("Vetor ordenado : \n");

     for(int i = 1; i <= tam; i++) {
        printf("[%d] ", vetorAuxR[i]);
	 }

	printf("\n");
	
    free(vetorAux);
    free(vetorAuxR);
}
