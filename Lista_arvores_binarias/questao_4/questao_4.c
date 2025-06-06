//4. Crie um algoritmo para calcular a media das notas dos alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
} Aluno;

typedef struct NoAluno {
    Aluno dadosAluno;
    struct NoAluno *esquerdo;
    struct NoAluno *direito;
} NoAluno;

NoAluno* criarNoAluno(Aluno a);
NoAluno* InserirAluno(NoAluno* T, Aluno a);
float calcularSomaNotas(NoAluno* T);
int contarTotalAlunos(NoAluno* T);
float calcularMediaNotas(NoAluno* T);
NoAluno* RemoverAluno(NoAluno* T);

int main() {
    NoAluno* raizAluno = NULL;
    Aluno a1 = {"Alice", 101, 8.5};
    Aluno a2 = {"Bob", 102, 7.0};
    Aluno a3 = {"Carol", 103, 9.2};

    raizAluno = InserirAluno(raizAluno, a1);
    raizAluno = InserirAluno(raizAluno, a2);
    raizAluno = InserirAluno(raizAluno, a3);

    float media = calcularMediaNotas(raizAluno);
    if (contarTotalAlunos(raizAluno) > 0) {
        printf("\nMedia das notas dos alunos: %.2f\n", media);
    } else {
        printf("\nNenhum aluno cadastrado para calcular a media.\n");
    }

    printf("\nLiberando a memoria\n");
    raizAluno = RemoverAluno(raizAluno);
    if (raizAluno == NULL) {
        printf("Memoria liberada com sucesso.\n");
    } else {
        printf("Erro ao liberar a memoria.\n");
    }

    return 0;
}

NoAluno* criarNoAluno(Aluno a) {
    NoAluno* novoNo = (NoAluno*) malloc(sizeof(NoAluno));
    if (novoNo != NULL) {
        strcpy(novoNo->dadosAluno.nome, a.nome);
        novoNo->dadosAluno.matricula = a.matricula;
        novoNo->dadosAluno.nota = a.nota;
        novoNo->esquerdo = NULL;
        novoNo->direito = NULL;
    }
    return novoNo;
}

NoAluno* InserirAluno(NoAluno* T, Aluno a) {
    if (T == NULL) {
        return criarNoAluno(a);
    }
    int comparacao = strcmp(a.nome, T->dadosAluno.nome);
    if (comparacao < 0) {
        T->esquerdo = InserirAluno(T->esquerdo, a);
    } else if (comparacao > 0) {
        T->direito = InserirAluno(T->direito, a);
    }
    return T;
}

float calcularSomaNotas(NoAluno* T) {
    if (T == NULL) {
        return 0.0f;
    } else {
        return T->dadosAluno.nota + calcularSomaNotas(T->esquerdo) + calcularSomaNotas(T->direito);
    }
}

int contarTotalAlunos(NoAluno* T) {
    if (T == NULL) {
        return 0;
    } else {
        return 1 + contarTotalAlunos(T->esquerdo) + contarTotalAlunos(T->direito);
    }
}

float calcularMediaNotas(NoAluno* T) {
    float somaDasNotas = calcularSomaNotas(T);
    int totalDeAlunos = contarTotalAlunos(T);

    if (totalDeAlunos == 0) {
        return 0.0f;
    } else {
        return somaDasNotas / totalDeAlunos;
    }
}

NoAluno* RemoverAluno(NoAluno* T) {
    if (T == NULL) {
        return NULL;
    }
    RemoverAluno(T->esquerdo); [cite: 29, 30]
    RemoverAluno(T->direito); [cite: 29, 30]
    free(T); [cite: 29, 30]
    return NULL;
}