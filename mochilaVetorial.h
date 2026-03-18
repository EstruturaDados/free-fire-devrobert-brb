
typedef struct {
    char nome[30];
    char tipo[30];
    int quantidade;
} Item;

int cadastrarVetorial(Item item[], int count){
    for (int i = 0; i < count; i++) {
        printf("Digite o nome do item vetorial numero %d \n", i + 1);
        scanf("%49s", item[i].nome);
    }
}

int listarVetorial(Item item[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s \n", item[i].nome);
    }
    return 0;
}

int buscarVetorial(Item lista[], int tamanho, Benchmark benchmark[]) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    char item[30];

    printf("Digite o nome do item vetorial que gostaria de buscar \n");
    scanf("%49s", item);

    int controle = 0;
    benchmark->start = time(NULL);
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        int comparacao = strcmp(lista[meio].nome, item);
        if (comparacao == 0) {
           printf("Item encontrado na lista \n");
           benchmark->end = time(NULL);
           return meio;
        } else if (comparacao > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
        controle++;
    }
    benchmark->end = time(NULL);
    benchmark->exec++;
    printf("Item nao encontrado \n");
    return -1;
}

int removerVetorial() {
    printf("Removendo item vetorial \n");
}