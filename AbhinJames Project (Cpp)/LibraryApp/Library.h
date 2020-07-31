#pragma once
#include <vector>
#include "Item.h"

class Library
{
private:
	std::vector<Item*> items;
	double lateFeesCollected;

public:
	Library(std::vector<Item*> items);

	const std::vector<Item*>& getItems();
	int getItemsCount();
	Item* getItem(int index);
	double getLateFeesCollected();

	std::vector<Item*> getAvailableItems();
	std::vector<Item*> getBorrowedItems();
	
	int findItemIndex(int serial);
	int findItemIndex(std::string title);

	void addItem(Item* item);
	bool removeItem(Item* item);
	bool removeItem(int index);

	void collectLateFee(Item* item);
};
