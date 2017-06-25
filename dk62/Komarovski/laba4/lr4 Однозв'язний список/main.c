#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tool.h"

int main()
{
	printf("Enter amount of elements and value for double adding.\n");
	printf("Pivot element will be between 0 and amount value.\n\n");
	
	//вводим переменные
	int amount, pivot;
	values(&amount, &pivot);
	
	//создаем список рандомных чисел
	Node *head = NULL;
	addNodes(&head, amount, pivot);
	
	//выводим на монитор и удаляем список
	if(head != NULL)
	{
		printNodes(head, pivot);
		deleteNodes(&head);
	}
	
	return 0;
}
