//
//  InstalacaoN.c
//  InicializacaoSistem_LerFichELoadEmMemoriaEstatica
//
//  Created by Jorge Loureiro on 05/01/2025.
//
//  Para a instalação do sistema, usando memória estática
//
#include "InstalacaoN.h"
#include "Utils.h"
#include "Requisitante_N.h"

/** \brief Função que vai permitir efectuar a personalização da aplicação, realizada, tipicamente, pelo "instalador da aplicação";
 *         Vai realizar 1.ª das duas tarefas que são realizadas no processo de incialização:
 *         - especificar um conjunto de parâmetros base da aplicação, neste caso, apenas o número máximo
 *           de registos de utilizadores permitidos;
 *         - outros parâmetros são incializados, neste caso, apenas o ultIdReq (o número -id- do último utilizador criado)
 *         A função retorna 1 se a operação for bem sucedida e 0, de contrário.
 *
 * \param paramSystem *PARAM_Syst_Mem_Estat
 * \return int
 *
 */
int personalizarAplicacaoN(PARAM_Syst_Mem_Estat *paramSystem){
	printf("Qual o número máximo permitido de registos de requisitantes? ");
	do{
		scanf("%d", &paramSystem->nMaxElem);
	} while (paramSystem->nMaxElem<= MIN_REQUIS || paramSystem->nMaxElem>=MAX_REQUIS);
	paramSystem->ultIdReq=0;
	printf("\nVai gravar o fich. de configuração...\n");
	// vai gravar o fich. de configuração
	FILE *F2 = fopen("erros.txt", "a");
	if (!F2) {
		printf("\n\tImpossível abrir o Ficheiro erros.txt!!!\n\n");
		mostrarMensagem("\tTrata-se de um erro irrecuperável. A aplicação vai encerrar!");
		return 0;
	}
	else{
		FILE *F1 = fopen("paramSyst.txt","w"); // vai abrir o ficheiro para escrita, recriando-o, se existir
		if (!F1) { // o ficheiro de parâmetros não pôde ser criado. Vai mostrar-se uma mensagem e escrever o ficheiro de erros
			printf("\n\tImpossível criar o ficheiro de parâmetros para assegurar a persistência dos parâmetros do sistema!!\n\n");
			mostrarMensagem("\tTrata-se de um erro irrecuperável. A aplicação vai encerrar!");
			fclose(F2);
			return 0;
		}
		// vai escrever os parâmetros no ficheiro
		fprintf(F1, "%d\n",paramSystem->nMaxElem);
		fprintf(F1, "%d\n",paramSystem->ultIdReq);
		fclose (F1);
		fclose(F2);
		return 1;
	}
}

/** \brief Função que vai permitir efectuar a leitura dos dados do ficheiro "requisitantes.txt" para o vector em memória;
 *         Vai realizar 2.ª das duas tarefas que são realizadas no processo de incialização:
 *         - esta função vai utilizar uma outra função "Read_Split_Line_File" que vai ler cada registo e o divide em substrings
 *         - cada substring deverá corresponder a um atributo da struct, mas em formato "string",
 *         - que deverá ser convertido para outro tipo, se for o caso;
 *         - depois, é efectuada uma verificação da validade dos dados;
 *         - caso seja detectado algum erro, esse erro será reportado para o ficheiro "erros.txt" e o requisitante não será considerado
 *         - outros parâmetros são incializados, neste caso, apenas o ultIdReq (o número -id- do último utilizador criado)
 *         A função retorna 1 se a operação for bem sucedida e 0, de contrário.
 *
 * \param paramSystem PARAM_Syst_Mem_Estat
 * \param vectReqN *VECT_REQUIS_N
 * \return int
 *
 */
