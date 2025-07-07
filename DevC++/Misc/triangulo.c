// Exercício 6 - Elabore o algoritmo de um programa que determine o terceiro
// lado de um triângulo rectângulo, dados os outros dois.
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <locale.h>
int main(void)
{
		setlocale(LC_ALL, "Portuguese");
		float lado1, lado2, lado3; lado1=lado2=lado3=0;
		int ladoQueFalta;
	 	printf("Qual o lado que falta? ");
	 	printf("[1 - Hipotenusa; 2 - Cateto]: ");
	 	scanf("%d",&ladoQueFalta);
	 	printf("\n");
	 	
		if (ladoQueFalta==1){
		do {
	 	printf("Insira o valor do cateto 1: ");
	 	scanf("%f", &lado1);
	 	} while(lado1<0.0);
	 	
	 	do {
	 	printf("Insira o valor do cateto 2: ");
	 	scanf("%f", &lado2);
	 	} while(lado2<0.0);
	 	
	 	lado3=sqrt(lado1*lado1+lado2*lado2);
	 	printf("O valor da hipotenusa é: %7.2f", lado3));
	 	}
		else {
		if (ladoQueFalta==2)
		{
			 do {
				 printf("Insira o valor do cateto 1: ");
				 scanf("%f", &lado1);
			 } while(lado1<0.0);
			 do {
				 printf("Insira o valor da hipotenusa: ");
				 scanf("%f", &lado2);
			 } while(lado2<0.0);
			 if (lado2*lado2-lado1*lado1 > 0){
			 	lado3=sqrt(lado2*lado2-lado1*lado1);
			 	printf("O valor do cateto: %7.2f", lado3)}
			 else
			 printf("Triângulo Impossível!!");
		}
	 	else
	 		printf("Tipo de cálculo inválido!!");
	 	}
	 	printf("\n\n");
	 	printf("Para fechar a janela, digite <Return> ");
 	c=getchar();
 	c=getchar();
 	return 0;
 } 