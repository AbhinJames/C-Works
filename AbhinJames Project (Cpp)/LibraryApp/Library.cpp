#include "Library.h"
using std::vector;

Library::Library(vector<Item*> items)
	: items(items), lateFeesCollected(0)
{ }

const vector<Item*>& Library::getItems()
{
	return items;
}

int Library::getItemsCount()
{
	return items.size();
}

Item* Library::getItem(int index)
{
	if (index >= 0 && index < items.size())
		return items[index];
	else
		return nullptr;
}

double Library::getLateFeesCollected()
{
	return lateFeesCollected;
}

vector<Item*> Library::getAvailableItems()
{
	vector<Item*> availableItems = vector<Item*>();
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->isAvailable())
			availableItems.push_back(items[i]);
	}
	return availableItems;
}

vector<Item*> Library::getBorrowedItems()
{
	vector<Item*> borrowedItems = vector<Item*>();
	for (int i = 0; i < items.size(); i++)
	{
		if (!items[i]->isAvailable())
			borrowedItems.push_back(items[i]);
	}
	return borrowedItems;
}

int Library::findItemIndex(int serial)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->getSerial() == serial)
			return i;
	}
	return -1;
}

int Library::findItemIndex(std::string title)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->getTitle() == title)
			return i;
	}
	return -1;
}

void Library::addItem(Item* item)
{
	items.push_back(item);
}

bool Library::removeItem(Item* item)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == item)
			return removeItem(i);
	}
	return false;
}

bool Library::removeItem(int index)
{
	if (index < 0 || index >= items.size())
		return false;
	items.erase(items.begin() + index);
	return true;
}

void Library::collectLateFee(Item* item)
{
	double lateFee = item->getTotalLateFee();
	lateFeesCollected += lateFee;
}
