#include "arvore.h"

// Funcao para inserir um no na arvore sintatica
struct Node* inserirArvore (struct Node *left, struct Node *right, char *token) {	
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	char *str = (char *)malloc(strlen(token)+1);
	strcpy(str, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = str;
	return(newnode);
} 

// Funcao para inserir onde esta o erro na arvore sintatica
struct Node* inserirError (struct Node *left, struct Node *right){
    struct Node *no = inserirArvore(left, right, "_ERROR_");
    return (no);
}

// Funcao auxiliar para imprimir a arvore sintatica
void imprimirAuxiliar (FILE* arquivo, struct Node* node, int n, int child){
    int i;
    for(i = 0; i < n; i++){
        if(i == n-1 && child == 0){
           fprintf(arquivo, " \u251c", 192);
        }
        else if(i == n-1 && child == 1){
            fprintf(arquivo, " \u2515", 195);
        }
        else{
            fprintf(arquivo, " | ");
        }
    }

    fprintf(arquivo,"%s\n", node->token);

    if(node->left != NULL)
        imprimirAuxiliar(arquivo, node->left, n+1, 0);
    if(node->right != NULL)
        imprimirAuxiliar(arquivo, node->right, n+1, 1);
}

// Funcao para imprimir a arvore sintativa
void imprimirArvore (FILE* arquivo, struct Node* node){
    fprintf(arquivo,"| | | ARVORE SINTATICA | | |\n");
    imprimirAuxiliar(arquivo, node, 0, 0);
}

