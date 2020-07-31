#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ConsoleInput.h"

namespace utility
{
	class ConsoleMenu
	{
	private:
		std::string title;
		std::string message;
		std::vector<std::string> options;

	public:
		ConsoleMenu(std::string title, std::string message, std::vector<std::string> options);
		ConsoleMenu();

		std::string getTitle();
		std::string getMessage();
		std::string getOption(int index);
		int getSize();

		void setTitle(std::string title);
		void setMessage(std::string message);
		void setOptions(std::vector<std::string> options);

		void displayTitle();
		void displayMessage();
		void displayOptions();

		int displayAndGetSelection();
		int displayAndGetSelectionIndex();

	private:
		static const std::string separator;
	public:
		static std::string getSeparator();
		static void displaySeparator();
		static void display(std::string text, unsigned int indentation = 0);
		static void displayLine(std::string text, unsigned int indentation = 0);
		static void newLine(unsigned int lines = 1);
		static int getCharacter();
		static void pause();
	};
}
