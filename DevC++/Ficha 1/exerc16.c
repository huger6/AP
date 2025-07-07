#include <stdio.h>

int main() {
	
	int x,y;
	printf("Escreva dois números inteiros: ");
	scanf("%d, %d", &x, &y);
	
	printf("%8d, %-8d", &x, &y);
}