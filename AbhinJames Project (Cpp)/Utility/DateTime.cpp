#include "DateTime.h"
using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace utility
{
	// Instance methods

	DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
		: Date(year, month, day)
	{
		if (hour < 0)
			hour = 0;
		else if (hour > 23)
			hour = 23;
		this->hour = hour;
	
		if (minute < 0)
			minute = 0;
		else if (minute > 59)
			minute = 59;
		this->minute = minute;
	
		if (second < 0)
			second = 0;
		else if (second > 59)
			second = 59;
		this->second = second;
	}

	DateTime::DateTime(int year, int month, int day)
		: DateTime(year, month, day, 0, 0, 0)
	{ }

	bool DateTime::operator ==(const DateTime& other)
	{
		return (Date::operator==(other)
			&& this->hour == other.hour
			&& this->minute == other.minute
			&& this->second == other.second);
	}

	bool DateTime::operator !=(const DateTime& other)
	{
		return !(*this == other);
	}

	bool DateTime::operator <(const DateTime& other)
	{
		if (this->getYear() < other.getYear())
			return true;
		else if (this->getYear() > other.getYear())
			return false;
		else if (this->getMonth() < other.getMonth())
			return true;
		else if (this->getMonth() > other.getMonth())
			return false;
		else if (this->getDay() < other.getDay())
			return true;
		else if (this->getDay() > other.getDay())
			return false;
		else if (this->hour < other.hour)
			return true;
		else if (this->hour > other.hour)
			return false;
		else if (this->minute < other.minute)
			return true;
		else if (this->minute > other.minute)
			return false;
		else if (this->second < other.second)
			return true;
		else
			return false;
	}

	bool DateTime::operator <=(const DateTime& other)
	{
		return (*this == other || *this < other);
	}

	bool DateTime::operator >(const DateTime& other)
	{
		return !(*this <= other);
	}

	bool DateTime::operator >=(const DateTime& other)
	{
		return !(*this < other);
	}
	
	int DateTime::getHour() const
	{
		return hour;
	}

	int DateTime::getMinute() const
	{
		return minute;
	}

	int DateTime::getSecond() const
	{
		return second;
	}

	int DateTime::getHoursUntil(DateTime* other)
	{
		return DateTime::getHoursBetween(this, other);
	}

	int DateTime::getMinutesUntil(DateTime* other)
	{
		return DateTime::getMinutesBetween(this, other);
	}

	int DateTime::getSecondsUntil(DateTime* other)
	{
		return DateTime::getSecondsBetween(this, other);
	}

	DateTime DateTime::addYears(int years)
	{
		return DateTime::addYears(this, years);
	}

	DateTime DateTime::addMonths(int months)
	{
		return DateTime::addMonths(this, months);
	}

	DateTime DateTime::addDays(int days)
	{
		return DateTime::addDays(this, days);
	}

	DateTime DateTime::addHours(int hours)
	{
		return DateTime::addHours(this, hours);
	}

	DateTime DateTime::addMinutes(int minutes)
	{
		return DateTime::addMinutes(this, minutes);
	}

	DateTime DateTime::addSeconds(int seconds)
	{
		return DateTime::addSeconds(this, seconds);
	}
	
	string DateTime::toString()
	{
		return Date::toString()
			+ ", " + Strings::intToString(hour, 2)
			+ ":" + Strings::intToString(minute, 2)
			+ ":" + Strings::intToString(second, 2);
	}


	// Static methods

	int DateTime::getHoursBetween(DateTime* first, DateTime* second)
	{
		return DateTime::getMinutesBetween(first, second) / 60;
	}

	int DateTime::getMinutesBetween(DateTime* first, DateTime* second)
	{
		return DateTime::getSecondsBetween(first, second) / 60;
	}

	int DateTime::getSecondsBetween(DateTime* first, DateTime* second)
	{
		int daysBetween = Date::getDaysBetween(first, second);
		int hoursDifference = second->hour - first->hour;
		int minutesDifference = second->minute - first->minute;
		int secondsBetween =
			(daysBetween * 24 * 60 * 60)
			+ (hoursDifference * 60 * 60)
			+ (minutesDifference * 60)
			+ (second->second - first->second);
		return secondsBetween;
	}

	// 
	DateTime DateTime::normalize(Date* initial, int hours, int minutes, int seconds)
	{
		if (seconds < 0)
		{
			int minuteOffset = ((-seconds - 1) / 60) + 1; // Positive
			minutes -= minuteOffset;
			seconds += (60 * minuteOffset);
		}
		else if (seconds >= 60)
		{
			int minuteOffset = (seconds / 60); // Positive
			minutes += minuteOffset;
			seconds -= (60 * minuteOffset);
		}

		if (minutes < 0)
		{
			int hourOffset = ((-minutes - 1) / 60) + 1; // Positive
			hours -= hourOffset;
			minutes += (60 * hourOffset);
		}
		else if (minutes >= 60)
		{
			int hourOffset = (minutes / 60); // Positive
			hours += hourOffset;
			minutes -= (60 * hourOffset);
		}

		int days = 0;
		if (hours < 0)
		{
			int dayOffset = ((-hours - 1) / 24) + 1; // Positive
			days -= dayOffset;
			hours += (24 * dayOffset);
		}
		else if (hours >= 24)
		{
			int dayOffset = (hours / 24); // Positive
			days += dayOffset;
			hours -= (24 * dayOffset);
		}

		Date final = initial->addDays(days);
		
		return DateTime(final.getYear(),
						final.getMonth(),
						final.getDay(),
						hours, minutes, seconds);
	}

	DateTime DateTime::addYears(DateTime* initial, int years)
	{
		return DateTime(initial->getYear() + years, initial->getMonth(), initial->getDay(),
						initial->getHour(), initial->getMinute(), initial->getSecond());
	}

	DateTime DateTime::addMonths(DateTime* initial, int months)
	{
		Date final = Date::addMonths(initial, months);
		return DateTime(final.getYear(), final.getMonth(), final.getDay(),
						initial->getHour(), initial->getMinute(), initial->getSecond());
	}

	DateTime DateTime::addDays(DateTime* initial, int days)
	{
		Date final = Date::addDays(initial, days);
		return DateTime(final.getYear(), final.getMonth(), final.getDay(),
						initial->getHour(), initial->getMinute(), initial->getSecond());
	}

	DateTime DateTime::addHours(DateTime* initial, int hours)
	{
		return DateTime::normalize(initial, initial->getHour() + hours, initial->getMinute(), initial->getSecond());
	}

	DateTime DateTime::addMinutes(DateTime* initial, int minutes)
	{
		return DateTime::normalize(initial, initial->getHour(), initial->getMinute() + minutes, initial->getSecond());
	}

	DateTime DateTime::addSeconds(DateTime* initial, int seconds)
	{
		return DateTime::normalize(initial, initial->getHour(), initial->getMinute(), initial->getSecond() + seconds);
	}

	DateTime DateTime::getNow()
	{
		struct tm now;
		time_t nowTime = time(0);
		localtime_s(&now, &nowTime);
		return DateTime(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
	}
}
