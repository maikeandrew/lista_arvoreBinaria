//b) Implemente as funções de criação, remoção, busca e inserção.

No* criarNo(int c) {
    No* novoNo = (No*) malloc(sizeof(No)); 
    if (novoNo != NULL) { 
        novoNo->dado = c;       
        novoNo->esquerdo = NULL; 
        novoNo->direito = NULL;  
    }
    return novoNo; 
}

No* Buscar(No* T, int c) {
    if (T == NULL) { 
        return NULL; 
    }
    if (T->dado == c) { 
        return T;       
    }
    if (c < T->dado) { 
        return Buscar(T->esquerdo, c); 
    }
    
    return Buscar(T->direito, c); 
}

No* Inserir(No* T, int c) {
    if (T == NULL) { 
        return criarNo(c); 
    }
    if (c < T->dado) { 
        T->esquerdo = Inserir(T->esquerdo, c); 
    } else if (c > T->dado) { 
        T->direito = Inserir(T->direito, c); 
    }
    
    return T; 
}


No* Remover(No* T) {
    if (T == NULL) { 
        return NULL;
    }
    Remover(T->esquerdo);  
    Remover(T->direito); 
    free(T);             
    return NULL;         
}
