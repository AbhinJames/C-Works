#include "LibraryController.h"
using std::string;
using std::vector;
using utility::ConsoleMenu;
using utility::Strings;

// Instance members

LibraryController::LibraryController(Library* library)
	: library(library)
{ }

void LibraryController::start()
{
	mainMenu();
}

void LibraryController::mainMenu()
{
	string title = "Library menu";
	string message = "Select an action:";
	vector<string> options = vector<string>
	{
		"View all items",
		"View item details",
		"Borrow item",
		"Return item",
		"Exit"
	};
	ConsoleMenu consoleMenu = ConsoleMenu(title, message, options);
	
	while (true)
	{
		int selection = consoleMenu.displayAndGetSelection();
		consoleMenu.newLine();
		if (selection == options.size())
			return;
		executeMainMenuSelection(selection);
	}
}

void LibraryController::executeMainMenuSelection(int selection)
{
	switch (selection)
	{
	case 1:
		viewAllItems();
		break;
	case 2:
		viewItemDetails();
		break;
	case 3:
		borrowItem();
		break;
	case 4:
		returnItem();
		break;
	}
}

void LibraryController::viewAllItems()
{
	ConsoleMenu::displaySeparator();
	ConsoleMenu::displayLine("View all items");
	ConsoleMenu::newLine();

	ConsoleMenu::displayLine("Available items:");
	ConsoleMenu::newLine();
	displayItems(library->getAvailableItems());
	ConsoleMenu::newLine();

	ConsoleMenu::displayLine("Borrowed items:");
	ConsoleMenu::newLine();
	displayItems(library->getBorrowedItems());
	ConsoleMenu::pause();
}

void LibraryController::viewItemDetails()
{
	const vector<Item*>& items = library->getItems();
	if (items.size() < 1)
	{
		ConsoleMenu::displaySeparator();
		ConsoleMenu::newLine();
		ConsoleMenu::displayLine("Error: No items to view", 1);
		ConsoleMenu::pause();
		return;
	}

	string title = "View item details";
	string message = "Select an item to view:";
	vector<string> options = getItemStrings(items);
	options.push_back("Cancel");
	ConsoleMenu consoleMenu = ConsoleMenu(title, message, options);

	int selectionIndex = consoleMenu.displayAndGetSelectionIndex();
	consoleMenu.newLine();
	if (selectionIndex == options.size() - 1)
		return;

	Item* item = items[selectionIndex];
	vector<string> borrowerHistory = item->getBorrowerHistory();

	consoleMenu.displayLine(item->toString());
	consoleMenu.displayLine(item->getInfo(), 3);

	if (borrowerHistory.size() > 0)
	{
		consoleMenu.displayLine("Borrower history:");
		for (int i = 0; i < borrowerHistory.size(); i++)
			consoleMenu.displayLine(borrowerHistory[i], 3);
	}
	else
	{
		consoleMenu.displayLine("No borrower history");
	}

	consoleMenu.pause();
}

void LibraryController::borrowItem()
{
	vector<Item*> availableItems = library->getAvailableItems();
	if (availableItems.size() < 1)
	{
		ConsoleMenu::displaySeparator();
		ConsoleMenu::newLine();
		ConsoleMenu::displayLine("Error: No available items to borrow", 1);
		ConsoleMenu::pause();
		return;
	}

	string title = "Borrow item";
	string message = "Select an item to borrow:";
	vector<string> options = getItemStrings(availableItems);
	options.push_back("Cancel");
	ConsoleMenu consoleMenu = ConsoleMenu(title, message, options);
	
	int selectionIndex = consoleMenu.displayAndGetSelectionIndex();
	consoleMenu.newLine();
	if (selectionIndex == options.size() - 1)
		return;
	
	string borrowerName = utility::readLine("Enter borrower name:");
	Item* item = availableItems[selectionIndex];
	bool success = item->borrowItem(borrowerName);
	consoleMenu.newLine();
	
	if (success)
	{
		consoleMenu.displayLine("Successfully borrowed item", 1);
		consoleMenu.displayLine(item->getInfo(), 2);
	}
	else
		consoleMenu.displayLine("Error: Failed to borrow item", 1);

	consoleMenu.pause();
}

void LibraryController::returnItem()
{
	vector<Item*> borrowedItems = library->getBorrowedItems();
	if (borrowedItems.size() < 1)
	{
		ConsoleMenu::displaySeparator();
		ConsoleMenu::newLine();
		ConsoleMenu::displayLine("Error: No borrowed items to return", 1);
		ConsoleMenu::pause();
		return;
	}

	string title = "Return item";
	string message = "Select an item to return:";
	vector<string> options = getItemStrings(borrowedItems);
	options.push_back("Cancel");
	ConsoleMenu consoleMenu = ConsoleMenu(title, message, options);

	int selectionIndex = consoleMenu.displayAndGetSelectionIndex();
	consoleMenu.newLine();
	if (selectionIndex == options.size() - 1)
		return;
	
	Item* item = borrowedItems[selectionIndex];
	string borrowerName = (item->getCurrentBorrowerName() != nullptr)
		? *item->getCurrentBorrowerName()
		: string();
	bool overdue = item->isOverdue();
	double lateFee = item->getTotalLateFee();

	library->collectLateFee(item);
	bool success = item->returnItem();

	if (success)
	{
		consoleMenu.displayLine("Successfully returned item for " + borrowerName, 1);
		if (overdue)
		{
			consoleMenu.displayLine("Overdue: " + Strings::doubleToCurrencyString(lateFee)
										+ " late fee paid by " + borrowerName, 2);
			consoleMenu.displayLine("Total late fees collected by library: "
										+ Strings::doubleToCurrencyString(library->getLateFeesCollected()), 2);
		}
	}
	else
		consoleMenu.displayLine("Error: Failed to return item", 1);

	consoleMenu.pause();
}


// Static members

void LibraryController::displayItems(const std::vector<Item*>& items)
{
	vector<string> itemStrings = getItemStrings(items);
	vector<string> itemInfoStrings = getItemInfoStrings(items);
	for (int i = 0; i < itemStrings.size(); i++)
	{
		ConsoleMenu::displayLine(itemStrings[i], 1);
		ConsoleMenu::displayLine(itemInfoStrings[i], 4);
	}
}

vector<string> LibraryController::getItemStrings(vector<Item*> items)
{
	vector<string> itemStrings = vector<string>();
	for (int i = 0; i < items.size(); i++)
	{
		itemStrings.push_back(items[i]->toString());
	}
	return itemStrings;
}

vector<string> LibraryController::getItemInfoStrings(vector<Item*> items)
{
	vector<string> itemStrings = vector<string>();
	for (int i = 0; i < items.size(); i++)
	{
		itemStrings.push_back(items[i]->getInfo());
	}
	return itemStrings;
}
