// fila - encademaneto simples

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* inicializar (int max) {
    Fila* f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->qntd = 0;
    f->max = max;

    return f; // retorna um ponteiro para a struct fila inicializada com o tam max
}

void destruir (Fila* f) {
    while (!vazia(f))
        removerInicio(f);
    free(f);
}

int vazia (Fila *f) {
    return f->qntd == 0;
}

int cheia (Fila *f) {
    return f->qntd == f->max;
}

int inserirFim (Fila *f, int data) {
    if (cheia(f)) return 0;

    Node *novo = malloc(sizeof(Node));
    novo->data = data;       // novo recebe o data
    novo->proximo = NULL;     // proximo aponta para nulo

    if (f->inicio == NULL) f->inicio = novo;     // se inicio  
    else f->fim->proximo = novo;

    f->fim = novo;
    f->qntd++;

    return 1;
}

int removerInicio (Fila *f) {
    if (vazia(f)) return 0;

    Node *atual = f->inicio;             // atual "segura" o inicio
    f->inicio = atual->proximo;          // inicio aponta para o proximo

    if (f->inicio == NULL) f->fim = NULL;

    free(atual);
    f->qntd--;

    return 1;
}

int quantidade (Fila *f) {
    return f->qntd;
}

int primeiroElemento (Fila *f) {
    return f->inicio->data;
}

void imprimirFila (Fila *f) {
    Node *atual = f->inicio;

    while (atual != f->fim) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
    printf("%d\n", f->fim->data);
}