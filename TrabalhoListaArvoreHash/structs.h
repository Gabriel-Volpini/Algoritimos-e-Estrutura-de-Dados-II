#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <stdbool.h>

typedef struct Telefonica{
    int codigo;
    char nome[50];
    char data_nasci[50];
    char telefone[50];
    char email[50];
} Telefonica;

typedef struct Lista{
    int tam, MAX;
    Telefonica *dados;
}Lista;

typedef struct TabelaHash{
    Telefonica *dados;
    int MAX;
    bool *ocupado;
}TabelaHash;

typedef struct No{
    Telefonica dado;
    struct No *esq, *dir;
}No;
#endif // STRUCTS_H_INCLUDED
