#include "hashtable.h"

// Função para inicializar uma tabela hash vazia
Hash** criarTabelaHash() {
    Hash** tabela = (Hash**)malloc(sizeof(Hash*) * TAM_TABELA);
    int i;
    for ( i = 0; i < TAM_TABELA; i++) {
        tabela[i] = NULL;
    }
    return tabela;
} 

// Função de hash simples para mapear uma chave a um índice na tabela
unsigned int hash(const char* chave) {
    unsigned int hash = 0;
    while (*chave) {
        hash = (hash * 31) + (*chave++);
    }
    return hash % TAM_TABELA;
}

// Função para inserir uma chave, valor e tipo na tabela hash passada
void inserir(Hash** tabela, const char* chave, char* token, int type) {
    Hash* verifica = buscar(tabela, chave);

    if(verifica == NULL){ //insere na tabela caso ainda não esteja inserida
        unsigned int indice = hash(chave);
        Hash* novoNo = (Hash*)malloc(sizeof(Hash));
        novoNo->chave = strdup(chave);
        novoNo->token = token;
        novoNo->type = type;

        if(strcmp(token, "ID") == 0) novoNo->isId = 1;
        else novoNo->isId = 0;
        
        if(type == 1 && strcmp(token, "DIG_INT") == 0) novoNo->valor_int = atoi(chave);
        else if(type == 2 && strcmp(token, "DIG_REAL") == 0) novoNo->valor_real = atof(chave);
        else if(type == 3 && strcmp(token, "STRING") == 0) strcpy(novoNo->valor_str, chave);
        else if(type == 6 && strcmp(token, "CARACTER") == 0) strcpy(novoNo->valor_char, chave);
        
        novoNo->prox = tabela[indice];
        tabela[indice] = novoNo;
        
    }
}

// Função para buscar um token na tabela hash com base na chave
Hash* buscar(Hash** tabela, const char* chave) {
    unsigned int indice = hash(chave);
    
    Hash* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual; //Caso a chave ja esteja na tabela, retorna no atual
        }
        atual = atual->prox;
    }

    return NULL; // Caso não tenha encontrado a chave
}

// Funcao para definir o tipo de uma variavel
void definirTipo(char* nome, int tipo, Hash** tabela){
    Hash* l = buscar(tabela, nome);

    l->type = tipo;
}

// Funcao para atribuir um valor a uma variavel
void receberValor(Hash** tabela, char *var_id, char* exp){
    Hash* l_id = buscar(tabela, var_id);
    Hash* l_exp = buscar(tabela, exp);

    if(l_exp->type == 1){
        l_id->valor_int = atoi(l_exp->chave);
    }
    else if(l_exp->type == 2){
            l_id->valor_real = atof(l_exp->chave);
    }
    else if(l_exp->type == 3){
            strcpy(l_id->valor_str, l_exp->chave);
    }
    else if(l_exp->type == 6){
            strcpy(l_id->valor_char, l_exp->chave);
    }
    //else strcpy(l_id->nulo, "underflow");
    
}

/*
int pegarTipo(Hash** tabela, char* nome){
    Hash* l = buscar(tabela, nome);

    if(l->type == TIPO_INT || l->type == TIPO_REAL)
        return l->type;
}
*/

int calcular(Hash** tabela, char* expressao1, char* expressao2, char* simbolo){
    Hash* expr1 = buscar(tabela, expressao1);
    Hash* expr2 = buscar(tabela, expressao2);
    int x;
    float y;

    if(expr1->type == 1){
        if (strcmp(simbolo, "+") == 0){
            x = expr1->valor_int + expr2->valor_int;
            return x;
        }
     
    }

    if(expr1->type == 2){
        if(strcmp(simbolo, "+") == 0){
        printf("exp1 : %f\nexp2: %f\n", expr1->valor_real, expr2->valor_real);
            y = expr1->valor_real + expr2->valor_real;
            printf("y = %f\n", y);
            return y;
        }
        
    }

    return 0;

}

// Função para imprimir todos os elementos da tabela de simbolos
void mostrar(Hash** tabela){
    int i;
    Hash* aux;
    printf("------------------------- -------------------- --------------- ----------\n");
    printf("Lexema                    Token                Tipo            Valor      \n");
    printf("------------------------- -------------------- --------------- ----------\n");
    for (i = 0; i < TAM_TABELA; i++){
        if(tabela[i] != NULL){
            aux = tabela[i];
            while(aux != NULL){
                printf("%-26s%-21s", aux->chave, aux->token);
                if(aux->type == TIPO_INT)           printf("%-16s", "int");
                else if(aux->type == TIPO_REAL)     printf("%-16s", "real");
                else if(aux->type == TIPO_STR)      printf("%-16s", "string");
                else if(aux->type == TIPO_CHAR)     printf("%-16s", "char");
                else if(aux->type == TIPO_VOID)     printf("%-16s", "void");
                else if(aux->type == TIPO_KEIWORD)  printf("%-16s", "keyword");
                else printf("%-16s", "underfined"); 
                
                
                if(aux->type == TIPO_INT && aux->isId == 1)       printf("%-16d", aux->valor_int);
                else if(aux->type == TIPO_REAL && aux->isId == 1) printf("%-16.2f", aux->valor_real);
                else if(aux->type == TIPO_STR && aux->isId == 1)  printf("%-16s", aux->valor_str);
                else if(aux->type == TIPO_CHAR && aux->isId == 1) printf("%-16s", aux->valor_char);
                else printf("%-16s", "---");

                
                printf("\n");
                aux = aux->prox;
            }   
        }
    }
}

// Função para imprimir todos os elementos da tabela de reservada
void mostrarReservada(Hash** tabela){
    int i;
    Hash* aux;
    printf("------------------------- -------------------- --------------- \n");
    printf("Lexema                    Token                Tipo            \n");
    printf("------------------------- -------------------- --------------- \n");
    for (i = 0; i < TAM_TABELA; i++){
        if(tabela[i] != NULL){
            aux = tabela[i];
            while(aux != NULL){
                printf("%-26s%-21s", aux->chave, aux->token);
                if(aux->type == TIPO_KEIWORD) printf("%-16s", "keyword");
                else if(aux->type == OP_ARITMETICO) printf("%-16s", "aritmetico");
                else if(aux->type == OP_RELACIONAL) printf("%-16s", "relacional");
                else if(aux->type == OP_INC_DEC) printf("%-16s", "inc_dec");
                else if(aux->type == OP_ATRI) printf("%-16s", "atribuicao");
                else if(aux->type == OP_LOGIC) printf("%-16s", "logico"); 
                else printf("%-16s", "underfined");
                
              
                printf("\n");
                aux = aux->prox;
            }   
        }
    }
}
