#include <stdio.h>


#define n 4

void somatorio(int i, int lim, int * soma) {
    if (i < n + 1) {
        *soma += i * (i + 3);
        somatorio(i + 1, lim, soma);
    }
}


int main(void) {
    int soma = 0;
    somatorio(1, n, &soma);
    printf("%d\n", soma);
}


