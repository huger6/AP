#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

typedef struct ponto {
	float x;
	float y;
}Ponto;

typedef struct retangulo {
	float area;
	float comprimento_diagonal;
}Retangulo;

Retangulo calculos(Ponto A, Ponto B, Retangulo * R1);


int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	Ponto A, B;
	Retangulo R1;
	
	printf("Insira as coordenadas de A (x,y): ");
	scanf("%f%f", &A.x, &A.y);
	
	printf("\nInsira as coordenadas de B (x,y): ");
	scanf("%f%f", &B.x, &B.y);
	
	calculos(A, B, &R1);
	
	printf("Área: %.2f\n", R1.area);
	printf("Comprimento da diagonal: %.2f\n", R1.comprimento_diagonal);
}

Retangulo calculos(Ponto A, Ponto B, Retangulo * R1) { //Passamos a struct por ponteiro
	//d=√((x_2-x_1)²+(y_2-y_1)²)
	R1 -> comprimento_diagonal = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)); //Objeto -> (atributo) = ... (quando se trata de ponteiros)
	float lado_horizontal, lado_vertical;
	lado_horizontal = (float) abs(A.x - B.x);
	lado_vertical = (float) abs(A.y - B.y);
	R1 -> area = lado_vertical * lado_horizontal;
	return *R1;
}
