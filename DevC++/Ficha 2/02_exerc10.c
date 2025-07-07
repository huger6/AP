//somatórios o i começa sempre em 1
//Calcular somatório de um fatorial básico

#include <stdio.h>

int fatorial (int a);

int main() {
	int n, soma;
	soma = 0;
	
	do {
		printf("Qual é o valor de N no somatório? ");
		scanf("%d", &n);
	} while (n < 1);
	
	for(int i = 1; i <= n; i++) {
		soma += fatorial(i);
	}
	printf("O resultado do somatório é %d", soma);	
}
//Calcula um fatorial básico
int fatorial (int a) {
	int total = 1; //Elemento neutro da multiplicação
	for (int i = a; i > 1; i --) { 	
		total *= i;
	}
	return total;
}