int lerFicheiroReq(PARAM_Syst_Mem_Estat paramSystem, VECT_REQUIS_N *vectReqN){
	int finalizar=0; // variável tipo bool que controla a leitura do ficheiro de requisitantes; se a true, termina a leitura do ficheiro
	int n_campos_max = 20;  // número máximo de campos a poder tratar em cada linha do ficheiro
	int n_campos_lidos;   // número de campos que foram extraídos da linha do ficheiro
	int n_linhas_lidas = 0;
	int n_linhas_validas = 0;
	char buffer[250]="";
	char subStr[40]="";
	char err;
	unsigned int idReqW=0;
	int nItensConvData=0;
	DATA dtNasc;
	DATA dtUltReq;
	dtUltReq.ano=0;
	dtUltReq.mes=0;
	dtUltReq.dia=0;
	
	vectReqN->nElemAct=0;
	
	//----------------------------------------------------------------------------
	FILE *F1 = fopen("requisitantes.txt","r"); // os campos estão separados por \t
	if (!F1) {
		printf("\n\n\tImpossível abrir o Ficheiro requisitantes.txt\n\n");
		mostrarMensagem("Trata-se de um erro irrecuperável. A aplicação vai terminar!");
		return -1;
	}
	FILE *F2 = fopen("erros.txt", "a");
	if (!F2) {
		printf("\n\n\tImpossível abrir o Ficheiro erros.txt\n\n");
		mostrarMensagem("Trata-se de um erro irrecuperável. A aplicação vai terminar!");
		return -1;
	}
	finalizar=0; // se a true, termina a leitura do ficheiro
	while(!feof(F1)||finalizar)
	{
		STRING *V = Read_Split_Line_File(F1, n_campos_max, &n_campos_lidos, "\t\r\n");
		printf("\nFoi lida a linha %d", n_linhas_lidas+1);
		// experimentar adicionar também o 'espaço' como separador (substituindo "\t\r\n" por "\t \r\n" na linha acima)
		// e verificar que passam a ser devolvidos mais campos por linha...
		
		if(n_campos_lidos!=4){
			int i=0;
			sprintf(buffer, "%s\t", V[0]);
			for(i=1; i<n_campos_lidos; i++){
				sprintf(subStr, "%s\t", V[i]);
				strcat(buffer, subStr);
			}
			fprintf(F2, "Há erro na linha %d do fich. requisitantes.txt! A linha lida é %s. O número de campos lidos foi %d e não os 4 devidos! O requisitante da linha não será considerado.\n", n_linhas_lidas+1, buffer, n_campos_lidos);
		}
		// Verificar os campos recebidos e enviar os erros para o fich. de erros, se houver outros erros na linha
		else{ // verificar o 1.º campo, o id do requisitante
			err=0;
			idReqW= convert(V[0], &err);
			if(err=='e'){
				printf("\nO idReq é: %s\n", V[0]);
				sprintf(buffer, "Há erro na linha %d do fich. requisitantes.txt! O idReq é: %s. Na conversão do 1.º campo para unsigned int ocorreu um erro! O requisitante da linha não será considerado.\n",  n_linhas_lidas+1, V[0]);
				fprintf(F2, "%s", buffer);
				n_linhas_lidas++;
			}
			else{
				if(strlen(V[1])==0){// testar o 2.º campo, o nome
					printf("\nO nome é: %s\n", V[1]);
					sprintf(buffer, "Há erro na linha %d do fich. requisitantes.txt! O Nome do Req. é: %s.Na conversão do 2.º campo (nome) o tamanho da string é 0! O requisitante da linha não será considerado.\n", n_linhas_lidas+1, V[1]);
					fprintf(F2, "%s", buffer);
					n_linhas_lidas++;
				}
				else{  // verificar o 3.º campo, a data do nascimento
					nItensConvData=sscanf(V[2], "%d-%d-%d", &dtNasc.dia, &dtNasc.mes, &dtNasc.ano);
					if(nItensConvData!=3){
						printf("\nA data é: %s\n", V[2]);
						sprintf(buffer, "Há erro na linha %d do fich. requisitantes.txt! A data de nasc. é: %s. Na conversão do 3.º campo (data do nascimento) para DATA o número de itens da data não é 3! O requisitante da linha não será considerado.\n", n_linhas_lidas+1, V[2]);
						fprintf(F2, "%s", buffer);
						n_linhas_lidas++;
					}
					else{  // validar a data existente no ficheiro
						if(!(validar_data(dtNasc.dia, dtNasc.mes, dtNasc.ano))){
							printf("\nA data existente no ficheiro é: %s\n", V[2]);
							printf("\nA data para validar é %d/%d/%d\n", dtNasc.dia, dtNasc.mes, dtNasc.ano);
							sprintf(buffer, "Há erro na linha %d do fich. requisitantes.txt! A data de nasc. é: %s. A data não é válida! O requisitante da linha não será considerado.\n", n_linhas_lidas+1, V[2]);
							fprintf(F2, "%s", buffer);
							n_linhas_lidas++;
						}
						else{ // verificar o 4.º campo, a freguesia
							if(strlen(V[3])!=6){
								printf("\nA freguesia é: %s\n", V[3]);
								sprintf(buffer, "Há erro na linha %d do fich. requisitantes.txt! A freguesia é: %s. Na conversão do 4.º campo (idFreguesia) o tamanho da string é dif. de 6! O requisitante da linha não será considerado.\n", n_linhas_lidas+1, V[3]);
								fprintf(F2, "%s", buffer);
								n_linhas_lidas++;
							}
							else{ // todas as verificações deram resultados correctos: acrescentar o novo requisitante ao vector
								if(vectReqN->nElemAct<paramSystem.nMaxElem){
									RegistarRequisitante(&vectReqN->elem[vectReqN->nElemAct+1], idReqW, V[1], dtNasc, V[3], dtUltReq, 'A');
									vectReqN->nElemAct++;
									n_linhas_validas++;
									n_linhas_lidas++;
								}
								else{
									mostrarMensagem("\n\nJá não há espaço para registar mais requisitantes em memória!");
									sprintf(buffer, "Há erro na linha %d do fich. requisitantes.txt! O requisitante %s não foi registado e as linhas restantes não serão consideradas!\n", n_linhas_lidas+1, V[1]);
									fprintf(F2, "%s", buffer);
									finalizar=1;
									fclose(F1);
									fclose(F2);
									return 0;
								}
								//    Como foi alocado espaço de memoria para as strings
								//    (devem ler os comentarios da função Read_Split_Line_File),
								//    há agora que os desalocar/libertar.
								//    Repare-se que os comentários/avisos da função são:
								//    "Dentro desta função é alocado espaço de memória, ficando a cargo
								//    de quem invoca a função a posterior libertação da memória alocada"
								for (int i = 0; i < n_campos_lidos; i++)
									free (V[i]);
								free (V);
							}
						}
					}
				}
			}
		}
	}
	fclose(F1);
	fclose(F2);
	return 1;
}

