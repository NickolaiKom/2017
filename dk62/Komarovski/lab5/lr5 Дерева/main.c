#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

int main()
{
	Tree *theTree = createTree();
	
	if(theTree != NULL)
	{
		int index;
		
		while(1)
		{
			index = enterIndex();
			
			switch(index)
			{
				case 1:
					addValue(theTree);
					break;
				case 2:
					addRand(theTree);
					break;
				case 3:
					deleteOneElement(theTree);
					break;
				case 4:
					deleteAllElements(theTree);
					break;
				case 5:
					changeElement(theTree);
					break;
				case 6:
					searchElement(theTree);
					break;
				case 7:
					print(theTree);
					break;
				case 8:
					exitProgram(theTree);
			}
		}
	}
	return 1;
}
