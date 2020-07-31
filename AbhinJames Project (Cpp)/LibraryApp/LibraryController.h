#pragma once
#include <string>
#include <vector>
#include "ConsoleInput.h"
#include "ConsoleMenu.h"
#include "Strings.h"
#include "Library.h"

class LibraryController
{
private:
	Library* library;

public:
	LibraryController(Library* library);
	void start();
private:
	void mainMenu();
	void executeMainMenuSelection(int selection);
	void viewAllItems();
	void viewItemDetails();
	void borrowItem();
	void returnItem();

private:
	static void displayItems(const std::vector<Item*>& items);
	static std::vector<std::string> getItemStrings(std::vector<Item*> items);
	static std::vector<std::string> getItemInfoStrings(std::vector<Item*> items);
};
