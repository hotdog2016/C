/*
 * 逆转数字，找最小数字
 * */
#include<stdio.h>
//[4,5,6,7,8,1,2,3]
int min(int *numbers , int length)
{
	int min;
	for(int i=0;i<length;i++){
		if(i == 0)
			min = numbers[i];
		if(numbers[i] < min)
			min = numbers[i];
	}
	return min;
}
int test(int *numbers,int length)
{
	int p1 = 0;
	int p2 = length-1;
	int mid = p1;
	//先比较p1和p2的大小，如果p1>p2说明数组是反转的，最小值在数组里面
	while(numbers[p1] >= numbers[p2]){
		//如果只剩下两个数字时
		if(p2-p1 == 1)
			return numbers[p2];
		// 先设置mid为数组中间的数字
		mid = (p1+p2)/2;
		//特殊情况，如果p1 p2 mid 这三个位置的数字相等，则只能用遍历法找到最小的数字
		if(numbers[p1] == numbers[p2] && numbers[mid] == numbers[p2]){
			length = p2-p1+1;
			return min(numbers,length);
		}
		//如果mid位置的数字大于p1位置的数字，那么最小数就在mid后面，把数组的范围改成mid和p2之间
		if(numbers[mid] >= numbers[p1]) 
			p1 = mid;
		else if(numbers[mid] <= numbers[p2]) //如果mid位置的数字小于p2位置的数字，那么最小数就在mid前面，把数组的范围改成mid和p2之间
			p2 = mid;
	}
	//如果p1位置的数字小于p2位置的数字，则数组是排好序的，直接输出p1就是最小的数字
	return numbers[mid];
}
int main()
{
	int min;
	int numbers[8] = {3,5,6,3,8,8,2,3};
	min = test(numbers,8);
	printf("min=%d\n",min);
	return 0;
}
