#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "DateTime.h"
#include "Strings.h"

class Item
{
private:
	static int const MAX_LATE_FEE;
	static int nextId;
	
	int serialNumber;
	std::string title;
	bool isAvailableOrNot;
	utility::DateTime* dueDate;
	std::string* currentBorrowerName;
	std::vector <std::string> borrowerHistory;

public:
	Item(std::string title);
	virtual ~Item();

	int getSerial();
	std::string getTitle();
	bool isAvailable();
	utility::DateTime* getDueDate();
	std::string* getCurrentBorrowerName();
	std::vector<std::string> getBorrowerHistory();
	
	bool isOverdue();
	double getTotalLateFee();
	virtual double getLateFeePerSecond();
	
	bool borrowItem(std::string borrowerName);
	bool returnItem();

	virtual std::string toString();
	std::string getInfo();

private:
	void setDueDate(utility::DateTime* dueDate);
	void setCurrentBorrowerName(std::string* currentBorrowerName);
};
