/*
Defina o tipo de dados FRACAO (numerador/denominador) e implemente as operações de soma,
subtração, divisão e multiplicação de frações. Os numeradores, denominadores e operação são
pedidos ao utilizador. */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct fracao {
	int numerador, denominador;
}Fracao;

Fracao lerFracao();
Fracao subFracao(Fracao f1, Fracao f2);
Fracao addFracao(Fracao f1, Fracao f2);
Fracao divFracao(Fracao f1, Fracao f2);
Fracao multFracao(Fracao f1, Fracao f2);


int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	Fracao f1, f2, resultado;
	printf("Fração 1: \n");
	f1 = lerFracao();
	printf("\nFração 2: \n");
	f2 = lerFracao();
	
	char operacao;
	
	printf("Qual a operação? ");
	scanf(" %c", &operacao); //o espaço antes do %c no scanf é importante porque não registra espaços em branco como o enter(já utilizado quando inserido os nºs)
	
	switch(operacao) {
		case '+':
			resultado = addFracao(f1, f2);
			printf("%d/%d", resultado.numerador, resultado.denominador);
			break;
		case '-':
			resultado = subFracao(f1, f2);
			printf("%d/%d", resultado.numerador, resultado.denominador);
			break;
		case 'x':
			resultado = multFracao(f1, f2);
			printf("%d/%d", resultado.numerador, resultado.denominador);
			break;
		case '/':
			resultado = divFracao(f1, f2);
			printf("%d/%d", resultado.numerador, resultado.denominador);
			break;
		default:
			printf("Opção inválida!");
			break;
	}
}

Fracao lerFracao() {
	Fracao f = {0,0}; //Os valores são atribuídos pela ordem em que foram declarados.
	do {
		printf("Insira o numerador e denominador: ");
		scanf("%d %d", &f.numerador, &f.denominador);
	} while (f.denominador == 0);
	return f;	
}


Fracao addFracao(Fracao f1, Fracao f2) {
	Fracao resultado;
	
	resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
	resultado.denominador = f1.denominador * f2.denominador;
	return resultado;
}

Fracao subFracao(Fracao f1, Fracao f2) {
	Fracao resultado;
	
	resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
	resultado.denominador = f1.denominador * f2.denominador;
	return resultado;
}

Fracao multFracao(Fracao f1, Fracao f2) {
	Fracao resultado;
	
	resultado.numerador = f1.numerador * f2.numerador;
	resultado.denominador = f1.denominador * f2.denominador;
	return resultado;
}

Fracao divFracao(Fracao f1, Fracao f2) {
	Fracao resultado;
	
	resultado.numerador = f1.numerador * f2.denominador;
	resultado.denominador = f1.denominador * f2.numerador;
	
	return resultado;
} 