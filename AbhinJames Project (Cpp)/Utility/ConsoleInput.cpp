#include "ConsoleInput.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace utility
{
	char readChar()
	{
		char character;
		cin >> character;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return character;
	}

	char readChar(char options[], int optionsCount)
	{
		while (true)
		{
			char character = readChar();
			for (int i = 0; i < optionsCount; i++)
			{
				if (options[i] == character)
					return character;
			}

			cout << "    Error: Invalid character. '"
				<< character << "' is not in the set of options { ";
			for (int i = 0; i < optionsCount; i++)
				cout << options[i] << " ";
			cout << "}" << endl;
		}
	}

	char readChar(string message)
	{
		cout << message << endl;
		return readChar();
	}

	char readChar(string message, char options[], int optionsCount)
	{
		cout << message << endl;
		return readChar(options, optionsCount);
	}

	string readWord()
	{
		string cinWord;
		cin >> cinWord;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return cinWord;
	}

	string readWord(string message)
	{
		cout << message << endl;
		return readWord();
	}

	string readLine()
	{
		string cinLine;
		std::getline(cin, cinLine);
		return cinLine;
	}

	string readLine(string message)
	{
		cout << message << endl;
		return readLine();
	}

	int readInt()
	{
		int cinInt;
		cin >> cinInt;
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "    Error: Invalid integer format" << endl;
			cin >> cinInt;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return cinInt;
	}

	int readInt(int min, int max)
	{
		int cinInt = readInt();
		while (cinInt < min || cinInt > max)
		{
			cout << "    Error: Out of bounds. " << cinInt << " is not between " << min << " and " << max << endl;
			cinInt = readInt();
		}
		return cinInt;
	}

	int readInt(string message)
	{
		cout << message << endl;
		return readInt();
	}

	int readInt(string message, int min, int max)
	{
		cout << message << endl;
		return readInt(min, max);
	}

	double readDouble()
	{
		double cinDouble;
		cin >> cinDouble;
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "    Error: Invalid number format" << endl;
			cin >> cinDouble;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return cinDouble;
	}

	double readDouble(double min, double max)
	{
		double cinDouble = readDouble();
		while (cinDouble < min || cinDouble > max)
		{
			cout << "    Error: Out of bounds. " << cinDouble << " is not between " << min << " and " << max << endl;
			cinDouble = readDouble();
		}
		return cinDouble;
	}

	double readDouble(string message)
	{
		cout << message << endl;
		return readDouble();
	}

	double readDouble(string message, double min, double max)
	{
		cout << message << endl;
		return readDouble(min, max);
	}
}
