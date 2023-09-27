#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

// a função getNome deve colocar o seu nome dentro da chamada
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

// Assuma que os vetores estão ordenados ao chamar as funções de busca
// As funções de busca não devem alterar o vetor
// O retorno das funções de busca é o índice do elemento no vetor,
// ou -1 caso o elemeno não exista no vetor
// Você deve armazenar no ponteiro int* numComparacoes o número de comparações
// envolvendo elementos do vetor feito pelo seu algoritmo na chamada
void imprimirVetor(int *vetor, int tam);

void preencheVetor(int *vetor, int tam);

int trocar(int vetor[], int idxIni, int tam);

// a busca sequencial é a busca ingênua
int auxBuscaSequencial(int vetor[], int idxIni, int tam, int valor, int *numComparacoes);

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes);

// busca binária no vetor
int auxBuscaBinaria(int vetor[], int IdxIni, int tam, int valor, int *numComparacoes);

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes);

// Cada uma das funções deve ordenar o vetor passado como parâmetro
// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

int inserir(int *vetor, int idxIni, int tam, int *insertionComp);
int auxInsertionSort(int *vetor, int idxIni, int tam, int *insertionComp);
int insertionSort(int vetor[], int tam);

int achaMenor(int *vetor, int idxIni, int tam, int *selectionComp);
int auxSelectionSort(int *vetor, int idxIni, int tam, int *selectionComp);
int selectionSort(int vetor[], int tam);

int copiar(int *vetor, int *vetorAux, int idxIni, int tam);
int merge(int *vetor, int *vetorAux, int idxIni, int meio, int tam, int *mergeComp);
int auxMergeSort(int *vetor, int vetorAux[], int idxIni, int tam, int *mergeComp);
int mergeSort(int vetor[], int tam);

int particionarVetor(int *vetor, int idxIni, int tam, int *quickComp);
int auxQuickSort(int *vetor, int idxIni, int tam, int *quickComp);
int quickSort(int vetor[], int tam);

void maxHeapfy(int *vetor, int i, int tam, int *heapComp);
void fazerMaxHeap(int *vetor, int tam, int *heapComp);
int auxHeapSort(int *vetor, int tam, int *heapComp);
int heapSort(int vetor[], int tam);

#endif // ORDENACAO_H_
