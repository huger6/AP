//
//  Funcs.c
//  FreqResol
//
//  Created by Jorge Loureiro on 07/01/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 10
// Questão 1.a)
void q1A(void){
	int i, vetor[4] = {1, 2, 3, 4};
	for (i = 0; i < 4; i++) {
		 vetor[i] = vetor[i] * 2; }
	 for (i = 0; i < 4; i++) {
		 printf("%d ", vetor[i]);}
}

// Questão 1.b)
int q1B(void){
	int i = 0, j = 0;
	while (i++ < 5) { j += i; }
	return j;
}

// Questão 2

// Função para colocar a 0 todos os elementos da matriz
void matrizTriang(int M[MAX][MAX]){//ou int M[9][9]
	//se a matriz n�o entrar, podem construir aqui, j� que o objetivo � imprimir
	//tamb�m podem nem sequer construir e apenas imprimir
	int nLin=0, i=0, j=0, num=0;
	do{
		printf("\nQual o n�mero de linhas que pretende usar da matriz (<=9)? ");
		scanf("%d", &nLin);
	}while (nLin>9|| nLin<=0);
	for(i=0; i<nLin; i++){
		for(j=0; j<i; j++){
			M[i][j]=0;//se n�o constru�rem a matriz, basta imprimir 0
			printf("%d\t",M[i][j]);
		}
		for(j=i, num=1; j<nLin; j++, num++){
			M[i][j]=num;//se n�o constru�rem a matriz, basta imprimir num
			printf("%d\t",M[i][j]);
		}
		printf("\n");
	}
}

/*
// Função para colocar a 0 todos os elementos da matriz
void limparMatriz(int M[MAX][MAX]){
	int i=0, j=0;
	for(i=0; i<MAX; i++)
		for(j=0; j<MAX; j++)
			M[i][j]=0;
}

// Função para mostrar a matriz resultante
void mostarMatriz(int M[MAX][MAX]){
	int nLin=0, i=0, j=0;
	do{
		printf("\nQual o número de linhas que pretende mostar da matriz (<=MAX)? ");
		scanf("%d", &nLin);
	}while (nLin<3 || nLin>MAX);
	for(i=0; i<nLin; i++){
		for(j=0; j<nLin; j++)
			printf("[%d]", M[i][j]);
		printf("\n");
	}
}*/

// Questão 3
void nPalavras(char *str, int *nP){
	*nP=0;
	do{
		if(*str==' '){
			(*nP)++;
		}
		str++;
	}while (*str!='\0');
	(*nP)++;
}

//Ex. 4 Ainda em relação à função anterior (nPalavras), escreva as
// instruções, por exemplo no main, que lhe permitam pedir uma string ao
// utilizador, invocar a função nPalavras e escrever, no ecrã, a
//  resposta da função (isto é, escrever, no ecrã, o número de palavras
// da string introduzida pelo utilizador).
void contarPalavEscritUtiliz(void){
	char buffer[101];
	int numPal=0;
	printf("\nDigite uma frase (m�ximo 100 caracteres): ");
	getchar();
	if (fgets(buffer, sizeof(buffer)-1, stdin) != NULL) {
		nPalavras(buffer, &numPal);
		printf("\nO n�mero de palavras da frase especificada pelo utilizador foi: %d\n\n", numPal);
	}
	else{
		printf("\nN�o foi introduzida qualquer frase!!!\n\n");
	}
}

// Ex. 6
// Complete a função abaixo que copie e retorne o conteúdo da string x para a string y, usando ponteiros.
void strCopiaComPonteiros(char *x, char *y){
	while (*x!='\0'){
		*y=*x;
		x++;
		y++;
	}
	*y='\0';
}

// Ex. 7
// Considere o vetor V={5,1,4,2,7,8,3,6}. Qual será o conteúdo do vetor V depois de executado o algoritmo abaixo?
void transfVector(int V[]){
	int i, aux;
	for(i=7; i>=4; i--){
		aux=V[i];
		V[i]=V[7-i+1];
		V[7-i+1]=aux;
		//printf("V[%d]=%d\n",i,V[i]);
		//printf("V[%d]=%d\n\n",7-i+1,V[7-i+1]);
	}
	V[2]=V[0];
	//printf("V[%d]=%d\n",2,V[2]);
	V[V[2]]=V[V[1]];
	printf("V[%d]=%d\n",V[2],V[V[2]]);
	// mostrar o vector
	printf("Vetor final: \n");
	for(i=0; i<8; i++)
		printf("V[%d]=%d\t", i+1, V[i]);
}

