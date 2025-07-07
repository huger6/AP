#include <stdio.h>

void troca(int * n, int * n2);

int main() {
	int n, n2;
	
	printf("Insira n: ");
	scanf("%d", &n);
	
	printf("Insira n2: ");
	scanf("%d", &n2);
	
	troca(&n, &n2);
	printf("%d, %d", n, n2);
	
	return 0;
}

void troca(int * n, int * n2) {
	int temp;
	
	temp = *n;
	*n = *n2;
	*n2 = temp;
}