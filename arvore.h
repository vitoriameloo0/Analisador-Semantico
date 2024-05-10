#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Estrutura para um no da Arvore Sintatica
struct Node { 
	char *token; 
	struct Node *left; 
	struct Node *right; 
};
 
// Funcao para inserir um no na arvore sintatica
// Entrada: Um token e o no que esta a sua direita e esquerda
// Retorno: No para o proximo no da arvore 
// Pré-Condição: Regra sintatica esta correta
// Pós-Condição: tokens inseridos na arvore
struct Node* inserirArvore(struct Node *left, struct Node *right, char *token);

// Funcao para inserir onde esta o erro na arvore sintatica
// Entrada: Posicao esqueda e direita nulas
// Retorno: O no daquele erro
// Pré-Condição: Regra sintatica esta errada
// Pós-Condição: Erro identificado na arvore
struct Node* inserirError (struct Node *left, struct Node *right);

// Funcao auxiliar para imprimir a arvore sintatica
// Entrada: Arquivo de gravacao, No dos dados, quantidade de no, e filho
// Retorno: Nenhuma
// Pré-Condição: Nenhuma
// Pós-Condição: Arvore sintatica imprimida 
void imprimirAuxiliar(FILE* of, struct Node* node, int n, int child);

// Funcao para imprimir a arvore sintativa
// Entrada: Arquivo que sera gravado e no dos dados
// Retorno: Nenhuma
// Pré-Condição: Nenhuma
// Pós-Condição: Arvore sintatica imprimida 
void imprimirArvore(FILE* of, struct Node* node);

