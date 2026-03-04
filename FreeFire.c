#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// Criação da struct dos itens.
struct Item {
    char nome[30];
    char tipo[20]; 
    int quantidade;
};

// Criação das funções.
void inserirItem(struct Item mochila[], int *total);
void removerItem(struct Item mochila[], int *total);
void listarItens(struct Item mochila[], int total);
void buscarItem(struct Item mochila[], int total);


int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        // Criação do menu interativo.
        printf("\n--- SOBREVIVENCIA NA ILHA: INVENTARIO ---\n");
        printf("1. Adicionar item a mochila.\n");
        printf("2. Remover item pelo nome.\n");
        printf("3. Listar inventario.\n");
        printf("4. Buscar item especifico.\n");
        printf("5. Sair.\n");
        printf("Escolha sua ação: ");

        scanf("%d", &opcao);
        getchar(); // Limpa o caractere de nova linha do buffer

        switch (opcao) {
            case 1:
                inserirItem(mochila, &totalItens);
                break;
            case 2:
                removerItem(mochila, &totalItens);
                break;
            case 3:
                listarItens(mochila, totalItens);
                break;
            case 4:
                buscarItem(mochila, totalItens);
                break;
            case 5:
                printf("Saindo... Boa sorte no combate, sobrevivente!\n");
                break;
            default:
                printf("Opção invalida no menu!\n");
        }
    } while (opcao != 5);

    return 0;
}

    // Cadastro de itens.
    void inserirItem(struct Item mochila[], int *total) {
        if (*total < MAX_ITENS) {
            printf("Nome do item: ");
            scanf("%29s", mochila[*total].nome);
            
            printf("Tipo (arma/cura/municao): ");
            scanf("%19s", mochila[*total].tipo);
            
            printf("Quantidade: ");
            scanf("%d", &mochila[*total].quantidade);
            
            (*total)++;
            printf("Item guardado com sucesso!\n");
        } else {

            // Alerta quando a capacidade máxima e atingida.
            printf("Erro: Sua mochila esta cheia! Descarte algo primeiro.\n");
        }
    }

    // Remoção de itens.
    void removerItem(struct Item mochila[], int *total) {
        if (*total == 0) {
            printf("A mochila ja esta vazia.\n");
            return;
        }

        char nomeBusca[30];
        printf("Digite o nome do item para remover: ");
        scanf("%29s", nomeBusca);

        for (int i = 0; i < *total; i++) {
            if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                for (int j = i; j < *total - 1; j++) {
                    mochila[j] = mochila[j + 1];
                }
                (*total)--; 
                printf("Item '%s' removido.\n", nomeBusca);
                return;
            }
        }

        printf("Item nao encontrado no inventario.\n");
    }

    // Listagem de itens.
    void listarItens(struct Item mochila[], int total) {
        if (total == 0) {
            printf("\nSua mochila esta vazia. Va coletar recursos!\n");
            return;
        }

        printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", total, MAX_ITENS);
        printf("%-20s | %-15s | %-10s\n", "NOME", "TIPO", "QTD");
        
        for (int i = 0; i < total; i++) {
            printf("%-20s | %-15s | %-10d\n", 
                mochila[i].nome, 
                mochila[i].tipo, 
                mochila[i].quantidade);
        }
    }

    void buscarItem(struct Item mochila[], int total) {
        char nomeBusca[30];
        printf("Digite o nome do item para buscar: ");
        scanf("%29s", nomeBusca);

        // Algoritmo olha item por item ate achar o valor alvo.
        for (int i = 0; i < total; i++) {
            if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                printf("\nItem encontrado na posicao %d da mochila:\n", i);
                printf("-> Tipo: %s\n", mochila[i].tipo);
                printf("-> Quantidade: %d unidades\n", mochila[i].quantidade);
                return;
            }
        }
    
    // Caso o loop termine sem encontrar o item.
    printf("O item '%s' nao foi localizado.\n", nomeBusca);
}