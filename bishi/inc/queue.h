#ifndef QUEUE_H
#define QUEUE_H

struct queue *creat_queue();

struct queue{
	void *data;
	void (*push)(void *,struct queue **);
	void *(*pop)(struct queue **);
	struct queue *tail;
	struct queue *next;
};

#endif
