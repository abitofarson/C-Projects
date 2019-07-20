#ifndef LIBRARY
#define LIBRARY

#include <string>
#include "BookList.h"

class Library
{
private:
	BookList* inListPtr; // List of books currently checked in
	BookList* outListPtr; // List of books currently checked out
	int highestId; // Keeps track of the highest currently assigned book id

public:
	Library();
	~Library();

	/*
	* Checks in the book with selected id
	*
	* @param id The id of the book to check out
	* @return True if the book was checked in, false if not.
	*/
	bool checkIn(int id);
	
	/*
	* Checks out the book with the given id
	*
	* @param id The id of the book to check in
	* @return True of the book was checked out, false if not.
	*/
	bool checkOut(int id);

	/*
	* Adds a new book the library collection. Will automatically assign the book
	* the next id number. Id numbers are not re-used.
	*
	* @param title The title of the book to add.
	* @param author The author of the book to add.
	* @return True of the book was successfully added, false if not.
	*/
	bool addBook(const std::string& title, const std::string& author);

	/*
	* Removes the book with the given id from the library collection.
	*
	* @param id The id of the book to remove.
	* @return True if the book was successfully removed, false if not.
	*/
	bool removeBook(int id);

	/*
	* Searches for all books in the catalog matching the given title
	* and displays the list of matches including title, author, and id to the screen.
	*
	* @param title The title to search for.
	*/
	void searchTitle(const std::string& title) const;

	/*
	* Searches for all books in the catalog matching the given author
	* and displays the list of matches including title, author, and id to the screen.
	*
	* @param author The author to search for.
	*/
	void searchAuthor(const std::string& author) const;

	/*
	* Searches for the book in the catalog matching the given id
	* and displays the match's title, author, and id to the screen.
	* Book ids are unique, so there should be a maximum of 1 match.
	*
	* @param author The id to search for.
	*/
	void searchId(int id) const;

	/*
	* Displays the title, author, and id for all the books in the catalog
	* to the screen for both checked in and checked out books as separate lists.
	* Sorts the 2 lists based on the given sort field.
	* 
	* @param sortField Number to indicate how to sort the book lists.
	*                  sortField = 1 is sort by title
	*                  sortField = 2 is sort by author
	*                  sortField = 3 is sort by id
	*/
	void displayCatalog(int sortField);

	/*
	* Returns the total number of books in the catalog (checked in + checked out)
	*
	* @return Total number of books in the catalog.
	*/
	int numOfBooks();

}; // end Library

#endif