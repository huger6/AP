#include <stdio.h>

int main() {
	int n;
	float media, temp, soma;
	soma = 0;
	media = 0;
	do {
		printf("Introduz o número de parcelas: ");
		scanf("%d", &n);
	} while (n < 1);

	printf("\n");
	
	for(int i = 0; i < n; i++) {
		do {
			printf("Insira um número: \n");
			scanf("%f", &temp);
		} while (temp < 0);
		soma += temp;
	}
	media = soma / n;
	printf("A média dos números introduzidos é de %.4f.\n", media); 
}