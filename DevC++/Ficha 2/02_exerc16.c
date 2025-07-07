#include <stdio.h>

void linha( int atual, int n);

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

void linha( int atual, int n) {
	int branco = (n - atual);
	for (int i = 0; i < branco; i++)
		printf(" ");
	int temp = 1;
	while (temp <= atual) {
		printf("%d", temp);
		temp++;
	}
	temp = atual - 1;
	while (temp >= 1) {
		printf("%d", temp);
		temp--;
	}
	
	for (int i = 0; i < branco; i++)
		printf(" ");
		
	printf("\n");
	
}
