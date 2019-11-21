#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pesquisa.h"

typedef struct TabelaHash{
    Telefonica *dados;
    int MAX;
    bool *ocupado;
}TabelaHash;

void create_tabela(TabelaHash *th,int n){
    th->MAX = n;
    th->dados = (Telefonica*)malloc(n*sizeof(Telefonica));
    th->ocupado = (bool*)malloc(n*sizeof(bool));

    for(int i = 0 ; i< n ; i++){
        th->ocupado[i]=false;
    }
}

int funcaoHash(TabelaHash th, Contato dado){
    return dado.cod%th.MAX;
}

void inserir(TabelaHash *th, Contato dado){
    int pos = funcaoHash(*th,dado);
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

void print_th(TabelaHash th){
    for(int i = 0 ; i< th.MAX ; i++){
        if(th.ocupado[i]){
            printf("[%d] - > %d - %s\n",i,th.dados[i].cod,th.dados[i].nome);
        }
        else{
            printf("[%d] - > Livre\n",i);
        }
    }
}



#endif // HASH_H_INCLUDED
