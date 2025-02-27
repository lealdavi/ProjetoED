#ifndef UTILS_H
#define UTILS_H

/**
 * @def TAM
 * @brief Tamanho máximo para a estrutura de dados.
 */
#define TAM 1000

/**
 * @def CHAR_SIZE
 * @brief Tamanho máximo para o nome do cliente.
 */
#define CHAR_SIZE 30

/**
 * @def NUM_ITENS
 * @brief Quantidade total de itens disponíveis no cardápio.
 */
#define NUM_ITENS 10

/**
 * @struct Pedido
 * @brief Estrutura que representa um pedido.
 * 
 * A estrutura contém informações sobre um pedido feito por um cliente,
 * incluindo um identificador, preço, número da mesa e o nome do cliente.
 */
struct Pedido
{
    int id;                 ///< Identificador do pedido.
    int preco;              ///< Preço do item do pedido.
    int mesa;               ///< Número da mesa que fez o pedido.
    char cliente[CHAR_SIZE]; ///< Nome do cliente que fez o pedido.
};

/**
 * @typedef Pedido
 * @brief Tipo que representa um ponteiro para a estrutura Pedido.
 */
typedef struct Pedido *Pedido;

/**
 * @var precos[]
 * @brief Array que contém os preços dos itens do cardápio.
 * 
 * Os preços estão associados à ordem dos itens no cardápio.
 */
int precos[NUM_ITENS] = {20, 15, 18, 25, 10, 10, 10, 5, 12, 12};

/**
 * @var cardapio
 * @brief Array que contém os nomes dos itens disponíveis no cardápio.
 * 
 * Este array contém os nomes de 10 itens que podem ser pedidos pelos clientes.
 */
char cardapio[NUM_ITENS][20] = {
    "X-Bacon",
    "X-Burger",
    "X-Egg",
    "X-Tudo",
    "Coca-Cola 1L",
    "Fanta 1L",
    "Soda 1L",
    "Água 500ml",
    "Batata Frita",
    "Onion Rings"};

#endif