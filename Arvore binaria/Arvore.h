#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
// DEFINIÇÃO DO TIPO REGISTRO

typedef struct Registro{
    int chave;
    int codigo;
    char nome[50];
    char data_nasci[50];
    char telefone[50];
    char email[50];
}Registro;

// DEFINIÇÃO DO TIPO NO
typedef struct No{
    Registro dado;
    struct No *esq, *dir;
}No;
//===================================================================
// DEFINIÇÃO DO TIPO ÁRVORE
typedef struct {
    No *raiz;
}ArvoreBinaria;
//===================================================================
void Inicializar_Arvore(ArvoreBinaria *arvore){
    arvore->raiz = NULL;
}
//===================================================================
Registro PesquisarNoArvore_Codigo(No *no, int chave){
    if (no == NULL) {
        Registro r;
        r.chave = -1;
        return r;
    }
    else if (chave < no->dado.chave) return PesquisarNoArvore_Codigo (no->esq, chave);
    else if (chave > no->dado.chave) return PesquisarNoArvore_Codigo (no->esq, chave);
    else return no->dado;
}

Registro Pesquisar_Codigo (ArvoreBinaria *arvore, int chave){
    return PesquisarNoArvore_Codigo(arvore->raiz, chave);
}
//===================================================================
No* InserirNo_Arvore(No *no, Registro dado){
    if (no == NULL) {
      no = (No*)malloc(sizeof(No));
      no->dado = dado;
      no->esq = NULL;
      no->dir = NULL;
    }
    else if (dado.chave < no->dado.chave) no->esq = InserirNo_Arvore (no->esq, dado);
    else if (dado.chave > no->dado.chave) no->dir = InserirNo_Arvore (no->dir, dado);
    else printf("Erro: Registro ja existente!");
    return no;
}

bool Inserir_Arvore(ArvoreBinaria *arvore, Registro dado){
    arvore->raiz = InserirNo_Arvore(arvore->raiz, dado);
}
//===================================================================
No* antecessor_Arvore (No *no, No *a) {
    if (a->dir != NULL) a->dir = antecessor_Arvore (no, a->dir);
    else {
        no->dado = a->dado; // TROCA O DADO COM O ANTECESSOR
        No *temp = a;
        a = a->esq;
        free(temp);
    }
    return a;
}

No* RemoverNo_Arvore (No *no, int chave) {
    if (no == NULL) printf("Erro: Registro nao encontrado");
    else if (chave < no->dado.chave) no->esq = RemoverNo_Arvore (no->esq, chave);
    else if (chave > no->dado.chave) no->dir = RemoverNo_Arvore (no->dir, chave);
    else { // REMOÇÃO CASO 1 E CASO 2
      if(no->dir == NULL || no->esq == NULL){
        No *temp = no;
        if (no->dir == NULL) no = no->esq;
        else no = no->dir;
        free(temp);
      } // REMOÇÃO CASO 3
      else no->esq = antecessor_Arvore (no, no->esq);
    }
    return no;
}
void Remover_Arvore (ArvoreBinaria *arvore, int chave) {
    arvore->raiz = RemoverNo_Arvore(arvore->raiz, chave);
}
//===================================================================
void ImprimirPreOrdem_Arvore(No *no){
    if (no != NULL) {
      printf("%i\n", no->dado.chave);
      ImprimirPreOrdem_Arvore (no->esq);
      ImprimirPreOrdem_Arvore (no->dir);
    }
}

void ImprimirEmOrdem_Arvore(No *no){
    if (no != NULL) {
      ImprimirEmOrdem_Arvore (no->esq);
      printf("%i\n", no->dado.chave);
      ImprimirEmOrdem_Arvore (no->dir);
    }
}

void ImprimirPosOrdem_Arvore(No *no){
    if (no != NULL) {
      ImprimirPosOrdem_Arvore (no->esq);
      ImprimirPosOrdem_Arvore(no->dir);
      printf("%i\n", no->dado.chave);
    }
}

#endif // ARVORE_H_INCLUDED
