#ifndef UTILS_H
#define UTILS_H

#define TAM 1000
#define CHAR_SIZE 30

struct Pedido
{
    int id;
    int preco;
    int mesa;
    char cliente[CHAR_SIZE];
};

typedef struct Pedido *Pedido;

int precos[] = {20, 15, 18, 25, 10, 10, 10, 5, 12, 12};

char cardapio[10][20] = {
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