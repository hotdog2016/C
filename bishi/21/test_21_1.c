#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool is_odd(int num)
{
	if (num & 0x1)
		return true;
	else 
		return false;
}

void sort_odd_before_even(int *num,int length)
{
	int *p1 = num;
	int *p2 = num + length - 1;

	if ( NULL == num )
		return ;

	while (p1 < p2) {
		if ( false==is_odd( *p1) && true == is_odd(*p2)) {
			int tmp;
			tmp = *p1;
			*p1 = *p2;
			*p2 = tmp;
			p1++;
			p2--;
		}
		else if (true == is_odd(*p1) && true == is_odd(*p2))
			p1++;
		else if (false == is_odd(*p1) && false == is_odd(*p2))
			p2--;
		else 
			p2--;
	}
}
int main()
{
	int num[15] = {1,2,3,4,5,1,3,7,8,6,3,11,15,20};

	for (int i = 0; i < 15; ++i)
		printf("%d", num[i]);
	printf("\n");
	sort_odd_before_even(num,15);

	for (int i = 0; i < 15; ++i)
		printf("%d", num[i]);
}
