#include "Book.h"
using std::string;
using utility::Strings;

Book::Book(string title, string author, int pageCount)
	: Item("Book")
{
	this->author = author;
	this->numberOfPages = numberOfPages;
}

string Book::getAuthor()
{
	return author;
}

int Book::getPageCount()
{
	return numberOfPages;
}


double Book::getLateFeePerSecond()
{
	if (numberOfPages <= 100)
		return Item::getLateFeePerSecond();
	else if (numberOfPages <= 400 && numberOfPages >= 100)
		return 2 * Item::getLateFeePerSecond();
	else if (numberOfPages <= 800 && numberOfPages >= 400)
		return 3 * Item::getLateFeePerSecond();
	else if (numberOfPages >= 800)
		return 4 * Item::getLateFeePerSecond();

}


string Book::toString()
{
	return Item::toString() + "Written by: " + this->author +"  "+ "with a page count of: " +" "+ std::to_string(getPageCount());
}
