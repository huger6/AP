//Elabore um programa que determine todos os números pares entre dois números inteiros ni e nf , (ni<nf). 

#include <stdio.h>

int main() {
	int ni, nf;
	
	printf("Insira um número inteiro inicial: ");
	scanf("%d", &ni);
	
	printf("Insira um número inteiro final: ");
	scanf("%d", &nf);
	
	if (ni >= nf) {
		printf("Erro. O número inicial é maior ou igual ao final.\n"); }
	
	else {
		int i = nf-1;
		while (ni+1 <= i) {
			if (i% 2 == 0){
				printf("%d é par.\n",i);
			}
			i -= 1;
		}
	}
	return 0;
}
