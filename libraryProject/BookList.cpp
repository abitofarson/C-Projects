#include <iostream>
#include "Book.h"
#include "BookList.h"


// Using Bubble Sort.
bool BookList::sort(int field)
{
    bool sortSuccessful = !(field > 0 && field < 4);
    int sizeOfList = getCurrentSize();

    while(!sortSuccessful){

        if(field == 1){
            for(int unsorted = 1; unsorted < sizeOfList; unsorted++){
            Book nextBook =
            }

        }

    }

	return sortSuccessful;
}

BookList* BookList::searchTitle(const std::string& title) const
{
	// STUB

	return new Book("Dummy Title", "Dummy Author", "0");
}

BookList* BookList::searchAuthor(const std::string& author) const
{
	// STUB

	return new Book("Dummy Title", "Dummy Author", "0");
}

BookList* BookList::searchId(int id) const
{
	// STUB

	return new Book("Dummy Title", "Dummy Author", "0");
}

Book* BookList::getPointerTo(int id) const
{
	bool found = false;
	Book* curPtr = headPtr;

	while (!found && (curPtr != nullptr))
	{
		if (id == curPtr->getId())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while

	return curPtr;
} // end getPointerTo

BookList::BookList() : headPtr(nullptr), bookCount(0)
{
}

BookList::~BookList()
{
	clear();
}

int BookList::getCurrentSize() const
{
	return bookCount;
}  // end getCurrentSize

bool BookList::isEmpty() const
{
	return bookCount == 0;
}  // end isEmpty

bool BookList::add(const std::string& title, const std::string& author, int id)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)
	Book* nextBookPtr = new Book(title, author, id, headPtr);

	headPtr = nextBookPtr; // New node is now first node
	bookCount++;

	return true;
}  // end add

bool BookList::remove(int id)
{
	Book* entryNodePtr = getPointerTo(id);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRemoveItem)
	{
		// Copy data from first node to located node
		entryNodePtr->setTitle(headPtr->getTitle());
		entryNodePtr->setAuthor(headPtr->getAuthor());
		entryNodePtr->setId(headPtr->getId());

		// Delete first node
		Book* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		bookCount--;
	} // end if

	return canRemoveItem;
}  // end remove

void BookList::clear()
{
	Book* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;

		nodeToDeletePtr = headPtr;
	}  // end while
	   // headPtr is nullptr; nodeToDeletePtr is nullptr

	bookCount = 0;
}  // end clear

void BookList::display()
{
	Book* travPtr = headPtr;

	while (travPtr != nullptr)
	{
		std::cout << "\"" << travPtr->getTitle() << "\"" << " by "
			<< travPtr->getAuthor() << " (ID: "
			<< travPtr->getId() << ")" << std::endl;

		travPtr = travPtr->getNext();
	}
}

Book* BookList::getBook(int id)
{
	//stub
	Book* resultPtr = getPointerTo(id);
	Book* returnPtr = nullptr;

	if (resultPtr != nullptr)
	{
		returnPtr = new Book(resultPtr->getTitle(), resultPtr->getAuthor(), resultPtr->getId());
	}

	return returnPtr;
}

bool BookList::contains(int id) const
{
	return (getPointerTo(id) != nullptr);
}
