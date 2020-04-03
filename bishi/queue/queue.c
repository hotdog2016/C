#include"../inc/queue.h"
#include"../inc/stack.h"
#include<stdio.h>
#include<stdlib.h>

struct stack *stack1 = NULL;
struct stack *stack2 = NULL;

void stack1_to_stack2(struct stack *stack1,struct stack *stack2)
{
	int tmp;
	if(stack1 ==NULL){
		printf("stack error");
		return;
	}
	while(!is_empty_stack(stack1)){
		tmp=pop(stack1);
		push(tmp,stack2);
	}
}

void creat_queue()
{
	stack1 = creat_stack();
	stack2 = creat_stack();
	if(stack2 == NULL || stack1 == NULL){
		printf("creat queue error\n");
		return;
	}
}

int append_tail(int val)
{
	if(stack1 != NULL&&stack2 != NULL)
		push(val,stack1);
	return 0;
}

int delete_head()
{
	if(stack2 == NULL){
		printf("stack error\n");
		return 1;
	}
	if(!is_empty_stack(stack2)){
		printf("delete %d\n",stack2->top->num);
		pop(stack2);
	}
	else{
		if(is_empty_stack(stack1)){
			printf("queue is empty\n");
			return 1;
		}
		stack1_to_stack2(stack1,stack2);
		printf("delete %d\n",stack2->top->num);
		pop(stack2);
	}
	return 0;
}
int main()
{
	creat_queue();
	push(1,stack1);
	push(2,stack1);
	push(3,stack1);
	delete_head();
	delete_head();
	delete_head();
	delete_head();
	append_tail(6);
	delete_head();
}


