// j) Crie um algoritmo para calcular o nıvel de um no na arvore.

#include <stdio.h>
#include <stdbool.h>


int calcNivelNo(No* T, int valorBuscado, int nivelAtual) {
    if (T == NULL) {
        return -1;
    }
    if (T->dado == valorBuscado) {
        return nivelAtual;
    }

    int nivelEsquerda = calcNivelNo(T->esquerdo, valorBuscado, nivelAtual + 1);
    if (nivelEsquerda != -1) {
        return nivelEsquerda;
    }

    int nivelDireita = calcNivelNo(T->direito, valorBuscado, nivelAtual + 1);
    return nivelDireita;
}

int main(){

    int nivel = calcNivelNo(raiz, 40, 0);

    if (nivel != -1) {
        printf("Nivel do no 40: %d\n", nivel);
    } else {
        printf("No 40 nao encontrado ou arvore vazia.\n");
    }


    return 0;
}