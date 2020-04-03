#include<stdio.h>
int vector[4][4]={{1,2,4,5},\
				  {3,4,6,7},\
				  {6,9,10,12},\
				  {5,7,9,20}};
int show_vector(int vector[4][4],int column,int row)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%d ",vector[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int find_num(int vector[4][4],int culomn,int row,int num)
{
	int i,j;
	i=0;
	j=culomn-1;
	while(i<row&&j>=0)
	{
		if(vector[i][j]==num)
		{
			printf("row=%d,culomn=%d\n",i,j);
			return 0;
		}
		else if(num>vector[i][j])
			i++;
		else
			j--;
	}
	printf("False\n");
	return 1;
}
int main()
{
	int num;
	scanf("%d",&num);
	find_num(vector,4,4,num);
}
