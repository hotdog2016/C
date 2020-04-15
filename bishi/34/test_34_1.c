#include <stdio.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"
#include <stdbool.h>

int sum = 0;
struct stack *stack;
//找到节点的值相加为num的路径
void find_path_sum( struct tree *root , int num )
{

	sum += root->data - '0';
	stack->push( root ,&stack );

	if( NULL == root->lchild && NULL == root->rchild ) {
		if( sum == num ) {
			printf("find!\n");
			//while( !is_empty( stack ) )
			//	printf("%c ",*(char *)stack->pop(&stack));
			return;
		}else {
			return ;
		}
	}


	find_path_sum( root->lchild , num );

	printf("sum1 = %d\n",sum );
	if( NULL != stack) {
		struct tree *tmp = NULL;
		tmp = stack->pop(&stack);
		sum -= tmp->data-'0';
	}

	find_path_sum( root->rchild , num );

	printf("sum2 = %d\n",sum );
	if( NULL != stack) {
		struct tree *tmp = NULL;
		tmp = stack->pop(&stack);
		sum -= tmp->data-'0';
	}
	return ;
}
void find_path( struct tree *root , int num )
{
	if ( NULL == root ) {
		printf("tree is empty\n");
		return ;
	}

	find_path_sum( root , num );

	sum -= root->data - '0';
	stack->pop(&stack);
}
int main()
{
	struct tree *tree = NULL;
	char *str = "124##2##15##6##";
	stack = creat_stack();
	creat_tree(&tree , &str);
	test_tree(tree);
	find_path( tree , 7 );
}





