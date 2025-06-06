/*
2. Modifique a estrutura para guardar uma dados dos alunos com os seguintes campos:
• Nome
• Matrıcula
• Nota

a) Implemente a estrutura de dados para a arvore bin aria de busca. 
Listing 2: Estrutura de um no da arvore bin aria de busca 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

typedef struct Aluno {
    char nome[50];       
    int matricula;       
    float nota;          
} Aluno;


typedef struct NoAluno {
    Aluno dadosAluno;        
    struct NoAluno *esquerdo; 
    struct NoAluno *direito;  
} NoAluno;