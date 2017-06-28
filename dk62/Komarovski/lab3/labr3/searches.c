#include <stdio.h>
#include <stdlib.h>

#include "searches.h"

int lineSearch(int value, int aSize, int *anArray)
{
	for(int i = 0; i < aSize; i++)
	{
		if(anArray[i] == value)
			return i;
	}
	return -1;
}

int binarySearch(int value, int aSize, int *anArray)
{
	int middle, lower = 0, upper = aSize - 1;
	while(lower <= upper)
    {
    	middle = (lower + upper) / 2;
	    
	    if(anArray[middle] == value)
	        return middle;
		
	    else if(anArray[middle] < value)
	        lower = middle + 1;
	    
	    else
	        upper = middle - 1;
    }
	return -1;
}
