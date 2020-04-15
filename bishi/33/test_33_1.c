#include <stdio.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"
#include <stdbool.h>

//检测某个序列是否为搜索二叉树的后序遍历序列

bool check_sequence_is_tree(int *start,int *end)
{
	int *p = start;
	int root = *end;
	bool left_ok = false;
	bool right_ok = false;
	if ( start == end ) {
		return true;
	}

	//找到左子树
	while (*p < root) {
		p++;
	}
	for (int* i = start; i < p; ++i) {
		if (*i > root) {
			return false;
		}
	}
	for (int *i = p; i < end; ++i) {
		if(*i < root)
			return false;
	}
	//检测左子树
	left_ok = check_sequence_is_tree( start , p-1 );
	//检测右子树
	right_ok = check_sequence_is_tree( p , end-1 );
	return left_ok && right_ok;
}
int main()
{
	int num[7] = { 4,7,6,9,1,10,8 };
	if( check_sequence_is_tree( num , num+6 ))
		printf("ok\n");
	else
		printf("error\n");
	return 0;
}
