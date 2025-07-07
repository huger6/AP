#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Há um erro algures na função de listar

//Devemos fazer com char pois char ocupa apenas 1 byte
typedef struct sala {
	char nome[50];
	int pago;
	int reservado;
}Sala;

void reservar(Sala * lugares, int nF, int nC);
void eliminar_reserva(Sala * lugares, int nF, int nC);
void mapear(Sala * lugares, int nF, int nC);
void listar(Sala * lugares, int nF, int nC);
void inicializa_lugares(Sala * lugares, int nF, int nC);
int menu();

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	int nF, nC;
	int escolha = 0;
	
	do {
		printf("Quantas filas e colunas tem a sala de espetáculos?(Max 10) ");
		scanf("%d %d", &nF, &nC); 
	} while (nF < 0 || nC < 0 || nF > 10 || nC > 10);
	
	system("cls");
	
	Sala lugares[nF][nC];
	
	inicializa_lugares(lugares, nF, nC);
	
	system("cls");
	do {
		escolha = menu();
		
		switch(escolha) {
			case 0:	        
		 		break;
		 	case 1:
		 		reservar(lugares, nF, nC);
		 		break;
		 	case 2:
		 		eliminar_reserva(lugares, nF, nC);
		 		break;
		 	case 3:
		 		mapear(lugares, nF, nC);
		 		break;
		 	case 4:
		 		listar(lugares, nF, nC);
		 		break;
		 	default:
		 		printf("Erro!\n");
		} 
		printf("\n");
	}while (escolha != 0);
	
}


void inicializa_lugares(Sala * lugares, int nF, int nC) {
	for(int i = 0; i < nF; i++) {
		for(int j = 0; j < nC; j++) {
			lugares->reservado = 0;
			lugares->pago = 0;
			lugares->nome[0]= '\0';
			lugares++;
		}
	}
}
//Averigura porque é que o ponteiro da sala nesta função é diferente do da main
void reservar(Sala * lugares, int nF, int nC) {
	int nCadeira, nFila;
	do {
		printf("Em que fila e que cadeira é que se quer sentar? ");
		scanf("%d %d", &nFila, &nCadeira); 
	} while (nFila < 0 || nCadeira < 0 || nFila > 10 || nCadeira > 10);
	nFila--; nCadeira--; //Retiramos um, ex:se for o lugar 1 1 queremos começar no 0
	//Colocar o ponteiro a apontar para o lugar que o utilizador pediu
	lugares+= nC * nFila + nCadeira;
	
	if (lugares->reservado == 0) {
		printf("Nome (Max 50): ");
		scanf(" %s", lugares->nome);
		
		printf("Já pagou? (0-Não; 1-Sim) ");
		scanf("%d", &lugares->pago);
	}
	else
		printf("Lugar ocupado!\n");
}


void eliminar_reserva(Sala * lugares, int nF, int nC) {
	int nCadeira, nFila;
	do {
		printf("Qual é o número da fila(Fila, Cadeira)?(Max 10) ");
		scanf("%d %d", &nFila, &nCadeira); 
	} while (nFila < 0 || nCadeira < 0 || nFila > 10 || nCadeira > 10);
	nFila--; nCadeira--;
	lugares+= nC * nFila + nCadeira;
	
	if(lugares->reservado == 1) {
		lugares->reservado = 0;
		printf("Reserva feita!\n");
	}
	else {
		printf("O lugar já está vazio!\n");
	}
}

void mapear(Sala * lugares, int nF, int nC) {
	printf("#----------------------------------------#\n");
	for(int i = 0; i < nC; i++) {
		printf("   \t%d", i+1);
	}
	printf("\n");
	for(int i = 0; i < nF; i++) {
		if (i == 0) {
			printf("# %d\t", i+1);
		}
		for(int j = 0; j < nC; j++) {
			if (lugares->reservado) {
				printf("1");
			}
			else {
				printf("0");
			}
			printf("\t");
			lugares++;
		}
		printf(" #\n");
	}
	printf("#----------------------------------------#\n");
}
//Erro aqui!!
void listar(Sala * lugares, int nF, int nC) {
	for(int i = 0; i < nF; i++) {
		for(int j = 0; j < nC; j++) {
			if (lugares->reservado == 1) {
				printf("O nome do cliente é %s\n", lugares->nome);
				printf("O lugar do cliente é Fila %d , Cadeira %d\n", i, j);
				if (lugares->pago == 1)
					printf("Pago!\n");
				else
					printf("Não pago!");
				printf("\n");
			}
			lugares++;
		}
	}
}
int menu() {
	int escolha;
	do {
		printf("0 - Sair\n");
		printf("1 - Reservar lugar\n");
		printf("2 - Eliminar uma reserva\n");
		printf("3 - Apresentar um mapa da ocupação da sala\n");
		printf("4 - Listar reservas\n");
		scanf("%d", &escolha);
	} while (escolha < 0 || escolha > 4);
	return escolha;
	 
}