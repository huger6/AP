#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//TODO SECTION
/* 
-Falta ainda colocar a opção de retirar um filme/série dos vistos ou para ver.
-Fazer de forma a que baste colocar o numero sem ter de pressionar enter
*/

//Structs
typedef struct filme {
	char * titulo;
	int ano;
	char * genero;
	float classificacao;
	int visto;
	char * descricao;
}Filme;

typedef struct serie {
	char * titulo;
	int ano;
	char * genero;
	int temporadas;
	int episodios_por_temporada;
	float classificacao;
	int visto;
	char * descricao;
}Serie;

//Funções
void menu_principal(int * primeira_opcao);
void menu_filmes(int * segunda_opcao, int * sair);
void menu_series(int * segunda_opcao, int * sair);
void escolha_menus(int * nivel_menu, int * primeira_opcao, int * segunda_opcao);
void apresentar_lista_vistos(void * elemento, int tipo);
void apresentar_lista_por_ver(void * elemento, int tipo);


int main() {
	//Colocar a consola em PT-PT
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int primeira_opcao, segunda_opcao, nivel_menu;
	segunda_opcao = -1; //Verificar se fomos ao menu 2.Se não, 2nd = 1
	
	escolha_menus(&nivel_menu, &primeira_opcao, &segunda_opcao);
	
	printf("1st: %d\n", primeira_opcao);
	printf("2st: %d", segunda_opcao);
}

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

void apresentar_lista_vistos(void * elemento, int tipo) {
	
}

void apresentar_lista_por_ver(void * elemento, int tipo) {
	
}

void verificar_visto(void * elemento, int tipo) {
	
}

void adicionar(void * elemento, int tipo) {
	
}

void marcar_visto(void * elemento, int tipo) {
	
}

void remover_de_ver(void * elemento, int tipo) {
	
}

void remover_visto(void * elemento, int tipo) {
	
}

void classificar(void * elemento, int tipo) {
	
}



