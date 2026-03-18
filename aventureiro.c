#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 50
#define MAX_ITEMS 20
#define MAX_BENCHMARKS 4

typedef struct {
    int start;
    int end;
    int exec;
} Benchmark;

void bufferClear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void listarBenchmarks(Benchmark benchmark[]) {
    printf("=========================== Comparativo de performance entre buscas ==============================");
    for (int i = 0; i < MAX_BENCHMARKS; i++) {
        int intervalo = (benchmark->start + benchmark->end) / 2;
        printf("Busca binaria vetorial -> Ultimo tempo de execucao %d \n", intervalo);
        printf("Busca sequencial encadeada -> Ultimo tempo de execucao %d \n", intervalo);
    }
}


#include "mochilaVetorial.h"
#include "mochilaEncadeada.h"

int menu(struct No** no, Item item[], Benchmark benchmark[]) {

    int menuSelecionado;

    printf("Selecione a opcao desejada no menu: \n");
    printf("1 - Cadastrar Novo Item Encadeado \n");
    printf("2 - Listar Itens Encadeados Disponiveis \n");
    printf("3 - Remover Item Encadeado da Mochila \n");
    printf("4 - Pesquisar Item Encadeado na Mochila \n");
    printf("5 - Cadastrar Novo Item Vetorial \n");
    printf("6 - Listar Itens Vetoriais Disponiveis \n");
    printf("7 - Remover Item Vetorial da Mochila \n");
    printf("8-  Pesquisar Item Vetorial na Mochila \n");
    printf("9-  Listar Benchmarks de Buscas \n");
    printf("0 - Sair \n");

    scanf("%d", &menuSelecionado);

    switch (menuSelecionado)
    {
        case 1:
            cadastrarEncadeado(no);
            listarEncadeado(*no);
            return 1;
        case 2:
            listarEncadeado(*no);
            return 1;
        case 3:
            removerEncadeado(no);
            listarEncadeado(*no);
            return 1;
        case 4:
            buscarEncadeado(*no);
            return 1;
        case 5:
            cadastrarVetorial(item, MAX_ITEMS);
            listarVetorial(item, MAX_ITEMS);
            return 1;
        case 6:
            listarVetorial(item, MAX_ITEMS);
            return 1;
        case 7:
            removerVetorial(item, MAX_ITEMS);
            listarVetorial(item, MAX_ITEMS);
            return 1;
        case 8:
            buscarVetorial(item, MAX_ITEMS, benchmark);
            return 1;
        case 9:
            listarBenchmarks(benchmark);
            listarVetorial(item, MAX_ITEMS);
            return 1;
        case 0:
            printf("Saindo ... \n");
            free(no);
            return 0;
        default:
            printf("Opcao invalida \n");
            return 0;
    }
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main() {
    int quantidadeAtualDeItens = 0;
    Item item[MAX_ITEMS];
    Benchmark benchmark[MAX_BENCHMARKS];
    struct No** no;
    no = calloc(MAX_ITEMS, sizeof(struct No));
    
    if (no == NULL) {
        printf("Erro ao alocar memoria");
        return;
    }

    while (menu(no, item, benchmark) > 0);
    return;
}
