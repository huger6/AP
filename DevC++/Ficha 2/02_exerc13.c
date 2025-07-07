#include <stdio.h>

int main() {
	
	int n;
	float soma = 1;
	
	do {
		printf("Qual é o valor de N: ");
		scanf("%d", &n);
	} while (n < 1);
	//ciclo só faz n-1 vezes porque já começamos em 1, que é um termo;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			soma += (1.0/(2.0*i));
		}
		else {
			soma -= (1.0/(2.0*i));	
		}
	}
	printf("\n%.6f", soma); 
}