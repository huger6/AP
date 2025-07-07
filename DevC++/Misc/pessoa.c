#include <stdio.h>

int main() {
	int idade;
	char nome[20];
	//Pedir idade e guardar
	printf("Idade: ");
	scanf("%d", &idade);
	//Pedir nome e guardar
	printf("Nome: ");
	scanf("%s", nome);
	
	printf("A pessoa tem %d anos e chama-se %s!\n\n", idade, nome);
	return 0;
	
}