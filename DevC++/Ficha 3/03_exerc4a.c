#include <stdio.h>

int cubo(int n);
int leitura();

int main() {
	printf("O resultado de n^3 é de %d", cubo(leitura()));
	return 0;
}

int leitura() {
	int n;
	do {
		printf("Valor de n: ");
		scanf("%d", &n);
	} while (n < 0);
	return n;
}

int cubo(int n) {
	int resultado = 1;
	for(int i = 0; i < 3; i++) {
		resultado *= n;
	}
	return resultado;
}