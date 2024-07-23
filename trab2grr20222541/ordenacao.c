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

	// Aloca memória para o vetor auxiliar
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
	// Caso base: se o subvetor tem menos de 2 elementos
	if (a >= b)
	{
		return;
	}

	// Calcula o ponto médio do vetor
	int meio = (a + b) / 2;

	// Chama recursivamente para as duas metades
	auxMergeSort(vetor, vetorAux, a, meio, mergeComp);
	auxMergeSort(vetor, vetorAux, meio + 1, b, mergeComp);

	// Mescla os dois subvetores ordenados
	mergir(vetor, vetorAux, a, meio, b, mergeComp);
}

void mergir(int *vetor, int *vetorAux, int a, int meio, int b, int *mergeComp)
{
	int k = 0;
	int i = a;
	int j = meio + 1;
	int aux;

	// caso base
	if (a >= b)
	{
		return;
	}

	// Mescla os subvetores
	for (k = 0; k <= b - a; k++)
	{
		if (j > b || (i <= meio && vetor[i] <= vetor[j]))
		{
			(*mergeComp)++;
			aux = i;
			i++;
		}
		else
		{
			(*mergeComp)++;
			aux = j;
			j++;
		}
		vetorAux[k] = vetor[aux];
	}

	// Copia o vetor auxiliar de volta para o vetor original
	copiar(vetor, vetorAux, a, b);
}

void copiar(int *vetor, int *vetorAux, int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		vetor[i] = vetorAux[i - a];
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
	// Caso base
	if (a >= b)
	{
		return;
	}

	// obtém o índice do pivô
	int m = particiona(vetor, a, b, quickComp);

	// Chama recursivamente para as duas metades
	auxQuickSort(vetor, a, m - 1, quickComp);
	auxQuickSort(vetor, m + 1, b, quickComp);
}

int particiona(int *vetor, int a, int b, int *quickComp)
{
	// Define o pivô como o último elemento do vetor
	int pivo = vetor[b];
	int m = a;

	// Particiona o vetor com base no pivô
	for (int i = a; i < b; ++i)
	{
		if (vetor[i] <= pivo)
		{
			(*quickComp)++;
			trocar(vetor, m, i);
			m++;
		}
		(*quickComp)++;
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
		// Move o maior elemento para o final
		trocar(vetor, 0, i);

		maxHeapfy(vetor, 0, i, heapComp);
	}

	return *heapComp;
}

void fazerMaxHeap(int *vetor, int tam, int *heapComp)
{
	// Constrói o max-heap chamando maxHeapfy para cada nó que não é folha
	for (int i = (tam / 2) - 1; i >= 0; i--)
		maxHeapfy(vetor, i, tam, heapComp);
	return;
}

void maxHeapfy(int *vetor, int i, int tam, int *heapComp)
{
	int fEsquerdo = 2 * i + 1;
	int fDireito = 2 * i + 2;
	int maior;

	// Verifica se o filho esquerdo é maior que o atual
	if (fEsquerdo < tam && vetor[fEsquerdo] > vetor[i])
		maior = fEsquerdo;
	else
		maior = i;

	*heapComp += 1;

	// Verifica se o filho direito é maior que o maior elemento até agora
	if (fDireito < tam && vetor[fDireito] > vetor[maior])
	{
		*heapComp += 1;
		maior = fDireito;
	}

	// Se o maior não é o atual, troca
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
	// Inicializa o contador de comparações
	int mergeSRcomp = 0;

	// Chama a função auxiliar de merge sort sem recursão
	auxMergeSortSR(vetor, tam, &mergeSRcomp);

	// Retorna o número de comparações feitas
	return mergeSRcomp;
}

void auxMergeSortSR(int vetor[], int tam, int *mergeSRcomp)
{
	int tamanho_atual;
	int inicio_esquerda;

	// Dobra o tamanho dos subvetores a serem mesclados a cada iteração
	for (tamanho_atual = 1; tamanho_atual <= tam - 1; tamanho_atual = 2 * tamanho_atual)
	{
		// Percorre o vetor dividindo-o em subvetores de tamanho_atual
		for (inicio_esquerda = 0; inicio_esquerda < tam - 1; inicio_esquerda += 2 * tamanho_atual)
		{
			// Calcula o ponto médio e o fim da parte direita
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
				// Mescla os subvetores ordenados
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

	// Verifica se os subvetores são válidos
	if (sub1 <= 0 || sub2 <= 0)
	{
		printf("subvetores inválidos.\n");
		return;
	}

	// Aloca memória para os subvetores esquerdo e direito
	int *Esq = (int *)malloc(sub1 * sizeof(int));
	int *Dir = (int *)malloc(sub2 * sizeof(int));

	if (Esq == NULL || Dir == NULL)
	{
		printf("falha ao alocar memoria.\n");
		free(Esq);
		free(Dir);
	}

	// Copia os dados para os subvetores
	for (i = 0; i < sub1; i++)
		Esq[i] = vetor[inicio + i];

	for (j = 0; j < sub2; j++)
		Dir[j] = vetor[meio + 1 + j];

	i = 0;
	j = 0;
	k = inicio;

	// Mescla os subvetores de volta ao vetor principal
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

	// Copia os elementos restantes de esquerda
	while (i < sub1)
	{
		vetor[k] = Esq[i];
		i++;
		k++;
	}

	// Copia os elementos restantes da direita
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
	// Aloca memória para a pilha
	int *pilha = (int *)malloc(tamanho * sizeof(int));

	if (pilha == NULL)
	{
		printf("falha ao alocar memoria.\n");
	}

	int topo = -1;

	// Inicializa a pilha com os índices iniciais do vetor
	pilha[++topo] = 0;
	pilha[++topo] = tamanho - 1;

	// Continua até que a pilha esteja vazia
	while (topo >= 0)
	{
		int final = pilha[topo--];
		int começo = pilha[topo--];

		// Particiona e obtem o pivo
		int p = particiona(vetor, começo, final, quickSRcomp);

		// Se houver elementos à esquerda do pivô, adiciona à pilha
		if (p - 1 > começo)
		{
			pilha[++topo] = começo;
			pilha[++topo] = p - 1;
		}

		// Se houver elementos à direita do pivô, adiciona à pilha
		if (p + 1 < final)
		{
			pilha[++topo] = p + 1;
			pilha[++topo] = final;
		}
	}

	free(pilha);
}

// ----------------------------------------------------------------

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

uint64_t heapSortSR(int vetor[], size_t tam)
{
	int heapCompSR = 0;

	auxHeapSortSR(vetor, tam, &heapCompSR);

	return heapCompSR;
}

void maxHeapfySR(int *vetor, int i, int tam, int *heapCompSR)
{
	int maior = i;
	int esq, dir;

	// Continua enquanto o atual não for uma folha
	while (maior < tam / 2)
	{
		// Calcula os índices dos filhos esquerdo e direito
		esq = 2 * i + 1;
		dir = 2 * i + 2;

		// Encontra o maior entre o atual e seus filhos
		if (esq < tam && vetor[esq] > vetor[maior])
			maior = esq;

		if (dir < tam && vetor[dir] > vetor[maior])
			maior = dir;

		*heapCompSR += 2;

		// Se o maior não atual, troca
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