//
// Analisador sintático para MiniCalc
//

// Analisador descendente recursivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "lexer.h"

Token *t;

// Analisa uma declaracao de variavel, se houver. Se nao houver, retorna NULL
Declaracao* AnaliseDeclaracao() {
    t = ProximoToken();

    if (t->tipo != TOKEN_VAR)
        return NULL;

    Declaracao *res = (Declaracao*) malloc(sizeof(Declaracao));

    t = ProximoToken();

    if (t->tipo != TOKEN_IDENT) {
        fprintf(stderr, "Erro de sintaxe: identificador esperado\n");
        free(res);
        exit(2);
    }

    strcpy(res->nomeIdent, t->nome);

    t = ProximoToken();

    if (t->tipo != TOKEN_IGUAL) {
        fprintf(stderr, "Erro de sintaxe: '=' esperado\n");
        free(res);
        exit(2);
    }

    res->e = AnaliseExpressao();

    t = ProximoToken();

    if (t->tipo != TOKEN_PONTOVIRG) {
        fprintf(stderr, "Erro de sintaxe: ';' esperado no final da declaracao\n");
        free(res);
        exit(2);
    }

    return res;
}

// Analisador sintático do programa
// Assume que o analisador léxico foi inicializado com o código-fonte
Programa* AnalisePrograma() {
    Programa *res = (Programa*) malloc(sizeof(Programa));

    if (res == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria.");
        exit(1);
    }

    Declaracao *orig = AnaliseDeclaracao();   // origem da lista encadeada
    Declaracao *d = orig;
    if (d != NULL) {
        Declaracao *d2 = AnaliseDeclaracao();
        while (d2 != NULL) {
            d->next = d2;
            d = d2;
            d2 = AnaliseDeclaracao();
        }
        d->next = NULL;
    }

    res->decls = orig;

    if (t->tipo != TOKEN_PRINT) {
        fprintf(stderr, "Erro sintatico: palavra-chave 'print' esperada no inicio do programa.");
        exit(2);
    }

    // analisa a expressao seguinte
    res->e = AnaliseExpressao();

//    t = ProximoToken();
//
//    if (t->tipo != TOKEN_EOF) {
//        fprintf(stderr, "Erro sintatico: entrada adicional apos fim do programa.");
//        exit(2);
//    }

    return res;
}

Expressao* AnaliseExpressao() {
    // analisa a expressao
    Expressao *res = (Expressao*) malloc(sizeof(Expressao));

    // parentese abrindo
    t = ProximoToken();

    // se proximo token for constante inteira, retorne expressao constante
    if (t->tipo == TOKEN_INT) {
        res->oper = OPER_CONST;
        res->valor = t->valor;
        res->op1 = NULL;
        res->op2 = NULL;
        return res;
    }

    // se proximo token for um identificador, retorne uma expressao composta por 1 variavel
    if (t->tipo == TOKEN_IDENT) {
        res->oper = OPER_VAR;
        res->valor = 0;
        strcpy(res->nomeIdent, t->nome);
        res->op1 = NULL;
        res->op2 = NULL;
        return res;
    }

    if (t->tipo != TOKEN_ABREPAR && t->tipo != TOKEN_ABRECOL) {
        fprintf(stderr, "Erro sintatico: '(' ou '[' esperado");
        exit(2);
    }

    // primeiro operando
    res->op1 = AnaliseExpressao(); // Expressao*

    // operador
    t = ProximoToken();

    if (t->tipo != TOKEN_SOMA && t->tipo != TOKEN_MULT && t->tipo != TOKEN_SUB && t->tipo != TOKEN_DIV) {
        fprintf(stderr, "Erro sintatico: operador esperado");
        exit(2);
    }

    switch(t->tipo){
        case TOKEN_SOMA:
            res->oper = OPER_SOMA;
            break;
        case TOKEN_MULT:
            res->oper = OPER_MULT;
            break;
        case TOKEN_SUB:
            res->oper = OPER_SUB;
            break;
        case TOKEN_DIV:
            res->oper = OPER_DIV;
            break;
    }

    // segundo operando
    res->op2 = AnaliseExpressao();

    // parentese fechando
    t = ProximoToken();

    if (t->tipo != TOKEN_FECHAPAR && t->tipo != TOKEN_FECHACOL) {
        fprintf(stderr, "Erro sintatico: ')' ou ']' esperado");
        exit(2);
    }

    return res;
}

void DestroiExpressao(Expressao *e) {
    if (e->oper == OPER_SOMA || e->oper == OPER_MULT || e->oper == OPER_SUB || e->oper == OPER_DIV) {
        DestroiExpressao(e->op1);
        DestroiExpressao(e->op2);
        e->op1 = NULL;
        e->op2 = NULL;
    }

    free(e);
}

void DestroiDeclaracoes(Declaracao *d) {
    Declaracao *d2;
    while (d != NULL) {
        d2 = d->next;
        free(d);
        d = d2;
    }
}

void DestroiPrograma(Programa *p) {
    DestroiExpressao(p->e);
    p->e = NULL;
    free(p);
}
