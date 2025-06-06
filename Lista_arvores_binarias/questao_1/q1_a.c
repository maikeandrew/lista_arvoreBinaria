/*
1. Implemente os algoritmos abaixo:
a) Implemente a estrutura de dados para a arvore binaria de busca. Por exemplo, em C:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int dado;
    struct No *esquerdo;
    struct No *direito;
} No;

