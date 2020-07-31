#pragma once
#include <string>
#include "Item.h"
#include "Strings.h"

class Book : public Item
{
private:
	std::string author;
	int numberOfPages;

public:
	Book(std::string title, std::string author, int pageCount);
	
	std::string getAuthor();
	int getPageCount();

	virtual double getLateFeePerSecond() override;

	virtual std::string toString() override;
};
