#include <stdio.h>
#include <stdlib.h>

#include "arq.h"
#include "lexer.h"
#include "parser.h"

float AvaliaExpressao(Expressao* e) {
    float res = 0;
    int v1, v2;

    switch (e->oper) {
        case OPER_CONST:
            res = e->valor;
            break;
        case OPER_SOMA:
            v1 = AvaliaExpressao(e->op1);
            v2 = AvaliaExpressao(e->op2);
            res = v1 + v2;
            break;
        case OPER_MULT:
            v1 = AvaliaExpressao(e->op1);
            v2 = AvaliaExpressao(e->op2);
            res = v1 * v2;
            break;
        case OPER_SUB:
            v1 = AvaliaExpressao(e->op1);
            v2 = AvaliaExpressao(e->op2);
            res = v1 - v2;
            break;
        case OPER_DIV:
            v1 = AvaliaExpressao(e->op1);
            v2 = AvaliaExpressao(e->op2);
            if(v2 == 0){
                fprintf(stderr, "Divisao por 0 encontrada.");
                exit(2);
            } 
            res = (float)v1 / (float)v2;
            break;
        default:
            printf("Operador nao reconhecido.\n");
    }

    return res;
}

int main() {
    InicializaLexer("./test/expcomplexa.mc");

    // arvore sintatica do programa
    Programa *p = AnalisePrograma();

    float resultado = AvaliaExpressao(p->e);

    printf("%.2f\n", resultado);

    DestroiPrograma(p);
    FinalizaLexer();
    return 0;
}
