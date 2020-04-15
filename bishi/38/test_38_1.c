#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"
#include "../inc/list.h"


void print_string( char *str )
{
	char *ch = str;
	while ( *ch != '\0' )
	{
		printf("%c ",*ch); 
		ch++;
	}
	printf("\n");
}

void swap( char *ch1,char *ch2)
{
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

void permutation_and_combination(char *start , char *end ,char *str)
{
	char *p1 = start;
	char *p2 = start;

	if ( start == end ) {
		print_string(str);
		return;
	}

	while ( *p2 != '\0' )
	{
		swap( p1 , p2 );
		permutation_and_combination( start+1 , end ,str);
		swap( p1 , p2 );
		p2++;
	}
}

int main()
{
	
	char *str = NULL;
	char tmp;
	char *const_string = "abc";
	str = (char *)malloc( sizeof(char)*100 );

	memcpy( str , const_string , strlen( const_string ) );

	permutation_and_combination( str , str+strlen(str)-1,str );


}

