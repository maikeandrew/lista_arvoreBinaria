//i) Crie um algoritmo para calcular a soma dos valores armazenados na arvore.

#include <stdio.h>

long long int calcSoma(No* T) { 
    if (T == NULL) { // Se a árvore é vazia, a soma é 0
        return 0;
    } else {
        return T->dado + calcSoma(T->esquerdo) + calcSoma(T->direito);
    }
}

int main(){

   long long int soma = calcSoma(raiz);
   printf("\nSoma dos valores na arvore: %lld\n", soma);

   return 0;

}