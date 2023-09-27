#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[])
{
	// substitua por seu nome
	strncpy(nome, "Matheus Ferreira Marquesini", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME - 1] = '\0'; // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR()
{
	return 20222541;
}

void imprimirVetor(int *vetor, int tam)
{
	for (int i = 0; i < tam; i++)
		printf("[%d] ", *(vetor + i));
	printf("\n");
}

void preencheVetor(int *vetor, int tam)
{
	for (int i = 0; i < tam; ++i)
		*(vetor + i) = rand() % 99;
}

int trocar(int *vetor, int indexIni, int tam)
{
	int aux = *(vetor + indexIni);
	*(vetor + indexIni) = *(vetor + tam);
	*(vetor + tam) = aux;

	return *vetor;
}

//----------------------------------------------------BUSCA SEQUENCIAL
int auxBuscaSequencial(int *vetor, int indexIni, int tam, int valor, int *numComparacoes)
{

	if (indexIni > tam)
		return indexIni - 1;

	if (valor >= *(vetor + tam))
	{
		*numComparacoes += 1;
		return tam;
	}

	*numComparacoes += 1;
	return auxBuscaSequencial(vetor, indexIni, tam - 1, valor, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes)
{
	int indexIni = 0;
	*numComparacoes = 0;

	int aux = auxBuscaSequencial(vetor, indexIni, tam - 1, valor, numComparacoes);

	if (aux < 0)
		aux = 0;

	return aux;
}

//----------------------------------------------------BUSCA BINARIA
int auxBuscaBinaria(int *vetor, int indexIni, int tam, int valor, int *nComparacao)
{
	int meio = (indexIni + tam) / 2;

	if (indexIni > tam)
		return indexIni - 1;

	if (valor < *(vetor + meio))
	{
		*nComparacao += 1;
		return auxBuscaBinaria(vetor, indexIni, meio - 1, valor, nComparacao);
	}

	*nComparacao += 1;
	return auxBuscaBinaria(vetor, meio + 1, tam, valor, nComparacao);
}

int buscaBinaria(int vetor[], int tam, int valor, int *nComparacao)
{
	int indexIni = 0;
	*nComparacao = 0;

	int aux = auxBuscaBinaria(vetor, indexIni, tam - 1, valor, nComparacao);

	if (aux < 0)
		aux = 0;

	return aux;
}

//----------------------------------------------------INSERTION SORT
int inserir(int *vetor, int indexIni, int tam, int *insertCompara)
{

	int indexAux = auxBuscaBinaria(vetor, indexIni, tam - 1, *(vetor + tam), insertCompara);
	int i = tam;

	while (i > indexAux + 1)
	{
		trocar(vetor, i, i - 1);
		i--;
	}
	return *vetor;
}

int auxInsertionSort(int *vetor, int indexIni, int tam, int *insertCompara)
{

	if (indexIni >= tam)
		return *vetor;

	auxInsertionSort(vetor, indexIni, tam - 1, insertCompara);
	inserir(vetor, indexIni, tam, insertCompara);

	return *vetor;
}

int insertionSort(int vetor[], int tam)
{
	int indexIni = 0;
	int insertCompara = 0;

	auxInsertionSort(vetor, indexIni, tam, &insertCompara);

	return insertCompara;
}

//----------------------------------------------------SELECTION SORT

int achaMenor(int *vetor, int indexIni, int tam, int *selectComparacao)
{

	int menor = indexIni;
	int i = indexIni + 1;

	while (i <= tam)
	{

		if (*(vetor + i) < *(vetor + menor))
		{
			*selectComparacao += 1;
			menor = i;
		}
		*selectComparacao += 1;
		i++;
	}
	return menor;
}

int auxSelectionSort(int *vetor, int indexIni, int tam, int *selectComparacao)
{

	if (indexIni >= tam)
		return *vetor;

	trocar(vetor, indexIni, achaMenor(vetor, indexIni, tam, selectComparacao));

	return auxSelectionSort(vetor, indexIni + 1, tam, selectComparacao);
}

int selectionSort(int vetor[], int tam)
{
	int indexIni = 0;
	int selectComparacao = 0;

	auxSelectionSort(vetor, indexIni, tam, &selectComparacao);

	return selectComparacao;
}

//----------------------------------------------------MERGE SORT

int copiar(int *vetor, int *vetorAux, int indexIni, int tam)
{
	int i = 0;

	while (i <= tam - indexIni)
	{
		*(vetor + indexIni + i) = *(vetorAux + i);
		i++;
	}

	return *vetorAux;
}

int merge(int *vetor, int *vetorAux, int indexIni, int meio, int tam, int *mergeComparacao)
{

	int k = 0;
	int i = indexIni;
	int j = meio + 1;
	int indexAux;

	if (indexIni >= tam)
		return *vetor;

	while (k <= tam - indexIni)
	{
		if (j > tam || (i <= meio && vetor[i] <= vetor[j]))
		{
			*mergeComparacao += 1;
			indexAux = i;
			i++;
		}
		else
		{
			*mergeComparacao += 1;
			indexAux = j;
			j++;
		}
		vetorAux[k] = vetor[indexAux];
		k++;
	}
	return copiar(vetor, vetorAux, indexIni, tam);
}

int auxMergeSort(int *vetor, int vetorAux[], int indexIni, int tam, int *mergeComparacao)
{

	if (indexIni >= tam)
		return *vetor;

	int meio = (indexIni + tam) / 2;

	auxMergeSort(vetor, vetorAux, indexIni, meio, mergeComparacao);
	auxMergeSort(vetor, vetorAux, meio + 1, tam, mergeComparacao);

	return merge(vetor, vetorAux, indexIni, meio, tam, mergeComparacao);
}

int mergeSort(int vetor[], int tam)
{
	int indexIni = 0;
	int mergeComparacao = 0;
	int *vetorAux = malloc(tam * sizeof(int));

	if (vetorAux == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	auxMergeSort(vetor, vetorAux, indexIni, tam, &mergeComparacao);

	return mergeComparacao;
}

//----------------------------------------------------QUICK SORT
int particionaVetor(int *vetor, int indexIni, int tam, int *quickComparacao)
{
	int pivo = *(vetor + tam);
	int indexM = indexIni;

	for (int i = indexIni; i < tam; ++i)
	{
		if (*(vetor + i) <= pivo)
		{
			*quickComparacao += 1;
			trocar(vetor, indexM, i);
			indexM++;
		}
		*quickComparacao += 1;
	}

	trocar(vetor, indexM, tam);
	return indexM;
}

int auxQuickSort(int *vetor, int indexIni, int tam, int *quickComparacao)
{
	if (indexIni >= tam)
		return *vetor;

	int meio = particionaVetor(vetor, indexIni, tam, quickComparacao);

	auxQuickSort(vetor, indexIni, meio - 1, quickComparacao);
	auxQuickSort(vetor, meio + 1, tam, quickComparacao);

	return *vetor;
}

int quickSort(int vetor[], int tam)
{
	int indexIni = 0;
	int quickComparacao = 0;

	auxQuickSort(vetor, indexIni, tam, &quickComparacao);

	return quickComparacao;
}
