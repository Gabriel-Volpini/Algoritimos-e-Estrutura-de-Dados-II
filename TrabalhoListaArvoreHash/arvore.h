#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

void criar_Arvore(ArvoreBinaria *arvore){
    arvore->raiz = NULL;
}
//===================================================================

No* InserirNo(No *no, Telefonica dado){
    if (no == NULL) {
      no = (No*)malloc(sizeof(No));
      no->dado = dado;
      no->esq = NULL;
      no->dir = NULL;
    }
    else if (dado.codigo < no->dado.codigo) no->esq = InserirNo (no->esq, dado);
    else if (dado.codigo > no->dado.codigo) no->dir = InserirNo (no->dir, dado);
    else printf("Erro: Registro ja existente!");
    return no;
}
bool arvore_add(ArvoreBinaria *arvore, Telefonica dado){
    arvore->raiz = InserirNo(arvore->raiz, dado);
}
//===================================================================

Telefonica PesquisarNo_Codigo(No *no, int chave){
    if (no == NULL) {
        Telefonica r;
        r.codigo = -1;
        return r;
    }
    else if (chave < no->dado.codigo) return PesquisarNo_Codigo(no->esq, chave);
    else if (chave > no->dado.codigo) return PesquisarNo_Codigo(no->dir, chave);
    else return no->dado;
}

Telefonica Pesquisar_por_code (ArvoreBinaria *arvore, int chave){
    return PesquisarNo_Codigo(arvore->raiz, chave);
}

Telefonica PesquisarNo_Nome(No *no, char chave[50]){
    if (no == NULL) {
        Telefonica r;
        r.codigo = -1;
        return r;
    }
    else if (strcmp(chave,no->dado.nome)<0) return PesquisarNo_Nome(no->esq, chave);
    else if (strcmp(chave,no->dado.nome)>0) return PesquisarNo_Nome(no->dir, chave);
    else return no->dado;
}

Telefonica Pesquisar_por_Nome (ArvoreBinaria *arvore, char chave[50]){
    return PesquisarNo_Nome(arvore->raiz, chave);
}

Telefonica PesquisarNo_Email(No *no, char chave[50]){
    if (no == NULL) {
        Telefonica r;
        r.codigo = -1;
        return r;
    }
    else if (strcmp(chave,no->dado.email)<0) return PesquisarNo_Email(no->esq, chave);
    else if (strcmp(chave,no->dado.email)>0) return PesquisarNo_Email(no->dir, chave);
    else return no->dado;
}

Telefonica Pesquisar_por_Email (ArvoreBinaria *arvore, char chave[50]){
    return PesquisarNo_Email(arvore->raiz, chave);
}

Telefonica PesquisarNo_Data(No *no, char chave[50]){
    if (no == NULL) {
        Telefonica r;
        r.codigo = -1;
        return r;
    }
    else if (strcmp(chave,no->dado.data_nasci)<0) return PesquisarNo_Data(no->esq, chave);
    else if (strcmp(chave,no->dado.data_nasci)>0) return PesquisarNo_Data(no->dir, chave);
    else return no->dado;
}

Telefonica Pesquisar_por_Data (ArvoreBinaria *arvore, char chave[50]){
    return PesquisarNo_Data(arvore->raiz, chave);
}

Telefonica PesquisarNo_Telefone(No *no, char chave[50]){
    if (no == NULL) {
        Telefonica r;
        r.codigo = -1;
        return r;
    }
    else if (strcmp(chave,no->dado.telefone)<0) return PesquisarNo_Data(no->esq, chave);
    else if (strcmp(chave,no->dado.telefone)>0) return PesquisarNo_Data(no->dir, chave);
    else return no->dado;
}

Telefonica Pesquisar_por_Telefone (ArvoreBinaria *arvore, char chave[50]){
    return PesquisarNo_Telefone(arvore->raiz, chave);
}

//===================================================================

No* antecessor (No *no, No *a) {
    if (a->dir != NULL) a->dir = antecessor (no, a->dir);
    else {
        no->dado = a->dado; // TROCA O DADO COM O ANTECESSOR
        No *temp = a;
        a = a->esq;
        free(temp);
    }
    return a;
}

No* RemoverNo (No *no, int codigo) {
    if (no == NULL) printf("Erro: Telefonica nao encontrado");
    else if (codigo < no->dado.codigo) no->esq = RemoverNo (no->esq, codigo);
    else if (codigo > no->dado.codigo) no->dir = RemoverNo (no->dir, codigo);
    else { 
      if(no->dir == NULL || no->esq == NULL){
        No *temp = no;
        if (no->dir == NULL) no = no->esq;
        else no = no->dir;
        free(temp);
      } 
      else no->esq = antecessor (no, no->esq);
    }
    return no;
}
void remover_arvore (ArvoreBinaria *arvore, int codigo) {
    arvore->raiz = RemoverNo(arvore->raiz, codigo);
}

//===================================================================
void scanf_arvore_onFile(ArvoreBinaria *arvore, FILE *file){
    int size = 0;
    Telefonica dado;
    fscanf(file, "\nSize: %d\n", &size);

    for(int i = 0; i < size; i++){
        fscanf(file, "\nCODIGO: %d\nNOME: %s \nTELEFONE:%s \nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", &dado.codigo, &dado.nome, &dado.telefone, &dado.data_nasci, &dado.email);
        arvore_add (arvore, dado);
    }
}
//===================================================================
void print_arvore(ArvoreBinaria *arvore){
    int selecionado;
    printf("1 - Pre ordem\n2 - Em ordem\n3 - Pos ordem\n");
    scanf("%d",&selecionado);
    switch (selecionado)
    {
    case 1:
        ImprimirPreOrdem(arvore->raiz);
        break;
    case 2:
        ImprimirEmOrdem(arvore->raiz);
        break;
    case 3:
        ImprimirPosOrdem(arvore->raiz);
        break;
    
    default:
        printf("Valor invalido\n");
        break;
    }
}

void ImprimirPreOrdem(No *no){
    if (no != NULL) {
      printf("CODIGO: %i \nNOME: %s\nTELEFONE: %s\nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", no->dado.codigo,no->dado.nome,no->dado.telefone,no->dado.data_nasci,no->dado.email);
      printf("======================\n");
      ImprimirPreOrdem (no->esq);
      ImprimirPreOrdem (no->dir);
    }
}

void ImprimirEmOrdem(No *no){
    if (no != NULL) {
      ImprimirEmOrdem (no->esq);
      printf("CODIGO: %i \nNOME: %s\nTELEFONE: %s\nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", no->dado.codigo,no->dado.nome,no->dado.telefone,no->dado.data_nasci,no->dado.email);
      printf("======================\n");
      ImprimirEmOrdem (no->dir);
    }
}

void ImprimirPosOrdem(No *no){
    if (no != NULL) {
      ImprimirPosOrdem (no->esq);
      ImprimirPosOrdem (no->dir);
      printf("CODIGO: %i \nNOME: %s\nTELEFONE: %s\nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", no->dado.codigo,no->dado.nome,no->dado.telefone,no->dado.data_nasci,no->dado.email);
      printf("======================\n");
    }
}

void Imprimir_arvore_element(Telefonica  no){
    printf("CODIGO: %i \nNOME: %s\nTELEFONE: %s\nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", no.codigo,no.nome,no.telefone,no.data_nasci,no.email);
    printf("======================\n");
}

void destroy_arvore(ArvoreBinaria *arvore){
    remover_arvore(arvore->raiz, arvore->raiz->dado.codigo);
}


#endif // ARVORE_H_INCLUDED