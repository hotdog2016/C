#include <stdio.h>

int main()
{
	char *str = "abcd";
		
	while ('\0' != *str) {
		printf("%c\n", *str);
		str++;
	}
	
}
