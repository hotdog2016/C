#include<stdio.h>
#include"../inc/tree.h"

int main()
{
	BITREE *tree;
	StrAssign(str,"ABDF###E##C#G##");
	creat_tree(&tree);
	printf("my pre order");
	PreOrderTraverse(tree);
	printf("\n");
	InOrderTraverse(tree);
	printf("\n");
	EndOrderTraverse(tree);
	printf("\n");
}
