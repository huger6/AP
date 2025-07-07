//
//  Requisitante_N.h
//  InicializacaoSistem_LerFichELoadEmMemoriaEstatica
//
//  Created by Jorge Loureiro on 30/12/2024.
//

#ifndef Requisitante_N_h
#define Requisitante_N_h

#include "Utils.h"
#define MAX_REQUIS 20000// número máximo de requisitantes passíveis de serem especificados como o
				   // número máximo de requisitantes a ser permitido registar no vector dos requisitante,
				   // se usadas variáveis estruturadas de dimensão fixa (usando o operador [])

#define MIN_REQUIS 1000 // número mínimo de requisitantes passíveis de serem especificados como o
				   // máximo a ser permitido registar no vector dos requisitante,
				   // se usadas variáveis estruturadas de dimensão fixa (usando o operador [])

//typedef struct dataN{  // Data para requisitante a usar num vector de dimensão fixa
//	short ano;
//	short mes;
//	short dia;
//} DATA_N;

typedef struct requisitanteN  // Estrutura do requisitante a usar no vector de dimensão fixa
{
	unsigned int idReq;  // atenção que o último dígito do idReq é um check-digit, cuja algoritmo de cálculo
						 // é o seguinte: a soma dos nove algarismos tem de ser um múltiplo de 10
	char nomeReq[51];
	DATA dataNasc;
	char idFreguesia[7];  // para termos 6 caracteres, precisamos de 7, certo?
	DATA dtUltRequis;   // colocar a 0, quando se carrega do fich. fornecido
	char sitReq; // situação do requisitante: A-Activo; S-Suspenso; I-Inactivo;
				 // colocar 'A' quando se carrega do fich. fornecido
}REQUISITANTE_N;

typedef struct vectRequisN{   // vector de tamanho fixo máximo definido por MAX_REQUIS
	int nElemAct;  // número de elementos actual - inicializar a 0 e incrementar de 1 quando se acrescenta um novo registo
				   // verificar quando o valor for igual a nMaxElem, caso em que já não será possível acrescentar um novo registo
	REQUISITANTE_N elem[MAX_REQUIS];
} VECT_REQUIS_N;

// Protótipos relativos às funções existentes no ficheiro .c
void RegistarRequisitante(REQUISITANTE_N *R, unsigned int _idReq, char *_nomeReq, DATA _dataNasc, char *_idFreg, DATA _dtUltRequis, char _sitReq);
void MostrarRequisitante_N(REQUISITANTE_N *R, int nElem);

#endif /* Requisitante_N_h */
