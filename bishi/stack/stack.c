#include<stdio.h>
#include"../inc/stack.h"
#include<stdlib.h>

struct stack *creat_stack()
{
	struct stack *tmp;
	tmp=(struct stack *)malloc(sizeof(struct stack));
	tmp->num=0;
	tmp->next=NULL;
	tmp->top=tmp;
	return tmp;
}
int push(int num,struct stack * stack)
{
	struct stack *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	temp->num=num;
	temp->next=stack->top;
	stack->top=temp;
	return 0;
}
int pop(struct stack * stack)
{
	struct stack * tmp;
	int i;
	tmp = stack->top;

	if(stack == tmp){
		printf("stack is empty\n");
		return -1;
	}
	i=tmp->num;
	stack->top=tmp->next;
	free(tmp);
	return i;
}
bool is_empty_stack(struct stack *stack)
{
	if(stack->top == stack){
		return 1;
	}
	return 0;
}


