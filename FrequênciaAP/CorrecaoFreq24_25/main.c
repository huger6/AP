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
	// Invocação da função relativa à  questão 1.a)
	printf("\nExecução da questão 1.a)-->\n");
	q1A();   // a resposta certa é a b)
	printf("\n\n");

	// Invocação da função relativa à  questÃ£o 1.b)
	printf("\nExecução da questão 1.b)-->\n");
	printf("O valor de j será: %d", q1B());   // a resposta certa é a b)
	printf("\n\n");

	// InvocaÃ§Ã£o da função relativa à questÃ£o 2)
	printf("\nExecução da questão 2)-->\n");
	int mat[MAX][MAX];
	//limparMatriz(mat);
	matrizTriang(mat);
	//mostarMatriz(mat);

	// Invocação da função relativa à  questÃ£o 3)
	printf("\nExecução da questão 3)-->\n");
	char str1[200]="Isto e um teste para ver quantas palavras tem esta string";
	int nPalav=0;
	nPalavras(str1, &nPalav);
	printf("O número de palavras da string: \"%s\" é: %d", str1, nPalav);
	printf("\n\n");
	
	// Invocação da função relativa à  questão 4)
	printf("\nExecução da questão 4)-->\n");
	contarPalavEscritUtiliz();
	
	// Exercício 5
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
	printf("\nO valor da área da parede é: %.2f\n", areaParede(parede));
	//printf("\nO valor da Ã¡rea coberta por azulejos na 1.Âª obra Ã©: %.2f\n", areaObra(obras+1));
	
	// c)
	printf("\nO número médio de cores utilizado na parede é: %.2f\n", mediaCores(parede));
	
	// d)
	//printf("\nA maior Ã¡rea ocupada por azulejos nas obras Ã©: %.2f\n", areaMaior(obras, 2));
	
	// d)
	infObra(parede);
	
	// Exercício 6
	char str10[10]="abcdef";
	char str20[10]="";
	strCopiaComPonteiros(str10, str20);
	printf("\nA string str20 e: %s\n", str20);
	
	// Exercício 7
	int V1[8]={5,1,4,2,7,8,3,6};
	transfVector(V1);
    // O vector no final Ã©: V1={5,1,5,2,7,1,3,6}
	return 0;
}
