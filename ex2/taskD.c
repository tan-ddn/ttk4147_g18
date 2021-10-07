#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


int main () 
{
	long capacity = 2;
	Array array1 = array_new(capacity);
    long size = 100*1000*1000; 
	for(int i=0; i< size; i++)
	{
		array_insertBack(&array1, i);
	}

	array_destroy(array1);
		
	return 0;

}


