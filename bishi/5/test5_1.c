/*
 * 找出字符串中的空格，并用%20代替
 * 思路：
 * 1.设置两个指针，一个指向替换前的字符串末尾，一个指向替换后的字符串末尾
 * 2.将字符串从后往前复制，遇到空格就改成%20
 * 注意：***字符串最后一个字符为'\0'
 *		 ***在使用指针之前，一定要先把空间申请好
 * */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int show_string(const char * string)
{
	if(NULL==string)
	{
		printf("error1\n");
		return -1;
	}
	while('\0'!=*string)
	{
		printf("%c",*string);
		string++;
	}
	printf("\n");
	return 0;
}
int cheack_blank(const char * string)
{
	int count=0;
	if(NULL==string)
	{
		printf("error2\n");
		return -1;
	}
	while('\0'!=*string)
	{
		if(' '==*string)
		{
			count++;
			string++;
		}
		else
		{
			string++;
		}
	}
	return count;
}

int change_string(char * string,int blank_counts)
{
	char replace[3]={'0','2','%'};
	char *p1;
	char *p2;
	int lens,replace_len;
	int i;
	lens = strlen(string);
	replace_len=strlen(replace);
	p1=string+lens+1;//包括'\0'
	p2=p1+blank_counts*(replace_len-1);
	show_string(replace);
	if(NULL==p1||NULL==p2)
	{
		printf("error\n");
	}
	while(1)
	{
		if(' '==*p1)
		{
			for(i=0;i<replace_len;i++)
			{
				*p2=replace[i];
				p2--;
			}
			p1--;	
		}
		else
		{
			*p2=*p1;
			if(p1==string)
			{
				show_string(string);
				return 0;
			}
			p1--;
			p2--;
		}
	}
	return 0;
}
int main()
{
	char * string;
	char * temp_string="we are happy new year  hello";
	int blank_counts;
	string=(char *)malloc(100);
	strcpy(string,temp_string);
	blank_counts=cheack_blank(string);
	change_string(string,blank_counts);
}
