#include <stdio.h>
#include <stdlib.h>

//链表结构
typedef struct Node{
	int num;
	struct Node * pHead;
	struct Node * pNext;
	struct Node * pTail;
}ListNode;
typedef struct stack{
	int num;
	struct stack *top;
	struct stack *next;
}STACK;

STACK *stack = NULL;

STACK * creat_stack()
{
	STACK *stack;
	stack=(STACK *)malloc(sizeof(STACK));
	stack->num=0;
	stack->next=NULL;
	stack->top=stack;
	return stack;
}
int push(int num,STACK * stack)
{
	STACK *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	temp->num=num;
	temp->next=stack->top;
	stack->top=temp;
	return 0;
}
int pop(STACK * stack)
{
	STACK * top;
	top=stack->top;

	if(stack==top)
	{
		printf("stack is empty\n");
		return -1;
	}
	printf("%d\n",top->num);
	stack->top=top->next;
	free(top);
	return 0;
}
int pop_all(STACK * stack)
{
	while(stack->top->next!=NULL)
	{
		pop(stack);
	}
	return 0;
}


int show_list(ListNode *List)
{
	struct Node * pCurrent=NULL;
	pCurrent = List;
	while(pCurrent!=NULL)
	{
		push(pCurrent->num,stack);
		pCurrent=pCurrent->pNext;
	}
	return 0;
}

ListNode * creat_node(int num)
{
	ListNode * pCurrent=NULL;
	pCurrent=(ListNode*)malloc(sizeof(ListNode));
	if(pCurrent==NULL)
	{
		printf("creat node error\n");
		return NULL;
	}
	pCurrent->num=num;
	pCurrent->pHead=NULL;
	pCurrent->pNext=NULL;
	pCurrent->pTail=NULL;
	return pCurrent;
}
int add_node(ListNode *pList,ListNode * pNode)
{
	if(pList==NULL)
	{
		printf("erro\n");
		return -1;
	}

	pNode->pHead=pList;
	pNode->pNext=NULL;
	pList->pTail->pNext=pNode;
	pList->pTail=pNode;
	return 0;
}

ListNode *creat_list(int num)
{
	int i;
	ListNode *pListHead=NULL;
	ListNode *pCurrent=NULL;
	pListHead=(ListNode*)malloc(sizeof(ListNode));
	if(pListHead==NULL)
	{
		printf("malloc list error\n");
		return NULL;
	}
	pListHead->pHead=pListHead;
	pListHead->pTail=pListHead;
	pListHead->pNext=NULL;

	for(i=0;i<num;i++)
	{
		pCurrent=creat_node(i+1);
		if(pCurrent==NULL)
		{
			printf("creat node error\n");
			return NULL;
		}
		if(pListHead==NULL)
		{
			printf("no list\n");
			return NULL;
		}
		add_node(pListHead,pCurrent);
	}
	return pListHead;
}

int main()
{
	ListNode *List;
	List=creat_list(20);
	stack=creat_stack();
	show_list(List);
	pop_all(stack);

}
