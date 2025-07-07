#include <stdio.h>

int main () {
	
	float  horas, resto_horas;
	int minutos, horas2;
	do {
		printf("Quantos minutos passaram desde a meia-noite? ");
		scanf("%d",&minutos);	
	} while (minutos > 1440);
	
	horas = (float) minutos / 60;
	horas2 = minutos / 60;
	resto_horas = horas - horas2;
	
	minutos = resto_horas * 60;
	
	printf("São %d:%d.\n", horas2, minutos);
	
	return 0;
}