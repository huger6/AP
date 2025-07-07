//
//  Requisitante_D.c
//  InicializacaoSistem_LerFichELoadEmMemoriaEstatica
//
//  Created by Jorge Loureiro on 30/12/2024.
//
#include "Requisitante_N.h"

void RegistarRequisitante(REQUISITANTE_N *R, unsigned int _idReq, char *_nomeReq, DATA _dataNasc, char *_idFreg, DATA _dtUltRequis, char _sitReq)
{
	R->idReq = _idReq;
	strcpy(R->nomeReq, _nomeReq);
	R->dataNasc = _dataNasc;
	strcpy(R->idFreguesia, _idFreg);
	R->dtUltRequis=_dtUltRequis;
	R->sitReq=_sitReq;
}

void MostrarRequisitante_N(REQUISITANTE_N *R, int nElem)
{
	printf("\tNúmero de registo: %d - \tRequisitante-> ID: %d Nome: [%s] Data Nasc.: %d/%d/%d\n", nElem, R->idReq, R->nomeReq, R->dataNasc.ano, R->dataNasc.mes, R->dataNasc.dia);
}
