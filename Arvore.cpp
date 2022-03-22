#include "Arvore.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/** Fun��o de Criar a Arvore */
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


/** Fun��o para destruir a �rvore */
int abpDestroi(TNode *t){
    if(t!=NULL){
        if(t->l==NULL && t->r==NULL){
            delete []t;
            return TRUE;
        }
    }
    return FALSE;
}


/** Fun��o que compara os datas, insira no primeiro par�metro da fun��o o data da �rvore e no segundo
par�metro o data recebido pelo usu�rio */
int cmpTNode(void *a, void *b){
    if(a!=NULL && b!=NULL){
        int *data = (int*)a;
        int *data2 = (int*)b;
        if(data!=NULL && data2!=NULL){
            /** Se os numeros forem iguais retorna 0 */
            if(*data2==*data){
                return 0;
            }
            /** Testa se o n�mero recebido pela fun��o � menor que o n�mero que
            t� no n� da �rvore, se for menor que o do n� da �rvore, quer dizer
            que o n�mero que ele procura pode estar a esquerda do n� da �rvore,
            que � onde ficam os n�meros menores que o n� e retorna -1 para
            sinalizar que o n�mero pesquisado � menor que o n�mero do n� da �rvore. */
            else if(*data2<*data){
                return -1;
            }
            /** Caso o n�mero recebido pela fun��o for maior que o n�mero que
            t� no n� da �rvore, quer dizer que o n�mero que ele procura pode
            estar a direita do n� da �rvore, que � onde ficam os n�meros
            maiores que o n� da �rvore e retorna 1 para sinalizar que o n�mero
            pesquisado � maior que o n�mero do n� da �rvore. */
            else{
                return 1;
            }
        }
    }
}

/** Fun��o de Pesquisar que retorna o Data pesquisado da �rvore */
void *abpQuerry(TNode *t, void *key, int(*cmp)(void*,void*)){
    int stat;
    if(t!=NULL && key!=NULL){
        stat = cmp(t->data, key);
        /** Se o n�mero pesquisado for igual ao n�mero do data
        retornamos o data. */
        if(stat==0){
            return t->data;
        }
        /** Se o n�mero inserido pelo usu�rio for menor que o n�mero
        do data, vamos para o n� da esquerda do data que � onde ficam
        os n�meros menores que o data. */
        else if(stat<0){
            return abpQuerry(t->l, key, cmp);
        }
        /** Se o n�mero inserido pelo usu�rio for maior que o n�mero
        do data, vamos para o n� da direita do data que � onde ficam
        os n�meros maiores que o data. */
        else{
            return abpQuerry(t->r, key, cmp);
        }
    }
    return NULL;
}

/** Fun��o de Inserir um inteiro na �rvore */
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

/** Fun��o que Retorna o Menor Data dentre a Sub�rvore */
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


/** Fun��o de Remover um n� da �rvore */
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

/** Visita o N� e imprime o data */
void visit(void *elm){
    int *a;
    a = (int*)elm;
    cout << *a;
}

/** Visita a �rvore em Pr�-Ordem e Imprime */
void abpPreOrdem (TNode *t, void(*visit)(void*)){
    if(t!=NULL){
        visit(t->data);
        abpPreOrdem(t->l, visit);
        abpPreOrdem(t->r, visit);
    }
}

/** Visita a �rvore em P�s-Ordem e Imprime */
void abpPosOrdem(TNode *t, void(*visit)(void*)){
    if(t!=NULL){
        abpPosOrdem(t->l, visit);
        abpPosOrdem(t->r, visit);
        visit(t->data);
    }
}


/** Visita a �rvore em Sim�trica e Imprime */
void abpSimetrico(TNode *t, void(*visit)(void*)){
    if(t!=NULL){
        abpSimetrico(t->l, visit);
        visit (t->data);
        abpSimetrico(t->r, visit);
    }
}
