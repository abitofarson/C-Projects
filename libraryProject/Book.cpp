#include "Book.h"

#include <string>

Book::Book() : title(""), author(""), id(0), next(nullptr)
{
} // end default constructor


Book::Book(const std::string& newTitle, const std::string& newAuthor, int newId) 
	: title(newTitle), author(newAuthor), id(newId), next(nullptr)
{
} // end constructor


Book::Book(const std::string& newTitle, const std::string& newAuthor, int newId, Book* nextBookPtr) 
	: title(newTitle), author(newAuthor), id(newId), next(nextBookPtr)
{
} // end constructor


void Book::setTitle(const std::string& newTitle)
{
	title = newTitle;
} // end setTitle

void Book::setAuthor(const std::string& newAuthor)
{
	author = newAuthor;
} // end setAuthor

void Book::setId(int newId)
{
	id = newId;
} // end setId

void Book::setNext(Book* nextBookPtr)
{
	next = nextBookPtr;
} // end setNext


std::string Book::getTitle() const
{
	return title;
} // end getTitle

std::string Book::getAuthor() const
{
	return author;
} // end getAuthor

int Book::getId() const
{
	return id;
} // end getId

Book* Book::getNext() const
{
	return next;
} // end getNext
