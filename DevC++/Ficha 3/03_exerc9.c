#include <stdio.h>
#include <locale.h>

#define MAX 20

void lerMatriz(int M[MAX][MAX], int nl, int nc);
void escreverMatriz(int M[MAX][MAX], int nl, int nc);
int minMatriz(int M[MAX][MAX], int nl, int nc);
void simetrica(int M[MAX][MAX], int n);
void transposta(int M[MAX][MAX], int MT[MAX][MAX], int nl, int nc);
void somaMatrizes(int M[MAX][MAX], int M2[MAX][MAX], int M_resultado[MAX][MAX], int n);


int main() {
	setlocale(LC_ALL, "Portuguese");
	int matriz[MAX][MAX], matriz_transposta[MAX][MAX], matriz_resultado[MAX][MAX], matriz2[MAX][MAX];
	int nl, nc, nl2, nc2;
	do {
		printf("Num de linhas da matriz: ");
		scanf("%d", &nl);
	} while (nl < 1 || nl > 20);
	
	do {
		printf("Num de colunas da matriz: ");
		scanf("%d", &nc);
	} while (nc < 1 || nc > 20);
	
	lerMatriz(matriz, nl, nc);
	escreverMatriz(matriz, nl, nc);
	
	printf("O menor valor da matriz é: %d\n",minMatriz(matriz, nl, nc));
	
	if (nc == nl) {
		simetrica(matriz, nc);	
	}
	
	transposta(matriz, matriz_transposta, nl, nc);
	
	printf("A matriz transposta é: \n");
	escreverMatriz(matriz_transposta, nc, nl);
	
	//Soma de matrizesç
	do {
		printf("Num de linhas da matriz 2: ");
		scanf("%d", &nl2);
	} while (nl2 < 1 || nl2 > 20);
	
	do {
		printf("Num de colunas da matriz 2: ");
		scanf("%d", &nc2);
	} while (nc2 < 1 || nc2 > 20);
	
	lerMatriz(matriz2, nl2, nc2);
	if (nl2 == nc2) {
		somaMatrizes(matriz, matriz2, matriz_resultado, nl2);
		escreverMatriz(matriz_resultado, nl2, nc2);
		
		printf("_____________________________________________\n|n");
		
		
		somaMatrizes(matriz, matriz2, matriz_resultado, nl2);
		escreverMatriz(matriz_resultado, nl2, nc2);
	}
}


void lerMatriz(int M[MAX][MAX], int nl, int nc) {
	for (int i = 0; i < nl; i++) {
		for (int j = 0; j < nc; j++) {
			printf("Valor para posição [%d][%d]: ", i, j);
			scanf("%d", &M[i][j]);
		}
	}
}

void escreverMatriz(int M[MAX][MAX], int nl, int nc) {
	for (int i = 0; i < nl; i++) {
		for (int j = 0; j < nc; j++) {
			printf("%d\t", M[i][j]);
		}
		printf("\n\n\n");
	}
}

int minMatriz(int M[MAX][MAX], int nl, int nc) {
	int min = M[0][0];
	for (int i = 0; i < nl; i++) {
		for (int j = 0; j < nc; j++) {
			if (M[i][j] < min) {
				min = M[i][j];
			}
		}
	return min;
}
}

//Só deve ser chamada se a matriz for quadrada
void simetrica(int M[MAX][MAX], int n) {
	int simetric = 1;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (M[i][j] != M[j][i])
				simetric = 0;
			}
		}
	if (simetric)
		printf("\nA matriz é simétrica.\n");
	else 
		printf("\nA matriz não é simétrica.\n");
}


void transposta(int M[MAX][MAX], int MT[MAX][MAX], int nl, int nc) {
	for (int i = 0; i < nl; i++) {
		for(int j = 0; j < nc; j++) {
			MT[j][i] = M[i][j];
		}
	}
}


void somaMatrizes(int M[MAX][MAX], int M2[MAX][MAX], int M_resultado[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M_resultado[i][j] = (M[i][j] + M2[i][j]);
		}
	}
}



