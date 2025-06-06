//e) Crie um algoritmo para percorrer a arvore em pre-ordem (pre-ordem).

#include <stdio.h>
#include <stdbool.h>

void percorrerPreOrdem(No* T) {
    if (T != NULL) {
        printf("%d ", T->dado);       
        percorrerPreOrdem(T->esquerdo); 
        percorrerPreOrdem(T->direito);  
    }
}

int main(){

    printf("\n Percorrer em ordem \n");
    percorrerPreOrdem(raiz);

    return 0;
}