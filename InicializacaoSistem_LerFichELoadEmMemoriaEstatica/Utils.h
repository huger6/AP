//
//  Utils.h
//  LerFichELoadEmMemoria
//
//  Created by Jorge Loureiro on 23/12/2024.
//

#ifndef Utils_h
#define Utils_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

// Definem-se aqui os tipos básicos para usar na função ReadSplitLine
#define STRING char *
#define MAX_LINHA_FICHEIRO 150
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];

// Outros tipos de dados usados
typedef struct data{
	int dia, mes, ano;
} DATA;

// Protótipos relativos às funções existentes no ficheiro .c
void retiraEnterString(char *S);
unsigned int convert(char *st, char *err);
void mostrarMensagem(char *mens);
STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores);
bool ano_bissexto(int ano);
bool validar_data(int dia, int mes, int ano);
#endif /* Utils_h */
