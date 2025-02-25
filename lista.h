#ifndef LISTA_H
#define LISTA_H

typedef int T;

typedef struct node {
    T dado;                          
    struct node *proximo, *anterior;
} Node;

typedef struct {
    Node *sentinela;
    int qntd, max;
} Lista;

Lista* inicializar (int max);
int vazia (Lista *l);
int cheia (Lista *l);
void destruir (Lista *l);
int removerInicio (Lista *l);
int removerFim (Lista *l);
int inserirInicio (Lista *l, T dado);
int inserirFim (Lista *l, T dado);
T primeiroElemento (Lista *l);
T ultimoElemento (Lista *l);
int quantidade (Lista *l);
void imprimirLista (Lista *l);

#endif