
struct No {
    char nome[30];
    char tipo[30];
    int quantidade;
    struct No* next;
};


int cadastrarEncadeado(struct No** item) {
    int i = 0;
    bufferClear();
    struct No* newNo = (struct No*) malloc (sizeof(struct No));
    printf ("Digite o nome do item: \n");
    fgets(newNo->nome, MAX_STRING, stdin);

    printf ("Digite o tipo do item: \n");
    fgets(newNo->tipo, MAX_STRING, stdin);

    printf ("Digite a quantidade do item: \n");
    scanf("%d", &newNo->quantidade);
    printf("\n\n");
    newNo->next = *item;
    *item = newNo;
    i++;
    return 1;
}

int listarEncadeado(struct No* item) {
    if (item == NULL) {
        printf("A mochila esta vazia \n\n");
        bufferClear();
        return 1;
    }
    bufferClear();
    printf("====================== LISTAGEM DE ITENS ENCADEADOS ================== \n");
    struct No* current = item;
    while (current != NULL) {
        printf("Nome do item => %s", current->nome);
        printf("Tipo do item => %s", current->tipo);
        printf("Quantidade do item => %d", current->quantidade);
        printf("\n\n\n");
        current = current->next;
    }
    return 1;
}

int buscarEncadeado(struct No* item) {
    int pos = 0;
    char itemPesquisado[30];

    printf("Digite o nome do item encadeado para buscar: ");
    bufferClear();
    fgets(itemPesquisado, MAX_STRING, stdin);
   
    struct No* current = item;
    while (current != NULL) {
        if (strcmp(itemPesquisado, current->nome) == 0) {
            printf("\n");
            printf(" ======= Item Encontrado ======== \n");
            printf("Nome do item => %s", current->nome);
            printf("Tipo do item => %s", current->tipo);
            printf("Quantidade do item => %d", current->quantidade);
            printf("\n\n\n");
            return pos;
        }
        current = current->next;
        pos++;
    }
    printf("No nao encontrado");
    return -1;
}

int removerEncadeado(struct No** item) {
    if (item == NULL || *item == NULL) {
        return 0;
    }
    char itemParaRemover[30];
    printf("Digite o nome do item encadeado para apagar: ");
    bufferClear();
    fgets(itemParaRemover, MAX_STRING, stdin);

    while (*item != NULL) {
        if (strcmp((*item)->nome, itemParaRemover) == 0) {
            struct No *current = *item;
            *item = (*item)->next;
            free(current);
            printf("No removido com sucesso \n");
            return 1;
        }
        item = &(*item)->next;
    }

    printf("No informado nao localizado... \n");
    return 0;
}