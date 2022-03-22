#include "Arvore.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


int main(){
    char criar;
    void *olha;
    TNode *t;
    int opcao, teste, *auxiliar;
    cout << "Deseja criar uma Arvore de Inteiros?" << endl;
    cout << "Digite s para Sim ou n para Nao: ";
    cin >> criar;

    if(criar=='s'){
        t = abpCreate();
        if(t!=NULL){
            cout << "Criando Arvore de Inteiros" << endl << endl;

            do{
                cout << "---------------Menu da Arvore---------------" << endl;
                cout << "Digite 0 para Destruir a Arvore e Sair do Programa" << endl;
                cout << "Digite 1 para Inserir um Inteiro na Arvore" << endl;
                cout << "Digite 2 para Pesquisar um Inteiro na Arvore" << endl;
                cout << "Digite 3 para Remover um Inteiro da Arvore" << endl;
                cout << "Digite 4 para Imprimir a Arvore em Pre-Ordem" << endl;
                cout << "Digite 5 para Imprimir a Arvore em Pos-Ordem" << endl;
                cout << "Digite 6 para Imprimir a Arvore em forma Simetrica" << endl;
                cout << endl << endl << "Digite a Opcao Escolhida: ";
                cin >> opcao;
                cout << endl;

                switch(opcao){
                case 0:
                    cout << endl << "Destruindo Arvore" << endl;
                    teste = abpDestroi(t);
                    if(teste==TRUE){
                        cout << endl << "Arvore Destruida com Sucesso!!" << endl;
                    }
                    else{
                        cout << endl << "Impossivel Destruir Arvore, remova todos os Elementos Antes!!" << endl;
                    }
                    break;

                case 1:
                    auxiliar = new int[1];
                    cout << endl << "Digite o Elemento que quer Inserir na Arvore: ";
                    cin >> *auxiliar;

                    olha = abpInsert(t, (void*)auxiliar, (void*)auxiliar, cmpTNode);
                    if(olha!=NULL){
                        cout << endl << "Numero " << *auxiliar << " Inserido com Sucesso!!!" << endl;
                    }
                    else{
                        cout << endl << "Erro, Impossivel Inserir Numero " << *auxiliar << endl;
                    }
                    break;

                case 2:
                    auxiliar = new int[1];
                    cout << endl << "Insira o Inteiro que quer Pesquisar: ";
                    cin >> *auxiliar;

                    olha = abpQuerry(t, (void*)auxiliar, cmpTNode);
                    if(olha!=NULL){
                        cout << endl << "Numero " << *auxiliar << " Encontrado com Sucesso!!!" << endl;
                    }
                    else{
                        cout << endl << "Numero " << *auxiliar << " nao Encontrado na Arvore" << endl;
                    }
                    break;

                case 3:
                    auxiliar = new int[1];
                    cout << endl << "Digite o Numero que quer Remover da Arvore: ";
                    cin >> *auxiliar;

                    olha = abpRemove(t, (void*)auxiliar, cmpTNode);
                    if(olha!=NULL){
                        cout << endl << "Numero " << *auxiliar << " removido com Sucesso!!!" << endl;
                    }
                    else{
                        cout << endl << "Impossivel remover Numero " << *auxiliar << endl;
                    }
                    break;

                case 4:
                    cout << endl << "Imprimindo a Arvore em Pre-Ordem: " << endl;
                    abpPreOrdem(t, visit);
                    break;

                case 5:
                    cout << endl << "Imprimindo a Arvore em Pos-Ordem: " << endl;
                    abpPosOrdem(t, visit);
                    break;

                case 6:
                    cout << endl << "Imprmindo a Arvore em Ordem Simetrica: " << endl;
                    abpSimetrico(t, visit);
                    break;
                }
            }
            while(opcao!=0);
        }
    }
    else{
        cout << endl << "Encerrando Programa!" << endl;
    }
}
