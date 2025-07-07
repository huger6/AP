//Fazer para expoente negativo

#include <stdio.h>

struct Valores {
		int n;
		int exp;
	};

int exponenciacao(int n, int exp);
struct Valores leitura();
 
int main() {
	struct Valores resultado = leitura();
	if (resultado.exp < 0) {
		float res = 1.0/(float)(exponenciacao(resultado.n, -resultado.exp));
		printf("O resultado de n^exp é de %.2f", res);
	}
	else 
		printf("O resultado de n^exp é de %d", exponenciacao(resultado.n, resultado.exp));
	return 0;
}

struct Valores leitura() {
	int n1, exp1;
	struct Valores resultado;
	do {
		printf("Valor de n: ");
		scanf("%d", &n1);
	} while (n1 < 0);
	
	do {
        printf("Valor de exp: ");
        if (scanf("%d", &exp1) != 1) {
            printf("Introduza um número válido: \n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer para evitar o loop infinito caso não seja int
        } else {
            break;
        }
    } while (1);
	
	resultado.n = n1;
	resultado.exp = exp1;
	return resultado;
}

int exponenciacao(int n, int exp) {
	int resultado = 1;
	for(int i = 0; i < exp; i++) {
		resultado *= n;
	}
	return resultado;
}