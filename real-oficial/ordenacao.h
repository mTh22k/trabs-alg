#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

//a função getNome deve colocar o seu nome dentro da chamada
//seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

//Assuma que os vetores estão ordenados ao chamar as funções de busca
//As funções de busca não devem alterar o vetor
//O retorno das funções de busca é o índice do elemento no vetor,
//ou -1 caso o elemeno não exista no vetor
//Você deve armazenar no ponteiro int* numComparacoes o número de comparações
//envolvendo elementos do vetor feito pelo seu algoritmo na chamada

void encheVetor(int *vetor, int tam);
void imprimeVetor(int vetor[], int tam);

//a busca sequencial é a busca ingênua
int auxBuscaSequencial(int v[], int a, int b, int valor, long *numComparacoes);

int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes);

//busca binária no vetor
int auxBuscaBinaria(int v[], int a, int b, int x, long* numComparacoes);

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes);

//Cada uma das funções deve ordenar o vetor passado como parâmetro
//O retorno das funções de ordenação é o número de comparações
//entre elementos do vetor

// insertion sort
void trocar(int *vetor, int a, int b);

void inserir(int *vetor, int a, int b, long *insertionComp);

void auxInsertionSort(int *vetor, int a, int b, long *insertionComp);

long insertionSort(int vetor[], int tam);

// selection sort
int minimo(int *vetor, int a, int b, long *selectionComp);

long selectionSort(int vetor[], int tam);

void auxSelectionSort(int *vetor, int a, int b, long *selectionComp);

// merge sort

void copiar(int *vetor, int *vetorAux, int a, int b);

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, long *mergeComp);

void auxMergeSort(int *vetor, int vetorAux[], int a, int b, long *mergeComp);

long mergeSort(int vetor[], int tam);

// quick sort

int particiona(int *vetor, int a, int b, long *quickComp);

void auxQuickSort(int *vetor, int a, int b, long *quickComp);

long quickSort(int vetor[], int tam);

long heapSort(int vetor[], int tam);

#endif // ORDENACAO_H_