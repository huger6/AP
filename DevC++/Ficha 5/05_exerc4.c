/* Elabore um programa que permita armazenar em memória a informação relativa a um novo livro
que chega a uma biblioteca. Considere que para cada livro deve ser guardada a seguinte
informação:
- título (máximo 30 caracteres);
- autor (máximo 30 caracteres);
- área (máximo 20 caracteres);
- ano.
O programa deve permitir a inserção de novos livros, bem como listar e retirar livros da lista */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct livro {
	char titulo[30];
	char autor[30];
	int area;
	int ano;
	int ocupado;
}Livro;


int repetir();
void inserir(Livro * p, int n);
void listar(Livro * p, int n);
void remover(Livro * p, int n);
void inicializa_livros(Livro * livros, int n);
int repetir();
int menuBiblioteca();

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	int n;
	Livro livros[100];
	
	do {
		n = menuBiblioteca;
		switch (n) {
			case 0:
				exit(0);
			case 1:
				inserir(livros, n);
				break;
			case 2:
				listar(livros, n);
				break;
			case 3:
				remover(livros, n);
				break;
			default:
				printf("Erro!\n");
				break;
		}
	}while (n != 0);
}


void inserir(Livro * p, int n) {
	int i = 0;
	while((p->ocupado != 0)&&(i < n)) {
		p++; i++;
	}
	if (i < n) {
		p->ocupado = 1;
		
		printf("\nInsira o título do livro: ");
        scanf(" %[^\n]", p->titulo);
        
        printf("\nInsira o autor do livro: ");
        scanf(" %[^\n]", p->autor);
        
        printf("\nInsira a área do livro: ");
        scanf(" %[^\n]", p->area);
        while (getchar() != '\n');
        printf("\nInsira o ano do livro: ");
        scanf("%d", &(p->ano));
	}
	else {
		printf("\nVetor cheio!\n");
	}
} 

void listar(Livro * p, int n) {
	int temLivro = 0;
	for(int i = 0; i < n; i++) {
		if (p->ocupado != 0) {
			printf("\nTítulo: %s", p->titulo);
			printf("\nAutor: %s", p->autor);
			printf("\nÁrea: %s", p->area);
			printf("\nAno: %d", p->ano);
		}
		p++;
	}
	if (!temLivro) {
		printf("\nNenhum livro disponível para listar.\n");
	}
	
}

void remover(Livro * p, int n) {
	int indice;
	do {
		printf("Qual o índice do livro a remover? ");
		scanf("%d", &indice);
	} while ((indice < 0) || (indice >= n));
	
	(p+indice)->ocupado = 0;
}
	

void inicializa_livros(Livro * livros, int n) {
	for(int i = 0; i < n; i++) {
		livros[i].ocupado = 0;
	}
}

int menuBiblioteca() {
	int n;
	do {
			printf("0 - Sair do programa\n");
			printf("1 - Inserir novo livro\n");
			printf("2 - Listar livros da lista\n");
			printf("3 - Retirar livros da lista\n");
			scanf("%d", &n);
		} while (n < 0 || n > 3);
	return n;
}
