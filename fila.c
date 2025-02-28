/**
 * @file fila.c
 * @brief Implementação de uma fila com alocacao dinamica e sequencial
 * 
 * Este arquivo contém as funções necessárias para manipular uma fila sequencial,
 * incluindo inserções, remoções e acesso aos elementos.
 */
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

/**
 * @brief Inicializa os índices e retorna um ponteiro para a fila.
 * 
 * Esta função aloca memória para a fila e inicializa seus índices,
 * quantidade de elementos e vetor para armazenar os dados.
 * 
 * @param max Limite máximo de elementos que a fila pode armazenar.
 * @return Fila* Ponteiro para a fila inicializada, ou NULL em caso de falha.
 */
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

/**
 * @brief Verifica se a fila está vazia.
 * 
 * Esta função retorna 1 se a quantidade atual de elementos for 0,
 * indicando que a fila está vazia.
 * 
 * @param f Ponteiro para a fila.
 * @return int Retorna 1 se a fila estiver vazia, 0 caso contrário.
 */
int fila_vazia(Fila *f)
{
    return f->qntd == 0;
}

/**
 * @brief Verifica se a fila está cheia.
 * 
 * Esta função retorna 1 se a quantidade atual de elementos for igual à
 * capacidade máxima da fila.
 * 
 * @param f Ponteiro para a fila.
 * @return int Retorna 1 se a fila estiver cheia, 0 caso contrário.
 */
int fila_cheia(Fila *f)
{
    return f->qntd == f->max;
}

/**
 * @brief Libera a memória ocupada pela fila.
 * 
 * Esta função desaloca o vetor de elementos da fila e a estrutura da fila.
 * 
 * @param f Ponteiro para a fila a ser destruída.
 */
void fila_destruir(Fila *f)
{
    free(f->vetor);
    free(f);
}

/**
 * @brief Insere um dado no fim da fila.
 * 
 * Esta função adiciona um novo elemento ao final da fila. Se a fila estiver
 * cheia, a função retorna 0 e a inserção não é realizada. Caso contrário,
 * o elemento é inserido e a função retorna 1.
 * 
 * @param f Ponteiro para a fila.
 * @param dado Valor a ser inserido na fila.
 * @return int Retorna 1 se a inserção for bem-sucedida, 0 se a fila estiver cheia.
 */
int inserir(Fila *f, T dado)
{
    if (fila_cheia(f))
        return 0;

    f->vetor[f->fim] = dado;
    f->fim = (f->fim + 1) % f->max;
    f->qntd++;
    return 1;
}

/**
 * @brief Remove o primeiro elemento da fila.
 * 
 * Esta função remove o primeiro elemento da fila. Se a fila estiver vazia,
 * a função retorna 0 e nenhuma remoção é feita. Caso contrário, o primeiro
 * elemento é removido e a função retorna 1.
 * 
 * @param f Ponteiro para a fila.
 * @return int Retorna 1 se a remoção foi bem-sucedida, 0 se a fila estiver vazia.
 */
int remover(Fila *f)
{
    if (fila_vazia(f))
        return 0;

    f->inicio = (f->inicio + 1) % f->max;
    f->qntd--;
    return 1;
}

/**
 * @brief Retorna o primeiro elemento da fila.
 * 
 * Esta função retorna o dado armazenado no primeiro elemento da fila.
 * 
 * @param f Ponteiro para a fila.
 * @return T O valor armazenado no primeiro elemento da fila.
 * @warning Se a fila estiver vazia, o comportamento é indefinido.
 */
T fila_primeiroElemento(Fila *f)
{
    return f->vetor[(f->inicio + 1) % f->max];
}

/**
 * @brief Retorna o último elemento da fila.
 * 
 * Esta função retorna o dado armazenado no último elemento da fila.
 * 
 * @param f Ponteiro para a fila.
 * @return T O valor armazenado no último elemento da fila.
 * @warning Se a fila estiver vazia, o comportamento é indefinido.
 */
T fila_ultimoElemento(Fila *f)
{
    return f->vetor[(f->fim - 1) % f->max];
}

/**
 * @brief Retorna a quantidade de elementos na fila.
 * 
 * Esta função retorna o número de elementos atualmente armazenados na fila.
 * 
 * @param f Ponteiro para a fila.
 * @return int A quantidade de elementos na fila.
 */
int fila_quantidade(Fila *f)
{
    return f->qntd;
}

/**
 * @brief Imprime os elementos da fila.
 * 
 * Esta função itera sobre os elementos da fila e chama uma função 
 * de impressão fornecida para cada elemento. Os elementos são impressos
 * na ordem em que aparecem na fila.
 * 
 * @param f Ponteiro para a fila.
 * @param print Ponteiro para a função de impressão que aceita um argumento do tipo T.
 */
void imprimirFila(Fila *f, void (*print)(T))
{
    for (int i = (f->inicio + 1) % f->max; i != f->fim; i = (i + 1) % f->max)
    {
        print(f->vetor[i]); // chama a função de impressão passada como parâmetro
    }
}