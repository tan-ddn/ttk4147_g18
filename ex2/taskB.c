#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


int main () 
{
	long capacity = 10;
	Array array1 = array_new(capacity);

	for(int i=0; i<= 11; i++)
	{
		array_insertBack(&array1, i);
	}

	array_destroy(array1);
		
	return 0;

}


