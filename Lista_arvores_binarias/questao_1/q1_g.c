//g) Crie um algoritmo para calcular a altura da arvore.

#include <stdio.h>
#include <stdbool.h>

int calcAltura(No* T) {
    if (T == NULL) { 
        return -1;
    } else {
        
        int alturaEsquerda = calcAltura(T->esquerdo);
        // Altura da subárvore direita
        int alturaDireita = calcAltura(T->direito);

        
        if (alturaEsquerda > alturaDireita) {
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }
}

int main(){

    int altura = calcAltura(raiz);

    printf("\nAltura da arvore: %d\n", altura);


    return 0;
}