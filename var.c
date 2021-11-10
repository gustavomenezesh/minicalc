//
// Created by archi on 2021/10/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "var.h"
#include "lexer.h"

#define MAX_VARS      60

typedef struct tagItem {
    char nome[IDENT_TAM_MAX];
    int valor;
} Item;

Item tabela[MAX_VARS];
int tamanho = 0;


void AdicionaVar(char* nome, int valor) {
    if (tamanho >= MAX_VARS) {
        fprintf(stderr, "Tabela de variaveis esgotada.\n");
        exit(4);
    }
    tabela[tamanho].valor = valor;
    strcpy(tabela[tamanho].nome, nome);
    tamanho++;
}

bool ConsultaVar(char* nome, int* valor) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nome, tabela[i].nome) == 0) {
            *valor = tabela[i].valor;
            return true;
        }
    }
    return false;
}
