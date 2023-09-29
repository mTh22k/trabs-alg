#include "ordenacao.h"
#include <string.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Paulo Ricardo Lisboa de Almeida", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 1234;
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
    int b = tam;

    int res = auxBuscaBinaria(vetor,a,b,valor,numComparacoes);

	if (res >= 0) {
		return res;
	}

	return -1;
}

int auxBuscaBinaria(int v[], int a, int b, int x, long* numComparacoes) {

    if (a > b)
    {
        return a - 1;
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

long insertionSort(int vetor[], int tam){	
	vetor[0] = 99;
	return -1;
}

long selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}