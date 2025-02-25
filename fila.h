#ifndef FILA_H
#define FILA_H

typedef int T;

typedef struct {
    int inicio, fim;   
    int qntd, max;   
    T *vetor;   
} Fila;

Fila* inicializar (int max);
int vazia (Fila *f);
int cheia (Fila *f);
void destruir (Fila *f);
int inserir (Fila *f, T dado);
int remover (Fila *f);
T primeiroElemento(Fila *f);
T ultimoElemento(Fila *f);
int quantidade (Fila* f);
void imprimirFila(Fila* f);

#endif