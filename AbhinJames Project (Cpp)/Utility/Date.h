#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Strings.h"

namespace utility
{
	class Date
	{
	private:
		int year;
		int month;
		int day;

	public:
		Date(int year, int month, int day);

		bool operator ==(const Date& other);
		bool operator !=(const Date& other);
		bool operator <(const Date& other);
		bool operator <=(const Date& other);
		bool operator >(const Date& other);
		bool operator >=(const Date& other);

		int getYear() const;
		int getMonth() const;
		int getDay() const;

		bool isLeapYear();
		std::string getMonthString();
		int getDaysInMonth();
		int getYearsUntil(Date* other);
		int getMonthsUntil(Date* other);
		int getDaysUntil(Date* other);
		Date addYears(int years);
		Date addMonths(int months);
		Date addDays(int days);

		std::string toString();
		std::string getInfo();

		// Static members
		static bool isLeapYear(int year);
		static std::string getMonthString(int month);
		static int getDaysInMonth(int month, int year);
		static int getYearsBetween(Date* first, Date* second);
		static int getMonthsBetween(Date* first, Date* second);
		static int getDaysBetween(Date* first, Date* second);
		static Date addYears(Date* initial, int years);
		static Date addMonths(Date* initial, int months);
		static Date addDays(Date* initial, int days);
		static void normalizeMonth(int& year, int& month);
		static Date normalize(int year, int month, int day);
		static Date getToday();
	};
}
