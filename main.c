#include <stdio.h>
#include <stdlib.h>

#include "arq.h"
#include "lexer.h"

void ImpBuffer(Buffer *b) {
    for (long c = 0; c < b->tam; ++c)
        putchar(b->cont[c]);
}

void ImprimeTipoToken(TipoToken tipo) {
    switch(tipo) {
        case TOKEN_INT:
            printf("TOKEN_INT");
            break;
        case TOKEN_PRINT:
            printf("TOKEN_PRINT");
            break;
        case TOKEN_EOF:
            printf("TOKEN_EOF");
            break;
        case TOKEN_ABREPAR:
            printf("TOKEN_ABREPAR");
            break;
        case TOKEN_FECHAPAR:
            printf("TOKEN_FECHAPAR");
            break;
        case TOKEN_SOMA:
            printf("TOKEN_SOMA");
            break;
        case TOKEN_MULT:
            printf("TOKEN_MULT");
            break;
        case TOKEN_ERRO:
            printf("TOKEN_ERRO");
            break;
        default:
            printf("Tipo desconhecido");
    }
}

int main() {
    InicializaLexer("../test/literal.mc");

    Token *t = ProximoToken();
    while (t->tipo != TOKEN_EOF) {
        printf("Tipo do token: ");
        ImprimeTipoToken(t->tipo);
        printf(" - Valor do token: %d\n", t->valor);

        t = ProximoToken();
    }

    FinalizaLexer();
    return 0;
}
