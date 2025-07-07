#include <stdio.h>


int somate(int n);

int main() {
    int n = 0; int a = 0;
    printf("Soma: ");
    scanf("%d", &n);
    a = somate(n);
    printf("%d", a);
    return 1;
}

int somate(int n) {
    if (n == 1) return 1;
    return n + somate(n - 1);
}