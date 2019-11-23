#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "lista.h"

//! 1 - criar contato
//! 2 - excluir contato
//// 3 - listar por ordenado_nome
//// 4 - listar por data de nascimento
//! 5 - pesquisar por tudo
//! 6 - acarregar dados do arquivo 
//// 7 - salvar em arquivo
//! 8 - sair


void adiciona(Lista *lista){ //TODO arvore e hash
        Telefonica TEMP;
        printf("Digite o codigo:\n");
            scanf("%d",&TEMP.codigo);
            fflush(stdin);
        printf("Digite o nome:\n");
            gets(TEMP.nome);
            fflush(stdin);
        printf("Digite a data de nascimento:\n");
            gets(TEMP.data_nasci);
            fflush(stdin);
        printf("Digite o telefone:\n");
            gets(TEMP.telefone);
            fflush(stdin);
        printf("Digite o email:\n");
            gets(TEMP.email);
            fflush(stdin);
        fflush(stdin);
//=============LISTA=================
        lista_add(lista,TEMP);
//===================================
}
void remover(Lista *lista){ //TODO arvore e hash
    int codigo, posicao;
    printf("Insira o codigo a ser removido\n");
    scanf("%d",&codigo);
//=============LISTA=================
    posicao = PesquisaBinaria_codigo(*lista, codigo);
    remove_lista_at(lista, posicao);
//===================================
}
void imprimir_Nome(Lista *lista){
//=============LISTA=================
    ordenado_nome(lista);
    print_lista(*lista);
//===================================
}

void imprimir_Data(Lista *lista){
//=============LISTA=================
    ordenado_data(lista);
    print_lista(*lista);
//===================================
}

void pesquisar_menu(Lista *lista){ //TODO arvore e hash
    int selecionado;
    printf("1 - pesquisa binaria\n2 - pesquisa em arvore\n3 - pesquisa em hash\n"); 
    scanf("%d",&selecionado);
    switch(selecionado){
        case 1:
        pesquisar_binaria(lista);
        break;
    default:
        printf("Valor invalido\n");
    }
}

//=============LISTA=================
void pesquisar_binaria(Lista *lista){
    int selecionado,posicaoDoElementoPesquisado, scanfIntValue;
    char scanfStringVlue[100];

    printf("1 - Codigo\n2 - Nome\n3 - Data\n4 - email\n5 - telefone\n");
    scanf("%d", &selecionado);
    switch(selecionado){
        case 1:
            ordenado_codigo(lista);
            printf("digite o codigo: ");
            scanf("%d", &scanfIntValue);
            posicaoDoElementoPesquisado = PesquisaBinaria_codigo(*lista, scanfIntValue);
            break;
        case 2:
            ordenado_nome(lista);
            printf("digite o nome:\n");
            scanf(" %s",&scanfStringVlue);
            posicaoDoElementoPesquisado = PesquisaBinaria_nome(*lista, scanfStringVlue);
            break;
        case 3:
            ordenado_data(lista);
            printf("digite a data:\n");
            scanf(" %s",&scanfStringVlue);
            posicaoDoElementoPesquisado = PesquisaBinaria_data(*lista, scanfStringVlue);
            break;
        case 4:
            ordenado_email(lista);
            printf("digite o email:\n");
            scanf(" %s",&scanfStringVlue);
            posicaoDoElementoPesquisado = PesquisaBinaria_email(*lista, scanfStringVlue);
            break;
        case 5:
            ordenado_telefone(lista);
            printf("digite o telefone:\n");
            scanf(" %s",&scanfStringVlue);
            posicaoDoElementoPesquisado = PesquisaBinaria_telefone(*lista, scanfStringVlue);
            break;
        default:
            printf("Valor invalido\n");
            break;
    }
    posicaoDoElementoPesquisado != -1 ? 
        print_lista_element(*lista, posicaoDoElementoPesquisado) :
        printf("Elemento nao encontrado\n");
}
//===================================

void salvar(Lista *lista){
    char nomeArquivo[50];
    printf("insira o nome do arquivo (sem .txt)\n");
    scanf(" %s",&nomeArquivo);
    strcat(nomeArquivo,".txt");
    FILE *arquivo = fopen(nomeArquivo,"w");
    print_lista_onFile(*lista, arquivo);
    fclose(arquivo);
}

void abrirArquivo(Lista *lista){//TODO arvore e hash
    char nomeArquivo[50];
    printf("insira o nome do arquivo (sem .txt)\n");
    scanf(" %s",&nomeArquivo);
    strcat(nomeArquivo,".txt");
    FILE *arquivo = fopen(nomeArquivo,"r");
    scanf_lista_onFile(lista, arquivo);
    if(arquivo == NULL){
        printf("Arquivo nao encontrado\n");
        return;
    }

    fclose(arquivo);
}

int main(){
    Lista lista;
    create_lista(&lista, 10);

    abrirArquivo(&lista);
    pesquisar_menu(&lista);


//============ FREE ==================
    destroy_lista(&lista);
//====================================
    return 0;
}
