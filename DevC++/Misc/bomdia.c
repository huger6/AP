#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese" );
	printf("***Bom dia!!***\n\n");
	return 0;
}