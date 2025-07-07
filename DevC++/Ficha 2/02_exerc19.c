#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	setlocale(LC_ALL, "pt_PT.UTF-8");
	
	int n, guess, tentativas;
	tentativas = 0;
	
	do {
		printf("Escreva um número entre 1 e 100: ");
		scanf("%d", &n);
	} while ((n < 0)||(n > 100));
	int k = 0;
	
	//Comando para ocultar/limpar o terminal antes deste ponto
	system("cls");
	
	while(1) {
		printf("Palpite: ");
		scanf("%d", &guess);
		
		if (guess < n)
			printf("Palpite é inferior!");
		else if (guess > n)
			printf("Palpite é superior");
		else {
			printf("Acertou!");
			tentativas++;
			break;
		}
		tentativas++;
		printf("\n");
	}
	printf("\n");
	printf("Foram necessárias %d tentativas.", tentativas);
	
}