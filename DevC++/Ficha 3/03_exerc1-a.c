#include <stdio.h>

int isDigit(char c);
int isAlpha(char c);
int isAllnum(char c);
char toLower(char c);
char toUpper(char c);

int main() {
	char a;
	printf("Insira um caracter: ");
	scanf("%c", &a);
	
	if (isAllnum(a))
		printf("É alfanumérico.\n");
	else
		printf("Não é alfanumérico.\n");
	
	if (isDigit(a))
		printf("É dígito.\n");
	else
		printf("Não é dígito.\n");
	
	if (isAlpha(a)) {
		printf("É letra e a maiúscula é %c.\n", toUpper(a));
		printf("É letra e a minúscula é %c.\n", toLower(a));
	}
	else
		printf("Não é letra.\n");
}


int isDigit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
	}

int isAlpha(char c) {
	if ((c >= 65 && c>= 90)||(c >= 97 && c<= 122))
		return 1;
	else
		return 0;
}

int isAllnum(char c) {
	if (isDigit(c)||isAlpha(c))
		return 1;
	else
		return 0;
}

char toLower(char c) {
	if (c >= 'a' && c <= 'z')
		return c;
	else
		return (c + 32);
}

char toUpper(char c) {
	if (c >= 'A' && c <= 'Z')
		return c;
	else
		return (c - 32);
}

