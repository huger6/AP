#include <stdio.h>

int maior(int a, int b);

int main() {
	int a, b;
	
	printf("a, b");
	scanf("%a, %b", &a, &b);
	maior(a, b);
	return 0;
}

int maior(int a, int b) {
	if (a < b)
		return b;
	else if (a > b)
		return a;
}