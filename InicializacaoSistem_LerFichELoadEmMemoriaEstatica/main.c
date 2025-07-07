//
//  main.c
//  InicializacaoSistem_LerFichELoadEmMemoriaEstatica
//
//  Created by Jorge Loureiro on 27/12/2024.
//
#include "Requisitante_N.h"
#include "InstalacaoN.h"
#include "Utils.h"
/**
	Função main(): apenas para teste da função
	STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores);
**/
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	// Exemplo sem utilizar memória dinâmica, ou seja, criar um vector cujo numero de elementos é
	// definido pelo valor da constante MAX_REQUIS, usando o operador []
	// O vector a criar é para efectuar o registo em memória dos requisitantes que serão lidos do ficheiro
	
	VECT_REQUIS_N vectReqN;  // VECT_REQUIS_N já tem o vector com MAX_REQUIS declarado
	vectReqN.nElemAct=0;
	
	PARAM_Syst_Mem_Estat paramSyst;  // declaração da variável que irá guardar os parâmetros do sistema
	paramSyst.nMaxElem=0;
	paramSyst.ultIdReq=0;
	
	// verificar se é necessário inicializar o sistema para o caso de utilização de memória estática
	FILE *F1=NULL;
	F1= fopen("paramSystN.txt","r"); // se o fich. não existir, isso quer dizer que o sistema ainda não foi incicializado
	// ou seja, o ponteiro ficará com NULL
	if (!F1) { // vai iniciar-se pela realização da 1.ª parte da incialização: a configuração do sistema
		if (personalizarAplicacaoN(&paramSyst)==0){
			mostrarMensagem("Houve um erro irrecuperável na personalização da aplicação. A aplicação vai terminar!");
			exit(0);
		}
		// passa-se à 2.ª fase da incialização: a leitura do ficheriro dos requisitantes
		printf("\nVai ler-se o fich. utilizando a função "STRING *Read_Split_Line_File(FILE *f, ......). \n");
		printf("\nNO entanto, pode utilizar-se uma outra qualquer função criada para o efeito.\n");
		if(lerFicheiroReq(paramSyst, &vectReqN)==0){
			mostrarMensagem("Houve um erro irrecuperável na leitura do ficheiro de requisitantes. A aplicação vai terminar!");
			exit(0);
		}
		fclose(F1);
		// Vai mostrar os requisitantes existentes em memória para fazer a verikficação do funcionamento correcto
		int i=0;
		printf("\nNo main() o ElemAct=%d\n", vectReqN.nElemAct);
		for(i=0; i<=vectReqN.nElemAct; i++)
			MostrarRequisitante_N(&vectReqN.elem[i], i+1);
	}
	else{
		// A aplicação já foi incicializada:
		// 1.ª fase do arranque:
		// Vão ler-se os parâmetros do sistema (o fich. de parâmetros do sistema)
		// e outros dados eventualmemnte existentes em ficheiros criados pelo grupo para guardar outros
		// dados importantes para o funcionamento da aplicação
		
		// colocar aqui o código necessário para ler os dados do fich. dos parâmetros para memória e outros que tenham sido
		// utilizados para guardar outros dados importantes para o funcionamento da aplicação

		
		// 2.ª fase do arranque:
		// Vão ler-se os ficheiros binários com os dados (neste caso os Requisitantes) que foram guardados
		// quando a aplicação foi fechada na utilização anterior
		
		// Neste caso, colocar aqui o código necessário para ler os dados do fich. binário
	}
	
	// Continuar com a chamada ao menu ou menus e, dedois, com o(s) switch... case para invocar as funções que
	// implementam cada funcionalidade
	
	return 0;
}
