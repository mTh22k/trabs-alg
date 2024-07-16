#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdint.h>
#include <sys/types.h>

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

void encheVetor(int *vetor, int tam, int n);
void imprimeVetor(int vetor[], int tam);
void trocar(int *vetor, int a, int b);

// MERGE SORT
uint64_t mergeSort(int vetor[], size_t tam);

void copiar(int *vetor, int *vetorAux, int a, int b);

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, int *mergeComp);

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, int *mergeComp);

// QUICK SORT
uint64_t quickSort(int vetor[], size_t tam);

int particiona(int *vetor, int a, int b, int *quickComp);

void auxQuickSort(int *vetor, int a, int b, int *quickComp);

// HEAP SORT
uint64_t heapSort(int vetor[], size_t tam);

void maxHeapfy(int *vetor, int i, int tam, int *heapComp);

void fazerMaxHeap(int *vetor, int tam, int *heapComp);

int auxHeapSort(int *vetor, int tam, int *heapComp);


// As funções que terminam em SR são "Sem Recursão"
uint64_t mergeSortSR(int vetor[], size_t tam);

uint64_t quickSortSR(int vetor[], size_t tam);

uint64_t heapSortSR(int vetor[], size_t tam);

#endif  // ORDENACAO_H_