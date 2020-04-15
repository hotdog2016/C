#include <stdio.h>
#include "../inc/tree.h"

void exchange(struct tree *root)
{
	struct tree *tmp;
	if ( NULL == root )
		return ;
	if ( NULL == root->lchild && NULL == root->rchild)
		return;

	tmp = root->lchild;
	root->lchild = root->rchild;
	root->rchild = tmp;

	exchange(root->lchild);
	exchange(root->rchild);

}
void mirror_tree(struct tree *root)
{

	struct tree *tmp;
	if (NULL == root) {
		printf("tree is null\n");
		return;
	}

	if ( NULL == root->lchild && NULL == root->rchild) {
		printf("tree has no childs!\n");
		return;
	}

	tmp = root->lchild;
	root->lchild = root->rchild;
	root->rchild = tmp;

	exchange(root->lchild);
	exchange(root->rchild);
}

int main(int argc, char *argv[])
{
	struct tree *tree = NULL;
	char *str = "865##7##19##2";
	creat_tree(&tree,&str);
	test_tree(tree);
	mirror_tree(tree);
	test_tree(tree);
	return 0;
}
