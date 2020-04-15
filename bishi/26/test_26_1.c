#include <stdio.h>
#include "../inc/tree.h"
#include <stdbool.h>

bool match_child_tree_recusion(struct tree *root1, struct tree *root2)
{
	if ( NULL == root2 ) {
		return true;
	} 

	if (NULL == root1) {
		return false;
	}
	if(root1->data != root2->data)
		return false;
	if (match_child_tree_recusion(root1->lchild , root2->lchild)\
			&& match_child_tree_recusion(root1->rchild , root2->rchild)) {
		return true;
	}
	return false;
}

bool is_child_tree_recusion(struct tree *root, struct tree *child_root)
{
	bool result = false;
	if (NULL == root || NULL == child_root) {
		return false;
		
	}

	//先找与child树跟节点,相同的节点
	if (root->data == child_root->data)
		result = match_child_tree_recusion(root,child_root);
	if (false == result) {
		result = is_child_tree_recusion(root->lchild,child_root);
	}
	if (false == result) {
		result = is_child_tree_recusion(root->rchild,child_root);
	}
	return result;

}
int main(int argc, char *argv[])
{
	bool result = false;
	struct tree *tree = NULL;
	struct tree *child_tree = NULL;
	char *str1 = "889##24##7##7##";
	char *str2 = "89##2##";
    creat_tree(&tree , &str1);	
    creat_tree(&child_tree , &str2);	
	result = is_child_tree_recusion(tree,child_tree);
	if (result) {
		printf("match ok!\n");
		return 0;
	}else{
		printf("can't match!\n");
	}
	return 0;

}
