#include "Arvore.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/** Função de Criar a Arvore */
TNode *abpCreate(){
    TNode *t;
    t = new TNode;

    if(t!=NULL){
        t->l = NULL;
        t->r = NULL;
        return t;
    }
    return NULL;
}


/** Função para destruir a Árvore */
int abpDestroi(TNode *t){
    if(t!=NULL){
        if(t->l==NULL && t->r==NULL){
            delete []t;
            return TRUE;
        }
    }
    return FALSE;
}


/** Função que compara os datas, insira no primeiro parâmetro da função o data da Árvore e no segundo
parâmetro o data recebido pelo usuário */
int cmpTNode(void *a, void *b){
    if(a!=NULL && b!=NULL){
        int *data = (int*)a;
        int *data2 = (int*)b;
        if(data!=NULL && data2!=NULL){
            /** Se os numeros forem iguais retorna 0 */
            if(*data2==*data){
                return 0;
            }
            /** Testa se o número recebido pela função é menor que o número que
            tá no nó da Árvore, se for menor que o do nó da Árvore, quer dizer
            que o número que ele procura pode estar a esquerda do nó da Árvore,
            que é onde ficam os números menores que o nó e retorna -1 para
            sinalizar que o número pesquisado é menor que o número do nó da Árvore. */
            else if(*data2<*data){
                return -1;
            }
            /** Caso o número recebido pela função for maior que o número que
            tá no nó da Árvore, quer dizer que o número que ele procura pode
            estar a direita do nó da Árvore, que é onde ficam os números
            maiores que o nó da Árvore e retorna 1 para sinalizar que o número
            pesquisado é maior que o número do nó da Árvore. */
            else{
                return 1;
            }
        }
    }
}

/** Função de Pesquisar que retorna o Data pesquisado da Árvore */
void *abpQuerry(TNode *t, void *key, int(*cmp)(void*,void*)){
    int stat;
    if(t!=NULL && key!=NULL){
        stat = cmp(t->data, key);
        /** Se o número pesquisado for igual ao número do data
        retornamos o data. */
        if(stat==0){
            return t->data;
        }
        /** Se o número inserido pelo usuário for menor que o número
        do data, vamos para o nó da esquerda do data que é onde ficam
        os números menores que o data. */
        else if(stat<0){
            return abpQuerry(t->l, key, cmp);
        }
        /** Se o número inserido pelo usuário for maior que o número
        do data, vamos para o nó da direita do data que é onde ficam
        os números maiores que o data. */
        else{
            return abpQuerry(t->r, key, cmp);
        }
    }
    return NULL;
}

/** Função de Inserir um inteiro na Árvore */
TNode *abpInsert(TNode *t, void *data, void *key, int(*cmp)(void*, void*)){
    if(t!=NULL){
        int stat;
        stat = cmp(t->data, key);
        if(stat<=0){
            t->l = abpInsert(t->l, data, key, cmp);
        }
        else{
            t->r = abpInsert(t->r, data, key, cmp);
        }
        return t;
    }
    else{
        TNode *newNode = new TNode;
        if(newNode!=NULL){
            newNode->l = NULL;
            newNode->r = NULL;
            newNode->data = data;
            return newNode;
        }
        return NULL;
    }
}

/** Função que Retorna o Menor Data dentre a Subárvore */
void *abpGetMenorData (TNode *t){
    if (t!=NULL){
        if (t->l!=NULL){
            return abpGetMenorData(t->l);
        }
        else{
            return t->data;
        }
    }
    return NULL;
}


/** Função de Remover um nó da árvore */
void *abpRemove (TNode *t, void *key, int(*cmp)(void*,void*)){
    TNode *filho;
    if (t!=NULL){
        if (cmp(t->data, key)==0){
            if ((t->l==NULL)&&(t->r==NULL)){
                delete []t->data;
                delete []t;
                return NULL;
            }
            else{
                if ((t->l==NULL)&&(t->r!=NULL)){
                    filho = t->r;
                    delete []t->data;
                    delete []t;
                    return filho;
                }
                else{
                    if ((t->l!=NULL)&&(t->r==NULL)){
                        filho=t->l;
                        delete []t->data;
                        delete []t;
                        return filho;
                    }
                    else{
                        t->data = abpGetMenorData(t->r);
                        t->r = (TNode*)abpRemove(t->r,t->data,cmp);
                        return t;
                    }
                }
            }
        }
        else{
            if (cmp(t->data, key)<0){
                t->l = (TNode*)abpRemove(t->l, key, cmp);
            }
            else{
                t->r = (TNode*)abpRemove(t->r, key, cmp);
            }
        }
    }
    return NULL;
}

/** Visita o Nó e imprime o data */
void visit(void *elm){
    int *a;
    a = (int*)elm;
    cout << *a;
}

/** Visita a Árvore em Pré-Ordem e Imprime */
void abpPreOrdem (TNode *t, void(*visit)(void*)){
    if(t!=NULL){
        visit(t->data);
        abpPreOrdem(t->l, visit);
        abpPreOrdem(t->r, visit);
    }
}

/** Visita a Árvore em Pós-Ordem e Imprime */
void abpPosOrdem(TNode *t, void(*visit)(void*)){
    if(t!=NULL){
        abpPosOrdem(t->l, visit);
        abpPosOrdem(t->r, visit);
        visit(t->data);
    }
}


/** Visita a Árvore em Simétrica e Imprime */
void abpSimetrico(TNode *t, void(*visit)(void*)){
    if(t!=NULL){
        abpSimetrico(t->l, visit);
        visit (t->data);
        abpSimetrico(t->r, visit);
    }
}
