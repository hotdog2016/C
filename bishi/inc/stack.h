#ifndef STACK_H
#define STACK_H
#include<stdbool.h>

struct stack{
	int num;
	struct stack *top;
	struct stack *next;
};
struct stack *creat_stack();
int push(int num,struct stack * stack);
int pop(struct stack * stack);
bool is_empty_stack(struct stack *stack);

#endif 
