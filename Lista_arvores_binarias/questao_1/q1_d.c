//d) Crie um algoritmo para percorrer a arvore em ordem (in-ordem)

#include <stdio.h>
#include <stdbool.h>

void percorrerOrdem(No* T) {
    if (T != NULL) {
        percorrerOrdem(T->esquerdo);
        printf("%d ", T->dado);      
        percorrerOrdem(T->direito); 
    }
}

int main(){

    printf("\n Percorrer em ordem \n");
    percorrerOrdem(raiz);

    return 0;

}