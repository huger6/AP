#include <stdio.h>


void ordenaVetor(int * vet, int N) {
    int houveTroca = 1;
    for (int i = 0; i < N - 1 && houveTroca == 1; i++) {
        houveTroca = 0;
        for (int j = 0; j < N - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                houveTroca = 1;
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
} 