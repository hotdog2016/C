//判断字符串是不是一个数字的科学表示法
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//分为三个部分，A.B[e|E]C

//先判断A部分,这一部分是小数点前的部分，可以为正，可以为负，也可以为0,但必须是整数
//检测是否为整数
bool is_unsigned_int(char **str)
{
	char *start = *str;
	if ( **str == '\0' )
		return false;

	while ((**str != '\0') && (**str >= '0') && (**str <= '9') ) {
		++(*str);
	}

	if (*str > start)
		return true;

	return false;
}

bool is_int(char **str)
{
	if ( **str == '\0')
		return false;

	if( **str == '+' || **str == '-')
		++(*str);

	return is_unsigned_int(str);

}
bool check_string(char *str)
{
	bool part_ok = false;
	if ( *str == '\0')
		return false;
		
	//检查A部分
	part_ok = is_int(&str);

	//检查B部分
	if ('.' == *str)
		++str;
	part_ok = is_unsigned_int(&str) || part_ok;

	//检查C部分
	if ('e' == *str || 'E' == *str) {
		++str;
		part_ok = is_int(&str) && part_ok;
		if (part_ok && *str == '\0')
			return true;
	}
	return false;
}

int main()
{
	bool tmp;
	char string[] = "-123e--456";
	tmp=check_string(string);
	if ( tmp )
		printf("true\n");
	else
		printf("false\n");

}
