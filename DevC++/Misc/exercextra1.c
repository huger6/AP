#include <stdio.h>

void func3(int * vetor, int n, int * np);

int main() {
	int npares = 0;
	int vet[6] = {10,3,8,2,5,4};
	func3(vet, 6, &npares);
	printf("np vale %d", npares);
}

void func3(int * vetor, int n, int * np) {
	*np = 0;
	for(int i = 0; i < n;i++) {
		if (!(vetor[i] % 2))
			(*np)++;
	}
}