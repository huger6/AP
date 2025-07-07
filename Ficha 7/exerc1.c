#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[50];
    FILE * ficheiro;
    ficheiro = fopen("exerc1.txt", "w");

    do {
        printf("Digite a frase (Max:50, escreva \".\" para acabar): ");
        gets(str);
        fputs(str, ficheiro);
        fputc('\n', ficheiro);
    }while (strcmp(str, "." ));
    fclose(ficheiro);
    ficheiro == NULL;

    ficheiro = fopen("exerc1.txt", "r");
    while(!feof(ficheiro)) {
        fgets(str, 51, ficheiro);
        printf("%s", str);
    }
    fclose(ficheiro);
}