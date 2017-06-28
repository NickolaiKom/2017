#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void bubblesort(int *anArray, int aSize)
{
	int k, i, swaps;
	for(k = 0; k < aSize-1; k++)
    {
    	for(i = 0; i < aSize-1-k; i++)
        {
        	if(anArray[i] > anArray[i+1])
            {
            	swap(&anArray[i], &anArray[i+1]);
            	swaps++;
            }
        }
    	
		if(swaps == 0)
    		break;
    }
}

void selectionsort(int *anArray, int aSize)
{
	int theOut;
	for(theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut, theIn;
		for(theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if(anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
		swap(&anArray[theOut], &anArray[theMinIndex]);
	}
}

void insertionsort(int *anArray, int aSize)
{
	int theOut;
	for(theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;
		while(theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			theIn--;
		}
		anArray[theIn] = theTmp;
	}
}

void swap(int *val1, int *val2)
{
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void printArray(int *anArray, int aSize)
{
	for(int i = 0; i < aSize; i++)
		printf("%i ", anArray[i]);
	printf("\n");
}
