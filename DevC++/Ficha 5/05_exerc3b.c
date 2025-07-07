/* - Pretendem-se registar as notas de um máximo de 50 estudantes. Para cada estudante é
necessário registar o número, nome e a nota respetiva.
a) Elabore um programa que solicite ao utilizador N nomes, respetivos números e notas (sendo
N <=50);
b) Acrescente ao programa anterior o código que permita, dado o número de um estudante,
mostre o respetivo nome e nota;
c) Crie um novo programa ou um novo projeto (copie e altere o criado para responder às duas
alíneas anteriores), mas, desta vez, estruturando-o, usando funções e use ponteiros para
aceder aos elementos do vetor. */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct aluno {
	int numero;
	char nome[50];
	float nota;
}Aluno;

Aluno ler_nomes();
Aluno ler_numero();
Aluno ler_notas();
void mostrar_dados(Aluno * student);

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	int n;
	do {
		printf("Quantos alunos há? /(Max: 50)/ ");
		scanf("%d", &n);
	} while (n < 0 || n > 50);
	
	Aluno * alunos = (Aluno *) malloc(n * sizeof(Aluno));
	if (alunos == NULL) {
		printf("Erro ao alocar memória!\n");
		return 1;	
	}
	for(int i = 0; i < n; i++) {
		*(alunos + i) = ler_nomes();
		(*(alunos + i)).numero = ler_numero().numero;
		(*(alunos + i)).nota = ler_notas().nota;
		printf("\n\n");
	}
	printf("\n");
	for(int i = 0; i < n;i++) {
		mostrar_dados(alunos + i);
		printf("\n");
	}
	
	free(alunos); 
}


//Ler nomes, etc
Aluno ler_nomes() {
	Aluno aluno;
	
	printf("Nome do aluno: ");
	scanf(" %s", &aluno.nome);
	printf("\n");
	
	return aluno;
}

Aluno ler_numero() {
	Aluno aluno;
	
	printf("Número do aluno: ");
	scanf("%d", &aluno.numero);
	printf("\n");
	return aluno;
}

Aluno ler_notas() {
	Aluno aluno;
	
	printf("Nota do aluno: ");
	scanf("%f", &aluno.nota);
	printf("\n");
	return aluno;
	
}

void mostrar_dados(Aluno * student) {
	printf("O nome do aluno é: %s\n", student->nome);
	printf("O número do aluno é: %d\n", student->numero);
	printf("A nota do aluno é: %.2f\n", student->nota);
	
}