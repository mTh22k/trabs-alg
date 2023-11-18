#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função getNomeAlgoritmoExtra deve colocar o nome do algoritmo
// extra implementado no trabalho
void getNomeAlgoritmoExtra(char nomeAlg[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor


void encheVetor(int *vetor, int tam);
void imprimeVetor(int vetor[], int tam);
void trocar(int *vetor, int a, int b);


// MERGE SORT

unsigned long mergeSort(int vetor[], int tam);

void copiar(int *vetor, int *vetorAux, int a, int b);

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, unsigned long *mergeComp);

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, unsigned long *mergeComp);


// QUICK SORT

unsigned long quickSort(int vetor[], int tam);

int particiona(int *vetor, int a, int b, unsigned long *quickComp);

void auxQuickSort(int *vetor, int a, int b, unsigned long *quickComp);

// HEAP SORT

unsigned long heapSort(int vetor[], int tam);

void maxHeapfy(int *vetor, int i, int tam, int *heapComp);

void fazerMaxHeap(int *vetor, int tam, int *heapComp);

int auxHeapSort(int *vetor, int tam, int *heapComp);



void countingSort(unsigned int vetor[], int tam,
                  int maxVal);  // maxVal é o k do algoritmo

// Na função algoritmoExtra implemente o algoritmo extra solicitado.
// Se o seu algoritmo escolhido não faz comparações, retorne -1.
unsigned long algoritmoExtra(int vetor[], int tam);

#endif  // ORDENACAO_H_