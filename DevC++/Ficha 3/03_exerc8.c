#include <stdio.h>


void troca(int x[], int p, int q);
void troca_circular(int x[], int n);
void lerVetor(int vet[], int n);
void escreverVetor(int vet[], int n);

int main() {
	int x[20], n, p, q, escolha;
	do {
		printf("Introduza o n: ");
		scanf("%d", &n);
	} while (n < 0);
	
	lerVetor(x, n);
	
	do {
		printf("Quer trocar 2 posições(1) ou trocar circularmente(2): "); //Estamos a usar as posicoes do array, caso contrario ajustar as funcoes
		scanf("%d", &escolha);
	} while ((escolha !=1) && (escolha != 2));
	if (escolha == 1) {
		do {
			printf("Introduza o p: ");
			scanf("%d", &p);
		} while (p < 0);
		
		do {
			printf("Introduza o q: ");
			scanf("%d", &q);
		} while (q < 0);
		troca(x, p, q);
		escreverVetor(x, n);
	}
	else {
		troca_circular(x, n);
		escreverVetor(x, n);
	} 
}

//funcao para a alinea a)
void troca(int x[], int p, int q) {
	int temp;
	temp = x[p];
	x[p] = x[q];
	x[q] = temp;
}

//funcao para a alinea b)
void troca_circular(int x[], int n) {
	int temp;
	temp = x[0];
	for (int i = 1; i < n; i++) {
		x[i-1] = x[i];
	}
	x[n-1] = temp;
}

void lerVetor(int vet[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Introduza o %dº número: ", i+1);
		scanf("%d", &vet[i]);
	}
}


void escreverVetor(int vet[], int n) {
	for(int i = 0; i < n; i++) {
		printf("O número da posição %d é %d", i, vet[i]); //posição no array!!!!
		printf("\n");
	}
}