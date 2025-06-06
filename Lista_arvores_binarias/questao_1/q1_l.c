//l) Crie um algoritmo para calcular o numero de folhas na arvore. 

#include <stdio.h>
#include <stdbool.h>

int contarFolhas(No* T) {
    if (T == NULL) { // Se a árvore é vazia, não há folhas
        return 0;
    }
    
    if (T->esquerdo == NULL && T->direito == NULL) {
        return 1; // Encontrou uma folha
    } else {
        
        return contarFolhas(T->esquerdo) + contarFolhas(T->direito);
    }
}

int main(){
    int numFolhas = contarFolhas(raiz);

    printf("\nNumero de folhas na arvore: %d\n", numFolhas);


    return 0;
}