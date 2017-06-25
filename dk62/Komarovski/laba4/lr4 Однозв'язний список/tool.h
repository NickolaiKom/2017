#ifndef tool_h
#define tool_h

typedef struct aNode
{
    int value;
    struct aNode *next;
}Node;

void values(int *amount, int *pivot);
void addNodes(Node **head, int amount, int pivot);

void addElement(Node **head, int value);
void printNodes(Node *head, int pivot);
void deleteNodes(Node **head);

#endif
