#ifndef FILA_H
#define FILA_H

typedef int T;

struct node {
    T data;
    struct node *proximo;
};
typedef struct node Node;

typedef struct {
    Node *inicio, *fim;
    int qntd, max;
} Fila;

Fila* inicializar (int max);
void destruir (Fila* f);
int vazia (Fila *f);
int cheia (Fila *f);
int inserirFim (Fila *f, int num);
int removerInicio (Fila *f);
int quantidade (Fila *f);
int primeiroElemento (Fila *f);
void imprimirFila (Fila *f);

#endif