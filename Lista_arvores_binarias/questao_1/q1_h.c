//h) Crie um algoritmo para calcular a profundidade de um no na arvore.

#include <stdio.h>
#include <stdbool.h>

int calcProfundidadeNo(No* T, int valorBuscado, int profundidadeAtual) {
    if (T == NULL) { 
        return -1;
    }
    if (T->dado == valorBuscado) { 
        return profundidadeAtual;   
    }

    
    int profEsquerda = calcProfundidadeNo(T->esquerdo, valorBuscado, profundidadeAtual + 1);
    if (profEsquerda != -1) { 
        return profEsquerda;
    }
 
    int profDireita = calcProfundidadeNo(T->direito, valorBuscado, profundidadeAtual + 1);
    return profDireita; 
}


int main() {

    int profundidade = calcProfundidadeNo(raiz, 40, 0); 

    if (profundidade != -1) {
        printf("Profundidade do no 40: %d\n", profundidade);
    } else {
        printf("No 40 nao encontrado ou arvore vazia.\n");
    }

    return 0;
}