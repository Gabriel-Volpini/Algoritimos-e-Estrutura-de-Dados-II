#ifndef FILA_PONTEIRO_H_INCLUDED
#define FILA_PONTEIRO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    typedef struct Celula{
        int dado;
        struct Celula *prox;
    }Celula;
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    typedef struct Fila{
        Celula *inicio,*fim;
        int tamanho;
    }Fila;
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    bool FilaIsEmpty(Fila f){
        return f.inicio == f.fim;
    }
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    void createFila(Fila *f){
        Celula *temp =(Celula*)malloc(sizeof(Celula));
        if(temp == NULL){ printf("MEMORIA CHEIA // ERRO DE ALOCAÇÃO"); return;}
        temp->prox = NULL;
        f->inicio = f->fim = temp;
        f->tamanho = 0;
    }
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    void FilaAdd(Fila *f, int valor){
        Celula *temp = (Celula *)malloc(sizeof(Celula));
        temp->dado = valor;
        temp->prox = NULL;
        f->fim->prox = temp;
        f->fim = temp;
        f->tamanho++;
    }
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    void printFila(Fila *f){
        Celula *proxima = f->inicio->prox;
        printf("\nTAMANHO: %d:\n", f->tamanho);
        while(proxima != NULL){
            printf("%d\n",proxima->dado);
            proxima = proxima->prox;
        }
    }
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    int FilaRemove(Fila *f){
        if(FilaIsEmpty(*f)){
            return -1;
        }
        Celula *temp =f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
        f->tamanho--;
        return f->inicio->dado;
    }
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    void FilaDestroy (Fila *f){
        while(FilaIsEmpty(*f)){
            FilaRemove(f);
        }
        free(f->inicio);
    }
///&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#endif // FILA_PONTEIRO_H_INCLUDED
