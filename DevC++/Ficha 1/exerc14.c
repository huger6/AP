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
	char* tipo;
	minutos = resto_horas * 60;
	if (horas2 > 12) {
		horas2 = horas2 - 12;
		tipo = "p.m";
	}
	else {
		tipo = "a.m";	
	}
	printf("São %d:%d%s.\n", horas2, minutos, tipo);
	
}
	
	