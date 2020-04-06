/*机器人走方格，设置坐标的数位和，坐标的数位和不能超过设置的数字*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define ROWS 3
#define COLUMNS 3

int digital_sum(int num)
{
	int sum=0;
	while(num>0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}

int check(int *matrix,int rows,int columns,int row,int col,int max,bool *bool_matrix)
{
	int count=0;
	if(matrix != NULL && bool_matrix != NULL)
	{
		if(row>=0 && row<rows\
				&&col>=0 && col<columns\
				&&bool_matrix[row*COLUMNS+col]!=true)
		{
			int tmp=0;
			tmp=digital_sum(row)+digital_sum(col);
			//printf("digital_sum=%d\n",tmp);
			bool_matrix[row*columns+col]=true;
			if(tmp <= max)
			{
				count=1+check(matrix,rows,columns,row,col,max,bool_matrix)\
					  +check(matrix,rows,columns,row+1,col,max,bool_matrix)\
					  +check(matrix,rows,columns,row,col-1,max,bool_matrix)\
					  +check(matrix,rows,columns,row,col+1,max,bool_matrix);
			}
		}
	}
	return count;
}

int count_path(int *matrix,int rows,int columns,int max)
{
	bool bool_matrix[ROWS*COLUMNS];
	int count=0;
	memset(bool_matrix,0,ROWS*COLUMNS);
	count=check(matrix,rows,columns,0,0,max,bool_matrix); 
	return count;
}

int main()
{
	int max=2;
	int matrix[ROWS*COLUMNS];
	int count=0;
	memset(matrix,1,ROWS*COLUMNS);
	count=count_path(matrix,ROWS,COLUMNS,max);
	if(count)
		printf("counts=%d\n",count);
	else
		printf("no path\n");
}
