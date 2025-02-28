#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "lista.h"
#include "utils.h"

/**
 * @brief Seleciona a operação a ser realizada com base na entrada do usuário.
 * 
 * Esta função exibe um menu para o usuário e chama a função apropriada 
 * com base na escolha do usuário.
 * 
 * @param fila Ponteiro para a fila de pedidos.
 * @param historico Ponteiro para a lista de histórico de pedidos.
 * @param pedido Ponteiro para um pedido a ser manipulado.
 * @param imprimirDados Ponteiro para a função que imprime os dados dos pedidos.
 */
void selecionar_operacao(Fila *fila, Lista *historico, Pedido *pedido, void(*imprimirDados));

/**
 * @brief Adiciona um novo pedido à fila.
 * 
 * Esta função coleta as informações do pedido do usuário e o adiciona
 * à fila de pedidos.
 * 
 * @param fila Ponteiro para a fila de pedidos.
 */
void adicionar_pedido(Fila *fila);

/**
 * @brief Prepara o pedido na fila.
 * 
 * Esta função retira um pedido da fila e o adiciona ao histórico de pedidos.
 * 
 * @param fila Ponteiro para a fila de pedidos.
 * @param historico Ponteiro para a lista de histórico de pedidos.
 */
void preparar_pedido(Fila *fila, Lista *historico);

/**
 * @brief Lista os pedidos em espera na fila.
 * 
 * Esta função imprime todos os pedidos que estão atualmente na fila de espera.
 * 
 * @param fila Ponteiro para a fila de pedidos.
 * @param imprimirDados Ponteiro para a função que imprime os dados dos pedidos.
 */
void listar_espera(Fila *fila, void(*imprimirDados));

/**
 * @brief Lista o histórico de pedidos.
 * 
 * Esta função imprime todos os pedidos que foram processados e armazenados
 * no histórico.
 * 
 * @param historico Ponteiro para a lista de histórico de pedidos.
 * @param imprimirDados Ponteiro para a função que imprime os dados dos pedidos.
 */
void listar_historico(Lista *historico);

/**
 * @brief Função que imprime os dados de um pedido.
 * 
 * Esta função recebe um ponteiro genérico e imprime as informações do
 * pedido correspondente.
 * 
 * @param p Ponteiro para o pedido a ser impresso.
 */
void imprimirDados(void *p);

/**
 * @brief Função principal do programa.
 * 
 * Inicializa a fila e a lista de histórico, aloca memória para um pedido,
 * e chama a função para selecionar operações com base na interação do usuário.
 * 
 * @return int Retorna 0 ao final da execução do programa.
 */

/**
 * @brief Imprime os elementos da lista na ordem do iterador.
 *
 * @param historico Ponteiro para a lista que será iterada e impressa.
 */
void imprimirIterador(Lista *historico);

int precoTotal(Lista *historico);

int main()
{
    Fila *fila;                      ///< Ponteiro para a fila de pedidos.
    Lista *historico;                ///< Ponteiro para a lista de histórico de pedidos.

    Pedido pedido = (Pedido)malloc(sizeof(struct Pedido)); ///< Ponteiro para um pedido.

    // Inicializar fila e lista
    fila = fila_inicializar(TAM);
    historico = lista_inicializar(TAM);

    printf("\n");
    printf("Bem-vindo ao ARRAY GOURMET, uma experiência de sabor indexada!");
    printf("\n");
    printf("Esse sistema oferece uma administração eficiente de pedidos, garantindo agilidade e qualidade em cada prato");
    printf("\n");
    selecionar_operacao(fila, historico, &pedido, imprimirDados); // Chama a função para selecionar operações.

    free(pedido); // Libera a memória do pedido.

    return 0; // Retorna 0 ao final da execução do programa.
}

/**
 * @brief Seleciona a operação a ser realizada pelo usuário.
 * 
 * Apresenta um menu de opções para o usuário escolher. Dependendo da escolha,
 * chama a função correspondente para adicionar um pedido, preparar um pedido,
 * listar pedidos em espera ou listar o histórico de pedidos. A função também
 * garante que a fila e o histórico sejam destruídos quando o usuário optar por sair.
 * 
 * @param fila Ponteiro para a fila de pedidos.
 * @param historico Ponteiro para a lista de histórico de pedidos.
 * @param pedido Ponteiro para um pedido a ser manipulado.
 * @param imprimirDados Ponteiro para a função que imprime os dados dos pedidos.
 */
