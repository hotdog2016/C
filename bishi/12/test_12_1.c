#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define ROWS  3
#define COLUMNS 4

bool search_path(char *matrix,\
		int rows,\
		int columns,\
		int row,\
		int col,\
		char *str,\
		int path_deep,\
		bool *bool_matrix)
{
	bool has=false;
	if(str[path_deep]=='\0')
	{
		return true;
	}
	if(matrix != NULL && bool_matrix != NULL)
	{
		if(row >= 0 && row < rows\
				&&col >= 0 && col < columns\
				&&matrix[row*COLUMNS+col]==str[path_deep]\
				&&bool_matrix[row*columns+col] == false)
		{
			++path_deep;
			bool_matrix[row*columns+col]=true;
			has = search_path(matrix,rows,columns,row,col-1,str,path_deep,bool_matrix)\
				  ||search_path(matrix,rows,columns,row,col+1,str,path_deep,bool_matrix)\
				  ||search_path(matrix,rows,columns,row-1,col,str,path_deep,bool_matrix)\
				  ||search_path(matrix,rows,columns,row+1,col,str,path_deep,bool_matrix);
		}
		if(!has)
			bool_matrix[row*columns+col]=false;
	}
	return has;
}
bool has_path(char *matrix,\
		int rows,\
		int columns,\
		char *str)
{
	bool has=false;
	bool bool_matrix[ROWS*COLUMNS];
	memset(bool_matrix,0,ROWS*COLUMNS);
	int path_deep=0;
	for (int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			has=search_path(matrix,ROWS,COLUMNS,i,j,str,path_deep,bool_matrix);
			if(has)
				return true;
		}
	}
	return false;
}
int main()
{
	bool has;
	char matrix[ROWS*COLUMNS] =\
	{'a','y','q','m',\
	'b','c','e','n',\
	'j','d','l','g'};

	char *str="ayqmnglecbj";

	has=has_path(matrix,ROWS,COLUMNS,str);
	if(has)
		printf("ok\n");
	else
		printf("no path!\n");
}
