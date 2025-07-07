#include <stdio.h>
#include <math.h>

int main() {
	
	int n;
	float soma = 0;
	
	do {
		printf("Qual é o valor de N: ");
		scanf("%d", &n);
	} while (n < 1);
	//ciclo só faz n-1 vezes porque já começamos em 1, que é um termo;
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			soma += (pow(2, i) - (i+1));
		}
		else {
			soma += (pow(2, i) + (i+1));
		}
	}
	printf("\n%.2f", soma); 
}