#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Telefonica{
    int codigo;
    char nome[50];
    char data_nasci[50];
    char telefone[50];
    char email[50];
} Telefonica;

//==============================
typedef struct Lista{
    int tam, MAX;
    Telefonica *dados;
}Lista;
//==============================
void create_lista(Lista *l, int n){
    l->MAX = n;
    l->tam = 0;
    l->dados= (int*)malloc(n*sizeof(int));
}
//==============================


bool add(Lista *l,Telefonica dado){
    if(l->tam == l->MAX)
        return false;

    l->dados[l->tam] = dado;
    l->tam++;
    return true;
}
//==============================
Telefonica remove_at(Lista *l, int pos){
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
void ordenado_nome(Lista *l,int n){

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (strcmp(l->dados[j].nome,l->dados[j+1].nome)>0)
                swapi(&l->dados[j], &l->dados[j+1]);
}

void ordenado_data(Lista *l,int n){

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (strcmp(l->dados[j].data_nasci,l->dados[j+1].data_nasci)>0)
                swapi(&l->dados[j], &l->dados[j+1]);
}

void ordenado_email(Lista *l,int n){

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (strcmp(l->dados[j].email,l->dados[j+1].email)>0)
                swapi(&l->dados[j],&l->dados[j+1]);

}

void ordenado_telefone(Lista *l,int n){

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (strcmp(l->dados[j].telefone,l->dados[j+1].telefone)>0)
                swapi(&l->dados[j], &l->dados[j+1]);

}

void ordenado_codigo(Lista *l,int n){

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (l->dados[j].codigo > l->dados[j+1].codigo)
                swapi(&l->dados[j], &l->dados[j+1]);

}

int PesquisaBinaria_code(Lista X, int n, int x){

    int inicio = 0, fim = n-1, meio;

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

//==============================
void print_lista(Lista l){
    printf("\nSize: %d\n", l.tam);
    for(int i = 0; i < l.tam; i++)
        printf("[%d] - %d - %s - %s - %s - %s \n", i, l.dados[i].codigo,l.dados[i].data_nasci,l.dados[i].email,l.dados[i].nome,l.dados[i].telefone);
}
//==============================
void destroy_lista(Lista *l){
    free(l->dados);
}

#endif // LISTA_H_INCLUDED
