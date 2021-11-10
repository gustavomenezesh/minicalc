//
// Analisador lexico
//

#ifndef MINICALC_LEXER_H
#define MINICALC_LEXER_H

#define IDENT_TAM_MAX  60

typedef enum tagTipoToken {
    TOKEN_INT,
    TOKEN_PRINT,
    TOKEN_VAR,
    TOKEN_IDENT,
    TOKEN_ERRO,
    TOKEN_SOMA,
    TOKEN_MULT,
    TOKEN_SUB,
    TOKEN_DIV,
    TOKEN_ABREPAR,
    TOKEN_FECHAPAR,
    TOKEN_ABRECOL,
    TOKEN_FECHACOL,
    TOKEN_IGUAL,
    TOKEN_PONTOVIRG,
    TOKEN_EOF
} TipoToken;

typedef struct tagToken {
    TipoToken tipo;
    int       valor;
    char      nome[IDENT_TAM_MAX];
} Token;


void InicializaLexer(char *arqFonte);
Token* ProximoToken();
void FinalizaLexer();


#endif //MINICALC_LEXER_H