#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/io.h>
#include "../inc/tree.h"

#define MAXSIZE 100

int j=1;

String str;

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

void creat_tree(struct tree  **T,char **str)
{
	char ch;
	if ('\0' == **str) {
		return ;
	}

	ch = **str;
	++(*str);
	if('#'==ch)
	{
		*T=NULL;
	}
	else
	{
		*T=(struct tree *)malloc(sizeof(struct tree ));
		if(!*T)
			exit(1);
		(*T)->data=ch;
		creat_tree(&(*T)->lchild,str);
		creat_tree(&(*T)->rchild,str);
	}
}

void pre_order_traverse(struct tree  * T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);
	pre_order_traverse(T->lchild);
	pre_order_traverse(T->rchild);
}

void middle_order_traverse(struct tree  *T)
{ 
	if(T==NULL)
		return;
	middle_order_traverse(T->lchild);
	printf("%c",T->data);
	middle_order_traverse(T->rchild);
}

void end_order_traverse(struct tree  *T)
{
	if(T==NULL)
		return;
	end_order_traverse(T->lchild);
	end_order_traverse(T->rchild);
	printf("%c",T->data);
}

void test_tree(struct tree *root)
{
	pre_order_traverse(root);
	printf("\n");
	middle_order_traverse(root);
	printf("\n");
	end_order_traverse(root);
	printf("\n");
}

