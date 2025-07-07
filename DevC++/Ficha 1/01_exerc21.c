#include <stdio.h>
#include <math.h>

int main() {
	printf("%d , %d", (unsigned int) pow(2, sizeof(int) * 8 -1) ,
	(unsigned int) pow(2, sizeof(int) * 8 -1) - 1);
	

	return 0;
}