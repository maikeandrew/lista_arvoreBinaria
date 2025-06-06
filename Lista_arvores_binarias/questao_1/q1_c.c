//c) Teste as funcoes com diferentes casos de teste

int main() {
    No* raiz = NULL; 

    printf("Teste de Insercao \n");
    raiz = Inserir(raiz, 50);
    Inserir(raiz, 30);
    Inserir(raiz, 70);
    Inserir(raiz, 20);
    Inserir(raiz, 40);
    Inserir(raiz, 60);
    Inserir(raiz, 80);
    printf("Elementos inseridos: 50, 30, 70, 20, 40, 60, 80\n");

    printf("\nTeste de Busca n");
    int valorBusca1 = 40;
    No* encontrado1 = Buscar(raiz, valorBusca1);
    if (encontrado1 != NULL) {
        printf("Valor %d encontrado na arvore.\n", valorBusca1);
    } else {
        printf("Valor %d NAO encontrado na arvore.\n", valorBusca1);
    }

    int valorBusca2 = 99;
    No* encontrado2 = Buscar(raiz, valorBusca2);
    if (encontrado2 != NULL) {
        printf("Valor %d encontrado na arvore.\n", valorBusca2);
    } else {
        printf("Valor %d NAO encontrado na arvore.\n", valorBusca2);
    }

    printf("\n Teste de Remocao (Liberando a arvore) \n");
    raiz = Remover(raiz); 
    if (raiz == NULL) {
        printf("Arvore liberada com sucesso.\n");
    } else {
        printf("Erro ao liberar a arvore.\n");
    }

    encontrado1 = Buscar(raiz, 40);
    if (encontrado1 != NULL) {
        printf("Valor %d encontrado (ERRO: Arvore deveria estar vazia).\n", valorBusca1);
    } else {
        printf("Valor %d NAO encontrado (CORRETO: Arvore vazia).\n", valorBusca1);
    }

    return 0;
}