void selecionar_operacao(Fila *fila, Lista *historico, Pedido *pedido, void(*imprimirDados))
{
    int opcao = 0;
    while (opcao != 5)
    {
        printf("\n");
        printf("Selecione a operação desejada:\n");
        printf("1 - Adicionar pedido\n");
        printf("2 - Preparar pedido\n");
        printf("3 - Listar pedidos em espera\n");
        printf("4 - Listar histórico de pedidos concluídos\n");
        printf("5 - Finalizar operação\n");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionar_pedido(fila);
            break;
        case 2:
            preparar_pedido(fila, historico);
            break;
        case 3:
            listar_espera(fila, imprimirDados);
            break;
        case 4:
            //imprimirIterador(historico);
            listar_historico(historico);
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

/**
 * @brief Adiciona um novo pedido à fila de pedidos.
 * 
 * Esta função exibe o cardápio e solicita ao usuário que insira o ID do pedido,
 * o número da mesa e o nome do cliente. Em seguida, aloca memória para um novo
 * pedido, define seus atributos e tenta inseri-lo na fila. Se a inserção falhar,
 * a memória alocada é liberada.
 * 
 * @param fila Ponteiro para a fila de pedidos onde o novo pedido será adicionado.
 */
void adicionar_pedido(Fila *fila)
{
    int id, mesa;
    char cliente[CHAR_SIZE];

    printf("\n");
    printf("Cardápio - ARRAY GOURMET :\n");
    printf("01 - Creme Brûlée ----------------------------- R$50,00\n");
    printf("02 - Risoto de Aspargos e Limão Siciliano ----- R$110,00\n");
    printf("03 - Ravioli de Lagosta ----------------------- R$200,00\n");
    printf("04 - Tartare de Salmão ------------------------ R$70,00\n");
    printf("05 - Filet Mignon ao Molho Béarnaise ---------- R$250,00\n");
    printf("06 - Trufas Negras ---------------------------- R$1050,00\n");
    printf("07 - Caviar ----------------------------------- R$600,00\n");
    printf("08 - Champagne Cristal 750ml ------------------ R$1500,00\n");
    printf("09 - Martini Dry 750ml ------------------------ R$150,00\n");
    printf("10 - Cognac Louis XIII 700ml ------------------ R$1500,00\n");
    printf("\n");

    printf("Digite o ID do pedido: ");
    scanf("%d", &id);
    printf("Digite o número da mesa: ");
    scanf("%d", &mesa);
    printf("Digite o nome do(a) cliente: ");

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
    
}

/**
 * @brief Prepara o primeiro pedido na fila.
 * 
 * Esta função verifica se há pedidos na fila. Se houver, o primeiro pedido é retirado da fila,
 * e uma mensagem de confirmação é exibida, incluindo o ID do pedido, o número da mesa e o nome
 * do cliente. Em seguida, o pedido preparado é adicionado ao histórico. Se a inserção no histórico
 * falhar, a memória alocada para o pedido é liberada.
 * 
 * @param fila Ponteiro para a fila de pedidos a partir da qual o pedido será preparado.
 * @param historico Ponteiro para a lista que armazenará o histórico dos pedidos preparados.
 */
void preparar_pedido(Fila *fila, Lista *historico)
{
    if (!fila_vazia(fila))
    {
        Pedido pedido_preparado = (Pedido)fila_primeiroElemento(fila);
        remover(fila);
        printf("Pedido %d da mesa %d, cliente %s preparado\n", pedido_preparado->id + 1, pedido_preparado->mesa, pedido_preparado->cliente);
        // free(pedido_preparado);
        
        if (!inserirInicio(historico, pedido_preparado))
        {
            printf("Erro ao adicionar pedido ao histórico.\n");
            free(pedido_preparado);
        }
    }
    else
        printf("Não há pedidos em espera\n");
}

/**
 * @brief Lista os pedidos em espera na fila.
 * 
 * Esta função verifica se há pedidos na fila. Se a fila não estiver vazia, ela exibe os pedidos
 * em espera, formatando a saída em uma tabela com colunas para o ID do pedido, preço, nome do cliente
 * e número da mesa. A função utiliza um ponteiro para uma função de impressão para exibir os dados de cada pedido.
 * 
 * @param fila Ponteiro para a fila de pedidos que contém os pedidos em espera.
 * @param imprimirDados Ponteiro para a função que será utilizada para imprimir os dados dos pedidos.
 */
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

/**
 * @brief Lista os pedidos do histórico.
 * 
 * Esta função verifica se há pedidos no histórico. Se o histórico não estiver vazio, ela exibe os pedidos
 * do histórico, formatando a saída em uma tabela com colunas para o ID do pedido, preço, nome do cliente
 * e número da mesa. A função utiliza um ponteiro para uma função de impressão para exibir os dados de cada pedido.
 * 
 * @param historico Ponteiro para a lista que contém os pedidos do histórico.
 * @param imprimirDados Ponteiro para a função que será utilizada para imprimir os dados dos pedidos.
 */
void listar_historico(Lista *historico)
{
    if (lista_vazia(historico))
    {
        printf("Não há pedidos no histórico\n");
        return;
    }
    printf("Histórico de pedidos:\n");
    printf("| %-*s | %-*s | %-*s | %-*s |\n", 20, "Pedido", 13, "Preço", 30, "Cliente", 10, "Mesa");
    imprimirIterador(historico);
    printf("\nPreço Total: R$%d\n", precoTotal(historico));
}

/**
 * @brief Imprime os dados de um pedido.
 * 
 * Esta função recebe um ponteiro genérico para um pedido e imprime seus dados formatados, incluindo o nome do
 * pedido (com base no cardápio), o preço, o nome do cliente e o número da mesa.
 * 
 * @param p Ponteiro para o pedido a ser impresso.
 */
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

int precoTotal (Lista *historico) 
{
    int preco = 0;
    iterador it = primeiro(historico);
    while (!acabou(it))
    {
        Pedido pedido = (Pedido)elemento(it);
        preco += pedido->preco;
        proximo(&it);
    }

    return preco;
}