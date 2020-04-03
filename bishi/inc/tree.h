#ifndef TREE_H
#define TREE_H

typedef struct BiTree{
	char data;
	struct BiTree *lchild;
	struct BiTree *rchild;
}BITREE;

typedef char  String[100];
String str;

int StrAssign(String T,char *chars);
void creat_tree(BITREE **T);
void PreOrderTraverse(BITREE * T);
void InOrderTraverse(BITREE *T);
void EndOrderTraverse(BITREE *T);
#endif
