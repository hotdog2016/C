#include<stdio.h>
int num_of_1(int num)
{
	int counts=0;
	while ( num )
	{
		counts++;
		num &= ( num-1 );
	}
	return counts;
}
int main()
{
	int counts=0;
	counts=num_of_1(255);
	printf("counts=%d\n",counts);
}

