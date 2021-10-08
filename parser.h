//
// Analisador sintático para MiniCalc
//

#ifndef MINICALC_PARSER_H
#define MINICALC_PARSER_H

typedef enum tagTipoOper {
    OPER_SOMA,
    OPER_MULT,
    OPER_SUB,
    OPER_DIV,
    OPER_CONST
} TipoOper;

typedef struct tagExpressao {
    struct tagExpressao *op1;
    struct tagExpressao *op2;
    int valor;
    TipoOper oper;
} Expressao;

typedef struct tagPrograma {
    Expressao *e;
} Programa;

Programa* AnalisePrograma();
Expressao* AnaliseExpressao();
void DestroiPrograma(Programa *p);

#endif //MINICALC_PARSER_H
