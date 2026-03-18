#include <stdio.h>

#define MAX_ITEMS 2
#define MAX_STRING 50

void bufferClear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct Item {
    char nome[30];
    char tipo[30];
    int quantidade;
    struct Item* next;
};


int cadastrar(struct Item** item) {
    int i = 0;
    bufferClear();
    struct Item* newItem = (struct Item*) malloc (sizeof(struct Item));
    printf ("Digite o nome do item: \n");
    fgets(newItem->nome, MAX_STRING, stdin);

    printf ("Digite o tipo do item: \n");
    fgets(newItem->tipo, MAX_STRING, stdin);

    printf ("Digite a quantidade do item: \n");
    scanf("%d", &newItem->quantidade);
    printf("\n\n");
    newItem->next = *item;
    *item = newItem;
    i++;
    return 1;
}

int listar(struct Item* item) {
    if (item == NULL) {
        printf("A mochila esta vazia \n\n");
        bufferClear();
        return 1;
    }
    bufferClear();
    printf("====================== LISTAGEM DE ITENS ================== \n");
    struct Item* current = item;
    while (current != NULL) {
        printf("Nome do item => %s", current->nome);
        printf("Tipo do item => %s", current->tipo);
        printf("Quantidade do item => %d", current->quantidade);
        printf("\n\n\n");
        current = current->next;
    }
    return 1;
}

int buscar (struct Item* item) {
    int pos = 0;
    char itemPesquisado[30];

    printf("Digite o nome do item para buscar: ");
    bufferClear();
    fgets(itemPesquisado, MAX_STRING, stdin);
   
    struct Item* current = item;
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
    printf("Item nao encontrado");
    return -1;
}

int remover(struct Item** item) {
    if (item == NULL || *item == NULL) {
        return 0;
    }
    char itemParaRemover[30];
    printf("Digite o nome do item para apagar: ");
    bufferClear();
    fgets(itemParaRemover, MAX_STRING, stdin);

    while (*item != NULL) {
        if (strcmp((*item)->nome, itemParaRemover) == 0) {
            struct Item *current = *item;
            *item = (*item)->next;
            free(current);
            printf("Item removido com sucesso \n");
            return 1;
        }
        item = &(*item)->next;
    }

    printf("Item informado nao localizado... \n");
    return 0;
}

int menu(struct Item** item) {
    int menuSelecionado;

    printf("Selecione a opcao desejada no menu: \n");
    printf("1 - Cadastrar Novo Item \n");
    printf("2 - Listar Itens Disponiveis \n");
    printf("3 - Remover Item da Mochila \n");
    printf("4 - Pesquisar Item na Mochila \n");
    printf("0 - Sair \n");

    scanf("%d", &menuSelecionado);

    switch (menuSelecionado)
    {
        case 1:
            cadastrar(item);
            listar(*item);
            return 1;
        case 2:
            listar(*item);
            return 1;
        case 3:
            remover(item);
            listar(*item);
            return 1;
        case 4:
            buscar(*item);
            return 1;
        case 0:
            printf("Saindo ... \n");
            free(item);
            return 0;
        default:
            printf("Opcao invalida \n");
            return 0;
    }
}

void main() {
    int quantidadeAtualDeItens = 0;
    struct Item** item;
    item = calloc(MAX_ITEMS, sizeof(struct Item));
    
    if (item == NULL) {
        printf("Erro ao alocar memoria");
        return;
    }

    while (menu(item) > 0);
    return;
}
