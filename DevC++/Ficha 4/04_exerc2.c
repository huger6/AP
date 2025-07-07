#include <stdio.h>

void manipularString(char * array);

int main() {
	char array[50];
	
	manipularString(array);
	
}

void manipularString(char * array) {
	
	printf("Escreva uma string: ");
	scanf("%49s", array); //49 limita a leitura a 49 chars + nul char
	
	int num_elementos = 0;
	for (int i = 0; array[i] != '\0'; i++)	
		num_elementos++;
		
	if (num_elementos < 2) 
		printf("A string não tem 2 caracteres.\n");
	
	else
		printf("O primeiro elemento da string é \"%c\" e o segundo é \"%c\"", array[0], array[1]);
}