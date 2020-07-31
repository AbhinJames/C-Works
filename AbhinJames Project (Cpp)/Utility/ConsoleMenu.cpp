#include "ConsoleMenu.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace utility
{
	// Instance members

	ConsoleMenu::ConsoleMenu(std::string title, std::string message, std::vector<std::string> options)
		: title(title), message(message), options(options)
	{ }

	ConsoleMenu::ConsoleMenu()
		: title(), message(), options()
	{ }

	string ConsoleMenu::getTitle()
	{
		return title;
	}

	string ConsoleMenu::getMessage()
	{
		return message;
	}

	string ConsoleMenu::getOption(int index)
	{
		if (index >= 0 && index < options.size())
			return options[index];
		else
			return string();
	}

	int ConsoleMenu::getSize()
	{
		return options.size();
	}

	void ConsoleMenu::setTitle(string title)
	{
		this->title = title;
	}

	void ConsoleMenu::setMessage(string message)
	{
		this->message = message;
	}

	void ConsoleMenu::setOptions(std::vector<std::string> options)
	{
		this->options = options;
	}

	void ConsoleMenu::displayTitle()
	{
		if (title.length() > 0)
		{
			ConsoleMenu::displayLine(title);
			ConsoleMenu::newLine();
		}
	}

	void ConsoleMenu::displayMessage()
	{
		if (message.length() > 0)
		{
			ConsoleMenu::displayLine(message);
			ConsoleMenu::newLine();
		}
	}

	void ConsoleMenu::displayOptions()
	{
		for (int i = 0; i < options.size(); i++)
		{
			ConsoleMenu::displayLine(to_string(i + 1) + " - " + options[i], 1);
		}
		ConsoleMenu::newLine();
	}

	int ConsoleMenu::displayAndGetSelection()
	{
		displaySeparator();
		displayTitle();
		displayOptions();

		int min = 1;
		int max = options.size();

		int userInt;
		if (message.length() > 0)
			userInt = readInt(message, min, max);
		else
			userInt = readInt(min, max);
		
		// return option number (one-based numbering)
		return userInt;
	}

	int ConsoleMenu::displayAndGetSelectionIndex()
	{
		// return option index (zero-based numbering)
		return displayAndGetSelection() - 1;
	}


	// Static members

	const string ConsoleMenu::separator = "-------------------------";

	std::string ConsoleMenu::getSeparator()
	{
		return separator;
	}

	void ConsoleMenu::displaySeparator()
	{
		ConsoleMenu::displayLine(separator);
	}

	void ConsoleMenu::display(std::string text, unsigned int indentation)
	{
		for (int i = 0; i < indentation; i++)
			cout << "    ";
		cout << text;
	}

	void ConsoleMenu::displayLine(std::string text, unsigned int indentation)
	{
		display(text, indentation);
		cout << endl;
	}

	void ConsoleMenu::newLine(unsigned int lines)
	{
		for (int i = 0; i < lines; i++)
			cout << endl;
	}

	int ConsoleMenu::getCharacter()
	{
		int character = cin.get();
		std::streamsize cinBufferSize = cin.rdbuf()->in_avail();
		if (cinBufferSize > 0)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return character;
	}

	void ConsoleMenu::pause()
	{
		getCharacter();
	}
}
