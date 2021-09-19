// Le um arquivo completo para um buffer em memoria

#include <stdio.h>
#include <stdlib.h>

#include "arq.h"


long tamanho_arq(FILE *f) {
    fseek(f, 0, SEEK_END);
    long result = ftell(f);
    rewind(f);

    return result;
}

Buffer* CriaBuffer(char *nome) {
    FILE *f = fopen(nome, "r");

    if (f == NULL) {
        fprintf(stderr, "Erro abrindo arquivo: %s\n", nome);
        exit(1);
    }

    long tam = tamanho_arq(f);
    Buffer *b = malloc(sizeof(Buffer));

    if (b == NULL) {
        fprintf(stderr, "Erro alocando estrutura para o buffer");
        exit(1);
    }

    b->tam = tam;
    b->cont = (char*) malloc(tam);

    if (b->cont == NULL) {
        fprintf(stderr, "Erro alocando memoria com %ld bytes\n", tam);
        exit(1);
    }

    fread(b->cont, tam, 1, f);
    fclose(f);

    return b;
}

void DestroiBuffer(Buffer *b) {
    free(b->cont);
    b->cont = NULL;
    free(b);
}
