#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 100

char * resposta() {
	char buffer[INITIAL_BUFFER_SIZE];
    char *input = NULL;
    size_t input_length = 0;
    size_t allocated_size = 0;

    while (fgets(buffer, INITIAL_BUFFER_SIZE, stdin)) {
        size_t buffer_length = strlen(buffer); //o próximo caracter introduzido

        // Verifica se precisamos de realocar mais memória
        if (input_length + buffer_length + 1 > allocated_size) {
        	//								Valor se:  			V			F
            size_t new_size = allocated_size == 0 ? INITIAL_BUFFER_SIZE : allocated_size * 2;
            char *new_input = realloc(input, new_size);
            if (!new_input) {
                free(input);
                printf("Erro de alocação de memória.\n");
                return NULL;
            }
            input = new_input;
            allocated_size = new_size;
        }

        strcpy(input + input_length, buffer);
        input_length += buffer_length;

        if (buffer[buffer_length - 1] == '\n') {
            break;
        }
    }

    if (input) {
        // Remove o caractere de nova linha, se presente
        if (input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }
    } 
	return(input);
}

