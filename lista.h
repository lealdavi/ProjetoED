#ifndef LISTA_H
#define LISTA_H

/**
 * @typedef T
 * @brief Tipo genérico para armazenar dados na lista.
 * 
 * Este tipo é um ponteiro void que permite armazenar qualquer tipo de dado
 * na lista encadeada.
 */
typedef void *T;

/**
 * @struct node
 * @brief Estrutura que representa um nó da lista encadeada.
 * 
 * Cada nó contém um dado do tipo T, um ponteiro para o próximo nó e um 
 * ponteiro para o nó anterior, permitindo a navegação bidirecional.
 */
typedef struct node
{
    T dado;
    struct node *proximo, *anterior;
} Node;

/**
 * @struct Lista
 * @brief Estrutura que representa a lista encadeada.
 * 
 * A estrutura contém um nó sentinela que facilita a manipulação da lista
 * e dois inteiros que armazenam a quantidade atual de elementos e o 
 * limite máximo de elementos.
 */
typedef struct
{
    Node *sentinela;
    int qntd, max;
} Lista;

/**
 * @brief Inicializa uma nova lista com um limite máximo de elementos.
 * 
 * Esta função aloca memória para a lista e configura o nó sentinela.
 * 
 * @param max Limite máximo de elementos que a lista pode armazenar.
 * @return Lista* Ponteiro para a lista inicializada.
 */
Lista *lista_inicializar(int max);

/**
 * @brief Verifica se a lista está vazia.
 * 
 * Esta função retorna 1 se a lista estiver vazia, ou seja, se o nó
 * sentinela aponta para si mesmo.
 * 
 * @param l Ponteiro para a lista.
 * @return int Retorna 1 se a lista estiver vazia, 0 caso contrário.
 */
int lista_vazia(Lista *l);

/**
 * @brief Verifica se a lista está cheia.
 * 
 * Esta função retorna 1 se a lista atingiu sua capacidade máxima.
 * 
 * @param l Ponteiro para a lista.
 * @return int Retorna 1 se a lista estiver cheia, 0 caso contrário.
 */
int lista_cheia(Lista *l);

/**
 * @brief Libera a memória ocupada pela lista.
 * 
 * Esta função remove todos os elementos da lista e libera a memória 
 * alocada para a estrutura da lista e seu nó sentinela.
 * 
 * @param l Ponteiro para a lista a ser destruída.
 */
void lista_destruir(Lista *l);

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
int removerInicio(Lista *l);

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
int removerFim(Lista *l);

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
int inserirInicio(Lista *l, T dado);

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
int inserirFim(Lista *l, T dado);

/**
 * @brief Retorna o primeiro elemento da lista.
 * 
 * Esta função retorna o dado armazenado no primeiro elemento da lista,
 * ou seja, no nó imediatamente após o nó sentinela.
 * 
 * @param l Ponteiro para a lista.
 * @return T O valor armazenado no primeiro nó da lista.
 * @warning Se a lista estiver vazia, o comportamento é indefinido.
 */
T lista_primeiroElemento(Lista *l);

/**
 * @brief Retorna o último elemento da lista.
 * 
 * Esta função retorna o dado armazenado no último elemento da lista,
 * ou seja, no nó imediatamente antes do nó sentinela.
 * 
 * @param l Ponteiro para a lista.
 * @return T O valor armazenado no último nó da lista.
 * @warning Se a lista estiver vazia, o comportamento é indefinido.
 */
T lista_ultimoElemento(Lista *l);

/**
 * @brief Retorna a quantidade de elementos na lista.
 * 
 * Esta função retorna o número de elementos atualmente armazenados na lista.
 * 
 * @param l Ponteiro para a lista.
 * @return int A quantidade de elementos na lista.
 */
int lista_quantidade(Lista *l);

/**
 * @brief Imprime os elementos da lista.
 * 
 * Esta função itera sobre os elementos da lista e chama uma função 
 * de impressão fornecida para cada elemento. Os elementos são impressos
 * na ordem em que aparecem na lista, começando pelo primeiro elemento.
 * 
 * @param l Ponteiro para a lista.
 * @param print Ponteiro para a função de impressão que aceita um argumento do tipo T.
 */
void imprimirLista(Lista *l, void (*print)(T));


#endif