//快速排序算法
#include<stdio.h>
#include<stdlib.h>
void show_nums(int *numbers,int length)
{
	for(int i=0;i<length;i++)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}
void swap(int *num1,int *num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
void quick(int *numbers,int length,int start,int end)
{
	//快速排序，首先随机找到一个值，然后把他放到最左边
	//结束条件
	if(start==end)
		return;
	int random = rand()%(end-start)+start;
	int p1=start-1;
	printf("random=%d\n",random);
	swap(&numbers[random],&numbers[end]);
	for(int i=start;i<end;i++)
	{
		if(numbers[i] < numbers[end])
		{
			//在遍历过程中让p1始终处于比所选数字小的数字的位置
			++p1;
			if(p1 != i)
				swap(&numbers[p1],&numbers[i]);
		}
	}
	++p1;//遍历完之后，将p1向右移动一次，这时p1指向的数字肯定是大于或等于所选的数字的数
	swap(&numbers[p1],&numbers[end]);//交换p1处和end处的数字，p1处的值左边都是小于他的数，右边都是大于他的
	if(start < p1) //对p1左边的数组进行位置调整
		quick(numbers,length,start,p1-1);
	if(p1 < end) //对p1右边的数组进行调整
		quick(numbers,length,p1+1,end);
}

int main()
{
#define LEN  8
	int nums[LEN]={2,4,3,5,4,7,4,5};
	show_nums(nums,LEN);
	quick(nums, 8 , 0 , LEN-1);
	show_nums(nums,LEN);

}

