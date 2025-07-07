#include <stdio.h>
#include <locale.h>

int resto(int a, int b);
int impar(int x);
int perfeito(int n);
int primo(int n);

int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b;
	printf("Escreva um número: ");
	scanf("%d", &a);
	
	printf("Escreva um número: ");
	scanf("%d", &b);
	if (b !=0)
		printf("O resto da divisão de %d por %d é %d.\n", a, b, resto(a, b));
			
	if (impar(a))
		printf("%d é ímpar.\n", a);
	else
		printf("%d não é ímpar.\n", a);
	
	if (perfeito(a)) 
		printf("%d é perfeito.\n", a);
	else
		printf("%d não é perfeito.\n", a);
	
	if (primo(a))
		printf("%d é Nº primo.\n", a);
	else
		printf("%d não é primo.\n", a);
	
	
}

int resto(int a, int b) {
	return (a % b);
}

int impar(int x) {
	if (x % 2 == 0) 
		return 0;
	else
		return 1;
}

int perfeito(int n) {
	int j;
	if (n % 2 == 0)
		j = n / 2;
	else
		j = n/2 +1;
	int soma = 0;
	for(int i = j; i > 0; i--) {
		if (n % i == 0)
			soma += i;
	}
	if (soma == n)
		return 1;
	else
		return 0;
}

int primo(int n) {
	if ((n % n == 0)&&(n % 1 == 0)) {
		for (int i = 2; i < n;i++) {
			if (n % i == 0)
				return 0; }
		return 1;
		}
	else
		return 0;
}