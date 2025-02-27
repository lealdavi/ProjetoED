// fila com alocacao dinamica e sequencial

#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

// inicializa os indices e retorna um ponteiro para a fila
Fila *fila_inicializar(int max)
{
    Fila *f = malloc(sizeof(Fila));
    if (!f)
        return NULL;

    f->inicio = 0;
    f->fim = 1;
    f->qntd = 0;
    f->max = max;
    f->vetor = (T *)malloc(max * sizeof(T));
    return f;
}

// returna 1 se a qntd atual for 0, ou seja, se estiver vazia
int fila_vazia(Fila *f)
{
    return f->qntd == 0;
}

// returna 1 se a qntd atual for igual a capacidade maxima
int fila_cheia(Fila *f)
{
    return f->qntd == f->max;
}

// desaloca o vetor e o ponteiro f
void fila_destruir(Fila *f)
{
    free(f->vetor);
    free(f);
}

// coloca o dado no fim e decrementa o indice (retorna 1 se funcionar e 0 se estiver cheia)
int inserir(Fila *f, T dado)
{
    if (fila_cheia(f))
        return 0;

    f->vetor[f->fim] = dado;
    f->fim = (f->fim + 1) % f->max;
    f->qntd++;
    return 1;
}

// incrementa o indice inicio (retorna 1 se funcionar e 0 se estiver vazia)
int remover(Fila *f)
{
    if (fila_vazia(f))
        return 0;

    f->inicio = (f->inicio + 1) % f->max;
    f->qntd--;
    return 1;
}

// retorna o primeiro elemento valido
T fila_primeiroElemento(Fila *f)
{
    return f->vetor[(f->inicio + 1) % f->max];
}

// retorna o ultimo elemento valido
T fila_ultimoElemento(Fila *f)
{
    return f->vetor[(f->fim - 1) % f->max];
}

int fila_quantidade(Fila *f)
{
    return f->qntd;
}

// imprime na tela a fila
void imprimirFila(Fila *f, void (*print)(T))
{
    for (int i = (f->inicio + 1) % f->max; i != f->fim; i = (i + 1) % f->max)
    {
        print(f->vetor[i]); // chama a função de impressão passada como parâmetro
    }
}