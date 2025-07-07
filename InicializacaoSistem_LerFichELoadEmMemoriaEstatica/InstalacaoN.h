//
//  InstalacaoN.h
//  InicializacaoSistem_LerFichELoadEmMemoriaEstatica
//
//  Created by Jorge Loureiro on 05/01/2025.
//
//  Para a instalação, usando memória estática
//
#ifndef InstalacaoN_h
#define InstalacaoN_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Requisitante_N.h"

typedef struct paramSystMemEstat{
	int nMaxElem;
	int ultIdReq;
} PARAM_Syst_Mem_Estat;

// Protótipos relativos às funções existentes no ficheiro .c
int personalizarAplicacaoN(PARAM_Syst_Mem_Estat *paramSystem);
int lerFicheiroReq(PARAM_Syst_Mem_Estat paramSystem, VECT_REQUIS_N *vectReqN);

#endif /* InstalacaoN_h */
