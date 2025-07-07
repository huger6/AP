#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void lerMatriz(int * matriz, int nL, int nC);
void escreverMatriz(int * matriz, int nL, int nC);
int tracoMatriz(int * matriz, int nL, int nC);
int simetria(int * matriz, int n);

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int nL, nC;
	
	do {
		printf("Quantas filas e colunas tem a matriz?(Max 10) ");
		scanf("%d %d", &nL, &nC); 
	} while (nL < 0 || nC < 0 || nL > 10 || nC > 10);
	
	int * matriz = (int *) malloc(nL * nC * sizeof(int));
	if(matriz == NULL) {
		printf("Erro ao alocar matriz!\n");
		return 1;
	}
	
	lerMatriz(matriz, nL, nC);
	escreverMatriz(matriz, nL, nC);
	
	printf("O traço da matriz é de %d", tracoMatriz(matriz, nL, nC));
	
	
}

void lerMatriz(int * matriz, int nL, int nC) {
	for(int i = 0; i < nL; i++) {
		for(int j = 0; j < nC; j++) {
			printf("Introduza o elemento [%d][%d]: ");
			scanf("%d", matriz + i*nC + j);	
		}
	}
}

void escreverMatriz(int * matriz, int nL, int nC) {
	for(int i = 0; i < nL; i++) {
		printf("Linha %d: ", i);
		for (int j = 0; j < nC;j++) {
			printf("%d", *(matriz + i*nC + j));
		}
	}
}

int tracoMatriz(int * matriz, int nL, int nC) {
	int soma = 0;
	if (nL != nC)
		return NULL;
	for(int i = 0; i < nL; i++) {
		soma += *(matriz + i*nC + i);
	}
	return soma;
}

int simetria(int * matriz, int n) {
	for(int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(matriz +i*n + j)!= *(matriz +j*n + i)){
				return 0;
			}
		}
	}
}

int produtoMatriz(int * m1, int nl1, int nc1, int * m2, int nl2, int nc2) {
	
}