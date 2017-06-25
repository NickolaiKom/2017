#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "tool.h"

int enterIndex()
{
	int tmp;
	
	printf("\nEnter number of option:\n1 - add value to tree\n2 - add a few random values to tree\n");
	printf("3 - delete element\n4 - delete all elements\n5 - change element\n");
	printf("6 - search element\n7 - print tree\n8 - exit program\n");
	
	do{
		printf("Enter: ");
		scanf("%i", &tmp);
	}while(tmp < 1 || tmp > 8);
	
	return tmp;
}

void addValue(Tree *aTree)
{
	Node *tmp = NULL;
	float value;
	
	do{
		printf("Enter value to add: ");
		scanf("%f", &value);
		
		tmp = searching(aTree->root, value);
	}while(tmp != NULL);
	
	insertElement(aTree, value);
}

void addRand(Tree *aTree)
{
	srand(time(NULL));
	
	Node *tmp = NULL;
	int amount;
	float value;
	
	do{
		printf("Enter amount of random values: ");
		scanf("%i", &amount);
	}while(amount < 1);
	
	insertElement(aTree, 22.2);
	for(int i = 0; i < amount - 1; i++)
	{
		do{
			value = rand();
			value /= 10;
			tmp = searching(aTree->root, value);
		}while(tmp != NULL);
		
		insertElement(aTree, value);	
	}
}

void deleteAllElements(Tree *aTree)
{
	if(aTree->root != NULL)
	{
		destroyNode(aTree, aTree->root);
		aTree->root = NULL;
	}
	else
		printf("The tree is empty\n");
}

void deleteOneElement(Tree *aTree)
{
	if(aTree->root != NULL)
	{
		Node *tmp = NULL;
		float value;
		
		printf("\nEnter element to delete: ");
		do{
			scanf("%f", &value);
			tmp = searching(aTree->root, value);
			
			if(tmp == NULL)
				printf("No such element.\nRetry: ");
		
		}while(tmp == NULL);
		
		deleteElementByValue(aTree, value);
	}
}

void changeElement(Tree *aTree)
{
	if(aTree->root != NULL)
	{
		Node *tmp = NULL;
		float value1, value2;
		
		printf("\nEnter element to change: ");
		do{
			scanf("%f", &value1);
			tmp = searching(aTree->root, value1);
			
			if(tmp == NULL)
				printf("No such element.\nRetry: ");
			
		}while(tmp == NULL);
		
		printf("Enter new value: ");
		scanf("%f", &value2);
		
		deleteElementByValue(aTree, value1);
		insertElement(aTree, value2);
	}
}

void searchElement(Tree *aTree)
{
	Node *tmp = NULL;
	float value;
	
	printf("Enter element to search: ");
	scanf("%f", &value);
	tmp = searching(aTree->root, value);

	if(tmp != NULL)
		printf("Finded!\n");
	else
		printf("No such element.\n");
}

void exitProgram(Tree *aTree)
{
	if(aTree != NULL)
		destroyTree(aTree);
	
	exit(0);
}

Tree *createTree()
{
	Tree *aTree = (Tree *) malloc(sizeof(Tree));
	if(aTree != NULL)
	{
		aTree->count = 0;
		aTree->root = NULL;
	}
	
	return aTree;
}

void destroyTree(Tree *aTree)
{
	if(aTree != NULL && aTree->root != NULL)
	{
		destroyNode(aTree, aTree->root);
		free(aTree);
	}
}

Node *createNode(Node *aParent, float value)
{
	Node *aNode = (Node *) malloc(sizeof(Node));
	if(aNode != NULL)
	{
		aNode->highParent = aParent;
		aNode->leftChild = NULL;
		aNode->rightChild = NULL;
		aNode->value = value;
	}
	
	return aNode;
}

void destroyNode(Tree *aTree, Node *aNode)
{
	if(aNode != NULL)
	{
		destroyNode(aTree, aNode->leftChild);
		destroyNode(aTree, aNode->rightChild);
		free(aNode);
		aTree->count--;
	}
}

