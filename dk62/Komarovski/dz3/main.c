#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main()
{
	printf("Max amount of piramides: 5\n");
	int amount = anAmount();
	
	List *Head = createList(amount);
	
	if(Head != NULL)
	{
		printf("\nPiramide has 4 dots\n\n");
		
		for(int i = 0; i < amount; i++)
		{
			if(addPiramide(Head) != 0)
			{
				deleteList(Head);
				return 1;
			}
		}
		
		printList(Head);
		printJson(Head);
		deleteList(Head);
		
		return 0;	
	}
	return 1;
}
