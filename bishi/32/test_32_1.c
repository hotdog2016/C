#include <stdio.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"

static struct stack *stack = NULL;
static struct queue *queue = NULL;

void print_tree_layer(struct tree *root)
{
	struct tree *tmp = NULL;
	
	static int layer_cnt = 0;
	static int layer_node_cnt=0;
	static int next_layer_cnt=0;

	if ( NULL == root ) {
		printf("tree is empty\n");
		return ;
	}

	queue->push(root , &queue);
	layer_node_cnt++;
	layer_cnt++;

	while(queue->tail) {
		tmp = queue->pop(&queue);
		layer_node_cnt--;

		if (!(layer_cnt%2)) {
			stack->push((tmp->data-'0') , &stack);
		}else{
			printf("%c ",tmp->data);
		}

		queue->push(tmp->lchild , &queue);
		next_layer_cnt++;
		queue->push(tmp->rchild , &queue);
		next_layer_cnt++;

		if( 0 == layer_node_cnt ) {
			layer_node_cnt = next_layer_cnt;
			if(!(layer_cnt%2)) {
				while(!stack->is_empty(stack)) {
					printf("%d ",stack->pop(&stack));
				}
			}
			layer_cnt++;
			printf("\n");
		}
	}
	printf("\n");
}

int main()
{
	struct tree *tree = NULL;
	char *str = "124##5##36##7##";
	creat_tree(&tree,&str);
	test_tree(tree);
	queue = creat_queue();
	stack = creat_stack();
	print_tree_layer(tree);
}
