#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "structs.h"

void create_tabela(TabelaHash *th,int n){
    th->MAX = n;
    th->dados = (Telefonica*)malloc(n*sizeof(Telefonica));
    th->ocupado = (bool*)malloc(n*sizeof(bool));

    for(int i = 0 ; i< n ; i++){
        th->ocupado[i]=false;
    }
}

int funcaoHash(TabelaHash th, int codigo){
    return codigo%th.MAX;
}

void th_add(TabelaHash *th, Telefonica dado){
    int pos = funcaoHash(*th,dado.codigo);
    if(!th->ocupado[pos]){
        th->dados[pos]=dado;
        th->ocupado[pos]=true;
    }
    else{
        int inicio = pos;
        pos = (pos+1)%th->MAX;
        while(pos != inicio && th->ocupado[pos]){
            pos = (pos+1)%th->MAX;
        }

        if(!th->ocupado[pos]){
            th->dados[pos]=dado;
            th->ocupado[pos]=true;
        }
        else{
            printf("\nTabela Cheia!!\n");
        }

    }
}

void remover_th(TabelaHash *th, int codigo){
    int pos = funcaoHash(*th, codigo);
    Telefonica vazia;

    if(!th->ocupado[pos]){
        printf("Codigo nao encontrado\n");
    }else{
        th->ocupado[pos] = false;
        th->dados[pos] = vazia;
    }
}

void print_th(TabelaHash th){
    printf("[POSICAO] - > CODIGO - NOME - TELEFONE - DATA DE NASCIMENTO - EMAIL\n");
    
    for(int i = 0 ; i< th.MAX ; i++){
        if(th.ocupado[i]){
            printf("[   %d   ] - > %d - %s - %s - %s - %s\n",i,th.dados[i].codigo,th.dados[i].nome,th.dados[i].telefone,th.dados[i].data_nasci,th.dados[i].email);

        }
        else{
            printf("[   %d   ] - > Livre\n",i);
        }
    }
}

void print_th_Element (TabelaHash th, int codigo){
    int i = funcaoHash(th, codigo);

    if(th.ocupado[i]){
        printf("[POSICAO] - > CODIGO - NOME - TELEFONE - DATA DE NASCIMENTO - EMAIL\n");
        printf("[   %d   ] - > %d - %s - %s - %s - %s\n",i,th.dados[i].codigo,th.dados[i].nome,th.dados[i].telefone,th.dados[i].data_nasci,th.dados[i].email);
    }
    else{
        printf("Nao encontrado..\n",i);
    }
}

void scanf_th_onFile(TabelaHash *tabela, FILE *file){
    int size = 0;
    Telefonica dado;
    fscanf(file, "\nSize: %d\n", &size);

    for(int i = 0; i < size; i++){
        fscanf(file, "\nCODIGO: %d\nNOME: %s \nTELEFONE:%s \nDATA DE NASCIMENTO: %s\nEMAIL: %s\n", &dado.codigo, &dado.nome, &dado.telefone, &dado.data_nasci, &dado.email);
        th_add(tabela,dado);
    }
}

void destroy_th(TabelaHash *th){
    free(th->dados);
    free(th->dados);
}


#endif // HASH_H_INCLUDED
