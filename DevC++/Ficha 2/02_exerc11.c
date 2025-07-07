//somatórios o i começa sempre em 1
//Calcular somatório de um fatorial (2^i / i!)

#include <stdio.h>

int fatorial (int a);
int potencia(int base, int expoente);

int main() {
	int n;
	float soma;
	soma = 0;
	
	do {
		printf("Qual é o valor de N no somatório? ");
		scanf("%d", &n);
	} while (n < 1);
	
	for(int i = 1; i <= n; i++) {
		// if (fatorial(i)) podia ser imlementado mas o fatorial de um numero positivo nunca é <= 0
		soma += (float)potencia(2, i) / fatorial(i);
	}
	printf("O resultado do somatório é %.2f\n", soma);	
}
//Calcula um fatorial básico
int fatorial (int a) {
	int total = 1; //Elemento neutro da multiplicação
	for (int i = a; i > 1; i --) { 	
		total *= i;
	}
	return total;
}

int potencia(int base, int expoente) {
	int soma = 1;
	for (int i = 0; i < expoente; i++) {
		soma *= base;
	}
	return soma;
}
