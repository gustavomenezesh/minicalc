//
// Analisador sintático para MiniCalc
//

#ifndef MINICALC_PARSER_H
#define MINICALC_PARSER_H

#include "lexer.h"

typedef enum tagTipoOper {
    OPER_SOMA,
    OPER_MULT,
    OPER_SUB,
    OPER_DIV,
    OPER_CONST,
    OPER_VAR,
} TipoOper;

typedef struct tagExpressao {
    struct tagExpressao *op1;
    struct tagExpressao *op2;
    int valor;
    char nomeIdent[IDENT_TAM_MAX];
    TipoOper oper;
} Expressao;

typedef struct tagDeclaracao {
    char nomeIdent[IDENT_TAM_MAX];
    Expressao *e;
    struct tagDeclaracao* next;
} Declaracao;

typedef struct tagPrograma {
    Declaracao *decls;
    Expressao *e;
} Programa;

Programa* AnalisePrograma();
Expressao* AnaliseExpressao();
void DestroiPrograma(Programa *p);

#endif //MINICALC_PARSER_H
