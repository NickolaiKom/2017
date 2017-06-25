#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tool.h"

int main()
{
	printf("Enter amount of elements and value for double adding.\n");
	printf("Pivot element will be between 0 and amount value.\n\n");
	
	//������ ����������
	int amount, pivot;
	values(&amount, &pivot);
	
	//������� ������ ��������� �����
	Node *head = NULL;
	addNodes(&head, amount, pivot);
	
	//������� �� ������� � ������� ������
	if(head != NULL)
	{
		printNodes(head, pivot);
		deleteNodes(&head);
	}
	
	return 0;
}
