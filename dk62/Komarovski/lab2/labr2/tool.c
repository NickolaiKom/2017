#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool.h"
#include "sorts.h"

void values(int *aSize, int *aTest)
{
	do{
    	printf("Enter amount of elements between 2 and 100000: ");
    	scanf("%i", &(*aSize));
	}while(*aSize < 2 || *aSize > 100000);
	
	do{
	    printf("\nSelect type of sorting:\n1 - Every type;\n2 - Bubble;");
		printf("\n3 - Selection;\n4 - Insertion;\n\nEnter: ");
    	scanf("%i", &(*aTest));
	}while(*aTest < 1 || *aTest > 4);
}

void fillValues(int *anArray, int aSize)
{
	srand(time(NULL));
	for(int i = 0; i < aSize; i++)
		anArray[i] = rand();
}

void aSort(int *anArray, int aSize, int aTest)
{
	FILE *file = fopen("Results.txt", "w");
	if(file != NULL)
	{
		double time;
		fprintf(file, "Type of algorithm\tTime\n\n");
	
		switch(aTest)
		{
		case 1:
		case 2:
			printf("Bubble sort started...\n");
			time = clock();
			bubblesort(anArray, aSize);
			time = clock() - time;
			time /= CLOCKS_PER_SEC;
			
			printf("Bubble sort finished.\n");
			fprintf(file, "Bubblesort\t\t\t%.3lf sec\n", time);
			
			if(aTest == 1)
				fillValues(anArray, aSize);
			else
				break;
		case 3:
			printf("Selection sort started...\n");
			time = clock();
			selectionsort(anArray, aSize);
			time = clock() - time;
			time /= CLOCKS_PER_SEC;
			
			printf("Selection sort finished.\n");
			fprintf(file, "Selection\t\t\t%.3lf sec\n", time);
			
			if(aTest == 1)
				fillValues(anArray, aSize);
			else
				break;
		case 4:
			printf("Insertion sort started...\n");
			time = clock();
			insertionsort(anArray, aSize);
			time = clock() - time;
			time /= CLOCKS_PER_SEC;
			
			printf("Insertion sort finished.\n");
			fprintf(file, "Insertion\t\t\t%.3lf sec", time);
		}
		fflush(file);
		fclose(file);
	}
	else
	{
		printf("Problem with file!\n\n");
		exit(2);
	}
}
