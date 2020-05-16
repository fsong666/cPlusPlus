#include "add.h"
#include <stdio.h>


bool add( const int* a, const int* b, int* out ){
	if ( a != NULL && b != NULL ) {
		*out = *a + *b; 
		return true;
	}else{
		return false;
	}
}