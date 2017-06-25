#ifndef tool_h
#define tool_h

typedef struct element
{
	float value;
	struct element *leftChild;
	struct element *rightChild;
	struct element *highParent;
}Node;

typedef struct aTree
{
	int count;
	Node *root;
}Tree;

int enterIndex();

void addValue(Tree *aTree);
void addRand(Tree *aTree);

void deleteAllElements(Tree *aTree);
void deleteOneElement(Tree *aTree);

void changeElement(Tree *aTree);
void searchElement(Tree *aTree);

void exitProgram(Tree *aTree);

Tree *createTree();										//create base of tree
void destroyTree(Tree *aTree);							//destroy base of tree

Node *createNode(Node *aParent, float value);			//create element with val value
void destroyNode(Tree *aTree, Node *aNode);				//destroy element

void insertElement(Tree *aTree, float value);			//insert element with val value
void deleteElement(Tree *aTree, Node *aNode);			//delete element
void deleteElementByValue(Tree *aTree, float value);	//delete element with val value

Node *maxElement(Node *aNode);							//return max value after aNode pointer
Node *searching(Node *aNode, float value);				//return pointer on element with val value

void printList(Node *aNode);							//print: left, root, right
void print(Tree *aTree);								//print tree

#endif
