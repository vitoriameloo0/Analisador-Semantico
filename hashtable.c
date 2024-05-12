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

// Função para inserir um par chave-valor na tabela hash
void inserir(Hash** tabela, const char* chave, char* token, int type) {
    Hash* verifica = buscar(tabela, chave);

    if(verifica == NULL){
        unsigned int indice = hash(chave);
        Hash* novoNo = (Hash*)malloc(sizeof(Hash));
        novoNo->chave = strdup(chave);
        novoNo->token = token;
        novoNo->type = type;

        novoNo->valor_int = -1;
        novoNo->valor_real= -1.0;
        strcpy(novoNo->valor_str ,"");
        strcpy(novoNo->nulo ,"");

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
            return atual; //Caso a chave ja esteja na tabela, retorna a no atual
        }
        atual = atual->prox;
    }

    return NULL; // Caso não tenha encontrado a chave
}

void definirTipo(char* nome, int tipo, Hash** tabela){
    Hash* l = buscar(tabela, nome);

    l->type = tipo;
}

void receberValor(Hash* tabela, char *var_id, char* exp){
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
    else if(l_exp->type == 4)
            strcpy(l_id->nulo, "underflow");
    else strcpy(l_id->nulo, "NULL");
}


int pegarTipo(Hash** tabela, char* nome){
    Hash* l = buscar(tabela, nome);

    if(l->type == TIPO_INT || l->type == TIPO_REAL)
        return l->type;
}

// Função para imprimir todos os elementos da tabela
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
                printf("%-26s%-20s", aux->chave, aux->token);
                if(aux->type == TIPO_INT) printf("%-15s", "int");
                else if(aux->type == TIPO_REAL) printf("%-15s", "real");
                else if(aux->type == TIPO_STR) printf("%-15s", "string");
                else if(aux->type == TIPO_KEIWORD) printf("%-15s", "keyword");
                else printf("%-10s", "underfined");
                
                
                if(aux->type == 1 && aux->valor_int!= -1) printf("%-2s%d"," " ,aux->valor_int);
                else if(aux->type == 2) printf("%-2s%d"," ", aux->valor_real);
                else if(aux->type == 3) printf("%-2s%s", " ", aux->chave);
                else printf("%-2s%s", " ", aux->nulo);

                
                printf("\n");
                aux = aux->prox;
            }   
        }
    }
}
