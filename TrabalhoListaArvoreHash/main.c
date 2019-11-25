#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "structs.h"
#include "lista.h"
#include "arvore.h"
#include "hash.h"

//// 1 - criar contato
//// 2 - excluir contato
//// 3 - listar por ordenado_nome
//// 4 - listar por data de nascimento
//// 5 - pesquisar por tudo
//// 6 - acarregar dados do arquivo 
//// 7 - salvar em arquivo
//// 8 - sair

//!======ALL_Tipes_Commands===========

void adiciona(Lista *lista, ArvoreBinaria *arvore, TabelaHash *tabela){
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

//=============ARVORE================
        arvore_add(arvore,TEMP);
//===================================

//=============TABELA================
        th_add(tabela,TEMP);
//===================================
}

void remover(Lista *lista, ArvoreBinaria *arvore, TabelaHash *tabela){
    int codigo, posicao;
    printf("Insira o codigo a ser removido\n");
    scanf("%d",&codigo);
//=============LISTA=================
    posicao = PesquisaBinaria_codigo(*lista, codigo);
    remove_lista_at(lista, posicao);
//===================================

//=============ARVORE================
    remover_arvore(arvore, codigo);
//===================================

//=============TABELA================
        remover_th(tabela,codigo);
//===================================
}

//!===================================

//!=========PESQUISA_Commands===========
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

void pesquisar_arvoreBinaria(ArvoreBinaria *arvore){
    int selecionado, scanfIntValue;
    char scanfStringVlue[50];
    Telefonica resposta;

    printf("1 - Codigo\n2 - Nome\n3 - Data\n4 - email\n5 - telefone\n");
    scanf("%d", &selecionado);
    switch(selecionado){
        case 1:
        printf("digite o codigo:\n");
        scanf("%d",&scanfIntValue);
        resposta = Pesquisar_por_code(arvore,scanfIntValue); 
            break;
        case 2:
            printf("digite o nome:\n");
            scanf(" %s",scanfStringVlue);
            resposta = Pesquisar_por_Nome(arvore, scanfStringVlue); 
            break;
        case 3:
            printf("digite a data:\n");
            scanf(" %s",scanfStringVlue);
            resposta = Pesquisar_por_Data(arvore, scanfStringVlue); 
            break;
        case 4:
            printf("digite o email:\n");
            scanf(" %s",scanfStringVlue);
            resposta = Pesquisar_por_Email(arvore, scanfStringVlue);
            break;
        case 5:
            printf("digite a teleLEFONE:\n");
            scanf(" %s",scanfStringVlue);
            resposta = Pesquisar_por_Telefone(arvore, scanfStringVlue);
            break;
        default:
            printf("Valor invalido\n");
            break;
    }
        Imprimir_arvore_element(resposta);
}

void pesquisar_th(TabelaHash *tabela){
    int digitado = 0;
    printf("Insira o codigo a ser pesquisado\n");
    scanf("%d",&digitado);
    print_th_Element(*tabela, digitado);
}

//!===================================

//!======ARQUIVO_Commands=============
void salvar(Lista *lista){
    char nomeArquivo[50];
    printf("insira o nome do arquivo (sem .txt)\n");
    scanf(" %s",&nomeArquivo);
    strcat(nomeArquivo,".txt");
    FILE *arquivo = fopen(nomeArquivo,"w");
    print_lista_onFile(*lista, arquivo);
    fclose(arquivo);
}

void abrirArquivo(Lista *lista, ArvoreBinaria *arvore, TabelaHash *tabela){
    char nomeArquivo[50];
    printf("insira o nome do arquivo (sem .txt)\n");
    scanf(" %s",&nomeArquivo);
    strcat(nomeArquivo,".txt");
    FILE *arquivo = fopen(nomeArquivo,"r");
    if(arquivo == NULL){
        printf("Arquivo nao encontrado\n");
        return;
    }
//=============ARVORE================
    scanf_arvore_onFile(arvore, arquivo);
    fclose(arquivo);
    arquivo = fopen(nomeArquivo,"r");
//===================================

//=============LISTA=================
    scanf_lista_onFile(lista, arquivo);
    fclose(arquivo);
    arquivo = fopen(nomeArquivo,"r");
//===================================

//=============TABELA================
    scanf_th_onFile(tabela, arquivo);
    fclose(arquivo);
//===================================    
}

