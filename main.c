#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "lista.h"
#include "utils.h"

void selecionar_operacao(Fila *fila, Lista *historico, Pedido *pedido, void(*imprimirDados));
void adicionar_pedido(Fila *fila, Lista *historico);
void preparar_pedido(Fila *fila, Lista *historico);
void listar_espera(Fila *fila, void(*imprimirDados));
void listar_historico(Lista *historico, void(*imprimirDados));
void imprimirDados(void *p);
void imprimirIterador(Lista *historico);

int main()
{
    Fila *fila;
    Lista *historico;

    Pedido pedido = (Pedido)malloc(sizeof(struct Pedido));

    // Inicializar fila e lista
    fila = fila_inicializar(TAM);
    historico = lista_inicializar(TAM);

    selecionar_operacao(fila, historico, &pedido, imprimirDados);

    free(pedido);

    return 0;
}

void selecionar_operacao(Fila *fila, Lista *historico, Pedido *pedido, void(*imprimirDados))
{
    int opcao = 0;
    while (opcao != 5)
    {
        printf("\n");
        printf("Selecione uma operação:\n");
        printf("1 - Adicionar pedido\n");
        printf("2 - Preparar pedido\n");
        printf("3 - Listar pedidos em espera\n");
        printf("4 - Listar histórico de pedidos concluídos\n");
        printf("5 - Sair\n");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionar_pedido(fila, historico);
            break;
        case 2:
            preparar_pedido(fila, historico);
            break;
        case 3:
            listar_espera(fila, imprimirDados);
            break;
        case 4:
            imprimirIterador(historico);
            // listar_historico(historico, imprimirDados);
            break;
        case 5:
            fila_destruir(fila);
            lista_destruir(historico);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
}

void adicionar_pedido(Fila *fila, Lista *historico)
{
    int id, mesa;
    char cliente[CHAR_SIZE];

    printf("\n");
    printf("Cardápio:\n");
    printf("01 - X-Bacon\n");
    printf("02 - X-Burger\n");
    printf("03 - X-Egg\n");
    printf("04 - X-Tudo\n");
    printf("05 - Coca-Cola 1L\n");
    printf("06 - Fanta 1L\n");
    printf("07 - Soda 1L\n");
    printf("08 - Água 500ml\n");
    printf("09 - Batata Frita\n");
    printf("10 - Onion Rings\n");
    printf("\n");

    printf("Digite o ID do pedido: ");
    scanf("%d", &id);
    printf("Digite o número da mesa: ");
    scanf("%d", &mesa);
    printf("Digite o nome do cliente: ");

    scanf(" %[^\n]", cliente);

    // Alocar memória para um novo pedido
    Pedido pedido = (Pedido)malloc(sizeof(struct Pedido));
    if (!pedido)
    {
        printf("Erro ao alocar memória para o pedido.\n");
        return;
    }

    pedido->id = id - 1;
    pedido->preco = precos[id - 1];
    pedido->mesa = mesa;
    strcpy(pedido->cliente, cliente);

    // Inserir o pedido na fila
    if (!inserir(fila, pedido))
    {
        printf("Erro ao adicionar pedido à fila.\n");
        free(pedido);
    }
    if (!inserirInicio(historico, pedido))
    {
        printf("Erro ao adicionar pedido à fila.\n");
        free(pedido);
    }
}

void preparar_pedido(Fila *fila, Lista *historico)
{
    // verificar se a fila está vazia
    if (!fila_vazia(fila))
    {
        Pedido pedido_preparado = (Pedido)fila_primeiroElemento(fila);
        remover(fila);
        printf("Pedido %d da mesa %d, cliente %s preparado\n", pedido_preparado->id + 1, pedido_preparado->mesa, pedido_preparado->cliente);
        // free(pedido_preparado);
    }
    else
        printf("Não há pedidos em espera\n");
}

// por ordem de pedido
void listar_espera(Fila *fila, void(*imprimirDados))
{
    if (fila_vazia(fila))
    {
        printf("Não há pedidos em espera\n");
        return;
    }
    printf("Pedidos em espera:\n");
    printf("| %-*s | %-*s | %-*s | %-*s |\n", 20, "Pedido", 13, "Preço", 30, "Cliente", 10, "Mesa");
    imprimirFila(fila, imprimirDados);
}

// do mais recente para o mais antigo
void listar_historico(Lista *historico, void(*imprimirDados))
{
    if (lista_vazia(historico))
    {
        printf("Não há pedidos no histórico\n");
        return;
    }
    printf("Histórico de pedidos:\n");
    printf("| %-*s | %-*s | %-*s | %-*s |\n", 20, "Pedido", 13, "Preço", 30, "Cliente", 10, "Mesa");
    imprimirLista(historico, imprimirDados);
}

void imprimirDados(void *p)
{
    Pedido pedido = (Pedido)p;

    printf("| %-*s | R$%-*d | %-*s | %-*d |\n", 20, cardapio[pedido->id], 10, pedido->preco, 30, pedido->cliente, 10, pedido->mesa);
}

void imprimirIterador(Lista *historico)
{
    iterador it = primeiro(historico);
    while (!acabou(it))
    {
        Pedido pedido = (Pedido)elemento(it);
        printf("| %-*s | R$%-*d | %-*s | %-*d |\n", 20, cardapio[pedido->id], 10, pedido->preco, 30, pedido->cliente, 10, pedido->mesa);
        proximo(&it);
    }
}