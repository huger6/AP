#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct lista {
	long votos;
	char nome[50];
}Lista;

Lista * ler_listas(int nlistas);
void ler_votos(int nlistas, Lista * nomes);


/*TODO LIST 
-Ver os casos em que há 0 ou 1 listas
-Só dividimos o valor se já tivermos atribuído um lugar

*/

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	int nListas, mandatos;
	
	do {
		printf("Quantas listas existem? ");
		scanf("%d", &nListas);
	}while (nListas < 0);
	
	do {
		printf("Quantos mandados serão atribuídos? ");
		scanf("%d", &mandatos);
	}while (mandatos < 0);
	
	Lista * listas = ler_listas(nListas);
	ler_votos(nListas, listas);
	
	
	
	
	
	free(listas);
	
	
}

Lista * ler_listas(int nlistas) {
	Lista * listas = (Lista *)malloc(nlistas * sizeof(Lista));
	int valido;
	for (int i = 0; i < nlistas; i++) {
		do {
			valido = 0;
			printf("Insira o nome da lista: ");
			valido = scanf(" %s", &listas->nome);
			if (valido == 1) listas++;
		} while (!valido);
	}
	return listas;
}


void ler_votos(int nlistas, Lista * nomes) {
	for(int i = 0; i < nlistas; i++) {
		printf("Quantos votos teve a lista %s? ", (nomes+i)->nome);
		scanf("%ld", &(nomes+i)->votos);
		nomes++;
	}
}

