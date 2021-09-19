//
// Created by archi on 2021/09/07.
//

#ifndef MINICALC_ARQ_H
#define MINICALC_ARQ_H

typedef struct tagBuffer {
    char *cont;
    long tam;
} Buffer;

Buffer* CriaBuffer(char *nome);
void DestroiBuffer(Buffer *b);

#endif //MINICALC_ARQ_H
