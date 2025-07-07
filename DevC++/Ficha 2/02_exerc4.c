//-Elabore um algoritmo que peça ao utilizador para introduzir um número entre 0 e 9 e enquanto não
//for introduzido um valor válido, a leitura é repetida

#include <stdio.h>

int main() {
	int n;
	do {
		printf("Insira um nº entre 0 e 9: ");
		scanf("%d", &n);
	} while ((n <= -1)||(n >= 10));
	return 0;
}
