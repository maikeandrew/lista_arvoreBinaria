// f) Crie um algoritmo para percorrer a arvore em p ´ os-ordem (pos-ordem).

#include <stdio.h>
#include <stdbool.h>

void percorrerPosOrdem(No* T) {
    if (T != NULL) {
        percorrerPosOrdem(T->esquerdo); 
        percorrerPosOrdem(T->direito);  
        printf("%d ", T->dado);       
    }
}

int main(){

    printf("\n Percorrer em ordem \n");
    percorrerPosOrdem(raiz);


    return 0;
}