#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tool.h"

Tree *createTree()
{
	Tree *aTree = (Tree *) malloc(sizeof(Tree));
	if(!aTree)
		exit(1);
	
	aTree->count = 0;
	aTree->root = NULL;
	return aTree;
}

//-------------------------------------------------------------------------

void destroyTree(Tree *aTree)
{
	if(aTree && aTree->root)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

//-------------------------------------------------------------------------

Node *createNode(Node *aParent, int val)
{
	Node *aNode = (Node *) malloc(sizeof(Node));
	if(!aNode)
		exit(2);
	
	aNode->parent = aParent;
	aNode->left = NULL;
	aNode->right = NULL;
	aNode->value = val;
	
	return aNode;
}

//-------------------------------------------------------------------------

void destroyNode(Node *aNode)
{
	if(aNode)
	{
		destroyNode(aNode->left);
		destroyNode(aNode->right);
		free(aNode);
	}
}

//-------------------------------------------------------------------------

void insertElement(Tree *aTree, int val)
{
	if(!aTree)
		exit(3);
	
	if(!aTree->root)
	{
		Node *aNode = createNode(aTree->root, val);	//(NULL, val);
		if(!aNode)
			return;
		aTree->root = aNode;
		aTree->count++;
	}
	
	else
	{
		Node *fast = aTree->root;
		Node *low = NULL;
		
		while(true)
		{
			low = fast;
			
			if(val == fast->value)
			{
				printf("Same element was added!\n");
				break;
			}
			
			else if(val < fast->value)
			{
				fast = fast->left;
				if(!fast)						//leaf
				{
					Node *aNode = createNode(low, val);
					low->left = aNode;
					aTree->count++;
					break;
				}
			}
			
			else
			{
				fast = fast->right;
				if(!fast)						//leaf
				{
					Node *aNode = createNode(low, val);
					low->right = aNode;
					aTree->count++;
					break;
				}
			}
		}
	}
}

//-------------------------------------------------------------------------

void preorderPrint(Node *aNode)
{
	if(!aNode)
		return;
	
	printf("%i ", aNode->value);
	preorderPrint(aNode->left);
	preorderPrint(aNode->right);
}

//-------------------------------------------------------------------------

void inorderPrint(Node *aNode)
{
	if(!aNode)
		return;
	
	inorderPrint(aNode->left);
	printf("%i ", aNode->value);
	inorderPrint(aNode->right);
}

//-------------------------------------------------------------------------

void postorderPrint(Node *aNode)
{
	if(!aNode)
		return;
	
	postorderPrint(aNode->left);
	postorderPrint(aNode->right);
	printf("%i ", aNode->value);
}

//-------------------------------------------------------------------------

void delElement(Tree *aTree, Node *aNode)
{
	if(aNode->left && aNode->right)
	{
		Node *max = maxVal(aNode->left);
		aNode->value = max->value;
		delElement(aTree, max);
		return;
	}
	
	else if(aNode->parent)
	{
		if(aNode->left)
		{
			if(aNode == aNode->parent->left)
				aNode->parent->left = aNode->left;
			else
				aNode->parent->right = aNode->left;
		}
	
		else if(aNode->right)
		{
			if(aNode == aNode->parent->right)
				aNode->parent->right = aNode->right;
			else
				aNode->parent->left = aNode->right;
		}
	
		else										//leaf
		{
			if(aNode == aNode->parent->left) 
				aNode->parent->left = NULL;
			else
				aNode->parent->right = NULL;
		}
	}
	
	else if(aTree->root == aNode)
	{
		if(aNode->left)
		{
			Node *tmp1 = maxVal(aNode->left);
			aTree->root->value = tmp1->value;
			delElement(aTree, tmp1);
			return;
		}
		
		else if(aNode->right)
		{
			Node *tmp2 = maxVal(aNode->right);
			aTree->root->value = tmp2->value;
			delElement(aTree, tmp2);
			return;
		}
		
		else										//leaf
		{
			aTree->root = NULL;
		}
	}
	
	free(aNode);
	aTree->count--;
}

//-------------------------------------------------------------------------

Node *minVal(Node *aNode)
{
	while(aNode->left)
		aNode = aNode->left;
	
	return aNode;
}

//-------------------------------------------------------------------------

Node *maxVal(Node *aNode)
{
	while(aNode->right)
		aNode = aNode->right;
	
	return aNode;
}

//-------------------------------------------------------------------------

Node *search(Node *aNode, int val)
{
	if(!aNode)
		return NULL;
	
	else if(val < aNode->value)
		return search(aNode->left, val);
	
	else if(val > aNode->value)
		return search(aNode->right, val);
	
	else
		return aNode;
}

//-------------------------------------------------------------------------

void delValElement(Tree *aTree, Node *aNode, int val)
{
	if(!aTree || !aNode)
	{
		printf("Error!\n");
		return;
	}
	
	Node *trash = search(aNode, val);
	
	if(trash)
		delElement(aTree, trash);
	else
	{
		printf("Error!\n");
		return;
	}
}

//-------------------------------------------------------------------------

void print(Tree *aTree, int type)
{
	printf("\nAmount of elements: %i\n", aTree->count);
	printf("Root element: %i\n", aTree->root->value);
	
	if(aTree->root)
	{
		printf("Binary tree:\n");
		
		switch(type)
		{
		case 1:
			preorderPrint(aTree->root);
			break;
		case 2:
			inorderPrint(aTree->root);
			break;
		case 3:
			postorderPrint(aTree->root);
			break;
		}
	}
}
