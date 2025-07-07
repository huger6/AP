#include <stdio.h>
#include "headers.h"

void menu_principal(int * primeira_opcao) {
	int valido = 0;
		do {
			system("cls"); //Limpar terminal
			printf("\t\tMENU\t\t");
			printf("\n\n");
			printf("0 - Sair\n");
			printf("1 - Filmes\n");
			printf("2 - Séries\n");
			printf("3 - Estatísticas\n");
			printf("4 - Exportar dados\n");
			printf("\n\nOpção: ");
			valido = scanf("%d", primeira_opcao);
			
			if (valido != 1) {
		        printf("Entrada inválida!\n");
		        while (getchar() != '\n');  // Limpar o buffer de entrada
			    printf("Pressione Enter para continuar.\n");
			    getchar();  // Esperar pelo Enter do utilizador
			}
	        
			else if (*primeira_opcao < 0 || *primeira_opcao > 4) {
				valido = 0;
				printf("Por favor, escolha um número do menu.\n");
				printf("Pressione Enter para continuar.\n");
	            getchar();  
	            system("cls");  
			}
			
			if ((*primeira_opcao == 0)&&(valido == 1)) {
				exit(0);
			}
		} while (valido == 0);
}

void menu_filmes(int * segunda_opcao, int * sair) {
	int valido = 0;
	*sair = 0;
	do {
		system("cls");
		printf("\t\tFILMES\t\t");
		printf("\n\n");
		printf("0 - Voltar ao menu anterior\n");
		printf("1 - Lista de filmes vistos\n");
		printf("2 - Lista de filmes para ver\n");
		printf("3 - Verificar se o filme já foi visto\n");
		printf("4 - Adicionar filme para ver\n");
		printf("5 - Marcar filme como visto\n");
		printf("6 - Remover filme de ver\n");
		printf("7 - Remover filme dos vistos\n");
		printf("8 - Classificar filme\n");
		printf("\n\nOpção: ");
		valido = scanf("%d", segunda_opcao);
		
		if (valido != 1) {
	        printf("Entrada inválida!\n");
	        while (getchar() != '\n');  // Limpar o buffer de entrada
		    printf("Pressione Enter para continuar.\n");
		    getchar();  // Esperar pelo Enter do utilizador
		}
        
		if (*segunda_opcao < 0 || *segunda_opcao > 8) {
			valido = 0;
			printf("Por favor, escolha um número do menu.\n");
			printf("Pressione Enter para continuar.\n");
            getchar();  
            system("cls");
		}
		
		if ((*segunda_opcao == 0)&&(valido == 1)) {
			*sair = 1;
			break;
		}
	} while (valido == 0);	 
}


void menu_series(int * segunda_opcao, int * sair) {
	int valido = 0;
	*sair = 0;
	do {
		system("cls");
		printf("\t\tSÉRIES\t\t");
		printf("\n\n");
		printf("0 - Voltar ao menu anterior\n");
		printf("1 - Lista de séries vistas\n");
		printf("2 - Lista de séries para ver\n");
		printf("3 - Verificar se a série já foi vista\n"); 
		printf("4 - Adicionar série para ver\n");
		printf("5 - Marcar série como vista\n"); 
		printf("6 - Remover série de ver\n"); 
		printf("7 - Remover série das vistas\n"); 
		printf("8 - Classificar série\n"); 
		printf("\n\nOpção: ");
		valido = scanf("%d", segunda_opcao);
		
		if (valido != 1) {
	        printf("Entrada inválida!\n");
	        while (getchar() != '\n');  // Limpar o buffer de entrada
		    printf("Pressione Enter para continuar.\n");
		    getchar();  // Esperar pelo Enter do utilizador
		}
        
		if (*segunda_opcao < 0 || *segunda_opcao > 8) {
			valido = 0;
			printf("Por favor, escolha um número do menu.\n");
			printf("Pressione Enter para continuar.\n");
            getchar();  
            system("cls");
		}
		
		if ((*segunda_opcao == 0)&&(valido == 1)) {
			*sair = 1;
			break;
		}
	} while (valido == 0);
}

void escolha_menus(int * nivel_menu, int * primeira_opcao, int * segunda_opcao) {
	int sair = 0;
	*nivel_menu = 1;
	while(1) {
		menu_principal(primeira_opcao);
		system("cls");
		
		switch (*primeira_opcao) {
			case 0: 
			//!!!Podemos ter de fechar os ficheiros aqui e libertar memória, ou então passar para a main para lidar com isso!!!
			 	exit(0);
			case 1:
				*nivel_menu = 2;
				menu_filmes(segunda_opcao, &sair);
				if (sair) {
					*nivel_menu = 1;
				}
				break;
			case 2:
				*nivel_menu = 2;
				menu_series(segunda_opcao, &sair);
				if (sair) {
					*nivel_menu = 1;
				}
				break;
			case 3:
				*nivel_menu = 2;
				break;
			case 4:
				*nivel_menu = 2;
				break;
			default:
				printf("Erro!\n");
				break;
		}
		system("cls");
		if (*nivel_menu != 1) {
			break;
		}
	}
}


//Provavelmente não será utilizado
void carregar_dados(FILE ** ficheiro, cJSON ** array) {
	
}

void apresentar_lista_vistos(void * elemento, int tipo) {
	
}

void apresentar_lista_por_ver(void * elemento, int tipo) {
	
}

void verificar_visto(void * elemento, int tipo) {
	
}
// 								definido por nós F(Filme) e S(Série)
void adicionar(FILE ** ficheiro, void * tipo, const char nome_tipo) {
	system("cls");
	if (nome_tipo == 'F') {
		Filme * filme = (Filme *) tipo; //Fazer o cast
		FILE * filmes = fopen(*ficheiro, "a");
		
		if(!filmes) {
			printf("Erro ao abrir o ficheiro de filmes.\n");
			return NULL;
		}
		printf("Nome do filme: ");
		filme->titulo = resposta();
		printf("Classificação do filme (0-10): ");
		while (scanf("%f", &filme->classificacao) != 1 || filme->classificacao < 0 || filme->classificacao > 10) {
            printf("Valor inválido. Insira uma classificação entre 0 e 10: ");
            while (getchar() != '\n'); // Limpa o buffer do stdin
        }
        while (getchar() != '\n'); //Limpar o buffer	
        
        //Falta dar fprintf no ficheiro e dar free
        
	}
	//Falta replicar para as séries
}

void marcar_visto(void * elemento, int tipo) {
	
}

void remover_de_ver(void * elemento, int tipo) {
	
}

void remover_visto(void * elemento, int tipo) {
	
}

void classificar(void * elemento, int tipo) {
	
}

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
