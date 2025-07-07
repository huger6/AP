#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    bool *isPrime = (bool *)malloc((n + 1) * sizeof(bool));
    
    // Assume que todos os números são primos
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    
    // 0 e 1 não são primos
    isPrime[0] = isPrime[1] = false;
    
    // Crivo de Eratóstenes
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            // Marca todos os múltiplos de p como não-primos
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    // Imprime todos os números primos
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d\n", i);
        }
    }
    
    free(isPrime); // Liberta a memória alocada
}

int main() {
    int n = 1000; // Podes definir o valor de `n` aqui
    sieveOfEratosthenes(n);
    return 0;
}
