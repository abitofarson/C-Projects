#ifndef BOOK
#define BOOK

#include <string>

class Book
{
private:
	std::string title; // Book title
	std::string author; // Book author
	int id; // Book id number
	Book* next; // Pointer to next node

public:

	/*
	* Book() creates a Book with empty string for title and author,
	* zero for id, and nullptr for next.
	*/
	Book();

	/*
	* Parameterized Book() creates a Book with given title, author, 
	* id and nullptr for next.
	*
	* @param newTitle The title to assign to the book.
	* @param newAuthor The author to assign to the book.
	* @param newId The id to assign to the book.
	*/
	Book(const std::string& newTitle, const std::string& newAuthor, int newId);

	/*
	* Parameterized Book() creates a Book with given title, author,
	* id and pointer for next.
	*
	* @param newTitle The title to assign to the book.
	* @param newAuthor The author to assign to the book.
	* @param newId The id to assign to the book.
	* @param nextBookPtr The Book pointer to assign to next.
	*/
	Book(const std::string& newTitle, const std::string& newAuthor, int newId, Book* nextBookPtr);
	
	/*
	* setTitle() is the mutator method for title.
	* 
	* @param newTitle The title to assign to the book.
	*/
	void setTitle(const std::string& newTitle);

	/*
	* setAuthor() is the mutator method for author.
	*
	* @param newAuthor The author to assign to the book.
	*/
	void setAuthor(const std::string& newAuthor);

	/*
	* setId() is the mutator method for author.
	*
	* @param newId The id to assign to the book.
	*/
	void setId(int newId);

	/*
	* setNext() is the mutator method for next.
	*
	* @param nextBookPtr The Book pointer to assign to next.
	*/
	void setNext(Book* nextBookPtr);

	/*
	* getTitle() is the accessor method for author.
	*
	* @return The book's title.
	*/
	std::string getTitle() const;

	/*
	* getAuthor() is the accessor method for author.
	*
	* @return The book's author.
	*/
	std::string getAuthor() const;

	/*
	* getId() is the accessor method for id.
	*
	* @return The book's id.
	*/
	int getId() const;

	/*
	* getNext() is the accessor method for next.
	*
	* @return The Book pointer stored in next.
	*/
	Book* getNext() const;
}; // end Book

#endif