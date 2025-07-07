#include <stdio.h>

void concatenacaoStrings(char * string1, char * string2);

int main() {
	char string1[100], string2[50];
	
	printf("Escreva a primeira string: ");
	scanf("%49s", string1); //49 limita a leitura a 49 chars + nul char
	
	printf("Escreva a segunda string: ");
	scanf("%49s", string2); //49 limita a leitura a 49 chars + nul char
	
	concatenacaoStrings(string1, string2);
	
	int i = 0;
	while (string1[i] != '\0') {
		printf("%c", string1[i]);
		i++;
	}
}

void concatenacaoStrings(char *x, char *y)
{
 while (*(x++) != '\0') //Loop vazio, coloca o x na casa a seguir do nul char
 ;
 x--; //para x fica a apontar para o nul char
 
 while ( (*(x++)=*(y++)) !='\0') //Dá assign da posição de x a começar no nul char ao primeiro char de y. O incremento só acontece depois por se usar x++ e não ao contrário.
 ;
}