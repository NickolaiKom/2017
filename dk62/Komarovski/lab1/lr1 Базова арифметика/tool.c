#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

void values(int *a, int *b, int *c)
{
	printf("Enter A: ");
	scanf("%i", *(&a));
	
	do{
		printf("Enter B: ");
		scanf("%i", *(&b));
	}while(*b == 0);
	
	do{
		printf("Enter C: ");
		scanf("%i", *(&c));
	}while(*b + *c < 0);
}

double formula(int a, int b, int c)
{
	double tmp = sqrt(b + c);
	tmp *= a;
	tmp /= b;
	
	return tmp;
}

void sigma(double *Q, int a, int c)
{
	for(int D = 0; D <= c; D++)
		*Q += factorial(D + a);
}

unsigned long int factorial(int x)
{
	if(x != 0)
	{
		unsigned long int result = 1;
		
		for(int i = 1; i <= x; i++)
		    result *= i;
		
		return result;
	}
	else
		return 1;
}
