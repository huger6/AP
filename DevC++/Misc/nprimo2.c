#include <stdio.h>

int main() {
	
	int n = 1000;
	int primo;
	printf("1\n");
	for(int j = 2; j < n; j++) {
		primo = 1;
		int j2 = j/2;
		
		for(int i = 2; i <= j2; i++) {
			if (j % i == 0)
				primo = 0; }
		if (primo == 1)
			printf("%d\n", j);
	}
}
	