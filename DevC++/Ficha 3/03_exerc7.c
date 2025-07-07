#include <stdio.h>
#include <locale.h>

int produto_vetores(int v[], int d[], int n);
void lerVetor(int vet[], int n);

void main() {
	int v1[20], n, produto_interno, v2[20];
	printf("Número de elementos do vetor: ");
	scanf("%d", &n);
	
	lerVetor(v1, n);
	printf("\n\n");
	lerVetor(v2, n);
	
	produto_interno = produto_vetores(v1, v2, n);
	printf("O produto interno dos vetores é de %d", produto_interno);
}

int produto_vetores(int v[], int d[], int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += (v[i] * d[i]);
	}
	return total;
}

void lerVetor(int vet[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Introduza o %dº número: ", i+1);
		scanf("%d", &vet[i]);
	}
}