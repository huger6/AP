//ESTÁ MAL

#include <stdio.h>

void calcularPascoa(int ano, int *dia, int *mes) {
    int a = ano % 19;
    int b = ano / 100;
    int c = ano % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 16;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 16;
    int j = c % 16;
    int k = (32 + 2 * e + 2 * i - h - j) % 7;
    int m = (a + 11 * h + 22 * k) / 451;

    *mes = (h + k - 7 * m + 114) / 31; // Mês da Páscoa
    *dia = (h + k - 7 * m + 114) % 31 + 1; // Dia da Páscoa
}

int main() {
    int ano;
    printf("Insira o ano: ");
    scanf("%d", &ano);

    int dia, mes;
    calcularPascoa(ano, &dia, &mes);
    
    printf("A Páscoa em %d calha a %d de %s.\n", ano, dia, (mes == 3 ? "março" : "abril"));
    
    return 0;
}
