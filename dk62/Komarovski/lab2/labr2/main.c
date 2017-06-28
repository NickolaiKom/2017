#include <stdio.h>
#include <stdlib.h>

#include "tool.h"
#include "sorts.h"

int main()
{
	int aSize, aTest;
	
	printf("Program supports the random numbers 0-32767.\n");
	
	values(&aSize, &aTest);
	
	int *anArray = (int *) malloc(sizeof(int) * aSize);
	if(anArray != NULL)
	{
		fillValues(anArray, aSize);
		//printArray(anArray, aSize);
		
		aSort(anArray, aSize, aTest);
		//printArray(anArray, aSize);
		
		free(anArray);
		return 0;
	}
	return 1;
}
