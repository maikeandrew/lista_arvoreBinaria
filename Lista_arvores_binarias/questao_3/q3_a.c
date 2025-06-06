// 3. Implemente um algoritmo para buscar um aluno pelo nome

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

NoAluno* buscarAlunoPorNome(NoAluno* T, const char* nomeBusca) {
    if (T == NULL) { 
        return NULL;
    }
    
    int comparacao = strcmp(nomeBusca, T->dadosAluno.nome);

    if (comparacao == 0) { s
        return T;         
    } else if (comparacao < 0) { 
        return buscarAlunoPorNome(T->esquerdo, nomeBusca); 
    } else { 
        return buscarAlunoPorNome(T->direito, nomeBusca); 
    }
}

NoAluno* RemoverAluno(NoAluno* T) {
    if (T == NULL) { 
        return NULL;
    }
    RemoverAluno(T->esquerdo);  
    RemoverAluno(T->direito); 
    free(T);             
    return NULL;         
}

int main() {
    NoAluno* raizAluno = NULL;
    Aluno a1 = {"Maike", 105, 8.0};
    Aluno a2 = {"Andrew", 100, 7.6};
    Aluno a3 = {"Fatima", 108, 9.1};

    raizAluno = InserirAluno(raizAluno, a1);
    raizAluno = InserirAluno(raizAluno, a2); 
    raizAluno = InserirAluno(raizAluno, a3); 

    printf("\n Busca por Aluno \n");
    char nomeBusca[50];
    printf("Digite o nome do aluno a buscar: ");
    
    strcpy(nomeBusca, "Bob"); 

    NoAluno* alunoEncontrado = buscarAlunoPorNome(raizAluno, nomeBusca);
    if (alunoEncontrado != NULL) {
        printf("Aluno encontrado: Nome: %s, Matricula: %d, Nota: %.2f\n",
               alunoEncontrado->dadosAluno.nome,
               alunoEncontrado->dadosAluno.matricula,
               alunoEncontrado->dadosAluno.nota);
    } else {
        printf("Aluno '%s' nao encontrado.\n", nomeBusca);
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
