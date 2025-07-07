#include <stdio.h>

void primo(int n);

int main() {
	int n;
	printf("Escreve n: ", n);
	scanf("%d", &n);
	primo(n);
	return 0;
}

void primo(int n) {
	int j = n/2;
	int is_primo = 1;
	for(int i = 2; i <= j; i++) {
		if (n % i == 0) {
			is_primo = 0;
			break; }
		}
	if (is_primo)
		printf("Primo.\n");
	else
		printf("!Primo.\n");
	}