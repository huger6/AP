#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct lista {
	long votos;
	char nome[50];
	int lugares;
	int divisor;
}Lista;

void ler_listas(int nlistas, int * lista);
void ler_votos(int nlistas, Lista * nomes);
void inicializar_lista(Lista * lista, int nlistas);


/*TODO LIST 
-Ver os casos em que há 0 ou 1 listas
-Só dividimos o valor se já tivermos atribuído um lugar
-Criar um unico array onde temos todos os valores atuais

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
	
	Lista * listas = (Lista *)malloc(nlistas * sizeof(Lista));
	inicializar_lista(listas, int nListas);
	
	ler_listas(nListas, listas);
	ler_votos(nListas, listas);
	
	
	
	
	
	free(listas);
	
	return 0;
}

void ler_listas(int nlistas, Lista * lista) {
	int valido;
	for (int i = 0; i < nlistas; i++) {
		do {
			valido = 0;
			printf("Insira o nome da lista: ");
			valido = scanf(" %s", &(listas+i)->nome);
			if (valido == 1) listas++;
		} while (!valido);
	}
}


void ler_votos(int nlistas, Lista * nomes) {
	for(int i = 0; i < nlistas; i++) {
		printf("Quantos votos teve a lista %s? ", (nomes+i)->nome);
		scanf("%ld", &(nomes+i)->votos);
		nomes++;
	}
}

void inicializar_lista(Lista * lista, int nlistas) {
	for (int i = 0; i < nlistas; i++) {
		lista->nome = '\n';
		lista->votos = 0;
		lista->lugares = 0;
		lista->divisor = 1;
	}
}