#include<stdio.h>
#define VECTOR_SIZE 7
/*
 * 先测前半组，再测后半组
 */
/*计算此范围内的数字在数组中出现的次数
 */
int count_range(int * vector,int lenth,int start,int end)
{
	int count=0;
	int i;
	for(i=0;i<lenth;i++)
	{
		if(vector[i]>=start&&vector[i]<=end)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int start=1;
	int end=VECTOR_SIZE-1;
	int middle=0;
	int count=0;
	int vector[VECTOR_SIZE]={1,5,3,4,6,2,6};
	while(end>=start)
	{

		middle=((end-start)>>1)+start;//调整查询范围
		count=count_range(vector,VECTOR_SIZE,start,middle);

		/*最后当找出来重复的数字时，start和end都是指向同一个数字*/
		if(end==start)
		{
			/*如果存在两个一样的数字，则有重复的数
			 * 否则没有重复的数字
			 */
			if(count>1)
			{
				printf("ok\n");
				return end;
			}
			else
			{
				printf("faulse\n");
				break;
			}
		}

		/*如果当前范围内的数字个数大于当前的范围，则必定存在重复的数
		 * 否则重复的数字必定存在在另一部分
		 */
		if(count>middle-start+1)
		{
			end=middle;
		}
		else
		{
			start=middle+1;
		}
	}
}
