#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_core(char * num, int length)
{
    bool flag = false;

    for (int i = 0; i < length; ++i) {

	if (num[i] > '0' && num[i] <= '9')
	    flag = true;

	if (flag)
	    printf("%c", num[i]);
    }
	printf(" ");
}

void print_1_to_num_core(char* num, int length, int index)
{
    if (index == length - 1) {
	print_core(num, length);
	return;
    }

    for (int i = 0; i < 10; ++i) {
	num[index + 1] = '0' + i;
	print_1_to_num_core(num, length, index + 1);
    }

	printf("\n");
}

void print_1_to_num(int n)
{
    char* num = NULL;
    bool is_overflow = false;
    num = (char*)malloc(sizeof(char) * (n + 1));
    if (num == NULL)
	return;

    for (int i = 0; i < 10; ++i) {
	num[0] = '0' + i;

	print_1_to_num_core(num, n, 0);

    }
}

int main(int argc, char *argv[])
{
	print_1_to_num(4);
	return 0;
}
