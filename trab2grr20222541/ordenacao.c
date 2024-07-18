#include "ordenacao.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[])
{
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

	int *vetorAux = (int *)malloc(tam * sizeof(int));

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

	for (int i = tam - 1; i > 0; --i)
	{
		trocar(vetor, 0, i);
		maxHeapfy(vetor, 0, i, heapComp);
	}

	return *heapComp;
}

void fazerMaxHeap(int *vetor, int tam, int *heapComp)
{

	for (int i = (tam / 2) - 1; i >= 0; i--)
		maxHeapfy(vetor, i, tam, heapComp);
	return;
}

void maxHeapfy(int *vetor, int i, int tam, int *heapComp)
{

	int fEsquerdo = 2 * i + 1;
	int fDireito = 2 * i + 2;
	int maior;

	if (fEsquerdo < tam && *(vetor + fEsquerdo) > *(vetor + i))
		maior = fEsquerdo;
	else
		maior = i;

	*heapComp += 1;

	if (fDireito < tam && *(vetor + fDireito) > *(vetor + maior))
	{
		*heapComp += 1;
		maior = fDireito;
	}

	if (maior != i)
	{
		trocar(vetor, i, maior);
		maxHeapfy(vetor, maior, tam, heapComp);
	}

	return;
}

// ----------------------------------------------------------------

// ----------------------MERGE SR----------------------------------

uint64_t mergeSortSR(int vetor[], size_t tam)
{

	int mergeSRcomp = 0;

	auxMergeSortSR(vetor, tam, &mergeSRcomp);
	return mergeSRcomp;
}

void auxMergeSortSR(int vetor[], int tam, int *mergeSRcomp)
{

	int tamanho_atual;
	int inicio_esquerda;

	for (tamanho_atual = 1; tamanho_atual <= tam - 1; tamanho_atual = 2 * tamanho_atual)
	{

		for (inicio_esquerda = 0; inicio_esquerda < tam - 1; inicio_esquerda += 2 * tamanho_atual)
		{

			int meio = inicio_esquerda + tamanho_atual - 1;
			int fim_direita = ((inicio_esquerda + 2 * tamanho_atual - 1) < (tam - 1)) ? (inicio_esquerda + 2 * tamanho_atual - 1) : (tam - 1);

			if (meio >= tam)
				break;

			if (fim_direita >= tam)
				fim_direita = tam - 1;

			if (meio >= tam - 1)
				meio = tam - 1;

			if (fim_direita >= tam)
				fim_direita = tam - 1;

			if (inicio_esquerda < meio && meio < fim_direita)
			{

				mergirSR(vetor, inicio_esquerda, meio, fim_direita, mergeSRcomp);
			}
		}
	}
}

void mergirSR(int vetor[], int inicio, int meio, int fim, int *mergeSRcomp)
{

	int i, j, k;
	int sub1 = meio - inicio + 1;
	int sub2 = fim - meio;

	if (sub1 <= 0 || sub2 <= 0)
	{
		printf("subvetores inválidos.\n");
		return;
	}

	int *Esq = (int *)malloc(sub1 * sizeof(int));
	int *Dir = (int *)malloc(sub2 * sizeof(int));

	if (Esq == NULL || Dir == NULL)
	{
		printf("falha ao alocar memoria.\n");
		free(Esq);
		free(Dir);
	}

	for (i = 0; i < sub1; i++)
		Esq[i] = vetor[inicio + i];

	for (j = 0; j < sub2; j++)
		Dir[j] = vetor[meio + 1 + j];

	i = 0;
	j = 0;

	k = inicio;

	while (i < sub1 && j < sub2)
	{

		(*mergeSRcomp)++;

		if (Esq[i] <= Dir[j])
		{
			vetor[k] = Esq[i];
			i++;
		}
		else
		{
			vetor[k] = Dir[j];
			j++;
		}

		k++;
	}

	while (i < sub1)
	{
		vetor[k] = Esq[i];
		i++;
		k++;
	}

	while (j < sub2)
	{
		vetor[k] = Dir[j];
		j++;
		k++;
	}

	free(Esq);
	free(Dir);
}

// ----------------------------------------------------------------

// -----------QUICK SR---------------------------------------------

uint64_t quickSortSR(int vetor[], size_t tam)
{

	int quickSRcomp = 0;

	auxQuickSortSR(vetor, tam, &quickSRcomp);
	return quickSRcomp;
}

void auxQuickSortSR(int vetor[], int tamanho, int *quickSRcomp)
{

	int *pilha = (int *)malloc(tamanho * sizeof(int));

	if (pilha == NULL)
	{

		printf("falha ao alocar memoria.\n");
	}

	int topo = -1;

	pilha[++topo] = 0;
	pilha[++topo] = tamanho - 1;

	while (topo >= 0)
	{

		int final = pilha[topo--];
		int começo = pilha[topo--];

		int p = particiona(vetor, começo, final, quickSRcomp);

		if (p - 1 > começo)
		{
			pilha[++topo] = começo;
			pilha[++topo] = p - 1;
		}

		if (p + 1 < final)
		{
			pilha[++topo] = p + 1;
			pilha[++topo] = final;
		}
	}

	free(pilha);
}

// ----------------------------------------------------------------

uint64_t heapSortSR(int vetor[], size_t tam)
{

	int heapCompSR = 0;
	auxHeapSort(vetor, tam, &heapCompSR);

	return heapCompSR;
}

int auxHeapSortSR(int *vetor, int tam, int *heapCompSR)
{

	fazerMaxHeap(vetor, tam, heapCompSR);

	for (int i = tam - 1; i > 0; --i)
	{
		trocar(vetor, 0, i);
		maxHeapfySR(vetor, 0, i, heapCompSR);
	}

	return *heapCompSR;
}

void maxHeapfySR(int *vetor, int i, int tam, int *heapCompSR)
{

	int maior = i;
	int esq, dir;

	while (maior < tam / 2)
	{
		esq = 2 * i + 1;
		dir = 2 * i + 2;

		if (esq < tam && vetor[esq] > vetor[maior])
			maior = esq;

		if (dir < tam && vetor[dir] > vetor[maior])
			maior = dir;

		*heapCompSR += 2;

		if (maior != i)
		{
			trocar(vetor, i, maior);
			i = maior;
		}
		else
		{
			break;
		}
	}
}
