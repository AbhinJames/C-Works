#pragma once
#include <iostream>
#include <string>

namespace utility
{
	char readChar();
	char readChar(char options[], int optionsCount);
	char readChar(std::string message);
	char readChar(std::string message, char options[], int optionsCount);

	std::string readWord();
	std::string readWord(std::string message);

	std::string readLine();
	std::string readLine(std::string message);

	int readInt();
	int readInt(int min, int max);
	int readInt(std::string message);
	int readInt(std::string message, int min, int max);

	double readDouble();
	double readDouble(double min, double max);
	double readDouble(std::string message);
	double readDouble(std::string message, double min, double max);
}
