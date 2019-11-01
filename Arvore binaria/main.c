#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "Arvore.h"

Registro ConverterTelefonicaEmRegistro(Telefonica T){
        Registro ARVORE;

        ARVORE.chave = ARVORE.codigo = T.codigo;
        strcpy(ARVORE.nome,T.nome);
        strcpy(ARVORE.data_nasci,T.data_nasci);
        strcpy(ARVORE.telefone,T.telefone);
        strcpy(ARVORE.email,T.email);
        return ARVORE;
}

void remover(int x,int n,Lista *l, ArvoreBinaria *A){

    for(int i = 0 ; i < n ; i++){
        if(l->dados[i].codigo == x){
            remove_at(l,i);
        }
        Remover_Arvore(A, x);
    }
}

void adiciona(Lista *X, ArvoreBinaria *A){
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
        printf("Digite o email:\n");
        fflush(stdin);
        gets(TEMP.email);
        fflush(stdin);

        Inserir_Arvore(A,ConverterTelefonicaEmRegistro(TEMP));

        add(X,TEMP);
}

void menu(int selecionado, Lista *X, int n, ArvoreBinaria *A){
    int x;
    switch(selecionado){
    case 1:
            system("cls");
            adiciona(X, A);
            printf("LISTA: ");
            print_lista(*X);
            printf("ARVORE: ");
            ImprimirPreOrdem_Arvore(A->raiz);
            getch();
            break;

        case 2:
            system("cls");
            printf("Insira codigo do contato a ser removido: \n");
            scanf("%d",&x);
            remover(x,n,X,A);
            print_lista(*X);
            getch();
            break;

        case 3:
            system("cls");
            ordenado_nome(X,n);
            print_lista(*X);
            getch();
            break;

        case 4:
            system("cls");
            ordenado_nome(X,n);
            print_lista(*X);
            getch();
            break;

        case 5:
            system("cls");
            printf("Codigo a ser pesquisado:");
            int y,res;
            scanf("%d",&y);
            res = PesquisaBinaria_code(*X,n,y);
            printf("\nCODIGO: %d",X->dados[res].codigo);
            printf("\nNOME: %s\n",X->dados[res].nome);
            printf("DATA DE NACIMENTO: %s\n",X->dados[res].data_nasci);
            printf("EMAIL: %s\n",X->dados[res].email);
            printf("TELEFONE: %s\n\n",X->dados[res].telefone);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 0:
            printf("Fechando..");
            break;
        default:
        system("cls");
        printf("Valor invalido..\n");
    }
}

int main()
{
    int n;
    printf("Insira o limite da agenda: ");
    scanf("%d",&n);
    Lista X;
    ArvoreBinaria A;
    create_lista(&X,n);
    Inicializar_Arvore(&A);

    int selecionado = 100;


    while(selecionado!=0){
        printf("=========================================================\n\n");
        printf("1 - Inserir contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Imprimir ordenado por nome\n");
        printf("4 - Imprimir ordenado por data de nascimento\n");
        printf("5 - Pesquisar por codigo\n");
        printf("6 - Pesquisar por nome\n");
        printf("7 - Pesquisar por data de nascimento\n");
        printf("8 - Pesquisar por email\n");
        printf("0 - Sair\n");
        printf("\n=========================================================\n");
        scanf("%d",&selecionado);
        menu(selecionado, &X, n, &A);
    }


    return 0;
}
