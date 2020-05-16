#include <stdio.h>
//#include "add.h"
//#include "sub.h"
#include "my_lib.h"

int main(void)
{
    printf("Hello libmyso.so!\n");
    int a = 100, b = 20, out;
    if( add( &a, &b, &out ) ){
    	printf("%d\n", out);

    }
    if( sub( &a, &b, &out ) ){
    	printf("%d\n", out);

   }
    return 0;
}