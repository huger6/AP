#include <stdio.h>

void linha_esquerda(int blocos, int altura);
void linha_direita(int blocos, int altura);


int main()
{
    int n, lado;
    do
    {
        printf("Introduza o valor de N: ");
        scanf("%d", &n);
    } while (n < 1);
    
    do {
    	printf("Quer alinhar à esquerda(1) ou à direita(2)? ");
    	scanf("%d", &lado);
	} while ((lado != 1)&&(lado != 2));
	
	printf("\n");
	//Loopar por cada linha 
    for (int i = 1; i <= n; i++) {
    	if (lado == 1)
        	linha_esquerda(i, n);
        else if (lado == 2)
        	linha_direita(i, n);
		}
		        	
}

void linha_esquerda(int blocos, int altura) {
	int branco = (altura - blocos);
    for(int i = 0; i < branco; i++) {
    	printf(" "); }
    //Printar blocos em cada linha
    for(int i = 0; i < blocos; i++)
        printf("*");
    //Passar para a linha de baixo
    printf("\n");
}

void linha_direita(int blocos, int altura) {
	//Printar blocos em cada linha
    for(int i = 0; i < blocos; i++)
    {
        printf("*");
    }
    //Passar para a linha de baixo
    printf("\n");
}
