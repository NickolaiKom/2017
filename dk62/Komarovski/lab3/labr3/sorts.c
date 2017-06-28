#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void shellSort(int *anArray, int aSize)
{
	int theInner = 0, theOuter = 0, H = 1;
	
	while(H <= aSize / 3)
		H = H * 3 + 1;
	
	while(H > 0)
	{
		for(theOuter = H; theOuter < aSize; theOuter++)
		{
			int tmp = anArray[theOuter];
			theInner = theOuter;
			
			while(theInner > H - 1 && anArray[theInner - H] >= tmp)
			{
				anArray[theInner] = anArray[theInner - H];
				theInner -= H;
			}
			anArray[theInner] = tmp;
		}
		H = (H - 1) / 3;
	}
}

void quickSort(int *anArray, int first, int last)
{
	int theInner = first, theOuter = last, w = anArray[(first + last) / 2];
	do{
		while(anArray[theInner] < w)
			theInner++;
	    while(anArray[theOuter] > w)
			theOuter--;
	
		if(theInner <= theOuter)
		{
			if(anArray[theInner] > anArray[theOuter])
				swap(&anArray[theInner], &anArray[theOuter]);
			theInner++;
			theOuter--;
		}
	}while(theInner <= theOuter);
	
	if(theInner < last)
		quickSort(anArray, theInner, last);
	if(first < theOuter)
		quickSort(anArray, first, theOuter);
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
