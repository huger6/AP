//Pedir um número e dizer os divisores por ordem maior para o menor

#include <stdio.h>

int main() {
	int n;
	
	do {
		printf("Escreva um número inteiro positivo: ");
		scanf("%d", &n);
	} while (n <= 0);
	
	printf("\n");
	printf("%d\n", n);
	for(int i = n/2; i >= 1; i--) {
		if (n % i == 0)
			printf("%d\n", i);
	}
	return 0;
}