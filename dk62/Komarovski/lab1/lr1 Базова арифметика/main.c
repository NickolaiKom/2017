#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main()
{
	printf("Enter 3 integer values. Attention, don't use big values. Value B != 0.\n\n");
	
	int a, b, c;
	double Q = 0;
	
	//������ ��������
	values(&a, &b, &c);
	
	//����������� ������� �����
	Q = formula(a, b, c);
	sigma(&Q, a, c);
	
	//������� �� �������
	printf("\nQ = %lf", Q);
	return 0;
}
