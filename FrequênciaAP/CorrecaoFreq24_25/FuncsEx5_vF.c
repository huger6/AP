//
//  FuncsEx5.c
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
#define MAX_AZ1 2    // para testes
#define MAX_AZ2 3    // para testes

typedef struct azulejo {
  float comp;
  float larg;
  int nCores;
}AZULEJO;

// Função do Ex. 5-b)
// Elabore uma fun��o que, dada uma parede, lhe permita 
//calcular e devolver o valor da �rea coberta de azulejos.
float areaParede(AZULEJO parede[MAX_AZ1][ MAX_AZ2]){
	int i=0, j=0;
	float areaOb=0.0;
	for(i=0; i<MAX_AZ1; i++)
		for(j=0; j<MAX_AZ2; j++){
			areaOb+=parede[i][j].comp * parede[i][j].larg;
		}
	return areaOb;
}

// Função do Ex. 5-c)
// Elabore uma fun��o que calcule e devolva o 
//n�mero m�dio de cores utilizado nos azulejos de uma parede.
float mediaCores(AZULEJO parede[MAX_AZ1][ MAX_AZ2]){
	int i=0, j=0;
	float totCores=0.0;
	int nAzulejos=0;//ou usar MAX_AZ1*MAX_AZ2 para o divisor no c�lculo da m�dia
	for(i=0; i<MAX_AZ1; i++)
		for(j=0; j<MAX_AZ2; j++)
			{
				totCores+=parede[i][j].nCores;
				nAzulejos++;//ou retirar
			}
	return totCores / nAzulejos;//ou usar MAX_AZ1*MAX_AZ2 no divisor
}


// Função do Ex. 5-d)
// Desenvolva uma fun��o que escreva, 
//num ficheiro de texto, a �rea dos azulejos com mais do que 2 cores

void infObra(AZULEJO parede[MAX_AZ1][ MAX_AZ2]){
	FILE *F=fopen("InfObra.txt", "w");
	int i=0, j=0;
	for(i=0; i<MAX_AZ1; i++)
		for(j=0; j<MAX_AZ2; j++){
			if (parede[i][j].nCores>2)
				fprintf(F, "Azulejo na posi��o [%d][%d] tem �rea de %.2f\n", i,j, parede[i][j].comp*parede[i][j].larg);
	}
	fclose(F);
}


