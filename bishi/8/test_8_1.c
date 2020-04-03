/*
 * 给定一个二叉树和其中一个节点，查询他的中序遍历的下一个节点是哪一个
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/io.h>
/*
 *             A
 *          B     C
 *        
 * */
#define MAXSIZE 100
typedef struct BiTree{
	char data;
	struct BiTree *lchild;
	struct BiTree *rchild;
	struct BiTree *parent;
}BITREE;
typedef char  String[100];
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
		(*T)->parent=NULL;
		creat_tree(&(*T)->lchild);
		creat_tree(&(*T)->rchild);
	}
}

void PreOrderTraverse(BITREE * T)
{ 
	if(T==NULL)
		return;
	if(T->lchild!=NULL)
		T->lchild->parent=T;
	if(T->rchild!=NULL)
		T->rchild->parent=T;
	printf("%c",T->data);
	if(T->parent!=NULL)
		printf(" parent is %c\n",T->parent->data);
	else
		printf(" is top node\n");

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

void find_node(BITREE * T,char data,BITREE ** node)
{
	if(T==NULL||(*node)!=NULL)
		return;
	if(T->data==data)
	{
		*node=T;
		return;
	}
	find_node(T->lchild,data,node);
	find_node(T->rchild,data,node);
}

BITREE * find_lchild(BITREE * T)
{
	if(T->lchild==NULL)
		return T;
	return find_lchild(T->lchild);
}

BITREE *check_parent(BITREE * node)
{
	if(node->parent==NULL)
	{
		return NULL;
	}
	if(node->parent->parent==NULL)
	{
		return NULL;
	}
	if(node->parent==node->parent->parent->lchild)
	{
		return node->parent->parent;
	}
	return check_parent(node->parent);
}

BITREE * get_next_node(BITREE *node)
{
	if(node==NULL)
		return NULL;
	if(node->lchild==NULL&&node->parent==NULL&&node->rchild==NULL)
	{
		printf("invalid node\n");
		return NULL;
	}
	//如果是顶节点
	if(node->parent==NULL)
	{
		printf("%c is top node\n",node->data);
		//如果没有右子树
		if(node->rchild==NULL)
		{
			printf("%c is last node\n",node->data);
		}
		else //如果有右子树
		{
			BITREE *temp;
			temp=find_lchild(node->rchild);
			if(NULL==temp)	//如果右子树没有左子树，返回当前节点的右节点
			{
				return node->rchild;
			}
			else//如果右子树有左子树，则返回左子树的最左节点
				return temp;
		}
	}
	//如果此节点是父节点的左节点
	if(node==node->parent->lchild)
	{
		printf("%c is %c's left child\n",node->data,node->parent->data);
		//如果此节点无右子树，那下一个节点应该是他的父节点
		if(node->rchild==NULL)
		{
			return node->parent;
		}
		else	//如果此节点有右子树
		{
			BITREE *temp;
			temp=find_lchild(node->rchild);
			if(NULL==temp)//如果右子树没左节点	
			{
				return node->rchild;
			}
			else//如果有左节点
				return temp;
		}
	}
	//如果此节点时父节点的右节点
	if(node==node->parent->rchild)
	{
		printf("%c is %c's right child\n",node->data,node->parent->data);
		//如果无右子树
		if(node->rchild==NULL)
		{
			printf("%c don't has right child\n",node->data);
			//往上遍历，看他的祖先节点是不是属于哪个节点的左节点。如果有，那他的下一个节点就是哪个祖先的父节点。如果没有，那他就是最后一个节点
			return check_parent(node);
		}
		else //如果有右子树
		{
			BITREE *temp;
			temp=find_lchild(node->rchild);
			if(NULL==temp)	
			{
				return node->rchild;
			}
			else
				return temp;
		}
	}
	return NULL;
}

int main()
{
	BITREE *tree;
	BITREE **node;
	BITREE *NextNode=NULL;
	node=(BITREE **)malloc(sizeof(BITREE**));
	*node=NULL;
	StrAssign(str,"ABDF###E##C#G##");
	creat_tree(&tree);
	PreOrderTraverse(tree);
	printf("InOrderTraverse is ");
	InOrderTraverse(tree);
	printf("\n");
	find_node(tree,'A',node);
	if(*node==NULL)
	{
		printf("can't find node\n");
		return 1;
	}
	else
	{
		printf("you want to find %c next node\n",(*node)->data);
		NextNode=get_next_node(*node);
		if(NextNode!=NULL)
		{
			printf("next node is %c\n",NextNode->data);
			return 0;
		}
		else
		{
			printf("%c is last node\n",(*node)->data);
			return 0;
		}
	}
		
}
