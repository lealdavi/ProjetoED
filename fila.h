#ifndef FILA_H
#define FILA_H

typedef void *T; // alterado de modo a permitir a criação de filas de qualquer tipo

typedef struct
{
    int inicio, fim;
    int qntd, max;
    T *vetor;
} Fila;

Fila *fila_inicializar(int max);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
void fila_destruir(Fila *f);
int inserir(Fila *f, T dado);
int remover(Fila *f);
T fila_primeiroElemento(Fila *f);
T fila_ultimoElemento(Fila *f);
int fila_quantidade(Fila *f);
void imprimirFila(Fila *f, void (*print)(T)); // alterado de modo a permitir a impressão de dados de qualquer tipo

#endif