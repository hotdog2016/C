#include<stdio.h>
#include<stdlib.h>
#include"../inc/queue.h"

static void push_core(void *,struct queue **);
static void *pop_core(struct queue **);
static struct queue *init_core();
struct queue *creat_queue();


static struct queue *init_core()
{
	struct queue *top;
	top=(struct queue *)malloc(sizeof(struct queue));
	top->data = NULL;
	top->push = push_core; 
	top->pop  = pop_core;
	top->tail = NULL;
	top->next = NULL;
	return top;
}

static void push_core(void *p, struct queue **queue)
{
	struct queue *tmp = *queue;
	struct queue *new = NULL;
	if ( NULL == p ) {
		return ;
	}

	//当前队列为空
	if (NULL == (*queue)->tail) {
		(*queue)->data = p;
		(*queue)->tail = (*queue);
		return;
	}

	new = init_core();
	new->data = p;

	(*queue)->tail->next = new;
	(*queue)->tail = (*queue)->tail->next;
}


static void *pop_core(struct queue **queue)
{
	struct queue *tmp=NULL;

	if(NULL == (*queue)->tail)
	{
		printf("empty\n");
		return NULL;
	}

	void *p = (*queue)->data;
	tmp = *queue;

	//只有一个节点了
	if((*queue)->tail == (*queue)) {
		(*queue)->tail = NULL;
		return p;
	}

	(*queue)->next->tail = (*queue)->tail;
	*queue = (*queue)->next;
	free(tmp);
	tmp = NULL;
	return p;
}

struct queue *creat_queue()
{
	return init_core();
}


