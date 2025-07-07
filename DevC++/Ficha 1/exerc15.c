#include <stdio.h>
#include <math.h>

int main() {
	float a,b,c,x1, x2;
	
	
	printf("Qual é o a, b e c? (Formato: a, b, c) ");
	scanf("%f, %f, %f", &a, &b, &c);
	
	if ((a != 0)&&(((b*b)- 4*a*c) >= 0)) {
		x1 = ((-1*b - sqrt(((b*b)- 4*a*c)))/2*a);
		x2 = ((-1*b + sqrt(((b*b)- 4*a*c)))/2*a);
	}
	else {
		printf("Não tem raízes.\n");
	}
	printf("As raízes são %f e %f\n", x1, x2);
	return 0;
}
