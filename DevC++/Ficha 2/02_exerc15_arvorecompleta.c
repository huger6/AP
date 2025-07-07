#include <stdio.h>

void linha( int blocos, int altura);

int main()
{
    int n;
    do
    {
        printf("Introduza o valor de N: ");
        scanf("%d", &n);
    } while (n < 1);
	
		
	printf("\n");
	//Loopar por cada linha 
    for (int i = 1; i <= n; i++)
    	linha(i, n);
		        	
}

void linha( int blocos, int altura) {
	int branco = (altura - blocos);
	blocos *= 2;
	for (int i = 0; i < branco; i++)
		printf(" ");
	for (int i = 0; i < blocos; i++)
		printf("*");
	for (int i = 0; i < branco; i++)
		printf(" ");
	printf("\n");
}
