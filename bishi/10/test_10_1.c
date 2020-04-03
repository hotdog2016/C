/*       | 0              n=0
 * f(n)= | 1              n=1 
 *       | f(n-1)+f(n-2)  n>1
 * */
#include<stdio.h>
//int foo(int n)
//{
//	int result[2] = {0,1};
//	long long Fnminusone = 1; 
//	long long Fnminustwo = 0; 
//	long long tmp;
//	if(n<2)
//		return result[n];
//	for(int i=2;i<n+1;i++){
//		tmp=Fnminusone+Fnminustwo;
//		printf("%llu+%llu = %llu\n",Fnminusone,Fnminustwo,tmp);
//		Fnminustwo = Fnminusone;
//		Fnminusone = tmp;
//	}
//	return tmp;
//}
unsigned long long foo(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return foo(n-1)+foo(n-2);
}

int main()
{
	unsigned long long tmp;
	tmp = foo(50);
	printf("%llu\n",tmp);
}
