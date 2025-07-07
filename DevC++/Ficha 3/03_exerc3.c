#include <stdio.h>

void classifica(int a, int b);

int main() {
	int a, b;
	do {
		printf("Escreva a: ");
		scanf("%d", &a); 
	} while (a < 0);
	
	do {
		printf("Escreva b: ");
		scanf("%d", &b); 
	} while (b < a);
	
	if (a < b) {
		classifica(a, b);
	}
}


void classifica(int a, int b) {
	int soma, num, n_reduzidos, n_abundantes, n_perfeitos;
	n_reduzidos = 0; n_abundantes = 0; n_perfeitos = 0;
	for(int i = a; i <= b;i++) {
		soma = 0;
		num = i/2;
		for (int j = 1; j <= num; j++) {
			if (i % j == 0) {
				soma += j;
			}
		}
		if (i > soma) {
			printf("%d é reduzido.\n", i);
			n_reduzidos += 1;
		}
		else if (i < soma) {
			printf("%d é abundante.\n", i);
			n_abundantes += 1;
		}
		else {
			printf("%d é perfeito.\n", i);
			n_perfeitos += 1;
		}	
	}
	printf("Há %d reduzidos, %d abundantes e %d perfeitos.\n", n_reduzidos, n_abundantes, n_perfeitos);
}