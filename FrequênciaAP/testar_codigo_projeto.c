#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void pressione_enter() {
    printf("Pressione Enter para continuar.\n");
    while (getchar() != '\n'); //Caso o user escreva algo e não enter limpar buffer
}

char * ler_linha_txt(FILE * ficheiro, int * n_linhas) {
    if(!ficheiro) return NULL;
    //n_linhas não será inicializado aqui
    char buffer[100]; //Buffer para armazenar parte da linha
    size_t tamanho_total = 0; //Comprimento da linha; size_t pois é sempre >0 e evita conversões que podem levar a erros com outras funções
    char * linha = NULL;

    while (fgets(buffer, sizeof(buffer), ficheiro)) { //fgets le ate buffer -1 caracteres ou '\n' ou EOF
        size_t tamanho = strlen(buffer); //Calcula o tamanho do texto lido
        //NOTA IMPORTANTE: se o ponteiro passado para realloc for nulo, ele funciona como o malloc
        char * temp = realloc(linha, tamanho_total + tamanho + 1); //+1 para o nul char
        if (!temp) {
            //Evitar ao máximo retornar NULL, pois isso terminaria o loop em carregar_dados
            if (linha) {
                linha[tamanho_total] = '\0';
                if (n_linhas != NULL) (*n_linhas)++;
                return linha;
            }
            return NULL; //Caso haja um erro fatal, temos que interromper
        }
        linha = temp; //atualizar o ponteiro linha para apontar para a nova memória

        //Copiar o conteúdo lido para a linha total
        memmove(linha + tamanho_total, buffer, tamanho); //linha + tamanho_total é um ponteiro para a posição da memória seguinte para onde a próxima parte de buffer será copiada
        tamanho_total += tamanho;
        //Se houver mais que uma leitura, o primeiro char da segunda leitura de fgets irá substituir o nul char, pelo que fica sempre no fim
        linha[tamanho_total] = '\0'; 

        //Verificamos se a linha está completa
        if (linha[tamanho_total - 1] == '\n') { //se tudo tiver sido copiado, o ultimo caracter do buffer(e da linha também) será o '\n'
            if (n_linhas != NULL) (*n_linhas)++;
            linha[tamanho_total - 1] = '\0'; //Substitui o \n por \0
            return linha;
        }
    }

    if (linha && tamanho_total > 0) {
        //Linha final sem '\n' mas tem conteudo (por ex: ultima linha)
        if (n_linhas != NULL) (*n_linhas)++;
        return linha;
    }

    //Se chegarmos aqui é porque aconteceu algum erro ou o ficheiro está vazio
    free(linha);
    return NULL;
}

int string_para_int(const char * str, int * resultado) {
    char * ptr_fim;
    long valor = strtol(str, &ptr_fim, 10);
    //strtol trunca em caso de overflow, daí o <= abaixo

    //Verificar erros de conversão
    if (ptr_fim == str || *ptr_fim != '\0') {
        return 0;  //Se o ponteiro de fim da str for igual ao ptr do inicio, não há um int; Se for diferente de nul char então também houve erro porque há caracteres indesejados
    }
    
    //Como strtol converte para longs e nós só queremos ints, pode ler números mais altos que o int conseguiria guardar
    if (valor >= INT_MAX || valor <= INT_MIN) {
        return 0; 
    }
    
    *resultado = (int) valor;
    return 1;
}

void pedir_codigo(int * codigo) {
    *codigo = 0;
    char * input = NULL;
    do {
        //Usamos ler_linha_txt para evitar overflows (o código é mais grave por causa dos algoritmos de procura)
        printf("Insira o código do estudante (ou '0' para sair): ");
        input = ler_linha_txt(stdin, NULL);
        if (!input) continue;

        if (!string_para_int(input, codigo)) {
            printf("Código inválido! Insira um número inteiro positivo.\n");
            pressione_enter();
            free(input);
            continue;
        }
        free(input);
        
        if (*codigo < 0) {
            printf("Código inválido! O código não pode ser negativo.\n");
            continue;
        }
        break;
    } while(1);
}


int main() {
    int codigo_temp = -1;
    pedir_codigo(&codigo_temp);
    printf("%d\n", codigo_temp);
}

