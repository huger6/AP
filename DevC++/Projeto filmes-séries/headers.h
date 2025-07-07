#ifndef HEADERS_H
#define HEADERS_H

#define INITIAL_BUFFER_SIZE 100

//Bibliotecas usadas
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "cJSON.h"

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
void * resposta();

#endif