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
	char nome[];
	float nota;
}Aluno;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
}