 /**
 * @file lista.c
 * @brief Implementação de uma lista circular, duplamente encadeada com sentinela.
 * 
 * Este arquivo contém as funções necessárias para manipular uma lista encadeada,
 * incluindo inserções, remoções e acesso aos elementos.
 */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * @brief Inicializa e aloca uma lista circular duplamente encadeada e o nó sentinela.
 * 
 * @param max O número máximo de elementos da lista.
 * @return Lista* Retorna um ponteiro para a nova lista criada.
 */
Lista *lista_inicializar(int max)
{
    Lista *l = malloc(sizeof(Lista));
    l->max = max;
    l->qntd = 0;

    l->sentinela = malloc(sizeof(Node));
    l->sentinela->anterior = l->sentinela->proximo = l->sentinela;
    return l;
}

/**
 * @brief Verifica se a lista está vazia.
 * 
 * Esta função retorna 1 se a lista estiver vazia, ou seja, 
 * se o nó sentinela apontar para si mesmo.
 * 
 * @param l Ponteiro para a lista.
 * @return int Retorna 1 se a lista estiver vazia, 0 caso contrário.
 */ 
int lista_vazia(Lista *l)
{
    return l->sentinela->proximo == l->sentinela;
}

/**
 * @brief Verifica se a lista está cheia.
 * 
 * Esta função retorna 1 se a lista atingiu sua capacidade máxima,
 * ou seja, se a quantidade de elementos armazenados é igual ao 
 * limite máximo definido.
 * 
 * @param l Ponteiro para a lista.
 * @return int Retorna 1 se a lista estiver cheia, 0 caso contrário.
 */
int lista_cheia(Lista *l)
{
    return l->qntd == l->max;
}

/**
 * @brief Libera a memória ocupada pela lista.
 * 
 * Esta função remove todos os elementos da lista e libera 
 * a memória alocada para a estrutura da lista e seu nó sentinela.
 * 
 * @param l Ponteiro para a lista a ser destruída.
 */
void lista_destruir(Lista *l)
{
    while (!lista_vazia(l))
    {
        removerInicio(l);
    }
    free(l->sentinela);
    free(l);
}

/**
 * @brief Remove o primeiro elemento da lista.
 * 
 * Esta função remove o primeiro elemento da lista (logo após o nó sentinela).
 * Se a lista estiver vazia, a função retorna 0 e nenhuma remoção é feita.
 * Caso contrário, o primeiro nó é removido, e a função retorna 1.
 * 
 * @param l Ponteiro para a lista.
 * @return int Retorna 1 se a remoção foi bem-sucedida, 0 se a lista estiver vazia.
 */
int removerInicio(Lista *l)
{
    if (lista_vazia(l))
        return 0;

    Node *inicio = l->sentinela->proximo;
    l->sentinela->proximo = inicio->proximo;
    inicio->proximo->anterior = l->sentinela;

    free(inicio);
    l->qntd--;
    return 1;
}

/**
 * @brief Remove o último elemento da lista.
 * 
 * Esta função remove o último elemento da lista (antes do nó sentinela).
 * Se a lista estiver vazia, a função retorna 0 e nenhuma remoção é feita.
 * Caso contrário, o último nó é removido, e a função retorna 1.
 * 
 * @param l Ponteiro para a lista.
 * @return int Retorna 1 se a remoção foi bem-sucedida, 0 se a lista estiver vazia.
 */
int removerFim(Lista *l)
{
    if (lista_vazia(l))
        return 0;

    Node *fim = l->sentinela->anterior;
    l->sentinela->anterior = fim->anterior;
    fim->anterior->proximo = l->sentinela;

    free(fim);
    l->qntd--;
    return 1;
}

/**
 * @brief Insere um elemento no início da lista.
 * 
 * Esta função insere um novo elemento no início da lista, logo após o nó sentinela.
 * Se a lista estiver cheia ou a alocação de memória falhar, a função retorna 0.
 * Caso contrário, o elemento é inserido corretamente e a função retorna 1.
 * 
 * @param l Ponteiro para a lista.
 * @param dado Valor a ser inserido na lista.
 * @return int Retorna 1 se a inserção for bem-sucedida, 0 se a lista estiver cheia ou a alocação falhar.
 */
