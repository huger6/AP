//Fazer tudo apenas com ponteiro

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int * lerVetor(int n); //a
void escreverVetor(int * vetor, int n); //b
void inverterVetor(int * vetor, int n); //c
int maximo(int * vetor, int n); //d
int minimo(int * vetor, int n); //e
int soma(int * vetor, int n); //f
float f_media(int * vetor, int n); //g
void maior_menor_media(int * vetor, float media, int n, int * superior, int * inferior); //h
int * dup_vetor(int * vetor, int n);
int * intercalar_vetores(int * vetor1, int * vetor2, int n);


int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	int n, n2, superior, inferior;
	float media;
	int inverter = 0;
	do {
		printf("Introduza o numero de elementos do vetor: ");
		scanf("%d", &n);
	} while (n < 0);
	//A função lerVetor retorna um vetor(que é um ponteiro), logo damos assign a um ponteiro.
	int * vetor = lerVetor(n);
	//Só se pode libertar a memória depois de a ter usado.
	escreverVetor(vetor, n);
	
	printf("\n\n");
	
	do {
		printf("Quer inverter o vetor?(0 - NAO, 1 - SIM): ");
		scanf("%d", &inverter);
	} while (inverter != 0 && inverter != 1);
	
	if (inverter) {
		inverterVetor(vetor, n);
		escreverVetor(vetor, n);
		inverterVetor(vetor, n); //Voltar ao vetor original
	}
	printf("\n\n");
	//Máximo
	printf("Máximo: %d\n", maximo(vetor, n));
	//Mínimo
	printf("Mínimo: %d\n", minimo(vetor, n));
	//Soma
	printf("Soma: %d\n", soma(vetor, n));
	//Média
	media = f_media(vetor, n);
	printf("A média dos elementos do vetor é %.2f\n", media);
	//Superior/Inferior à média
	superior = 0;
	inferior = 0;
	maior_menor_media(vetor, media, n, &superior, &inferior);

	printf("Há %d números superiores à média\n", superior);
	printf("Há %d números inferiores à média\n", inferior);
	
	
	int * dup = dup_vetor(vetor, n);
	printf("O vetor duplpicado é: \n");
	escreverVetor(dup, n);
	free(dup);
	
	printf("\n\n\n");
	do {
		printf("Introduza o numero de elementos do vetor 2: ");
		scanf("%d", &n2);
	} while (n2 < 0);
	printf("\n");
	
	int * vetor2 = lerVetor(n2);
	escreverVetor(vetor2, n2);
	
	printf("\n\n\n\n\n");
	
	if(n == n2) {
		inverterVetor(vetor2, n);
		int * vetor_resultante = intercalar_vetores(vetor, vetor2, n);
		escreverVetor(vetor_resultante, 2 * n);
		free(vetor_resultante);
	}
	free(vetor2);
	free(vetor); //Temos de libertar a memória usada pelo malloc.
	
}


int * lerVetor(int n) {
	int * vetor = (int *) malloc(n * sizeof(int));
	if (vetor == NULL) {
		printf("ERRO!\n");
		
		return NULL;
	}
	for (int i = 0; i < n;i++) {
		printf("Insira o elemento %d do vetor: ", i);
		scanf("%d", vetor + i);
	}
	return vetor;
	
}

void escreverVetor(int * vetor, int n) {
	for(int i = 0; i < n; i++) {
		printf("O elemento da posição %d é %d\n", i, *(vetor + i));
	}
}

void inverterVetor(int * vetor, int n) {
	for(int i = 0; i < n/2;i++) {
		//vai à posição i, e coloca numa var temp
		int temp = *(vetor + i);
		//troca a posição colocada na temp pela posição "contrária"
		*(vetor+i) = *(vetor + (n-1-i));
		//Colocamos temp na posição 
		*(vetor + (n-1-i)) = temp;
	}
}

int maximo(int * vetor, int n) {
	int maximo = *vetor;
	for(int i = 1; i < n; i++) {
		if (*(vetor + i) > maximo)
			maximo = *(vetor + i);
	}
	return maximo;
}

int minimo(int * vetor, int n) {
	int minimo;
	minimo = *vetor;
	for(int i = 1; i < n; i++) {
		if (*(vetor + i) < minimo)
			minimo = *(vetor + i);
	}
	return minimo;
}

int soma(int * vetor, int n) {
	int soma = 0;
	for(int i = 0; i < n; i++) {
		soma += *(vetor + i);
	}
	return soma;
}

float f_media(int * vetor, int n) {
	float media = 0;
	for(int i = 0; i < n;i++) {
		media += *(vetor + i);
	}
	return ((float) (media /= n));
}

void maior_menor_media(int * vetor, float media, int n, int * superior, int * inferior) {
	*superior = 0;
	*inferior = 0;
	for(int i = 0; i < n; i++) {
		if (*(vetor + i) > media)
			(*superior)++;
		else if (*(vetor + i) < media)
			(*inferior)++;
	}
}

int * dup_vetor(int * vetor, int n) {
	int * dup = (int *) malloc(n * sizeof(int));
	if (dup == NULL) {
		printf("Erro ao alocar memória.");
		return NULL;
	}
	for(int i = 0; i < n; i++) {
		*(dup + i) = *(vetor + i);
	}
	return dup;
}


int * intercalar_vetores(int * vetor1, int * vetor2, int n) {
	int * vetor_resultante = (int *) malloc(n * 2 * sizeof(int));
	if (vetor_resultante == NULL) {
		printf("Erro ao alocar memória.");
		return NULL;
	}
	
	for (int i = 0; i < n;i++) {
		*(vetor_resultante + 2 * i) = *(vetor1 + i);     // Posições pares
        *(vetor_resultante + 2 * i + 1) = *(vetor2 + i); // Posições ímpares
	}
	return vetor_resultante;
} 

