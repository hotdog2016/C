#include <stdio.h>
#include <stdlib.h>
/*
 * 根据前序遍历和中序遍历的值来构建一个树
 *
 * */
 typedef struct Tree{
	 int val;
	 struct Tree *lchild;
	 struct Tree *rchild;
 }TREENODE,*PTREE;
int iPreOrder[8]={1,2,4,7,3,5,6,8};
int iInOrder[8]={4,7,2,1,5,3,8,6};

/*
 * 根据前序列表和中序列表构建树
 * 参数：PreOrderStart	前序列表的起始指针
 *		 PreOrderEnd  	前序列表的结束指针
 *		 InOrderStart 	中序列表的起始指针
 *		 InOrderEnd   	中序列表的结束指针
 * */

PTREE construct_tree_core(int *PreOrderStart,\
		int *PreOrderEnd,\
		int *InOrderStart,\
		int *InOrderEnd)
{
	PTREE pRootNode=NULL;
	int   iRootVal=0;
	int * pRootNodeOfInOrder;
	int iLeftTreeLen;
	//前序列表的第一个值就是根节点的值
	iRootVal=PreOrderStart[0];
	//建立根节点
	pRootNode=(PTREE)malloc(sizeof(TREENODE));
	pRootNode->val=iRootVal;
	pRootNode->lchild=NULL;
	pRootNode->rchild=NULL;
	//如果列表中只有一个节点时，前序和中序列表的起始和结束地址都一样
	if(PreOrderStart==PreOrderEnd)
	{
		if(InOrderStart==InOrderEnd)
		{
			if(*PreOrderStart==*InOrderStart)
			{
				printf("%d\n",pRootNode->val);
				return pRootNode;
			}
		}
	}
	//找到中序列表中根节点的位置
	pRootNodeOfInOrder=InOrderStart;
	while(pRootNodeOfInOrder<=InOrderEnd&&*pRootNodeOfInOrder!=iRootVal)
	{
		++pRootNodeOfInOrder;
	}
	//根节点左边的就是左子树，右边的就是右子树
	iLeftTreeLen=pRootNodeOfInOrder-InOrderStart;
	//取出前序列表中的左子树部分（改变前序指针的头针和尾指针）
	if(iLeftTreeLen>0)
	{
		pRootNode->lchild=construct_tree_core(PreOrderStart+1,\
											  PreOrderStart+iLeftTreeLen,\
											  InOrderStart,\
											  pRootNodeOfInOrder-1);
	}

	//取出右子树部分
	if(iLeftTreeLen<PreOrderEnd-PreOrderStart)
	{
		pRootNode->rchild=construct_tree_core(PreOrderStart+iLeftTreeLen+1,\
				PreOrderEnd,\
				pRootNodeOfInOrder+1,
				InOrderEnd);
	}
	printf("%d\n",pRootNode->val);

	return pRootNode;
}

PTREE construct_tree(int *PreOrderStart,\
		int *PreOrderEnd,\
		int *InOrderStart,\
		int *InOrderEnd)
{
	return construct_tree_core(PreOrderStart,PreOrderEnd,InOrderStart,InOrderEnd);
}

void PreOrderTraverse(PTREE  T)
{ 
	if(T==NULL)
		return;
	printf("%d",T->val);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(PTREE T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%d",T->val);
	InOrderTraverse(T->rchild);
}
void EndOrderTraverse(PTREE T)
{
	if(T==NULL)
		return;
	EndOrderTraverse(T->lchild);
	EndOrderTraverse(T->rchild);
	printf("%d",T->val);
}
int main()
{
	PTREE tree;
	tree=construct_tree(iPreOrder,\
			iPreOrder+7,\
			iInOrder,\
			iInOrder+7);

	printf("PreOrder:");
	PreOrderTraverse(tree);
	printf("\n");
	printf("InOrder:");
	InOrderTraverse(tree);
	printf("\n");
	printf("EndOrder:");
	EndOrderTraverse(tree);
	printf("\n");

	return 0;
}
