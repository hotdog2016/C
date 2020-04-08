#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/io.h>
#include "../inc/tree.h"

#define MAXSIZE 100

int j=1;

int StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return -1;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return 0;
	}
}

void creat_tree(BITREE **T)
{
	char ch;
	ch = str[j++];
	if('#'==ch)
	{
		*T=NULL;
	}
	else
	{
		*T=(BITREE*)malloc(sizeof(BITREE));
		if(!*T)
			exit(1);
		(*T)->data=ch;
		creat_tree(&(*T)->lchild);
		creat_tree(&(*T)->rchild);
	}
}

void PreOrderTraverse(BITREE * T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BITREE *T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}

void EndOrderTraverse(BITREE *T)
{
	if(T==NULL)
		return;
	EndOrderTraverse(T->lchild);
	EndOrderTraverse(T->rchild);
	printf("%c",T->data);
}

