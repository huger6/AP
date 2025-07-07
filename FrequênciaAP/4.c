#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_UCS 10

typedef struct uc {
    char nomeUC[15];
    float notaUC;
} UC;

typedef struct aluno {
    char nome[50];
    UC cadeiras[MAX_UCS];
    float mediaUCs;
} Aluno;

void notaMediaAlunos(Aluno * turma, int n) {
    float soma;
    for(int i = 0; i < n; i++) {
        soma = 0.0;
        for (int j = 0; j < MAX_UCS; j++) {
            soma += turma[i].cadeiras[j].notaUC
        }
        turma[i].mediaUCs = soma / MAX_UCS;
    }
}

int posicaoDaMelhor(Aluno* turma, int n, float* maior) {
    *maior = turma[0].mediaUCs;
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (turma[i].mediaUCs > *maior) {
            *maior = turma[i].mediaUCs;
            indice = i;
        }
    }
    return i;
}

void infoUC(Aluno* turma, int n, char* nome, FILE *f) {
    if (!f) return;
    f = fopen("ficha.txt", "w");
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(strcmp(turma[i].cadeiras->nomeUC, nome) == 0) {
                fprintf(f, turma[i].nome);
                fprintf(f, turma[i].cadeiras->notaUC);
            }
        }
    }
}

int main() {
    int n;
    Aluno * turma;
    printf("n: ");
    scanf("%d", &n);
    turma = (Aluno *) malloc(n * sizeof(Aluno));
}
