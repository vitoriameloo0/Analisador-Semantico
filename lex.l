%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "hashtable.h"
    #include "parser.tab.h"

    Hash** tabela_reservada;
    Hash** tabela_simbolos;
    int line = 1;
%}

%option yylineno

DIG             [0-9]
INTEGER		    ([-]?{DIG}+)
REAL	        ({DIG}+)\.({DIG}+)
CARACTER	    (\'.*\')
ID		        [a-zA-Z_]+[a-zA-Z0-9_]*
STR             (\".*\")
ESCRITA          (\^.*\^)
LEITURA           (\*.*\*)
ERROSIMB        ("@"|"#"|"&"|"?"|"$")+("=")+
INCREMENTO	    "++"
DECREMENTO	    "--"
ADICAO		    "+"
SUBTRACAO	    "-" 
MULTIPLICACAO	"*"
DIVISAO		    "/"
IGUAL		    "=="
ATRIBUICAO	    "="
COMPARACAO      (<|>|<\=|>\=)
DIFERENTE	    "!="
AND             "&&"
OR              "||"
NOT             "!"
PONTO_VIRGULA	";"
VIRGULA		    ","
A_PARENT	    "("
F_PARENT	    ")"
A_CHAVE		    "{"
F_CHAVE		    "}"
A_COLCHET	    "["
F_COLCHET	    "]"
COMENTARIO     ("//"[^\n]*)
ERROID          [0-9]+[A-Za-z0-9]+
ERROID2         (LETRA)*("@"|"#"|"&"|"?"|"$")+(LETRA)+
BIBLIOTECA      ("#include"[ ]*<.+\.h>)

%%
 

"int"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_INT", 5, 5, line);    
                return INT;
            }

"float"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_FLOAT", 5, 5, line);             
                return FLOAT;
            }

"char"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_CHAR", 5, 5, line);
                return CHAR;
            }

"double"	{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_DOUBLE", 5, 5, line);
                return DOUBLE;
            }

"void"      {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_VOID", 5, 5, line);
                return VOID;
            }

"string"    {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "TIPO_STRING", 5, 5, line);
                return STRING;
            }

"if"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "IF", 5, 5, line);                
                return IF;
            }

"else"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "ELSE", 5, 5, line);              
                return ELSE;
            }

"for"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "FOR", 5, 5, line);                                 
                return FOR;
            }

"while"		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "WHILE", 5, 5, line);                                  
                return WHILE;
            }

"return"    {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "RETURN", 5, 5, line);                   
                return RETURN;
            }

"printf"    {    strcpy(yylval.no_obj.strNome, (yytext));
                 inserir(tabela_reservada, yytext, "PRINTF", 5, 5, line);                                
                return PRINTF;
            }

"scanf"    {   strcpy(yylval.no_obj.strNome, (yytext));
               inserir(tabela_reservada, yytext, "SCANF", 5, 5, line);                               
               return SCANF;
            }         

{ID}		{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "ID", 4, 4, line);  
                //yylval.no_obj.listaSimb = buscar(tabela_simbolos, yytext);                              
                return ID;
            }

{STR}       {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "STRING", 3, 24, line);  
                yylval.no_obj.type = TIPO_STR;                                            
                return STR;
            }

{ESCRITA}   {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "ESCRITA", 4, 24, line);                                
                return ESCRITA;           
            }

{LEITURA}   {  strcpy(yylval.no_obj.strNome, (yytext));
               inserir(tabela_simbolos, yytext, "LEITURA", 4, 24, line);                                 
               return LEITURA;           
            }

{INTEGER}	{  strcpy(yylval.no_obj.strNome, (yytext));
               inserir(tabela_simbolos, yytext, "DIG_INT", 1, 20, line); 
               yylval.no_obj.type = TIPO_INT;                                
                return  INTEGER;
            }

{REAL}      {   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "DIG_REAL", 2, 20, line); 
                yylval.no_obj.type = TIPO_REAL;                
                return REAL;
            }           

{CARACTER}	{   strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_simbolos, yytext, "CARACTER", 6, 24, line);   
                yylval.no_obj.type = TIPO_CHAR;                             
                return CARACTER;
            }

