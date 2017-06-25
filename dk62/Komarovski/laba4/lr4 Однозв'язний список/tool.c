#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

void values(int *amount, int *pivot)
{
	do{
		printf("Enter amount: ");
		scanf("%i", *(&amount));
	}while(*amount <= 0);
	
	do{
		printf("Enter pivot between 0 and %i: ", *amount);
		scanf("%i", *(&pivot));
	}while(*pivot < 0 || *pivot > *amount);
	printf("\n");
}

void addNodes(Node **head, int amount, int pivot)
{
	int tmp;
	srand(time(NULL));
	
	for(int i = 0; i < amount; i++)
	{
		tmp = rand() % (amount + 1);
		addElement(head, tmp);
		
		if(tmp == pivot)
			addElement(head, tmp);
	}
}

void addElement(Node **head, int value)
{
	Node *tmp = (Node *) malloc(sizeof(Node));
	tmp->next = *head;
	tmp->value = value;
	*head = tmp;
	tmp = NULL;
}

void deleteNodes(Node **head)
{
	if(head != NULL)
	{
		Node *tmp = NULL;
		while((*head)->next != NULL)
		{
	    	tmp = *head;
	    	*head = (*head)->next;
	    	free(tmp);
	    }
		free(*head);
		*head = NULL;
	}
}

void printNodes(Node *head, int pivot)
{
	while(head != NULL)
	{
		if(head->value != pivot)
			printf("%i ", head->value);
		else
			printf("!_%i_! ", head->value);
		
		head = head->next;
	}
	printf("\n");
}
