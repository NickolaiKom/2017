#include "dk_tool.h"

int main()
{
	DK_Polka *thePolka = createPolka(20);
	
	char theAuthor[] = "Name author";
	char theNazva[] = "the title of the book";
	
	addBookToPolka(thePolka, "Nikolai Gogol", "Viy");
	addBookToPolka(thePolka, "Garcia Marquez", "One Hundred Years of Solitude");
	addBookToPolka(thePolka, "Mikhail Bulgakov", "The Master and Margarita");
	addBookToPolka(thePolka, "J.R.R.Tolkien", "The Lord of the Rings");
	
	printPolka(thePolka);
		
	sortPhoneBook(DK_PhoneBook *inPhoneBook)

	printPolka(thePolka);
	
	return 0;
}