{BIBLIOTECA} {  strcpy(yylval.no_obj.strNome, (yytext));
                inserir(tabela_reservada, yytext, "NOME_BIBLIOTECA", 5, 25, line);                                 
                return BIBLIOTECA;
            } 

{INCREMENTO} {  inserir(tabela_reservada, yytext, "INCREMENTO", 12, 26, line);                       
                return INCREMENTO;
             }

{DECREMENTO} {  inserir(tabela_reservada, yytext, "DECREMENTO", 12, 26, line);                        
                return DECREMENTO;
             }

{ADICAO}	{  inserir(tabela_reservada, yytext, "ADICAO", 10, 26, line);                   
               return ADICAO;
            }

{SUBTRACAO}	{   inserir(tabela_reservada, yytext, "SUBTRACAO", 10, 26, line);                    
                return SUBTRACAO;
            }

{MULTIPLICACAO} {   inserir(tabela_reservada, yytext, "MULTIPLICACAO", 10, 26, line);                       
                    return MULTIPLICACAO;
                }

{DIVISAO}	{   inserir(tabela_reservada, yytext, "DIVISAO", 10, 26, line);                   
                return DIVISAO;
            }

{IGUAL}		{   inserir(tabela_reservada, yytext, "IGUAL", 13, 26, line);                    
                return IGUAL;
            }

{ATRIBUICAO}	{   inserir(tabela_reservada, yytext, "ATRIBUICAO", 13, 26, line);                        
                    return ATRIBUICAO;
                }            

{COMPARACAO}	{   inserir(tabela_reservada, yytext, "COMPARACAO", 11, 26, line);                       
                    return COMPARACAO;
                }

{DIFERENTE}	    {   inserir(tabela_reservada, yytext, "DIFERENTE", 11, 26, line);
                    return DIFERENTE;
                }

{AND}           {   inserir(tabela_reservada, yytext, "AND", 14, 26, line);
                    return AND;
                }

{OR}            {   inserir(tabela_reservada, yytext, "OR", 14, 26, line);
                    return OR;
                }

{NOT}           {   inserir(tabela_reservada, yytext, "NOT", 14, 26, line);
                    return NOT;
                }
            
{PONTO_VIRGULA}	{   inserir(tabela_reservada, yytext, "PONTO_VIRGULA", 4, 26, line);
                    return PONTO_VIRGULA;
                }

{VIRGULA}		{   inserir(tabela_reservada, yytext, "VIRGULA", 4, 26, line);
                    return VIRGULA;
                }
                
{A_PARENT}	    {   inserir(tabela_reservada, yytext, "A_PARENT", 4, 26, line);
                    return  A_PARENT;
                }

{F_PARENT}	    {   inserir(tabela_reservada, yytext, "F_PARENT", 4, 26, line);
                    return F_PARENT;
                }           

{A_CHAVE}	    {   inserir(tabela_reservada, yytext, "A_CHAVE", 4, 26, line);
                    return A_CHAVE;
                }

{F_CHAVE}	    {   inserir(tabela_reservada, yytext, "F_CHAVE", 4, 26, line); 
                    return F_CHAVE;
                }

{A_COLCHET}	    {   inserir(tabela_reservada, yytext, "A_COLCHET", 4, 26, line);
                    return A_COLCHET;
                }

{F_COLCHET}	    {   inserir(tabela_reservada, yytext, "F_COLCHET", 4, 26, line);
                    return F_COLCHET;
                }       

{COMENTARIO}    {   inserir(tabela_simbolos, yytext, "COMENTARIO", 4, 26, line);
                   strcpy(yylval.no_obj.strNome, (yytext));
                    return COMENTARIO;
                }

"\n"            {line++;}            

[ \t\r]*        {;}

{ERROID}        {
                    printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
                    
                }

{ERROID2}       {
                    printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
                    
                }

{ERROSIMB}      {
                  printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext);
                  
                }

.               {
                    printf("\nErro Lexico na linha %d , token  %s nao identificado\n", yylineno, yytext); 
                
                }
%%

int yywrap(){
    return 1;
}
