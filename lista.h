#ifndef LISTA_H
#define LISTA_H

typedef void *T;

typedef struct node
{
    T dado;
    struct node *proximo, *anterior;
} Node;

typedef struct
{
    Node *sentinela;
    int qntd, max;
} Lista;

Lista *lista_inicializar(int max);
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
void lista_destruir(Lista *l);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int inserirInicio(Lista *l, T dado);
int inserirFim(Lista *l, T dado);
T lista_primeiroElemento(Lista *l);
T lista_ultimoElemento(Lista *l);
int lista_quantidade(Lista *l);
void imprimirLista(Lista *l, void (*print)(T));

#endif