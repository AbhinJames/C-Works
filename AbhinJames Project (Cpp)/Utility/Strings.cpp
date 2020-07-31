#include "Strings.h"
using std::string;

namespace utility
{
	string Strings::boolToString(bool value)
	{
		return (value) ? "True" : "False";
	}

	std::string Strings::intToString(int value, unsigned int minimumDigits)
	{
		bool negative = (value < 0);
		if (negative)
			value *= -1;
		string valueString = std::to_string(value);

		std::stringstream stream;
		if (negative)
			stream << '-';
		if (valueString.length() < minimumDigits)
		{
			int digitsToPad = minimumDigits - valueString.length();
			for (int i = 0; i < digitsToPad; i++)
				stream << '0';
		}
		stream << valueString;
		return stream.str();
	}

	string Strings::doubleToString(double value) // Automatic precision
	{
		unsigned int precision = 0;
		while (true)
		{
			double multiple = pow(10, precision) * value;
			long long truncated = (long long)multiple;
			if (multiple != truncated)
				precision++;
			else
				break;
		}
		return doubleToString(value, precision);
	}

	string Strings::doubleToString(double value, unsigned int precision)
	{
		std::stringstream stream;
		stream.precision(precision);
		stream << std::fixed;
		stream << value;
		return stream.str();
	}

	string Strings::doubleToCurrencyString(double value)
	{
		return "$" + doubleToString(value, 2);
	}

	string Strings::applyFixedLength(string s, unsigned int length, bool ellipsis)
	{
		unsigned int originalLength = (unsigned int)s.length();
		if (length == originalLength)
			return s;
		
		std::stringstream stream;
		if (length < originalLength)
		{
			int charsToCopy = (ellipsis) ? length - 3 : length;
			stream << s.substr(0, charsToCopy);
			if (ellipsis)
				stream << "...";
		}
		else // if (length > originalLength)
		{
			stream << s;
			int charsToPad = length - originalLength;
			for (int i = 0; i < charsToPad; i++)
				stream << ' ';
		}
		return stream.str();
	}
}
