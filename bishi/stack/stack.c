#include<stdio.h>
#include"../inc/stack.h"
#include<stdlib.h>

static void push_core(void * ,struct stack **);
static void push(void * ,struct stack **);
static void *pop_core(struct stack **);
static void *pop(struct stack **);
static struct stack *init_core();
static struct stack *local_init_new_stack_node();
static void *get_min(struct stack *);
#define MIN 0



void *get_min(struct stack *stack)
{
	return (char *)(stack->min_stack->data) ;
}

static void push_core( void *data,struct stack **stack)
{
	struct stack *top;
	top = local_init_new_stack_node(); 
	top->data  = data;
	top->next = *stack;
	*stack = top;
}
static void push(void *data,struct stack **stack)
{
#if MIN
	char min = *(char *)(*stack)->min_stack->data;
	//stack 为空时
	if ((*stack) == (*stack)->next)
		min = *(char *)data;
#endif

	push_core(data,stack);

#if MIN
	if(*(char *)data < min)
		push_core(data,&((*stack)->min_stack));
	else
		push_core(&min,&((*stack)->min_stack));
#endif
}

static void* pop_core(struct stack **stack)
{
	if(NULL == *stack)
		return NULL;

	if((*stack)->next == *stack){
		printf("stack is empty\n");
		return NULL;
	}

	struct stack * top;
	void *data = (*stack)->data;
	top = *stack;


	*stack = (*stack)->next;

	free(top);
	top = NULL;

	return data;
}

static void *pop(struct stack **stack)
{
#if MIN
	pop_core(&((*stack)->min_stack));
#endif
	return pop_core(stack);
}


bool is_empty(struct stack *stack)
{
	if(NULL == stack)
	{
		printf("stack is invalid!\n");
		return true;
	}
	if(stack->next == stack){
		return true;
	}
	return false;
}

static struct stack *init_core()
{
	struct stack *top;
	top=(struct stack *)malloc(sizeof(struct stack));
	top->data=NULL;
	top->push = push; 
	top->pop = pop_core;
	top->get_min = get_min;
	top->min_stack = NULL;
	top->next=top;
	return top;
}

static struct stack *local_init_new_stack_node() 
{
	struct stack *new_stack = NULL;
	new_stack = init_core();
#if MIN
	if(NULL != new_stack && NULL == new_stack->min_stack)
	{
		new_stack->min_stack = init_core();
		return new_stack;
	}
#elif 0==MIN
	if( NULL != new_stack )
		return new_stack;
#endif
	return NULL;
}

struct stack *creat_stack()
{
	return local_init_new_stack_node(); 
}

