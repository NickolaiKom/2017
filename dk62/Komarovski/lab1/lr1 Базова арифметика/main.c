#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main()
{
	printf("Enter 3 integer values. Attention, don't use big values. Value B != 0.\n\n");
	
	int a, b, c;
	double Q = 0;
	
	//вводим значения
	values(&a, &b, &c);
	
	//расчитываем искомое число
	Q = formula(a, b, c);
	sigma(&Q, a, c);
	
	//выводим на монитор
	printf("\nQ = %lf", Q);
	return 0;
}
