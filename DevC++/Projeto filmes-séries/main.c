#include <stdio.h>
#include "headers.h"
//TODO SECTION
/*
-Verificar o exit - possíveis problemas associados a fechar os ficheiros
-Fazer de forma a que baste colocar o numero sem ter de pressionar enter

Ordem
-
*/

int main() {
	//Colocar a consola em PT-PT
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int primeira_opcao, segunda_opcao, nivel_menu;
	segunda_opcao = 0; //Verificar se fomos ao menu 2.
	
	escolha_menus(&nivel_menu, &primeira_opcao, &segunda_opcao);
	//Colocar o ponteiro a NULL caso haja erros
	FILE * file_filmes = NULL;
	cJSON * total_filmes = NULL;
	FILE * file_series = NULL;
	cJSON * total_series = NULL;
	//Secção para os filmes
	file_filmes = fopen("filmes.json", "r");
	\
	if (file_filmes == NULL) { //Ficheiro não existe -> abrir o ficheiro e criar o array para os filmes
		file_filmes = fopen("filmes.json", "w");
		total_filmes = cJSON_CreateArray(); //Se ainda não existe, criamos o array para os filmes (o que vai contar os diferentes filmes)
		//Vamos criar um objeto com um array para todos os filmes
		cJSON * filme = cJSON_CreateObject();
		cJSON_AddItemToObject(filme, "Filmes", total_filmes);
		//Passar os dados para o ficheiro
		char * inicializar_dados = cJSON_Print(filme);
		fwrite(dados_json, sizeof(char), strlen(dados_json), file_filmes);
		free(dados_json); //Libertar memória
	}
	
	fclose(file_filmes);
	
	//Secção para as séries
	file_series = fopen("series.json", "r");
	
	if (file_series == NULL) { //Seguimos a mesma lógica dos filmes
		file_series = fopen("series.json", "w");
		total_series = cJSON_CreateArray();
		
		cJSON * serie = cJSON_CreateObject();
		cJSON_AddItemToObject(serie, "Séries", total_series);
		
		char * inicializar_dados = cJSON_Print(filme);
		fwrite(dados_json, sizeof(char), strlen(dados_json), file_series);
		free(dados_json); //Libertar memória
	}
	
	fclose(file_series);
	
	//Dar delete nos arrays utilizados
	
}





