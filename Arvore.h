#ifndef ARVORE_H
#define ARVORE_H
#define TRUE 1
#define FALSE 0

typedef struct _treenode_{
    struct _treenode_ *l;
    struct _treenode_ *r;
    void *data;
}TNode;

/** Fun��o de Criar a Arvore */
TNode *abpCreate();

/** Fun��o para destruir a �rvore */
int abpDestroi(TNode *t);

/** Fun��o que compara o data do n� da Arvore com o data recebido pelo Usu�rio */
int cmpTNode(void *a, void *b);

/** Fun��o que retorna o inteiro pesquisado na �rvore */
void *abpQuerry(TNode *t, void *key, int(*cmp)(void*,void*));

/** Fun��o de Inserir um inteiro na �rvore */
TNode *abpInsert(TNode *t, void *data, void *key, int(*cmp)(void*, void*));

/** Fun��o que Retorna o Menor Data dentre a Sub�rvore */
void *abpGetMenorData (TNode *t);

/** Fun��o de Remover um n� da �rvore */
void *abpRemove(TNode *t, void *key, int(*cmp)(void*,void*));

/** Visita o N� e imprime o data */
void visit(void *elm);

/** Visita a �rvore em Pr�-Ordem e Imprime */
void abpPreOrdem (TNode *t, void(*visit)(void*));

/** Visita a �rvore em P�s-Ordem e Imprime */
void abpPosOrdem(TNode *t, void(*visit)(void*));

/** Visita a �rvore em Sim�trica e Imprime */
void abpSimetrico(TNode *t, void(*visit)(void*));

#endif
