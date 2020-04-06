#include<stdio.h>
#include<stdlib.h>
int max_length(int length)
{
	int *len=NULL;
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;
	len=(int *)malloc(sizeof(int)*(length+1));
	//0,1,2,3是比较特殊的情况，可以直接得出，后面会以这些长度的绳子为基数
	len[0]=0;//长度为0的绳子
	len[1]=1;//长度为1的绳子
	len[2]=2;//长度为2的绳子
	len[3]=3;//长度为3的绳子
	for(int i=4;i<=length;i++)
	{
		int max=0;
		for(int j=1;j<=i/2;j++)
		{
			if(max<len[j]*len[i-j])
				max=len[j]*len[i-j];
		}
		len[i]=max;
	}
	return len[length];
}
int main()
{
	int max=0;
	max=max_length(10);
	printf("max=%d\n",max);
}
