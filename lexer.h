//
// Analisador lexico
//

#ifndef MINICALC_LEXER_H
#define MINICALC_LEXER_H

typedef enum tagTipoToken {
    TOKEN_INT,
    TOKEN_PRINT,
    TOKEN_ERRO,
    TOKEN_SOMA,
    TOKEN_MULT,
    TOKEN_ABREPAR,
    TOKEN_FECHAPAR,
    TOKEN_EOF
} TipoToken;

typedef struct tagToken {
    TipoToken tipo;
    int       valor;
} Token;


void InicializaLexer(char *arqFonte);
Token* ProximoToken();
void FinalizaLexer();


#endif //MINICALC_LEXER_H
