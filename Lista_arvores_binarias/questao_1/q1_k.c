//k) Crie um algoritmo para calcular o numero de nos na arvore

#include <stdio.h>
#include <stdbool.h>

int contarNos(No* T) {
    if (T == NULL) { // Se a árvore é vazia, não há nós
        return 0;
    } else {
        
        return 1 + contarNos(T->esquerdo) + contarNos(T->direito);
    }
}

int main(){
    int numNos = contarNos(raiz);
    
    printf("\nNumero total de nos na arvore: %d\n", numNos);

    return 0;
}