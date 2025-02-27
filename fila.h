#ifndef FILA_H
#define FILA_H

/**
 * @typedef T
 * @brief Tipo genérico para armazenar dados na fila.
 * 
 * Este tipo é um ponteiro void que permite armazenar qualquer tipo de dado
 * na fila.
 */
typedef void *T; 

/**
 * @struct Fila
 * @brief Estrutura que representa uma fila.
 * 
 * A estrutura contém informações sobre os índices de início e fim,
 * a quantidade atual de elementos, o limite máximo de elementos,
 * e um vetor dinâmico para armazenar os elementos da fila.
 */
typedef struct
{
    int inicio; ///< Índice do primeiro elemento da fila.
    int fim;    ///< Índice do próximo espaço livre na fila.
    int qntd;   ///< Quantidade atual de elementos na fila.
    int max;    ///< Limite máximo de elementos que a fila pode armazenar.
    T *vetor;   ///< Vetor dinâmico que armazena os elementos da fila.
} Fila;

/**
 * @brief Inicializa uma nova fila com um limite máximo de elementos.
 * 
 * Esta função aloca memória para a fila e inicializa seus atributos.
 * 
 * @param max Limite máximo de elementos que a fila pode armazenar.
 * @return Fila* Ponteiro para a fila inicializada.
 */
Fila *fila_inicializar(int max);

/**
 * @brief Verifica se a fila está vazia.
 * 
 * Esta função retorna 1 se a fila estiver vazia, ou seja, se a quantidade
 * de elementos for zero.
 * 
 * @param f Ponteiro para a fila.
 * @return int Retorna 1 se a fila estiver vazia, 0 caso contrário.
 */
int fila_vazia(Fila *f);

/**
 * @brief Verifica se a fila está cheia.
 * 
 * Esta função retorna 1 se a fila atingiu sua capacidade máxima.
 * 
 * @param f Ponteiro para a fila.
 * @return int Retorna 1 se a fila estiver cheia, 0 caso contrário.
 */
int fila_cheia(Fila *f);

/**
 * @brief Verifica se a fila está cheia.
 * 
 * Esta função retorna 1 se a fila atingiu sua capacidade máxima.
 * 
 * @param f Ponteiro para a fila.
 * @return int Retorna 1 se a fila estiver cheia, 0 caso contrário.
 */
void fila_destruir(Fila *f);

/**
 * @brief Insere um elemento na fila.
 * 
 * Esta função adiciona um novo elemento ao fim da fila. Se a fila estiver cheia
 * ou a alocação de memória falhar, a função retorna 0. Caso contrário, o elemento
 * é inserido corretamente e a função retorna 1.
 * 
 * @param f Ponteiro para a fila.
 * @param dado Valor a ser inserido na fila.
 * @return int Retorna 1 se a inserção for bem-sucedida, 0 se a fila estiver cheia ou a alocação falhar.
 */
int inserir(Fila *f, T dado);

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
int remover(Fila *f);

/**
 * @brief Retorna o primeiro elemento da fila.
 * 
 * Esta função retorna o dado armazenado no primeiro elemento da fila.
 * 
 * @param f Ponteiro para a fila.
 * @return T O valor armazenado no primeiro elemento da fila.
 * @warning Se a fila estiver vazia, o comportamento é indefinido.
 */
T fila_primeiroElemento(Fila *f);

/**
 * @brief Retorna o último elemento da fila.
 * 
 * Esta função retorna o dado armazenado no último elemento da fila.
 * 
 * @param f Ponteiro para a fila.
 * @return T O valor armazenado no último elemento da fila.
 * @warning Se a fila estiver vazia, o comportamento é indefinido.
 */
T fila_ultimoElemento(Fila *f);

/**
 * @brief Retorna a quantidade de elementos na fila.
 * 
 * Esta função retorna o número de elementos atualmente armazenados na fila.
 * 
 * @param f Ponteiro para a fila.
 * @return int A quantidade de elementos na fila.
 */
int fila_quantidade(Fila *f);

/**
 * @brief Imprime os elementos da fila.
 * 
 * Esta função itera sobre os elementos da fila e chama uma função 
 * de impressão fornecida para cada elemento. Os elementos são impressos
 * na ordem em que aparecem na fila, começando pelo primeiro elemento.
 * 
 * @param f Ponteiro para a fila.
 * @param print Ponteiro para a função de impressão que aceita um argumento do tipo T.
 */
void imprimirFila(Fila *f, void (*print)(T)); // alterado de modo a permitir a impressão de dados de qualquer tipo

#endif