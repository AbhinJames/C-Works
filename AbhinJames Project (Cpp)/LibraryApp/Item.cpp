#include "Item.h"
using std::string;
using std::vector;
using utility::Date;
using utility::DateTime;
using utility::Strings;

int const Item::MAX_LATE_FEE = 5.00;
int Item::nextId = 1000;







Item::Item(std::string title)
{
	this->title = title;
	this->serialNumber = nextId;
	this->nextId++;
	this->isAvailableOrNot = true;
	this->currentBorrowerName = nullptr;
	this->dueDate = nullptr;
	this->borrowerHistory = {};

}

Item::~Item()
{
		
}

int Item::getSerial()
{
	return serialNumber;
}

string Item::getTitle()
{
	return title;
}

bool Item::isAvailable()
{
	return true;
}

DateTime* Item::getDueDate()
{
	return dueDate;
}

string* Item::getCurrentBorrowerName()
{
	return currentBorrowerName;
}

 vector<string> Item::getBorrowerHistory()
{
	 return borrowerHistory;
}

bool Item::isOverdue()
{
	if(DateTime::getNow() > *dueDate)
		return true;
	else
		return false;
}

double Item::getTotalLateFee()
{

	if (isOverdue())
	{
		return 0.05 * dueDate->getSecondsUntil(dueDate);
	}

}


double Item::getLateFeePerSecond()
{
	return 0.05;
}

bool Item::borrowItem(string borrowerName)
{
	if (isAvailable())
	{
		this->isAvailableOrNot = false;
		setDueDate(this->dueDate);
		string* currentBorrowerName = new string(borrowerName);
		setCurrentBorrowerName(currentBorrowerName);
		borrowerHistory.push_back(borrowerName);
	}
	else
		return false;
}

bool Item::returnItem()
{
	if(isAvailable())
		return false;
	else
	{
		this->isAvailableOrNot = true;
		this->dueDate = nullptr;
		this->currentBorrowerName = nullptr;
		return true;
	}
}


string Item::toString()
{
	return "#" + std::to_string(serialNumber) + "  " + title + " ";
}

string Item::getInfo()
{
	if (isAvailable() && !isOverdue())
		return "#" + std::to_string(serialNumber) + "  " + title + "Available to borrow!";
	else
		return "#" + std::to_string(serialNumber) + "  " + title + "Unavailable to borrow!" + "Currently borrowed by: " + *currentBorrowerName + "Due by: "  + "Late fees: " + std::to_string(getTotalLateFee());
		
}

void Item::setDueDate(DateTime* dueDate)
{
	dueDate = this->dueDate;
}

void Item::setCurrentBorrowerName(string* currentBorrowerName)
{
	currentBorrowerName = this->currentBorrowerName;
}
