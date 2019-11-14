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

//  void remover(int x,int n,Lista *l, ArvoreBinaria *A){

//      for(int i = 0 ; i < n ; i++){
//          if(l->dados[i].codigo == x){
//              remove_at(l,i);
//          }
//          Remover_Arvore(A, x);
//      }
//  }

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

// void pesquisaPorCodigo(Lista *X, ArvoreBinaria *A, int tamanho){
//     int selecionado;
//     int y,resBinario;
//     Registro resArvore;
//     printf("1 - PesquisaBinaria\n2 - Pesquisa em arvore:\n");
//     scanf("%d",&selecionado);
//     printf("Codigo a ser pesquisado:");
//     scanf("%d",&y);
//     switch(selecionado){
//         case 1:
//             resBinario = PesquisaBinaria_codigo(*X,tamanho,y);
//             printf("\nCODIGO: %d",X->dados[resBinario].codigo);
//             printf("\nNOME: %s\n",X->dados[resBinario].nome);
//             printf("DATA DE NACIMENTO: %s\n",X->dados[resBinario].data_nasci);
//             printf("EMAIL: %s\n",X->dados[resBinario].email);
//             printf("TELEFONE: %s\n\n",X->dados[resBinario].telefone);
//             break;
//         case 2:
//             resArvore = Pesquisar_Codigo(A, y);
//             printf("\nCODIGO: %d",resArvore.codigo);
//             printf("\nNOME: %s\n",resArvore.nome);
//             printf("DATA DE NACIMENTO: %s\n",resArvore.data_nasci);
//             printf("EMAIL: %s\n",resArvore.email);
//             printf("TELEFONE: %s\n\n",resArvore.telefone);
//             break;
//         default:
//             printf("Valor invalido\n");
//             break;
//     }
//     return;
// }

// void pesquisaPorNome(Lista *X, ArvoreBinaria *A, int tamanho){
//     int selecionado;
//     int resBinario;
//     char y[100];
//     Registro resArvore;

//     printf("1 - PesquisaBinaria\n2 - Pesquisa em arvore:\n");
//     scanf("%d",&selecionado);
//     printf("Nome a ser pesquisado:");
//     scanf(" %s",&y);

//     switch(selecionado){
//         case 1:
//             resBinario = PesquisaBinaria_nome(*X,tamanho,y);
//             printf("\nCODIGO: %d",X->dados[resBinario].codigo);
//             printf("\nNOME: %s\n",X->dados[resBinario].nome);
//             printf("DATA DE NACIMENTO: %s\n",X->dados[resBinario].data_nasci);
//             printf("EMAIL: %s\n",X->dados[resBinario].email);
//             printf("TELEFONE: %s\n\n",X->dados[resBinario].telefone);
//             break;
//         case 2:

//             break;
//         default:
//             printf("Valor invalido\n");
//             break;
//     }
//     return;
// }

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
            // system("cls");
            // printf("Insira codigo do contato a ser removido: \n");
            // scanf("%d",&x);
            // remover(x,n,X,A);
            // print_lista(*X);
            // getch();
            // system('PAUSE');
            break;

        case 3:
            system("cls");
            ordenado_nome(X,n);
            print_lista(*X);
            getch();
            system('PAUSE');
            break;

    //     case 4:
    //         system("cls");
    //         ordenado_nome(X,n);
    //         print_lista(*X);
    //         getch();
    //         system('PAUSE');
    //         break;

    //     case 5:
    //         system("cls");
    //         pesquisaPorCodigo(X,A,n);
    //         system('PAUSE');
    //         break;
    //     case 6:
    //          system("cls");
    //          pesquisaPorNome(X,A,n);
    //         system('PAUSE');
    //         break;
    //     case 7:
    //         system('PAUSE');
    //         break;
    //     case 8:
    //         break;
    //     case 0:
    //
         default:
         break;
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


    while(1){
        system("cls");
        ImprimirPreOrdem_Arvore(A.raiz);
        print_lista(X);
        printf("=========================================================\n\n");
        printf("1 - Inserir contato\n");
        // printf("2 - Remover contato\n");
        printf("3 - Imprimir ordenado por nome\n");
        printf("4 - Imprimir ordenado por data de nascimento\n");
        printf("5 - Pesquisar por codigo\n");
        printf("6 - Pesquisar por nome\n");
        printf("7 - Pesquisar por data de nascimento\n");
        printf("8 - Pesquisar por email\n");
        printf("0 - Sair\n");
        printf("\n=========================================================\n");
        scanf("%d",&selecionado);
        if(selecionado == 0){
           destroy_lista(&X);
            system("PAUSE");
            return 0;
        }
        menu(selecionado, &X, n, &A);
    }

   return 0;
}
