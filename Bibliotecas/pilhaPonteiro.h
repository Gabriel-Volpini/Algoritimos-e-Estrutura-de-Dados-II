#ifndef PILHAPONTEIRO_H_INCLUDED
#define PILHAPONTEIRO_H_INCLUDED
///===========================================
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
///===========================================
typedef struct Celula{
    int dado;
    struct Celula *prox;
}Celula;
///===========================================
typedef struct{
    Celula *topo;
    int tam;
}Pilha;
///===========================================

void create_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}
///===========================================
void push( Pilha *p, int dado){
    Celula *temp = (Celula*)malloc(sizeof(Celula));
    temp->prox = p->topo;
    temp->dado = dado;
    p->topo = temp;
    p->tam++;
}
///===========================================
void printPilha(Pilha p){
    Celula *temp = p.topo;
    printf("\nTamanho: %d \n",p.tam);
    while(temp != NULL){
        printf("%d\n", temp->dado);
        temp = temp->prox;
    }
}
///===========================================
bool pilhaIsEmpty(Pilha p){
    return p.topo == NULL;
}
///===========================================
int pop(Pilha *p){
    if(pilhaIsEmpty(*p)){
        return -1;
    }
    Celula *temp = p->topo;
    p->topo = p->topo->prox;
    p->tam--;

    int dado = temp->dado;
    free(temp);
    return dado;
}
///===========================================

#endif // PILHAPONTEIRO_H_INCLUDED