int inserirInicio(Lista *l, T dado)
{
    if (lista_cheia(l))
        return 0;

    Node *novo = malloc(sizeof(Node));
    if (!novo)
        return 0;

    novo->dado = dado;
    novo->anterior = l->sentinela;
    novo->proximo = l->sentinela->proximo;

    l->sentinela->proximo = novo;
    novo->proximo->anterior = novo;

    l->qntd++;
    return 1;
}

/**
 * @brief Insere um elemento no final da lista.
 * 
 * Esta função insere um novo elemento no final da lista, antes do nó sentinela.
 * Se a lista estiver cheia ou a alocação de memória falhar, a função retorna 0.
 * Caso contrário, o elemento é inserido corretamente e a função retorna 1.
 * 
 * @param l Ponteiro para a lista.
 * @param dado Valor a ser inserido na lista.
 * @return int Retorna 1 se a inserção for bem-sucedida, 0 se a lista estiver cheia ou a alocação falhar.
 */
int inserirFim(Lista *l, T dado)
{
    if (lista_cheia(l))
        return 0;

    Node *novo = malloc(sizeof(Node));
    if (!novo)
        return 0;

    novo->dado = dado;
    novo->proximo = l->sentinela;
    novo->anterior = l->sentinela->anterior;

    l->sentinela->anterior = novo;
    novo->anterior->proximo = novo;

    l->qntd++;
    return 1;
}

/**
 * @brief Retorna o primeiro elemento da lista.
 * 
 * Esta função retorna o dado armazenado no primeiro elemento da lista,
 * ou seja, no nó imediatamente após o nó sentinela.
 * Não pode ser chamada se a lista estiver vazia.
 * 
 * @param l Ponteiro para a lista.
 * @return T O valor armazenado no primeiro nó da lista.
 */
T lista_primeiroElemento(Lista *l)
{
    return l->sentinela->proximo->dado;
}

/**
 * @brief Retorna o último elemento da lista.
 * 
 * Esta função retorna o dado armazenado no último elemento da lista,
 * ou seja, no nó imediatamente antes do nó sentinela.
 * Não pode ser chamada se a lista estiver vazia.
 * 
 * @param l Ponteiro para a lista.
 * @return T O valor armazenado no último nó da lista.
 */
T lista_ultimoElemento(Lista *l)
{
    return l->sentinela->anterior->dado;
}

/**
 * @brief Retorna a quantidade de elementos na lista.
 * 
 * Esta função retorna o número de elementos atualmente armazenados na lista.
 * 
 * @param l Ponteiro para a lista.
 * @return int A quantidade de elementos na lista.
 */
int lista_quantidade(Lista *l)
{
    return l->qntd;
}

/**
 * @brief Obtém o primeiro elemento da lista.
 * 
 * @param l Ponteiro para a lista.
 * @return Iterador apontando para o primeiro elemento da lista.
 */
iterador primeiro(Lista *l)
{
    iterador i;
    i.posicao = l->sentinela->proximo;
    i.estrutura = l;
    return i;
}

/**
 * @brief Obtém o último elemento da lista.
 * 
 * @param l Ponteiro para a lista.
 * @return Iterador apontando para o último elemento da lista.
 */
iterador ultimo(Lista *l)
{
    iterador i;
    i.posicao = l->sentinela->anterior;
    i.estrutura = l;
    return i;
}

/**
 * @brief Avança o iterador para o próximo elemento da lista.
 * 
 * @param i Ponteiro para o iterador.
 */
void proximo(iterador *i)
{
    if (!acabou(*i))
        i->posicao = i->posicao->proximo;
}

/**
 * @brief Retrocede o iterador para o elemento anterior da lista.
 * 
 * @param i Ponteiro para o iterador.
 */
void anterior(iterador *i)
{
    if (!acabou(*i))
        i->posicao = i->posicao->anterior;
}

/**
 * @brief Retorna o elemento atual do iterador.
 * 
 * @param i Iterador.
 * @return Elemento do tipo T armazenado na posição atual do iterador.
 */
T elemento(iterador i)
{
    if (!acabou(i))
        return i.posicao->dado;
}

/**
 * @brief Verifica se o iterador chegou ao final da lista.
 * 
 * @param i Iterador.
 * @return 1 se o iterador está no final da lista, 0 caso contrário.
 */
int acabou(iterador i)
{
    return (i.posicao == i.estrutura->sentinela);
}