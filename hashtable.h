#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 100
#define TAM_VAR 100

//Tipos das Variaveis
#define TIPO_INT        1
#define TIPO_REAL       2
#define TIPO_STR        3
#define TIPO_UNDEF      4
#define TIPO_KEIWORD    5
#define TIPO_CHAR       6
#define TIPO_VOID       7

#define OP_ARITMETICO   10
#define OP_RELACIONAL   11
#define OP_INC_DEC      12
#define OP_ATRI         13
#define OP_LOGIC        14

// Categorias
#define NUMERO          20
#define VARIAVEL        21
#define FUNCAO          22
#define TIPO_DADO       23
#define CARACTERES      24
#define BIBLIOTECAS     25
#define SIMBOLOS        26

// Estrutura pra guardar as linhas que uma variavel apareceu
typedef struct ListaId {
    int line;
    struct ListaId *next;
}ListaId;

// Estrutura para um nó da tabela hash
typedef struct Hash {
    char* chave; 
    char* token;
    int categoria;      
    int type;

    int valor_int;              // caso seja um ID e receba um valor inteiro  
    float valor_real;           // caso seja um ID e receba um valor real  
    char valor_str[TAM_VAR];    // caso seja um ID e receba uma string
    char valor_char[TAM_VAR];   // caso seja um ID e receba um caracter    

    ListaId *lines;             // lista de quais linhas uma variavel apareceu

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
// Entrada: Tabela que será inserida, a chave, o token, o tipo, a categoria e a linha que ele apareceu.
// Retorno: Nenhuma.
// Pré-Condição: A chave não esta presente na tabela.
// Pós-Condição: A chave, o token, o type e a categoria inseridos na tabela.
void inserir(Hash** tabela, const char* chave, char* token, int type, int categoria, int linha);

// Função para buscar um token na tabela hash com base na chave
// Entrada: Tabela e a chave que sera analisada.
// Retorno: Ponteiro da chave, ou NULL caso não encontrado
// Pré-Condição: Nenhuma.
// Pós-Condição: Nenhuma.
Hash* buscar(Hash** tabela, const char* chave);

// Função para verificar se o nome da funcao ja apareceu em alguma parte do codigo como ID
// Entrada: Tabela e a chave que sera analisada.
// Retorno: O numero da linha em que ele apareceu pela primeira vez
// Pré-Condição: O tipo do token padrao ter sido modificado.
// Pós-Condição: Apontar a linha que apareceu a variavel.
int verificaExistencia(Hash** tabela, char* nome);

// Função para definir a categoria de um token na tabela 
// Entrada: Tabela, o nome do lexema e a categoria dela
// Retorno: Nenhuma.
// Pré-Condição: Nenhuma.
// Pós-Condição: Categoria definida.
void definirCategoria(Hash** tabela, char* nome , int categoria);

// Função para definir o tipo de um lexema
// Entrada: Tabela, o nome do token, tipo do token.
// Retorno: Nenhuma. 
// Pré-Condição: Nenhuma.
// Pós-Condição: Token com type atualizado.
void definirTipo(char* nome, int tipo, Hash** tabela);

// Função para calcular os valores inteiros a partir do sinal aritmetico passado
// Entrada: Tabela, expressão 1, expressão 2 e o sinal aritmetico
// Retorno: Resultado do calculo. 
// Pré-Condição: Nenhuma.
// Pós-Condição: Nenhuma.
int calcularInt(Hash** tabela, char* expressao1, char* expressao2, char* simbolo);

// Função para calcular os valores float a partir do sinal aritmetico passado
// Entrada: Tabela, expressão 1, expressão 2 e o sinal aritmetico
// Retorno: Resultado do calculo. 
// Pré-Condição: Nenhuma.
// Pós-Condição: Nenhuma.
float calcularReal (Hash** tabela, char* expressao1, char* expressao2, char* simbolo);

// Função para imprimir todos os elementos da tabela de simbolos 
// Entrada: Tabela.
// Retorno: Nenhuma. 
// Pré-Condição: Nenhuma.
// Pós-Condição: Tabela impressa.
void mostrar(Hash** tabela);

// Função para imprimir todos os elementos da tabela reservada
// Entrada: Tabela.
// Retorno: Nenhuma. 
// Pré-Condição: Nenhuma.
// Pós-Condição: Tabela impressa.
void mostrarReservada(Hash** tabela);

#endif //HASHTABLE_H
