//Sucessão de fibonnaci

#include <stdio.h>
#include <stdlib.h>
#define N 50


long long fibonacci_recursiva(int n);

int main() {
    // printf("%ld", fibonacci_recursiva(N));
    long * vetor = (long *) malloc(N * sizeof(N));
    return 1;
}


long long fibonacci_recursiva(int n) {
    if (n == 0 || n == 1) return n;

    return fibonacci_recursiva(n - 1) + fibonacci_recursiva(n -2);
}

long fiboPro(int n, long * vetor) {
    if (n == 0) vetor[0] = 0;
    if (n == 1) vetor[1] = 1;
    if(n > 1) {
        if (vetor[n -1] == -1) vetor[n - 1] = fiboPro(n -1, vetor);
        if (vetor[n -2] == -1) vetor[n - 2] = fiboPro(n -2, vetor);
        vetor[n] = vetor[n - 1] + vetor[n -2];
    }
    return vetor[n];
}