#include <stdio.h>

int main() {
	int n;	
	printf("Que tabuada quer saber? ");
	scanf("%d", &n);
	
	for (int i = 1; i < 11;i++) {
		printf("%d x %d = %d\n", n, i, n*i);
	}
	return 0;
}