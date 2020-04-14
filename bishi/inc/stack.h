#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct stack{
	void *data;
	void (*push)(void *,struct stack **);
	void *(*pop)(struct stack **);
	void *(*get_min)(struct stack *);
	struct stack *min_stack;
	struct stack *next;
};

typedef struct stack Stack;
struct stack *creat_stack();
bool is_empty(struct stack *);
#endif 
