#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_TABELA 100

//Tipos de Variaveis

#define TIPO_INT        1
#define TIPO_REAL       2
#define TIPO_STR        3
#define TIPO_UNDEF      4
#define TIPO_KEIWORD    5

// Lista para guardar quantas vezes uma variavel aparece no arquivo
typedef struct Lista {
    int linha;
    int type;
    struct Lista* next;
}Lista;

// Estrutura para um nó da tabela hash
typedef struct Hash {
    char* chave;
    char* token;
    int type;
    int valor_int; float valor_real; char valor_str[100]; char nulo[10];        
    struct Hash* prox;
} Hash;
 
// Função de hash simples para mapear uma chave a um índice na tabela
// Entrada: A chave que será mapeada.
// Retorno: O valor da chave.
// Pré-Condição: Nenhuma.
// Pós-Condição: Nenhuma.
unsigned int hash(const char* chave);

// Função para inicializar uma tabela hash vazia
// Entrada: Nenhuma.
// Retorno: Tabela inicializada como vazia.
// Pré-Condição: Tabela criada.
// Pós-Condição: Tabela estar vazia.
Hash** criarTabelaHash();

// Função para inserir um par chave-valor na tabela hash
// Entrada: Tabela que será inserida, a chave e o token.
// Retorno: Nenhuma.
// Pré-Condição: A chave não esta presente na tabela.
// Pós-Condição: A chave e o token inseridos na tabela.
void inserir(Hash** tabela, const char* chave, char* token, int type);

// Função para buscar um token na tabela hash com base na chave
// Entrada: Tabela e a chave que sera analisada.
// Retorno: 1 caso a chave ja esteja na tabela, 0 caso contrario.
// Pré-Condição: Nenhuma.
// Pós-Condição: Nenhuma.
Hash* buscar(Hash** tabela, const char* chave);

// Função para imprimir todos os elementos da tabela
// Entrada: Tabela.
// Retorno: Nenhuma. 
// Pré-Condição: Nenhuma.
// Pós-Condição: Tabela impressa.
void mostrar(Hash** tabela);

void definirTipo(char* nome, int tipo, Hash** tabela);

int pegarTipo(Hash** tabela, char* nome);

#endif //HASHTABLE_H