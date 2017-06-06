#ifndef tool_h
#define tool_h

typedef struct aCoordinate
{
	int x;
	int y;
	int z;
}Coordinate;

typedef struct aPiramide
{
	Coordinate *A;
	Coordinate *B;
	Coordinate *C;
	Coordinate *D;
}Piramide;

typedef struct aList
{
	Piramide *theList[5];
	int aSize;
	int aCurrentSize;
}List;

int anAmount();

List *createList();
int addPiramide(List *Head);

void coordinate(Piramide *object);
double aSquare(Piramide *object);

void deleteList(List *Head);
void deletePir(List *Head, int i);

void printList(List *Head);
void printPir(List *Head, int i);

void printJson(List *Head);
void printPirJson(List *Head, FILE *afile, int i);

#endif
