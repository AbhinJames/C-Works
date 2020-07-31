#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

namespace utility
{
	class Strings
	{
	public:
		static std::string boolToString(bool value);
		static std::string intToString(int value, unsigned int minimumDigits = 0);
		static std::string doubleToString(double value);
		static std::string doubleToString(double value, unsigned int precision);
		static std::string doubleToCurrencyString(double value);
		static std::string applyFixedLength(std::string s, unsigned int length, bool ellipsis = true);
	};
}
