#include <stdio.h>

int main() {
	double a;
	int b;
	
	printf("Valor de a: ");
	scanf("%lf", &a);
	
	printf("Valor de b: ");
	scanf("%d", &b);
	
	double resultado = 1.0;
	for(int i = 0; i < b; i++) {
		resultado *= a;
	}
	printf("O resultado de a^b é de %lf", resultado);
	return 0;
}