void insertElement(Tree *aTree, float value)
{
	if(aTree != NULL)
	{
		if(aTree->root == NULL)
		{
			Node *aNode = createNode(aTree->root, value);	//(NULL, value);
			if(aNode != NULL)
			{
				aTree->root = aNode;
				aTree->count++;
			}
		}
		
		else
		{
			Node *chil = aTree->root;
			Node *par = NULL;
			
			while(1)
			{
				par = chil;
				
				if(value == chil->value)
				{
					printf("Same element was added!\n");
					break;
				}
				
				if(value < chil->value)
				{
					chil = chil->leftChild;
					if(chil == NULL)
					{
						Node *aNode = createNode(par, value);
						par->leftChild = aNode;
						aTree->count++;
						break;
					}
				}
				
				else
				{
					chil = chil->rightChild;
					if(chil == NULL)
					{
						Node *aNode = createNode(par, value);
						par->rightChild = aNode;
						aTree->count++;
						break;
					}
				}
			}
		}
	}
}

void printList(Node *aNode)
{
	if(aNode != NULL)
	{
		printList(aNode->leftChild);
		printf("%f ", aNode->value);
		printList(aNode->rightChild);
	}
}

void deleteElement(Tree *aTree, Node *aNode)
{
	if(aNode->leftChild != NULL && aNode->rightChild != NULL)
	{
		Node *max = maxElement(aNode->leftChild);
		aNode->value = max->value;
		deleteElement(aTree, max);
		return;
	}
	
	else if(aNode->highParent != NULL)
	{
		if(aNode->leftChild != NULL)
		{
			if(aNode == aNode->highParent->leftChild)
				aNode->highParent->leftChild = aNode->leftChild;
			else
				aNode->highParent->rightChild = aNode->leftChild;
		}
		
		else if(aNode->rightChild != NULL)
		{
			if(aNode == aNode->highParent->rightChild)
				aNode->highParent->rightChild = aNode->rightChild;
			else
				aNode->highParent->leftChild = aNode->rightChild;
	    }
		
		else
		{
			if(aNode == aNode->highParent->leftChild) 
				aNode->highParent->leftChild = NULL;
			else
				aNode->highParent->rightChild = NULL;
	    }
	}
	
	else if(aTree->root == aNode)
	{
		if(aNode->leftChild != NULL)
		{
			Node *tmp1 = maxElement(aNode->leftChild);
			aTree->root->value = tmp1->value;
			deleteElement(aTree, tmp1);
			return;
		}
		
		else if(aNode->rightChild != NULL)
		{
			Node *tmp2 = maxElement(aNode->rightChild);
			aTree->root->value = tmp2->value;
			deleteElement(aTree, tmp2);
			return;
		}
		
		else
		{
			aTree->root = NULL;
		}
	}
	
	free(aNode);
	aTree->count--;
}

Node *maxElement(Node *aNode)
{
	while(aNode->rightChild != NULL)
		aNode = aNode->rightChild;
	
	return aNode;
}

Node *searching(Node *aNode, float value)
{
	if(aNode != NULL)
	{
		if(value < aNode->value)
			return searching(aNode->leftChild, value);
		
		else if(value > aNode->value)
			return searching(aNode->rightChild, value);
		
		else
			return aNode;
	}
	
	else
		return NULL;
}

void deleteElementByValue(Tree *aTree, float value)
{
	if(aTree != NULL && aTree->root != NULL)
	{
		Node *toDelete = searching(aTree->root, value);
		
		if(toDelete != NULL)
			deleteElement(aTree, toDelete);
		
		else
		{
			printf("Error!\n");
			return;
		}
	}
}

void print(Tree *aTree)
{
	printf("\nAmount of elements: %i\n", aTree->count);
	
	if(aTree->count > 0)
	{
		printf("Binary tree:\n");
		printList(aTree->root);
		printf("\n");
	}
}
