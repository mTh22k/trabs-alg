#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define MAX_CHAR_NOME 50

// a função getNome deve colocar o seu nome dentro da chamada
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

// Assuma que os vetores estão ordenados ao chamar as funções de busca
// As funções de busca não devem alterar o vetor
// O retorno das funções de busca é o índice do elemento no vetor,
// ou -1 caso o elemeno não exista no vetor
// Você deve armazenar no ponteiro int* numComparacoes o número de comparações
// envolvendo elementos do vetor feito pelo seu algoritmo na chamada

// Implemente a versão recursiva nos algoritmos que terminam em Rec, e a versão
// iterativa nos demais

void encheVetor(int *vetor, int tam);
void imprimeVetor(int vetor[], int tam);

// a busca sequencial é a busca ingênua
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes);

ssize_t auxBuscaSequencialRec(int v[], int a, int b, int valor, uint64_t* numComparacoes);

ssize_t buscaSequencial(int vetor[], size_t tam, int valor, uint64_t* numComparacoes);


// busca binária no vetor
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes);

ssize_t auxBuscaBinariaRec(int v[], int a, int b, int x, uint64_t* numComparacoes);

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes);

// Cada uma das funções deve ordenar o vetor passado como parâmetro
// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor realizado



// insertion recursivo

uint64_t insertionSortRec(int vetor[], size_t tam);

void inserir(int *vetor, int a, int b, uint64_t *insertionComp);

void trocar(int *vetor, int a, int b);

void auxInsertionSortRec(int *vetor, int a, int b, uint64_t *insertionComp);

// insertion interativo

uint64_t insertionSort(int vetor[], size_t tam);

// selection recursivo

uint64_t selectionSortRec(int vetor[], size_t tam);

int minimo(int *vetor, int a, int b, uint64_t *selectionComp);

uint64_t selectionSortRec(int vetor[], size_t tam);

void auxSelectionSortRec(int *vetor, int a, int b, uint64_t *selectionComp);

// selection interativo

uint64_t selectionSort(int vetor[], size_t tam);

// merge sort

void copiar(int *vetor, int *vetorAux, int a, int b);

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, uint64_t *mergeComp);

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, uint64_t *mergeComp);

uint64_t mergeSort(int vetor[], size_t size_t);


#endif  // ORDENACAO_H_