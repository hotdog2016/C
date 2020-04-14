#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"
#include "../inc/list.h"

void convert_core( struct tree *tree_node , struct tree **current_list_node )
{
	if ( NULL == tree_node ) {
		return ;
	}
	if (NULL != tree_node->lchild) {
		convert_core( tree_node->lchild , current_list_node );
	}
	if ( NULL == *current_list_node ) {
		*current_list_node = tree_node;
		(*current_list_node)->lchild = NULL;
	} else {
		(*current_list_node)->rchild = tree_node;
		tree_node->lchild = (*current_list_node);
		*current_list_node = tree_node;
	}

	if (NULL != tree_node->rchild) {
		convert_core( tree_node->rchild , current_list_node );
	}

}

struct tree *tree_convert_list( struct tree *root )
{
	struct tree *list = NULL;
	if ( NULL == root ) {
		printf("root is null\n");
		return NULL;
	}
	convert_core( root , &list );
	return list;
}

int main()
{
	struct tree *tree = NULL;
	struct tree *list = NULL;
	char * str = "421##3##76##8##";
	creat_tree( &tree , &str );
	list = tree_convert_list( tree );
	if( list != NULL ) {
		while ( list ) {
			printf( "%c ",list->data );
			list = list->lchild;
		}
	}
}

