#include <stdio.h>
#include <locale.h>

int posMaior(int vet[], int n);
void lerVetor(int vet[], int n);
void escreverVetor(int vet[], int n);
int pos_maior(int vet[], int maiores[], int n);

int main() {
	setlocale(LC_ALL, "");
	setlocale(LC_ALL, "pt_PT.UTF-8");
	int vet[20], n, posicao, maiores [20];
	do {
		printf("Num de posições do vetor: ");
		scanf("%d", &n);
	} while (n < 1 || n > 20);
	
	lerVetor(vet, n);
	
	escreverVetor(vet, n);
	printf("A maior componente do vetor\n");
	pos_maior(vet, maiores, n);
	
	printf("As posições dos maiores números do array são: \n");
	for (int i = 0; i < n; i++) {
		if (maiores[i]!= -1) {
			printf("%d\n", maiores[i]);
		}
	}
	/*
	printf("\n é v[%d] = %d\n", posicao+1, vet[posicao]); */
}


void lerVetor(int vet[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Introduza o %dº número: ", i+1);
		scanf("%d", &vet[i]);
	}
}

void escreverVetor(int vet[], int n) {
	for(int i = 0; i < n; i++) {
		printf("O %dº número é %d", i+1, vet[i]);
	}
}
/*
int posMaior(int vet[], int n) {
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (vet[i] > vet[pos]) {
			pos = i;
		}	
	}
	return pos;  
	}
	

//Função posMaior no caso de haver 2+ maiores
int pos_maior(int vet[], int n) {
	int pos = 0;
	int maiores[20];
	for (int i = 0; i < 20; i++) {
		maiores[i] = -1;
	}
	maiores[0] = 0;
	
	//Fazer uma nova variável k para contar o numero de maiores
	//Depois, usar essa variável para entrar nos maiores e alterar
	//O que se pretende é colocar as posições dos maiores nas primeiras k posições do array maiores;
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (vet[i] > vet[pos]) {
			//Limpar o array
			for (int j = 0; j < 20; j++)
				maiores[j] = -1;
			//Atualizar o array
			maiores[0] = i;
			k = 0;
		}
		
		}
		else if (vet[i] == vet[pos]) {
			maiores[k] = i;
			maiores[k+1] = pos;
			k++;
			pos = i;
		}
	}
}
*/

int pos_maior(int vet[], int maiores[], int n) {
	int maior = 0;
	for (int i = 0; i < 20; i++) {
		maiores[i] = -1;
	}
	maiores[0] = 0;
	
	//Fazer uma nova variável k para contar o numero de maiores
	//Depois, usar essa variável para entrar nos maiores e alterar
	//O que se pretende é colocar as posições dos maiores nas primeiras k posições do array maiores;
	int k = 0;
	for (int i = 1; i < n; i++) {
        if (vet[i] > vet[maior]) {
            // Limpa o array
            for (int j = 0; j < 20; j++) {
                maiores[j] = -1;
            }
            // Atualiza o array e o índice de maior
            maiores[0] = i;
            k = 1;
            maior = i;
        }
        else if (vet[i] == vet[maior]) {
        	//Apenas queremos associar os dois valores quando for a primeira vez que encontramos 2 maiores
            if (k == 0) {
                maiores[k] = maior;
                k++;
            }
            maiores[k] = i;
            k++;
        }
    }
}