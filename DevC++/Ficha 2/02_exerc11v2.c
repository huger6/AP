//Versão melhorada do exercicio 12 de modo a permitir N's maiores.

#include <stdio.h>

int main() {
	int n;
	float parcela, soma;
	
	do {
		printf("Qual é o valor de N no somatório? ");
		scanf("%d", &n);
	} while (n < 1);
	
	soma = 0;
	parcela = 1.0;
	
	for(int i = 1; i <= n; i++) {
		parcela *= (2.0/i);
		soma += parcela;
	}
	printf("A soma vale %.7f\n", soma);
	return 0;
}