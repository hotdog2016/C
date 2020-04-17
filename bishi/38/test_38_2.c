#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"
#include "../inc/list.h"
int m = 0;
/*
 * 打印出来当前字符串num个字符的组合，
 * 保持其他位的字符不变，只向后按顺序改变最后一位的字符
 * 例如打印字符串abcd中，以a为首字母的所有2个字符的组合
 * a b c d => a b c d  => a b c d 
 * ^ ^        ^   ^       ^     ^
 * */
void print_string( char *p[],int num )
{
	int index = num -1;
	while( *p[index] != '\0' ) {
		for (int i = 0; i < num; ++i) {
			printf("%c" ,*(p[i]));
		}
		m++;
		printf("\n");
		++p[index];
	}
}
/*
 * 调整数组中在第一位和最后一位之间的字符
 * 例如：a b c d e => a b c d e => a b c d e 
 *		 ^ ^ ^        ^   ^ ^      ^     ^ ^
 * 调整好之后再使用print_string函数打印出来不
 * 同情况下，最后一位变化的所有组合
 * */
void adjust_point( char *p[] , int index ,int num , char *end) 
{
	bool flag = true;
	int max_index = num-1;
	while ( flag ) {
		for (int i = index; i  < max_index ; i++) {
			if ( i==index ) {
				++p[i];
				flag = (num - index) <= (end - p[i])/sizeof(char);
			}else{
				p[i] = p[i-1]+1;
			}
		} 
		p[num-1] = p[num-2]+1;

		print_string( p,num );
	}
}
/*
 * 组合函数
 * 原理：每一次，先固定好num-1个字符，然后通过改变最后一位字符，来找出来当前情况的所有组合
 * 例如：找到5个字符中，3个字符的所有组合方式
 *		第一种情况 a b c d e => a b c d e => a b c d e
 *		           ^ ^ ^        ^ ^   ^      ^ ^     ^
 *		第二种情况 a b c d e => a b c d e
 *				   ^   ^ ^      ^   ^   ^
 *		第二种情况 a b c d e 
 *				   ^     ^ ^    
 *		当以a为首字母的组合打印完之后，通过递归的方式，再次调用这个函数，要将字符串的头指针向后移动一位 
 *      第一种情况 b c d e => b c d e 
 *                 ^ ^ ^      ^ ^   ^
 *      第二种情况 b c d e 
 *                 ^   ^ ^     
 *      以b为首字母的组合打印完之后再打印以c为首字母的组合
 *      第一种情况 c d e
 *                 ^ ^ ^
 * */
void combine( char *str , int num ,char *end)
{
	char *p[num];
	if(num == 0)
		return;

	//首先创建指针数组，用来指向字符的组合，如果要3个字符的组合就创建3个指针
	for (int i = 0; i < num; ++i) {
		p[i] = str + i;
	}

	if (1 == num)
	{
		print_string( p,num );
		return ;
	}

	if (strlen(str) == num)
	{
		print_string( p,num );
		return ;
	}

	/*
	 * 这个循环是用来调整数组中间几个指针的位置,其中第一位不做调整,最后一位
	 * 根据它前面指针的位置做调整。要使在调整之后，除了第一个指针之外，其余
	 * 的指针都要保持连续。
	 * 例如：a b c d e f
	 *       ^ ^ ^ ^
	 *       x o o x 
	 *       在这里先调整倒数第二个指针，每次调整好之后，要把它后面的
	 *       指针按照顺序调整好。
	 *       a b c d e f => a b c d e f => a b c d e f
	 *       ^ ^   ^ ^      ^ ^   ^ ^      ^ ^     ^ ^
	 *              
	 *       a b c d e f => a b c d e f => a b c d e f
	 *       ^ ^   ^ ^      ^ ^   ^ ^      ^ ^     ^ ^
	 * */
	int max_index = num -1;
	for (int i = max_index; i >= 0 ; --i) {
		if (i == 0) {
			print_string( p,num );
			continue;
		}
		if (i == max_index) {
			print_string( p,num );
			continue;
		}
		adjust_point( p , i , num ,end );
	}
	str++;
	combine( str , num ,(str+strlen( str )-1));
}

int main()
{
	char *str_val = "abcde";
	char *str = NULL;
	
	str = malloc(sizeof(char)*strlen(str_val));
	strncpy( str , str_val , strlen(str_val) );

	for (int i = strlen(str); i >0 ; --i) {
		combine( str , i ,str + strlen( str ));
	}

	printf("m = %d\n",m);
}

