#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"
#include "tool.h"
#include "searches.h"

int main()
{
	int aSize, aTest, aTest2;
	
	printf("Program supports the random numbers 0-32767.\n");
	
	values(&aSize, &aTest, &aTest2);
	
	int *anArray = (int *) malloc(sizeof(int) * aSize);
	FILE *file = fopen("Results.txt", "w");
	if(anArray != NULL && file != NULL)
	{
		fillValues(anArray, aSize);
		printArray(anArray, aSize);
		
		aSort(file, anArray, aSize, aTest);
		printArray(anArray, aSize);
		aSearch(file, anArray, aSize, aTest2);
		
		fflush(file);
		fclose(file);
		
		free(anArray);
		return 0;
	}
	return 1;
}
