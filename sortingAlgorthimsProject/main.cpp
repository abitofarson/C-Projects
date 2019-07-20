#include <iostream>


using namespace std;

#include "Sorter.hpp"

// displays menu and returns valid option
int displayMenu();

// pause for a key the clear screen
void pause();

int main()
{
    int listSize = 10;
	int choice = 0;

	do
	{
		choice = displayMenu();

		if (choice != 5)
		{
			do
			{
				cout << "How many random integers would you like to sort? (10 or more): ";
				cin >> listSize;
				if (listSize < 10)
					cout << "Error, you must enter 10 or more." << endl;
			} while (listSize < 10);

			system("cls");

			Sorter* sorterPtr = new Sorter(listSize);

			sorterPtr->doSort(choice);

			delete sorterPtr;

			pause();
		}	

	} while (choice != 5);

    return 0;
}

int displayMenu()
{
	int choice = 0;

	cout << "Choose a sort to run:" << endl
		<< "1. Selection Sort" << endl
		<< "2. Bubble Sort" << endl
		<< "3. Insertion Sort" << endl
		<< "4. Quick Sort" << endl
		<< "5. Quit" << endl
		<< "=============================" << endl
		<< "Your choice (1-5): ";

		do
		{
			cin >> choice;
			if (choice < 1 || choice > 5)
				cout << "Invalid options, please choose again (1-5):";
		} while (choice < 1 || choice > 5);

		return choice;
}

void pause()
{
	cout << endl << "Press any key to clear screen and continue...";
	cin.ignore();
	cin.get();
	system("cls");
}