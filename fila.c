// fila com alocacao dinamica e sequencial

#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

// inicializa os indices e retorna um ponteiro para a fila
Fila* inicializar (int max) {
    Fila* f = malloc(sizeof(Fila));
    if (!f) return 0;

    f->inicio = 0;
    f->fim = 1;
    f->qntd = 0;
    f->max = max;
    f->vetor = (int*)malloc(max * sizeof(int));
    return f;
}

// returna 1 se a qntd atual for 0, ou seja, se estiver vazia
int vazia (Fila* f) {
    return f->qntd == 0;
}

// returna 1 se a qntd atual for igual a capacidade maxima
int cheia (Fila* f) {
    return f->qntd == f->max; 
}

// desaloca o vetor e o ponteiro f
void destruir (Fila* f) {
    free(f->vetor);
    free(f);
}

// coloca o dado no fim e decrementa o indice (retorna 1 se funcionar e 0 se estiver cheia)
int inserir (Fila* f, T dado) {
    if (cheia(f)) return 0;

    f->vetor[f->fim] = dado;
    f->fim = (f->fim + 1) % f->max;    
    f->qntd++;
    return 1;
}

// incrementa o indice inicio (retorna 1 se funcionar e 0 se estiver vazia)
int remover (Fila* f) {
    if (vazia(f)) return 0;

    f->inicio = (f->inicio + 1) % f->max;
    f->qntd--;
    return 1;
}

// retorna o primeiro elemento valido
T primeiroElemento (Fila* f) {
    return f->vetor[(f->inicio + 1) % f->max]; 
}

// retorna o ultimo elemento valido
T ultimoElemento (Fila* f) {
    return f->vetor[(f->fim - 1) % f->max];
}

int quantidade (Fila* f) {
    return f->qntd;
}

// imprime na tela a fila
void imprimirFila (Fila* f) {
    for (int i = (f->inicio+1) % f->max; i != f->fim; i = (i+1) % f->max) {
        printf("%d ", f->vetor[i]);
    }
    printf("\n");
}