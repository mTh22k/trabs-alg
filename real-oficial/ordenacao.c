#include "ordenacao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Matheus Ferreira Marquesini", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20222541;
}

void encheVetor(int *vetor, int tam)
{
	for (int i = 0; i < tam; ++i)
		vetor[i] = rand() % 99;
}

void imprimeVetor(int vetor[], int tam) {

	for(int i=0; i < tam; i++){
		printf("[%d] ", vetor[i]);
	}
	printf("\n");
}

void trocar(int *vetor, int a, int b) {
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

// ---------------------busca sequencial-------------------------------------

int auxBuscaSequencial(int v[], int a, int b, int valor, long *numComparacoes)
{

	if (a > b)
		return a - 1;

	if (valor == v[b])
	{
		*numComparacoes += 1;
		return b;
	}

	*numComparacoes += 1;
	return auxBuscaSequencial(v, a, b - 1, valor, numComparacoes);
}

int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes)
{
	int a = 0;
	int b = tam;
	*numComparacoes = 0;

	int res = auxBuscaSequencial(vetor, a, b, valor, numComparacoes);

	if (res >= 0) {
		return res;
	}

	return -1;
}

// -------------------------------------------------------

// ---------------busca binaria----------------------------------------


int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes){
	
	*numComparacoes = 0;

 	int a = 0;
    int b = tam - 1;

    int res = auxBuscaBinaria(vetor,a,b,valor,numComparacoes);

	if (res >= 0) {
		return res;
	}

	return -1;
}

int auxBuscaBinaria(int v[], int a, int b, int x, long* numComparacoes) {

    if (a > b)
    {
        return -1;
    }

    int m = (a + b)/2;

    if (v[m] == x)
    {
		*numComparacoes += 1;
        return m;
    }

    if (x < v[m]) {
		*numComparacoes += 1;
        return auxBuscaBinaria(v,a, m - 1, x,numComparacoes);
    } else {
		*numComparacoes += 1;
        return auxBuscaBinaria(v, m + 1, b ,x,numComparacoes);
    }
    

}

// -------------------------------------------------------


// ---------------insertion sort----------------------------------------

void inserir(int *vetor, int a, int b, long *insertionComp) {
    long p = auxBuscaBinaria(vetor, a, b - 1, vetor[b], insertionComp);
    int i = b - 1;

    while (i > p) {
        trocar(vetor, i, i + 1);
        i--;
    }
}

void auxInsertionSort(int *vetor, int a, int b, long *insertionComp) {
    if (a >= b)
        return;

    auxInsertionSort(vetor, a, b - 1, insertionComp);
    inserir(vetor, a, b, insertionComp);
}

long insertionSort(int vetor[], int tam){
	int a = 0;
	int b = tam;
	long insertionComp = 0;

	auxInsertionSort(vetor, a, b, &insertionComp);

	return insertionComp;
}

// ---------------------------------------------------------------------


// ------------------------selection sort-------------------------------

int minimo(int *vetor, int a, int b, long *selectionComp) {

	int min = a;

	for (int i = a + 1; i <= b; i++) {

			*selectionComp+= 1;
            if (vetor[min] > vetor[i]) {
                min = i;
            }
    }
	return min;
}


void auxSelectionSort(int *vetor, int a, int b, long *selectionComp) {

	if (a >= b) {
		return;
	}

	trocar(vetor, a, minimo(vetor,a,b,selectionComp));
	return auxSelectionSort(vetor, a + 1, b, selectionComp);

}

long selectionSort(int vetor[], int tam) {

	int a = 0;
	int b = tam - 1;
	long selectionComp = 0;

	auxSelectionSort(vetor, a, b, &selectionComp);

	return selectionComp;
}

// -----------------------merge sort----------------------------------------------

void copiar(int *vetor, int *vetorAux, int a, int b) {

	for (int i = 0; i <= b - a; i++) {

    vetor[a + i] = vetorAux[i];

}

}

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, long *mergeComp) {

	int k = 0;
	int i = a;
	int j = meio + 1;
	int aux;

	if (a >= b)
	{
		return;
	}

	for (k = 0; k <= b - a; k++) {
    if (j > b || (i <= meio && vetor[i] <= vetor[j])) {
        *mergeComp += 1;
        aux = i;
        i++;
    } else {
        *mergeComp += 1;
        aux = j;
        j++;
    }
    vetorAux[k] = vetor[aux];
}

	return copiar(vetor, vetorAux, a, b);

}

void auxMergeSort(int *vetor,int vetorAux[] ,int a, int b, long *mergeComp) {

	if (a >= b)
	{
		return;
	}

	int meio = (a + b)/2;
	
	auxMergeSort(vetor, vetorAux, a, meio, mergeComp);
	auxMergeSort(vetor, vetorAux, meio + 1, b, mergeComp);

	return mergir(vetor, vetorAux, a, meio, b, mergeComp);

}

long mergeSort(int vetor[], int tam){

	int a = 0;
	int b = tam;
	long mergeComp = 0;

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

// ---------------------------------------------------------------------

// ---------------------------quick sort--------------------------------

int particiona(int *vetor, int a, int b, long *quickComp) {

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

void auxQuickSort(int *vetor, int a, int b, long *quickComp) {

	if (a >= b) {
		return;
	}	

	int m = particiona(vetor, a, b, quickComp);

	auxQuickSort(vetor, a, m - 1, quickComp);
	auxQuickSort(vetor, m + 1, b, quickComp);

	return;

}

long quickSort(int vetor[], int tam){
	
	int a = 0;
	int b = tam;
	long quickComp = 0;

	auxQuickSort(vetor, a, b, &quickComp);

	return quickComp;

}


// ---------------------------------------------------------------------

long heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}