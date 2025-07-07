//
//  main.c
//  FreqResol
//
//  Created by Jorge Loureiro on 07/01/2025.
//

#include "Funcs_vF.c"
#include "FuncsEx5_vF.c"

int main() {
	setlocale(LC_ALL, "Portuguese");
	// Invoca��o da fun��o relativa � quest�o 1.a)
	printf("\nExecu��o da quest�o 1.a)-->\n");
	q1A();   // a resposta certa � a b)
	printf("\n\n");

	// Invoca��o da fun��o relativa � questão 1.b)
	printf("\nExecu��o da quest�o 1.b)-->\n");
	printf("O valor de j ser�: %d", q1B());   // a resposta certa � a b)
	printf("\n\n");

	// Invocação da fun��o relativa � questão 2)
	printf("\nExecu��o da quest�o 2)-->\n");
	int mat[MAX][MAX];
	//limparMatriz(mat);
	matrizTriang(mat);
	//mostarMatriz(mat);

	// Invoca��o da fun��o relativa � questão 3)
	printf("\nExecu��o da quest�o 3)-->\n");
	char str1[200]="Isto e um teste para ver quantas palavras tem esta string";
	int nPalav=0;
	nPalavras(str1, &nPalav);
	printf("O n�mero de palavras da string: \"%s\" �: %d", str1, nPalav);
	printf("\n\n");
	
	// Invoca��o da fun��o relativa � quest�o 4)
	printf("\nExecu��o da quest�o 4)-->\n");
	contarPalavEscritUtiliz();
	
	// Exerc�cio 5
	// a)
	
	AZULEJO parede[MAX_AZ1][ MAX_AZ2];

	
	//preencher para testes
	parede[0][0].comp=0.2;
	parede[0][0].larg=0.4;
	parede[0][0].nCores=2;
	parede[0][1].comp=0.3;
	parede[0][1].larg=0.7;
	parede[0][1].nCores=3;
	parede[0][2].comp=0.4;
	parede[0][2].larg=0.4;
	parede[0][2].nCores=5;
	parede[1][0].comp=0.3;
	parede[1][0].larg=0.5;
	parede[1][0].nCores=2;
	parede[1][1].comp=0.4;
	parede[1][1].larg=0.8;
	parede[1][1].nCores=4;
	parede[1][2].comp=2.5;
	parede[1][2].larg=3.7;
	parede[1][2].nCores=6;
	// b)
	printf("\nO valor da �rea da parede �: %.2f\n", areaParede(parede));
	//printf("\nO valor da área coberta por azulejos na 1.ª obra é: %.2f\n", areaObra(obras+1));
	
	// c)
	printf("\nO n�mero m�dio de cores utilizado na parede �: %.2f\n", mediaCores(parede));
	
	// d)
	//printf("\nA maior área ocupada por azulejos nas obras é: %.2f\n", areaMaior(obras, 2));
	
	// d)
	infObra(parede);
	
	// Exerc�cio 6
	char str10[10]="abcdef";
	char str20[10]="";
	strCopiaComPonteiros(str10, str20);
	printf("\nA string str20 e: %s\n", str20);
	
	// Exerc�cio 7
	int V1[8]={5,1,4,2,7,8,3,6};
	transfVector(V1);
    // O vector no final é: V1={5,1,5,2,7,1,3,6}
	return 0;
}
