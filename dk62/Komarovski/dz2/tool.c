#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tool.h"

List *createList(int aSize)
{
	List *Head = (List *) malloc(sizeof(List));
	
	if(Head != NULL)
	{
		Head->aSize = aSize;
		Head->aCurrentSize = 0;
		
		for(int i = 0; i < aSize; i++)
			Head->theList[i] = (Piramide *) malloc(sizeof(Piramide));
		
	}
	return Head;
}

int addPiramide(List *Head)
{
	if(Head->aCurrentSize < Head->aSize)
	{
		Piramide *object = Head->theList[Head->aCurrentSize];
		
		if(object != NULL)
		{
			object->A = (Coordinate *) malloc(sizeof(Coordinate));
			object->B = (Coordinate *) malloc(sizeof(Coordinate));
			object->C = (Coordinate *) malloc(sizeof(Coordinate));
			object->D = (Coordinate *) malloc(sizeof(Coordinate));
			
			if(object->A != NULL && object->B != NULL && object->C != NULL && object->D != NULL)
			{
				coordinate(object);
				printf("\nCreated\n");
				
				double square = aSquare(object);
				printf("Area: %lf\n\n", square);
				
				Head->aCurrentSize++;
				return 0;
			}
			
			return 1;
		}
		
		return 1;
	}
	
	return 1;
}

void coordinate(Piramide *object)
{
	printf("Dot A:\nEnter x coordinate: ");
	scanf("%i", &(object->A->x));
	
	printf("Enter y coordinate: ");
	scanf("%i", &(object->A->y));
	
	printf("Enter z coordinate: ");
	scanf("%i", &(object->A->z));
	
	printf("Dot B:\nEnter x coordinate: ");
	scanf("%i", &(object->B->x));
	
	printf("Enter y coordinate: ");
	scanf("%i", &(object->B->y));
	
	printf("Enter z coordinate: ");
	scanf("%i", &(object->B->z));
	
	printf("Dot C:\nEnter x coordinate: ");
	scanf("%i", &(object->C->x));
	
	printf("Enter y coordinate: ");
	scanf("%i", &(object->C->y));
	
	printf("Enter z coordinate: ");
	scanf("%i", &(object->C->z));
	
	printf("Dot D:\nEnter x coordinate: ");
	scanf("%i", &(object->D->x));
	
	printf("Enter y coordinate: ");
	scanf("%i", &(object->D->y));
	
	printf("Enter z coordinate: ");
	scanf("%i", &(object->D->z));
}

double aSquare(Piramide *object)
{
	double result, tmp1, tmp2, tmp3;
	tmp1 = (object->B->y - object->A->y) * (object->C->z - object->A->z);
	tmp1 -= (object->C->y - object->A->y) * (object->B->z - object->A->z);
	
	tmp2 = (object->B->x - object->A->x) * (object->C->z - object->A->z);
	tmp2 -= (object->C->x - object->A->x) * (object->B->z - object->A->z);
	
	tmp3 = (object->B->x - object->A->x) * (object->C->y - object->A->y);
	tmp3 -= (object->C->x - object->A->x) * (object->B->y - object->A->y);
	result = sqrt(pow(tmp1, 2) + pow(tmp2, 2) + pow(tmp3, 2)) / 2;
	
	tmp1 = (object->B->y - object->A->y) * (object->D->z - object->A->z);
	tmp1 -= (object->D->y - object->A->y) * (object->B->z - object->A->z);
	
	tmp2 = (object->B->x - object->A->x) * (object->D->z - object->A->z);
	tmp2 -= (object->D->x - object->A->x) * (object->B->z - object->A->z);
	
	tmp3 = (object->B->x - object->A->x) * (object->D->y - object->A->y);
	tmp3 -= (object->D->x - object->A->x) * (object->B->y - object->A->y);
	result += sqrt(pow(tmp1, 2) + pow(tmp2, 2) + pow(tmp3, 2)) / 2;
	
	tmp1 = (object->C->y - object->A->y) * (object->D->z - object->A->z);
	tmp1 -= (object->D->y - object->A->y) * (object->C->z - object->A->z);
	
	tmp2 = (object->C->x - object->A->x) * (object->D->z - object->A->z);
	tmp2 -= (object->D->x - object->A->x) * (object->C->z - object->A->z);
	
	tmp3 = (object->C->x - object->A->x) * (object->D->y - object->A->y);
	tmp3 -= (object->D->x - object->A->x) * (object->C->y - object->A->y);
	result += sqrt(pow(tmp1, 2) + pow(tmp2, 2) + pow(tmp3, 2)) / 2;
	
	tmp1 = (object->C->y - object->B->y) * (object->D->z - object->B->z);
	tmp1 -= (object->D->y - object->B->y) * (object->C->z - object->B->z);
	
	tmp2 = (object->C->x - object->B->x) * (object->D->z - object->B->z);
	tmp2 -= (object->D->x - object->B->x) * (object->C->z - object->B->z);
	
	tmp3 = (object->C->x - object->B->x) * (object->D->y - object->B->y);
	tmp3 -= (object->D->x - object->B->x) * (object->C->y - object->B->y);
	result += sqrt(pow(tmp1, 2) + pow(tmp2, 2) + pow(tmp3, 2)) / 2;
	
	if(result < 0)
		result *= -1;
	
	return result;
}

void deleteList(List *Head)
{
	if(Head != NULL)
	{
		for(int i = 0; i < Head->aSize; i++)
		{
			deletePir(Head, i);
			free(Head->theList[i]);
		}
		
		free(Head);
	}
}

void deletePir(List *Head, int i)
{
	if(i < Head->aCurrentSize)
	{
		Piramide *object = Head->theList[i];
		
		free(object->A);
		free(object->B);
		free(object->C);
		free(object->D);
		
		Head->aCurrentSize--;
	}
}

void printList(List *Head)
{
	if(Head != NULL)
	{
		for(int i = 0; i < Head->aCurrentSize; i++)
			printPir(Head, i);
	}
}

void printPir(List *Head, int i)
{
	if(Head != NULL)
	{
		Piramide *object = Head->theList[i];
		
		printf("\nPiramide %i\nArea: %lf\n", i, aSquare(object));
		printf("Dot A: X:%i\tY:%i\tZ:%i\n", object->A->x, object->A->y, object->A->z);
		printf("Dot B: X:%i\tY:%i\tZ:%i\n", object->B->x, object->B->y, object->B->z);
		printf("Dot C: X:%i\tY:%i\tZ:%i\n", object->C->x, object->C->y, object->C->z);
		printf("Dot D: X:%i\tY:%i\tZ:%i\n", object->D->x, object->D->y, object->D->z);
	}
}

int anAmount()
{
	int amount;
	
	do{
		printf("Enter amount of piramides: ");
		scanf("%i", &amount);
	}while(amount < 1 || amount > 5);
	
	return amount;
}
