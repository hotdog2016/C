#include <stdio.h>
#include "../inc/stack.h"
#include <stdbool.h>


bool check_sequences( int *seq1,int *seq2, struct stack *stack , int length )
{
	int current_seq1 = 0;
	bool is_find = false;

	//查看列表2的第一个字符，找到列表1中的这个字符将这个字符和它前面的字符都入栈
	for (int i = 0; i < length; ++i) {

		if ( stack->is_empty(stack) == false && seq2[i] == stack->num  ) {
			printf("i = %d\n", i);
			printf("first pop:%d\n",stack->pop(&stack));

			if (i==length-1) 
				return true;

			continue;
		}

		for ( int j = current_seq1; j < length ; ++j ) {
			stack->push(seq1[j] , &stack);
			printf("push:%d\n", seq1[j]);
			if (seq2[i] == stack->num) {
				
				current_seq1 = j+1;
				break;
			}
		}

		printf("seq2[%d] = %d top = %d\n", i,seq2[i],stack->num);

		if (seq2[i] == stack->num) {
			printf("second pop:%d\n", stack->pop(&stack));
			continue;
		}

		if (length == current_seq1 && seq2[i] != stack->num) {

			printf("seq2[%d] = %d top = %d\n", i,seq2[i],stack->num);

			return false;
		}
	}

	return true;
}

int main()
{
	int seq1[5] = {1,2,3,4,5}; 
	int seq2[5] = {4,3,5,1,2}; 
	int seq3[5] = {4,5,3,2,1};

	struct stack *stack = NULL;
	
	stack = creat_stack();

	if( check_sequences(seq1 , seq3 , stack ,5) ) {
		printf("ok!\n");
		return 1;
	}
	else {
		printf("can't find!\n");
		return 0;
	} 
}