//!===================================

//!=========MENU_commands=============
//TODO hash
void menu(int selecionado, Lista *lista, ArvoreBinaria *arvore, TabelaHash *tabela){

    int x;
     switch(selecionado){
            case 1: //? Adicionar
                system("cls");
                adiciona(lista, arvore, tabela);
                system("PAUSE");
                system("cls");
                break;

            case 2: //? Remover
                system("cls");
                remover(lista, arvore, tabela);
                system("PAUSE");
                system("cls");
                break;

            case 3: //? Imprimir por nome
                system("cls");
                ordenado_nome(lista);
                print_lista(*lista);
                system("PAUSE");
                system("cls");
                break;

            case 4: //? Imprimir por data de nascimento
                system("cls");
                ordenado_data(lista);
                print_lista(*lista);
                system("PAUSE");
                system("cls");
                break;

            case 5: //? Pesquisar
                system("cls");
                pesquisar_menu(lista, arvore, tabela);
                system("PAUSE");
                system("cls");
                break;

            case 6: //? Salvar lista atual em arquivo
                system("cls");
                salvar(lista);
                system("PAUSE");
                system("cls");
                break;

            case 7: //? Abrir lista de arquivo
                system("cls");
                abrirArquivo(lista, arvore, tabela);
                system("PAUSE");
                system("cls");
                break;

            case 8://?Imprimir em arvore  
                system("cls");
                print_arvore(arvore);
                system("PAUSE");
                system("cls");          
                break;
            case 9://?Imprimir tabela hash  
                system("cls");
                print_th(*tabela);
                system("PAUSE");
                system("cls");          
                break;
            default:
                system("cls");
                printf("Valor invalido, tente novamente\n\n");
                system("PAUSE");
                system("cls");
                break;
     }
}

void pesquisar_menu(Lista *lista, ArvoreBinaria *arvore, TabelaHash *tabela){
    int selecionado;
    printf("1 - pesquisa binaria\n2 - pesquisa em arvore\n3 - pesquisa em hash\n"); 
    scanf("%d",&selecionado);
    switch(selecionado){
    case 1:
        system("cls");
        pesquisar_binaria(lista);
        break;
    case 2:
        system("cls");
        pesquisar_arvoreBinaria(arvore);
        break;
    case 3:
        system("cls");
        pesquisar_th(tabela);
        break;
    default:
        printf("Valor invalido\n");
    }
}
//!===================================


int main(){
    Lista lista;
    ArvoreBinaria arvore;
    TabelaHash tabela;
    int n;
    int selecionado = 100;

    system("cls");
    printf("Insira o limite da agenda: ");
    scanf("%d",&n);    
    create_lista(&lista, n);
    criar_Arvore(&arvore);
    create_tabela(&tabela,n);

    system("cls");
    while(1){
        printf("=========================================================\n\n");
        printf("1 - Inserir contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Imprimir ordenado por nome\n");
        printf("4 - Imprimir ordenado por data de nascimento\n");
        printf("5 - Pesquisar\n");
        printf("6 - Salvar em arquivo\n");
        printf("7 - Abrir arquivo\n");
        printf("8 - Imprimir arvore\n");
        printf("9 - Imprimir tabela hash\n");
        printf("0 - Sair\n");
        printf("\n=========================================================\n");
        scanf("%d",&selecionado);
        if(selecionado == 0){
            system("cls");
            break;
        }
        menu( selecionado, &lista, &arvore, &tabela );
    }

//============ FREE ==================
    destroy_lista(&lista);
    destroy_arvore(&arvore);
    destroy_th(&tabela);
    system("EXIT");
//====================================
    return 0;
}
