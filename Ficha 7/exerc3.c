#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long tamanhoBytes(FILE * f);

int main() {
    FILE * f;
    const char * nome = "exerc1.txt";
    printf("O ficheiro tem %d bytes.", tamanhoBytes(f));

}


long tamanhoBytes(FILE * f) {
    if (f == NULL)
        return 0;
    else {
        fseek(f,0,2);
        return ftell(f);
    }
}