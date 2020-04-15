#include <stdio.h>

int power(int num, int n)
{
	int result=0;
    if (0 == n) {
	return 1;
    }
    if (1 == n) {
	return num;
    }
    result = power(num, n >> 1) * power(num,n>>1);
    if (0x1 & n) {
	result *= num;
    }
    return result;
}

int main(int argc, char* argv[])
{
    int num = 0;
    num = power(2, 1);
    printf("%d\n", num);
}
