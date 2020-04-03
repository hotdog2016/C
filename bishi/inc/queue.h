#ifndef QUEUE_H
#define QUEUE_H
struct queue{
	struct stack *head;
	struct stack *tail;
};

int append_queue(struct queue *queue);
int delete_queue(struct queue *queue);
void creat_queue();

#endif
