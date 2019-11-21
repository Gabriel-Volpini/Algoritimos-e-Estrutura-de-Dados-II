#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "lista.h"

void adiciona(Lista *lista){
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
//==================================
}
void remover(Lista *lista){
    int codigo, posicao;
    printf("Insira o codigo a ser removido\n");
    scanf("%d",&codigo);
//=============LISTA=================
    posicao = PesquisaBinaria_codigo(*lista, codigo);
    remove_lista_at(lista, posicao);
//==================================
}
void imprimir_Nome(Lista *lista){
//=============LISTA=================
    ordenado_nome(lista);
    print_lista(*lista);
//==================================
}

void imprimir_Data(Lista *lista){
//=============LISTA=================
    ordenado_data(lista);
    print_lista(*lista);
//==================================
}

void pesquisar_menu(Lista *lista){
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
void pesquisar_binaria(Lista *lista){
    int selecionado;
    int valor;
    int posicao;
    printf("1 - Codigo\n2 - Nome\n3 - Data\n4 - email\n5 - telefone\n");
    scanf("%d", &selecionado);
    switch(selecionado){
        case 1:
            ordenado_codigo(lista);
            printf("digite o valor: ");
            scanf("%d", &valor);
            posicao = PesquisaBinaria_codigo(*lista, valor);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Valor invalido\n");
            break;
    }
    print_lista_element(*lista, posicao);
}

int main()
{
    Lista lista;
    create_lista(&lista, 10);

    Telefonica objeto;
    adiciona(&lista);
    adiciona(&lista);

    pesquisar_menu(&lista);

    remover(&lista);
    print_lista(lista);

    return 0;
}
