#include <stdio.h>

int main() {
	int n, n2, soma = 0;
	
	do {
		printf("Quantos número quer somar? ");
		scanf("%d", &n);
	} while (n <= 0);
	
	for (int i = 0; i < n; i++) {
		printf("Introduza um número: ");
		scanf("%d", &n2);
		soma += n2;
		printf("A soma é %d\n", soma);
	}
	return 0;
}