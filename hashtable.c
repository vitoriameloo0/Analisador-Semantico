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

void receberValor(Hash** tabela, char* id, char* valor){
    Hash* l_id = buscar(tabela, id);
    Hash* l_tipo = buscar(tabela, valor);

    if(l_tipo->type == TIPO_INT){
        l_id->valor_int = atoi(l_tipo->chave);
    }
    else if(l_tipo->type == TIPO_REAL){
    l_id->valor_real = atof(l_tipo->chave);
    }
    else if(l_tipo->type == TIPO_STR){
    strcpy(l_id->valor_str, l_tipo->valor_str);
    }
    else
        strcpy(l_id->nulo, NULL);
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

                if(aux->valor_int == TIPO_INT) 


                printf("\n");
                aux = aux->prox;
            }   
        }
    }
}

