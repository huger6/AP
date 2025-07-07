#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Definimos aqui os tipos básicos
#define STRING char *
#define MAX_LINHA_FICHEIRO 150
typedef struct pessoa{
	char nome[50];
	int idade;
	char caract[50];
	int altura;
}PESSOA;
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];

LinhaTexto LT;

/**
Nome-da-fun��o: Read_Split_Line_File
Descri��o: Permite ler o conte�do de uma linha do ficheiro e devolve
           uma tabela de strings com os v�rios campos lidos;
Parametros:
 - F :    ficheiro onde vai ser feita a leitura
 - n_campos_max:    n�mero m�ximo de campos a ler
 - n_campos_lidos:    devolve o numero de campos que a linha cont�m
 - separadores :    permite especificar os delimitadores dos campos que est�o na linha do ficheiro
Retorno:
 - Retorna uma tabela de strings
Observa��o:
 - Dentro desta fun��o � alocado espa�o de mem�ria, ficando a cargo
   de quem invoca a fun��o a liberta��o da mem�ria alocada
Autor: Francisco Morgado
**/
STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores)
{
    *n_campos_lidos = 0;
    if (!f) return NULL;
    if (fgets(LT , MAX_LINHA_FICHEIRO , f) != NULL)    // fgets l� uma linha do ficheiro de texto para a string LT
    {
        // "partir" a linha lida, usando os separadores definidos
        STRING *Res = (STRING *)malloc(n_campos_max*sizeof(STRING));  // aloca��o de um array com n_campos_max ponteiros para STRING
        char *pch = strtok (LT, separadores);
        int cont = 0;
        while (pch != NULL)
        {
            Res[cont] = (char *)malloc((strlen(pch)+1)*sizeof(char)); // aloca��o do espa�o necess�rio para guardar a string correspondente ao campo
            strcpy(Res[cont++], pch);
            pch = strtok (NULL, separadores);
        }
        *n_campos_lidos = cont;
        return Res;
    }
    return NULL;
};

/**
    Fun��o main(): apenas para teste da fun��o
    STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores);
**/
int main()
{
    printf("\nObjectivo: \n\tVer como se usa a funcao STRING *Read_Split_Line_File(FILE *f, ......) \n");
    int n_campos_max = 20;
    int n_campos_lidos;
    int n_linhas_lidas = 0;
    int i;
    
    //----------------------------------------------------------------------------
    FILE *F1 = fopen("exemploRSL.txt","r"); // os campos est�o separados por \t
    if (F1==NULL) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        return -1;
    }
    while(!feof(F1))
    {
        STRING *V = Read_Split_Line_File(F1, 4, &n_campos_lidos, "\t");  // experimentar
            // adicionar tamb�m o 'espa�o' como separador (substituindo "\t\r\n" por "\t \r\n" na linha acima)
            // e verificar que passam a ser devolvidos mais campos por linha...

        printf("\nA linha %d contem %d campos:\n", ++n_linhas_lidas, n_campos_lidos);
        for (i = 0; i < n_campos_lidos; i++)
            printf("\tcampo %d = V[%d] = [%s]\n", i+1, i, V[i]);
            
            PESSOA p;
            strcpy(p.nome,V[0]);
            p.idade=atoi(V[1]);
            printf("Nome: %s; Idade:%d\n",p.nome,p.idade);

        //    Como foi alocado espaco de memoria para as strings
        //    (devem ler os comentarios da funcao Read_Split_Line_File),
        //    h� agora que os desalocar/libertar.
        // Reparem que os coment�rios/avisos da fun��o s�o:
        //    "Dentro desta fun��o � alocado espa�o de mem�ria, ficando a cargo
        //    de quem invoca a fun��o a posterior liberta��o da mem�ria alocada"
        for (i = 0; i < n_campos_lidos; i++)
        {
            free (V[i]);
        }
        free (V);
    }
    fclose(F1);

    return 0;
}