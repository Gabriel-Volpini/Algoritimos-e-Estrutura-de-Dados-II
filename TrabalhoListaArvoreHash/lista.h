#ifndef PESQUISA_H_INCLUDED
#define PESQUISA_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

//==============================
void create_lista(Lista *l, int n){
    l->MAX = n;
    l->tam = 0;
    l->dados= (Telefonica*)malloc(n*sizeof(Telefonica));
}
//==============================

bool lista_add(Lista *l,Telefonica dado){
    if(l->tam == l->MAX)
        return false;

    l->dados[l->tam] = dado;
    l->tam++;
    return true;
}

//==============================
Telefonica remove_lista_at(Lista *l, int pos){
    Telefonica X;
    X.codigo=-1;
    if(pos < 0 || pos >= l->tam )
        return X;

    Telefonica dado = l->dados[pos];

    l->tam--;

    for(int i = pos; i < l->tam; i++)
        l->dados[i] = l->dados[i+1];

    return dado;
}
//==============================
void swapi(Telefonica *a, Telefonica *b){
    Telefonica temp = *a;
    *a = *b;
    *b = temp;
}
//=============================
void ordenado_nome(Lista *l){

    for (int i=0; i<l->tam - 1; i++)
        for (int j=0; j<l->tam -i-1; j++)
            if (strcmp(l->dados[j].nome,l->dados[j+1].nome)>0)
                swapi(&l->dados[j], &l->dados[j+1]);
}

void ordenado_data(Lista *l){

    for (int i=0; i<l->tam-1; i++)
        for (int j=0; j<l->tam-i-1; j++)
            if (strcmp(l->dados[j].data_nasci,l->dados[j+1].data_nasci)>0)
                swapi(&l->dados[j], &l->dados[j+1]);
}

void ordenado_email(Lista *l){

    for (int i=0; i<l->tam-1; i++)
        for (int j=0; j<l->tam-i-1; j++)
            if (strcmp(l->dados[j].email,l->dados[j+1].email)>0)
                swapi(&l->dados[j],&l->dados[j+1]);

}

void ordenado_telefone(Lista *l){

    for (int i=0; i<l->tam-1; i++)
        for (int j=0; j<l->tam-i-1; j++)
            if (strcmp(l->dados[j].telefone,l->dados[j+1].telefone)>0)
                swapi(&l->dados[j], &l->dados[j+1]);

}

void ordenado_codigo(Lista *l){

    for (int i=0; i<l->tam-1; i++)
        for (int j=0; j<l->tam-i-1; j++)
            if (l->dados[j].codigo > l->dados[j+1].codigo)
                swapi(&l->dados[j], &l->dados[j+1]);

}

int PesquisaBinaria_codigo(Lista X, int x){

    int inicio = 0, fim = X.tam, meio;

    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(X.dados[meio].codigo == x)
            return meio;
        if(X.dados[meio].codigo < x)
            inicio = meio + 1;
        else
            fim = meio-1;
    }
    return -1;
}

int PesquisaBinaria_nome(Lista X, char nomeP[]){
    int inicio = 0, fim = X.tam-1, meio;
    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(strcmp(X.dados[meio].nome,nomeP)==0)
            return meio;
        if(strcmp(X.dados[meio].nome,nomeP)<0)
            inicio = meio + 1;
        else
            fim = meio-1;
    }

    return -1;
}

int PesquisaBinaria_data(Lista X,char nomeP[]){

    int inicio = 0, fim = X.tam-1, meio;


    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(strcmp(X.dados[meio].data_nasci,nomeP)==0)
            return meio;
        if(strcmp(X.dados[meio].data_nasci,nomeP)<0)
            inicio = meio + 1;
        else
            fim = meio-1;
    }

    return -1;
}

int PesquisaBinaria_email(Lista X,char nomeP[]){

    ordenado_email(&X);
    int inicio = 0, fim = X.tam-1, meio;


    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(strcmp(X.dados[meio].email,nomeP)==0)
            return meio;
        if(strcmp(X.dados[meio].email,nomeP)<0)
            inicio = meio + 1;
        else
            fim = meio-1;
    }

    return -1;
}




//==============================
void print_lista(Lista l){
    printf("\nSize: %d\n", l.tam);
    for(int i = 0; i < l.tam; i++)
        printf("\n[%d]CODIGO: %d\nNOME: %s \nTELEFONE:%s \nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", i, l.dados[i].codigo,l.dados[i].nome,l.dados[i].telefone,l.dados[i].data_nasci,l.dados[i].email);
}
void print_lista_element(Lista l, int i){
    printf("\n[%d]CODIGO: %d\nNOME: %s \nTELEFONE:%s \nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", i, l.dados[i].codigo,l.dados[i].nome,l.dados[i].telefone,l.dados[i].data_nasci,l.dados[i].email);
}
//==============================
void destroy_lista(Lista *l){
    free(l->dados);
}

#endif // PESQUISA_H_INCLUDED
