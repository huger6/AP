//-Escreva um programa em C que leia um número inteiro positivo N e calcule o maior número par P
//tal que a soma de todos os números pares até P seja inferior a N

#include <stdio.h>

int main() {
	int soma = 0;
	int n = 0;
	int p = 0;
	do {
		printf("Escreva um nº inteiro positivo: ");
		scanf("%d", &n);	
	} while(n <= 0);
	
	//i podia começar em 2, neste caso.
	for (int i = 0; soma + i < n; i += 2) {
        soma += i;
        p = i;     
    }
    //podia-se escrever apenas i
	printf("P=%d\n", p);
	return 0;
}