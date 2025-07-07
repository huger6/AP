//Lê um nº inteiro e escreve todos os múltiplos menores que 100

#include <stdio.h>

int main() {
	int n = 0;
	do {
	printf("Escreva um nº inteiro: ");
	scanf("%d", &n);
	} while(n<=0);
	
	for (int i = 0; i < 100; i++) {
		if (i % n == 0) {
			printf("%d é múltiplo de %d.\n", i, n);
		}
	}
	return 0;
}