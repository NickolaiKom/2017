#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool.h"
#include "sorts.h"
#include "searches.h"

void values(int *aSize, int *aTest, int *aTest2)
{
	do{
    	printf("Enter amount of elements between 2 and 100000: ");
    	scanf("%i", &(*aSize));
	}while(*aSize < 2 || *aSize > 100000);
	
	do{
	    printf("\nSelect type of sorting:\n1 - Every type;\n2 - Shell;");
		printf("\n3 - Quick;\n\nEnter: ");
    	scanf("%i", &(*aTest));
	}while(*aTest < 1 || *aTest > 3);
	
	do{
		printf("\nSelect type of searching:\n1 - All types;\n2 - Line;\n");
		printf("3 - Binary;\n\nEnter: ");
    	scanf("%i", &(*aTest2));
	}while(*aTest2 < 1 || *aTest2 > 3);

}

void fillValues(int *anArray, int aSize)
{
	srand(time(NULL));
	for(int i = 0; i < aSize; i++)
		anArray[i] = rand();
}

void aSort(FILE *file, int *anArray, int aSize, int aTest)
{
	double time;
	fprintf(file, "Type of algorithm\tTime\n\n");
	
	switch(aTest)
	{
	case 1:
	case 2:
		printf("\nShell sort started...\n");
		time = clock();
		shellSort(anArray, aSize);
		time = clock() - time;
		time /= CLOCKS_PER_SEC;
		
		printf("Shell sort finished.\n\n");
		fprintf(file, "Shellsort\t\t\t%.3lf sec\n", time);
		
		if(aTest == 1)
			fillValues(anArray, aSize);
		else
			break;
	case 3:
		printf("Quick sort started...\n");
		time = clock();
		quickSort(anArray, 0, aSize - 1);
		time = clock() - time;
		time /= CLOCKS_PER_SEC;
		
		printf("Quick sort finished.\n\n");
		fprintf(file, "Quicksort\t\t\t%.3lf sec\n", time);
	}
}

void aSearch(FILE *file, int *anArray, int aSize, int aTest2)
{
	double timer;
	int pivot, result;
	
	switch(aTest2)
	{
	case 1:
	case 2:
		printf("Line search started...\n");
		pivot = rand();
		printf("Random value to search: %i\n", pivot);
		
		timer = clock();
		result = lineSearch(pivot, aSize, anArray);
		timer = clock() - timer;
		timer /= CLOCKS_PER_SEC;
		
		printf("Line search finished.\n");
		fprintf(file, "Line search\t\t\t%.3lf sec\n", timer);
		
		if(result >= 0)
			printf("Position of element: %i\n\n", result);
		else
			printf("Not founded!\n\n");
		
		if(aTest2 != 1)
			break;
	case 3:
		printf("Binary search  started...\n");
		pivot = rand();
		printf("Random value to search: %i\n", pivot);
		
		timer = clock();
		result = binarySearch(pivot, aSize, anArray);
		timer = clock() - timer;
		timer /= CLOCKS_PER_SEC;
		
		printf("Binary search finished.\n");
		fprintf(file, "Binary search\t\t%.3lf sec\t\t", time);
		
		if(result >= 0)
			printf("Position of element: %i\n\n", result);
		else
			printf("Not founded!\n\n");
	}
}
