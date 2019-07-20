#ifndef BOOK_LIST
#define BOOK_LIST

#include <string>
#include "Book.h"

class BookList
{
private:
	Book* headPtr; // Pointer to first book in the chain;
	int bookCount; // Current count of books in the list

	/*
	* getPointerTo() finds the book with the given id and returns
	* a pointer to that book.
	*
	* @param id The book id to search for.
	* @return Pointer to the book with matching id OR nullptr if id
	* is not found.
	*/
	Book* getPointerTo(int id) const;

public:

	/*
	* Default constructor creates an empty BookList
	*/
	BookList();

	/*
	* Destructor removes all items from the heap.
	*/
	~BookList();

	/*
	* Gets the current number of books in this BookList.
	*
	* @return The integer number of books currently in the BookList.
	*/
	int getCurrentSize() const;

	/*
	* Sees whether this Booklist is empty.
	*
	* @return True if the bag is empty, or false if not.
	*/
	bool isEmpty() const;

	/*
	* Adds a new entry to this BookList.
	*
	* @param title  Title of the book to be added.
	* @param author  Author of the book to be added.
	* @param id  Id of the book to be added.
	* @return  True if addition was successful, or false if not.
	*/
	bool add(const std::string& title, const std::string& author, int id);

	/*
	* Removes one occurrence of a given book from this BookList, if possible.
	*
	* @param id Id of the book to be removed.
	* @return  True if removal was successful, or false if not.
	*/
	bool remove(int id);

	/*
	* Removes all books from this BookList.
	*/
	void clear();

	/*
	* Tests whether this BookList contains a given id.
	*
	* @param id  The id to locate.
	* @return  True if bag contains id, or false otherwise.
	*/
	bool contains(int id) const;

	/*
	* Sorts the books in this BookList with Bubble Sort.
	*
	* @param field Indicates which field to sort the BookList on.
	*              field = 1 sorts by title
	*              field = 2 sorts by author
	*              field = 3 sorts by id
	* @return True of the sort was done, false if not.
	*/
	bool sort(int field);

	/*
	* Searches this BookList for all books matching a given title.
	* Returns the matching books in a BookList sorted by author.
	*
	* @param title The title to search for.
	* @return A BookList containing the search results sorted by author.
	*/
	BookList* searchTitle(const std::string& title) const;

	/*
	* Searches this BookList for all books matching a given author.
	* Returns the matching books in a BookList sorted by title.
	*
	* @param title The author to search for.
	* @return A BookList containing the search results sorted by title.
	*/
	BookList* searchAuthor(const std::string& author) const;

	/*
	* Searches this BookList for all books matching a given id.
	* Returns the matching books in a BookList sorted by author.
	*
	* @param title The id to search for.
	* @return A BookList containing the search results sorted by author.
	*/
	BookList* searchId(int id) const;

	/*
	* Displays the contents of this BookList to cout
	*/
	void display();

	/*
	* Returns a pointer to a book with the title and author for the given id.

	* @param id The id of the book to search for.
	* @return A Book pointer to a book information for the given id or nullptr if
	*         the id is not found.
	*/
	Book* getBook(int id);

}; // end BookList

#endif
