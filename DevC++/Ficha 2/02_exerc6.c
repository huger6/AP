#include <stdio.h>

int main() {
	int m, n;
	
	printf("Qual o valor de m? ");
	scanf("%d", &m);
	
	printf("Indique os n primeiros múltiplos que quer calcular: ");
	scanf("%d", &n);
	
	printf("Os %d primeiros múltiplos de %d são: \n", n, m);
	
	for(int i = 1; i <= n; i++) {
		printf("%d\n", m*i);
	}
	return 0;
}