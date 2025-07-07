#include <stdio.h>

int main() {
	int pares, numero_atual, total;
	pares = numero_atual = total = 0;
	
	while (1) {
		
		printf("Introduza um número: ");
		scanf("%d", &numero_atual);
		
		if (numero_atual == 0) {
			do {
				printf("Introduza um número: ");
				scanf("%d", &numero_atual);
			} while (numero_atual == 0);
		}
		
		if (numero_atual < 0)
			break;
	
		if (numero_atual % 2 == 0)
			pares += 1;
		total+=1; 
	}
	printf("Há %d números pares e %d números ímpares.\n", pares, total - pares);
	return 0;
}