#include <stdio.h>
#include "../inc/tree.h"
#include <stdbool.h>

String str_tmp;
void pre_order_traverse_from_right(struct tree *root)
{
	if (NULL == root) {
		return;
	}
	printf("%c", root->data);
	pre_order_traverse_from_right(root->rchild);
	pre_order_traverse_from_right(root->lchild);
}

bool check_symmetrical_tree(struct tree *root)
{
	pre_order_traverse(root);
	printf("\n");
	pre_order_traverse_from_right(root);
	return true;
}
int main(int argc, char *argv[])
{
	char *str = "865##7##67##5##";
	struct tree *tree = NULL;
	creat_tree(&tree,&str);
	check_symmetrical_tree(tree);
	return 0;
}
