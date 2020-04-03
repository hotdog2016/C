//找出数组中的重复数字
//例 1,5,8,0,9,2,8
/*先进行排序
 *判断当前标号的数字是否与标号一致，如果不一致兑换到相应的标号
 */
#include<stdio.h>
#define VICTOR_SIZE  10
int repeat;
int swap(int * a,int * b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int print_shuzu(int temp[])
{
	int i;
	for(i=0;i<VICTOR_SIZE;i++)
	{
		printf("%d ",temp[i]);
	}
	printf("\n");
}
int test3(int temp[])
{
	int i,j;
	j = 0;
	for(i = 0;i<VICTOR_SIZE;i++)
	{
		while(i != temp[i])
		{
			//如果两个相等说明找到一个重复的数字
			if(temp[i]==temp[temp[i]])
			{
				repeat = temp[i];
				return 0;
			}
			else
			{
				//将此处的数字放到相应的下表处
				swap(&(temp[i]),&(temp[temp[i]]));
				j++;
			}
			if((VICTOR_SIZE-1)==j)
			{
				j = 0;
				break;
			}
		}
	}
}
int main()
{

	int temp[VICTOR_SIZE] = {1,2,3,0,3,2,6,4,9,8};
	if(0==test3(temp))
	{
		printf("ok  num=%d\n",repeat);

	}
	printf("repeat = %d\n",repeat);
}

