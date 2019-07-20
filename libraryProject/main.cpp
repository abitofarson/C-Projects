#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

void fillLibrary(Library* theLibrary);
void testLibrary(Library* theLibrary);
void displayLibrary(Library* theLibrary);

int main()
{
	Library* myLibrary = new Library();

	fillLibrary(myLibrary);
	testLibrary(myLibrary);
	displayLibrary(myLibrary);

	cin.ignore();
	cin.get();
	return 0;
}

void testLibrary(Library* theLibrary)
{
	for (int i = 3; i <= theLibrary->numOfBooks(); i += 3)
		theLibrary->checkOut(i);

	for (int i = 2; i <= theLibrary->numOfBooks(); i += 2)
		theLibrary->checkIn(i);

	theLibrary->removeBook(1);
	theLibrary->removeBook(6);
	theLibrary->removeBook(14);
	theLibrary->removeBook(21);
	theLibrary->removeBook(25);
	theLibrary->removeBook(50);

	for (int i = 2; i <= theLibrary->numOfBooks(); i += 2)
		theLibrary->checkOut(i);

	for (int i = 5; i <= theLibrary->numOfBooks(); i += 5)
		theLibrary->checkIn(i);

}

void displayLibrary(Library* theLibrary)
{

	cout << "** SORTING BY TITLE **" << endl
		<< "======================" << endl;
	theLibrary->displayCatalog(1);
	cout << "END OF SORTING BY TITLE" << endl
		 << "=======================" << endl;

	cout << endl << "** SORTING BY AUTHOR **" << endl
		<< "=======================" << endl;
	theLibrary->displayCatalog(2);
	cout << endl << "END OF SORTING BY AUTHOR" << endl
		         << "========================" << endl;

	cout << endl << "** SORTING BY ID **" << endl
		<< "===================" << endl;
	theLibrary->displayCatalog(3);
	cout << endl << "END OF SORTING BY ID" << endl
		         << "====================" << endl;

	cout << endl << "** PERFORMING VARIOUS TEST SEARCHES **" << endl
		<< "======================================" << endl;
	theLibrary->searchAuthor("King, Stephen");
	theLibrary->searchAuthor("Koontz, Dean");
	theLibrary->searchTitle("Jumper");
	theLibrary->searchTitle("Twilight");
	theLibrary->searchId(13);
	theLibrary->searchId(14);
}

void fillLibrary(Library* theLibrary)
{
	theLibrary->addBook("Tommyknockers", "King, Stephen");
	theLibrary->addBook("Jumper", "Gould, Steven");
	theLibrary->addBook("Ex-Patriots", "Clines, Peter");
	theLibrary->addBook("Fight Club", "Palahniuk, Chuck");
	theLibrary->addBook("Jurassic Park", "Chrichton, Michael");
	theLibrary->addBook("Children of the New World", "Weinstein, Alexander");
	theLibrary->addBook("The Road", "McCarthy, Cormac");
	theLibrary->addBook("Misery", "King, Stephen");
	theLibrary->addBook("Reflex", "Gould, Steven");
	theLibrary->addBook("Phantoms in the Brain", "Ramachandran, VS");
	theLibrary->addBook("14", "Clines, Peter");
	theLibrary->addBook("Tommyknockers", "King, Stephen");
	theLibrary->addBook("We Sold Our Souls", "Hendrix, Grady");
	theLibrary->addBook("The Mist", "King, Stephen");
	theLibrary->addBook("Kill Creek", "Thomas, Scott");
	theLibrary->addBook("The Ice Limit", "Preston, Douglas");
	theLibrary->addBook("Old Man's War", "Scalzi, John");
	theLibrary->addBook("The Running Man", "King, Stephen");
	theLibrary->addBook("The Hike", "Magary, Drew");
	theLibrary->addBook("Pet Semetary", "King, Stephen");
	theLibrary->addBook("Salem's Lot", "King, Stephen");
	theLibrary->addBook("Collected Stories", "Dick, Philip K.");
	theLibrary->addBook("Ex-Heroes", "Clines, Peter");
	theLibrary->addBook("The Pragmatic Programmer", "Hunt, Andrew");
	theLibrary->addBook("The C++ Programming Language", "Stroustrup, Bjarne");
	theLibrary->addBook("Fight Club", "Palahniuk, Chuck");
	theLibrary->addBook("The Road", "McCarthy, Cormac");
	theLibrary->addBook("The Mist", "King, Stephen");
	theLibrary->addBook("Collected Stories", "Dick, Philip K.");
	theLibrary->addBook("The Hike", "Magary, Drew");
}