#ifndef ARVORE_H
#define ARVORE_H
#define TRUE 1
#define FALSE 0

typedef struct _treenode_{
    struct _treenode_ *l;
    struct _treenode_ *r;
    void *data;
}TNode;

/** Função de Criar a Arvore */
TNode *abpCreate();

/** Função para destruir a Árvore */
int abpDestroi(TNode *t);

/** Função que compara o data do nó da Arvore com o data recebido pelo Usuário */
int cmpTNode(void *a, void *b);

/** Função que retorna o inteiro pesquisado na Árvore */
void *abpQuerry(TNode *t, void *key, int(*cmp)(void*,void*));

/** Função de Inserir um inteiro na Árvore */
TNode *abpInsert(TNode *t, void *data, void *key, int(*cmp)(void*, void*));

/** Função que Retorna o Menor Data dentre a Subárvore */
void *abpGetMenorData (TNode *t);

/** Função de Remover um nó da árvore */
void *abpRemove(TNode *t, void *key, int(*cmp)(void*,void*));

/** Visita o Nó e imprime o data */
void visit(void *elm);

/** Visita a Árvore em Pré-Ordem e Imprime */
void abpPreOrdem (TNode *t, void(*visit)(void*));

/** Visita a Árvore em Pós-Ordem e Imprime */
void abpPosOrdem(TNode *t, void(*visit)(void*));

/** Visita a Árvore em Simétrica e Imprime */
void abpSimetrico(TNode *t, void(*visit)(void*));

#endif
