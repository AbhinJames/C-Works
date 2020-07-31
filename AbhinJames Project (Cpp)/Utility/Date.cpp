#include "Date.h"
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace utility
{
	// Instance methods

	Date::Date(int year, int month, int day)
	{
		// Any year is valid, so no need to validate
		// Store argument in year field
		this->year = year;
	
		// Validate month
		if (month < 1)
			month = 1;
		else if (month > 12)
			month = 12;
	
		// Store validated month argument in month field
		this->month = month;
	
		// Validate day
		if (day < 1)
			day = 1;
		int lastDayOfMonth = getDaysInMonth(month, year);
		if (day > lastDayOfMonth)
			day = lastDayOfMonth;
	
		// Store validated day argument in day field
		this->day = day;
	
		// All of the object's fields have now been initialized with valid values
	}

	bool Date::operator ==(const Date& other)
	{
		return (this->year == other.year
			&& this->month == other.month
			&& this->day == other.day);
	}

	bool Date::operator !=(const Date& other)
	{
		return !(*this == other);
	}

	bool Date::operator <(const Date& other)
	{
		if (this->year < other.year)
			return true;
		else if (this->year > other.year)
			return false;
		else if (this->month < other.month)
			return true;
		else if (this->month > other.month)
			return false;
		else if (this->day < other.day)
			return true;
		else
			return false;
	}

	bool Date::operator <=(const Date& other)
	{
		return (*this == other || *this < other);
	}

	bool Date::operator >(const Date& other)
	{
		return !(*this <= other);
	}
	
	bool Date::operator >=(const Date& other)
	{
		return !(*this < other);
	}

	int Date::getYear() const
	{
		return year;
	}

	int Date::getMonth() const
	{
		return month;
	}

	int Date::getDay() const
	{
		return day;
	}

	bool Date::isLeapYear()
	{
		return Date::isLeapYear(this->year);
	}

	string Date::getMonthString()
	{
		return Date::getMonthString(this->month);
	}

	int Date::getDaysInMonth()
	{
		return Date::getDaysInMonth(this->month, this->year);
	}

	int Date::getYearsUntil(Date* other)
	{
		return Date::getYearsBetween(this, other);
	}

	int Date::getMonthsUntil(Date* other)
	{
		return Date::getMonthsBetween(this, other);
	}

	int Date::getDaysUntil(Date* other)
	{
		return Date::getDaysBetween(this, other);
	}

	Date Date::addYears(int years)
	{
		return Date::addYears(this, years);
	}

	Date Date::addMonths(int months)
	{
		return Date::addMonths(this, months);
	}

	Date Date::addDays(int days)
	{
		return Date::addDays(this, days);
	}

	string Date::toString()
	{
		return getMonthString() + " " + to_string(day) + ", " + to_string(year);
	}

	string Date::getInfo()
	{
		return "Is leap year = " + Strings::boolToString(isLeapYear())
			+ ", Month string = " + getMonthString()
			+ ", Days in month = " + to_string(getDaysInMonth());
	}


	// Static methods (calculated getter methods)

	bool Date::isLeapYear(int year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

	string Date::getMonthString(int month)
	{
		switch (month)
		{
		case 1: return "January";
		case 2: return "February";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return string();
		}
	}

	int Date::getDaysInMonth(int month, int year)
	{
		int daysInMonth;
		if ((month < 8 && month % 2 == 1)
			|| (month >= 8 && month % 2 == 0))
			daysInMonth = 31;
		else if (month == 2)
			daysInMonth = (isLeapYear(year)) ? 29 : 28;
		else
			daysInMonth = 30;
		return daysInMonth;
	}
	
	int Date::getYearsBetween(Date* first, Date* second)
	{
		return Date::getMonthsBetween(first, second) / 12;
	}

	int Date::getMonthsBetween(Date* first, Date* second)
	{
		return Date::getDaysBetween(first, second) / 30;
	}

	int Date::getDaysBetween(Date* first, Date* second)
	{
		int yearsDifference = second->year - first->year;
		int monthsDifference = second->month - first->month;
		int monthsBetween = yearsDifference * 12 + monthsDifference;
		int daysBetween = monthsBetween * 30 + second->day - first->day;
		return daysBetween;
	}

	void Date::normalizeMonth(int& year, int& month)
	{
		if (month < 1)
		{
			int yearOffset = (-month / 12) + 1; // Positive
			year -= yearOffset;
			month += (12 * yearOffset);
		}
		else if (month > 12)
		{
			int yearOffset = (month - 1) / 12; // Positive
			year += yearOffset;
			month -= (12 * yearOffset);
		}
	}

	Date Date::normalize(int year, int month, int day)
	{
		Date::normalizeMonth(year, month);

		while (day < 1)
		{
			if (month > 1)
				month--;
			else
			{
				month = 12;
				year--;
			}
			day += Date::getDaysInMonth(month, year);
		}
		
		int daysInMonth;
		while (day > (daysInMonth = Date::getDaysInMonth(month, year)))
		{
			if (month < 12)
				month++;
			else
			{
				month = 1;
				year++;
			}
			day -= daysInMonth;
		}
		
		Date::normalizeMonth(year, month);
		
		return Date(year, month, day);
	}

	Date Date::addYears(Date* initial, int years)
	{
		return Date(initial->getYear() + years, initial->getMonth(), initial->getDay());
	}

	Date Date::addMonths(Date* initial, int months)
	{
		return Date::normalize(initial->getYear(), initial->getMonth() + months, initial->getDay());
	}

	Date Date::addDays(Date* initial, int days)
	{
		return Date::normalize(initial->getYear(), initial->getMonth(), initial->getDay() + days);
	}
	
	Date Date::getToday()
	{
		struct tm now;
		time_t nowTime = time(0);
		localtime_s(&now, &nowTime);
		return Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
	}
}
