#include <stdio.h>
#include <locale.h>

int main() {
	
	setlocale(LC_ALL, "pt_PT.UTF-8"); 
	float base;
	float altura;
	do {
		printf("Introduza a base: ");
		scanf("%f",&base);
	} while (base < 0);
	do {
		printf("Introduza a altura: ");
		scanf("%f",&altura);	
	} while (altura < 0);
	
	float area = (base*altura)/2;
	
	printf("A área do triângulo é %f", area);
	return 0;	
}