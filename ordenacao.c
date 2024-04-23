#include "ordenacao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[])
{
	// substitua por seu nome
	strncpy(nome, "Matheus Ferreira Marquesini", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME - 1] =
		'\0'; // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20222541; }

void encheVetor(int *vetor, int tam)
{
	for (int i = 0; i < tam; ++i)
		vetor[i] = rand() % 9;
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

// ---------------------busca sequencial-------------------------------------

ssize_t auxBuscaSequencialRec(int v[], int a, int b, int valor, uint64_t *numComparacoes)
{

	if (a > b)
		return -1;

	if (v[a] == valor)
	{
		*numComparacoes += 1;
		return a;
	}

	*numComparacoes += 1;
	return auxBuscaSequencialRec(v, a + 1, b, valor, numComparacoes);
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t *numComparacoes)
{
	int a = 0;
	int b = tam - 1;
	*numComparacoes = 0;

	int res = auxBuscaSequencialRec(vetor, a, b, valor, numComparacoes);

	if (res >= 0)
	{
		return res;
	}

	return -1;
}

ssize_t buscaSequencial(int vetor[], size_t tam, int valor, uint64_t *numComparacoes)
{

	*numComparacoes = 0;

	for (size_t i = 0; i < tam; i++)
	{
		(*numComparacoes)++;

		if (vetor[i] == valor)
		{
			return i;
		}
	}

	return -1;
}

// ---------------busca binaria----------------------------------------

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, uint64_t *numComparacoes)
{

	*numComparacoes = 0;

	int a = 0;
	int b = tam - 1;

	int res = auxBuscaBinariaRec(vetor, a, b, valor, numComparacoes);

	if (res >= 0)
	{
		return res;
	}

	return -1;
}

ssize_t auxBuscaBinariaRec(int v[], int a, int b, int x, uint64_t *numComparacoes)
{

	if (a > b)
	{
		return -1;
	}

	int m = (a + b) / 2;

	if (v[m] == x)
	{
		*numComparacoes += 1;
		return m;
	}

	if (x < v[m])
	{
		*numComparacoes += 1;
		return auxBuscaBinariaRec(v, a, m - 1, x, numComparacoes);
	}
	else
	{
		*numComparacoes += 1;
		return auxBuscaBinariaRec(v, m + 1, b, x, numComparacoes);
	}
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor, uint64_t *numComparacoes)
{

	*numComparacoes = 0;
	ssize_t a = 0;
	ssize_t b = tam - 1;
	ssize_t m;

	while (a <= b)
	{
		(*numComparacoes)++;

		m = a + (b - a) / 2;

		if (vetor[m] == valor)
		{
			return m;
		}

		if (vetor[m] > valor)
		{
			b = m - 1;
		}
		else
		{
			a = m + 1;
		}
	}
	return -1;
}

// ---------------insertion sort----------------------------------------

void inserir(int *vetor, int a, int b, uint64_t *insertionComp)
{
	int chave = vetor[b];
	int i = b - 1;

	while (i >= a && vetor[i] > chave)
	{
		vetor[i + 1] = vetor[i];
		i--;
		(*insertionComp)++;
	}

	vetor[i + 1] = chave;
}

void auxInsertionSortRec(int *vetor, int a, int b, uint64_t *insertionComp)
{
	if (a >= b)
		return;

	auxInsertionSortRec(vetor, a, b - 1, insertionComp);
	inserir(vetor, a, b, insertionComp);
}

uint64_t insertionSortRec(int vetor[], size_t tam)
{
	int a = 0;
	int b = tam - 1;
	uint64_t insertionComp = 0;

	auxInsertionSortRec(vetor, a, b, &insertionComp);

	return insertionComp;
}

uint64_t insertionSort(int vetor[], size_t tam)
{
	uint64_t insertionComp = 0;

	for (size_t i = 1; i < tam; i++)
	{
		int comp = vetor[i];
		ssize_t j = i - 1;

		while (j >= 0 && vetor[j] > comp)
		{
			vetor[j + 1] = vetor[j];
			j--;
			insertionComp++;
		}

		vetor[j + 1] = comp;
	}

	return insertionComp;
}

// ------------------------selection sort-------------------------------

int minimo(int *vetor, int a, int b, uint64_t *selectionComp)
{

	int min = a;

	for (int i = a + 1; i <= b; i++)
	{

		*selectionComp += 1;
		if (vetor[min] > vetor[i])
		{
			min = i;
		}
	}
	return min;
}

void auxSelectionSortRec(int *vetor, int a, int b, uint64_t *selectionComp)
{

	if (a >= b)
	{
		return;
	}

	trocar(vetor, a, minimo(vetor, a, b, selectionComp));
	return auxSelectionSortRec(vetor, a + 1, b, selectionComp);
}

uint64_t selectionSortRec(int vetor[], size_t tam)
{

	int a = 0;
	int b = tam - 1;
	uint64_t selectionComp = 0;

	auxSelectionSortRec(vetor, a, b, &selectionComp);

	return selectionComp;
}

uint64_t selectionSort(int vetor[], size_t tam)
{

	uint64_t numComparacoes = 0;

	for (size_t i = 0; i < tam - 1; i++)
	{
		size_t indice_min = i;

		for (size_t j = i + 1; j < tam; j++)
		{
			numComparacoes++;
			if (vetor[j] < vetor[indice_min])
			{
				indice_min = j;
			}
		}

		if (indice_min != i)
		{
			trocar(vetor, i, indice_min);
		}
	}

	return numComparacoes;
}

// -----------------------merge sort----------------------------------------------

void copiar(int *vetor, int *vetorAux, int a, int b)
{

	for (int i = 0; i <= b - a; i++)
	{

		vetor[a + i] = vetorAux[i];
	}
}

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, uint64_t *mergeComp)
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

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, uint64_t *mergeComp)
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

uint64_t mergeSort(int vetor[], size_t tam)
{

	int a = 0;
	int b = tam - 1;
	uint64_t mergeComp = 0;

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
