#include <stdio.h>

int main() {
	char a;
	scanf("%c", &a);
	
	if ((a == 33)||(a == 34)||(a == 39)||(a == 58)||(a == 59)||(a == 63)||(a == 94)||(a == 126)) {
		printf("Caracter de pontuação.\n");
	}
	else if ((a >= 48)&&(a <= 57)) 
		printf("Dígito.\n");
	else if ((a >=63) && (a <= 90)) 
		printf("Letra maiúscula.\n");
	else if ((a >= 97)&&(a <= 122))
		printf("Letra minúscula.\n");
	return 0;
}