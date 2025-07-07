#include <stdio.h>

int main() {
	int n = 0;
	float media, temp, soma;
	soma = 0;
	media = 0;
	
	while (1) {
		printf("Insira um número: ");
		scanf("%f", &temp);
		printf("\n");
		if (temp < 0)
			break;
		soma += temp;
		n++;
	}
	printf("\n");
	media = soma / n;
	printf("A média dos números introduzidos é de %.2f.\n", media); 
}