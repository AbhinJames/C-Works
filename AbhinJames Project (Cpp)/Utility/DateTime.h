#pragma once
#include <string>
#include <ctime>
#include "Date.h"
#include "Strings.h"

namespace utility
{
	class DateTime : public Date
	{
	private:
		int hour;
		int minute;
		int second;

	public:
		DateTime(int year, int month, int day, int hour, int minute, int second);
		DateTime(int year, int month, int day);
		
		bool operator ==(const DateTime& other);
		bool operator !=(const DateTime& other);
		bool operator <(const DateTime& other);
		bool operator <=(const DateTime& other);
		bool operator >(const DateTime& other);
		bool operator >=(const DateTime& other);
		
		int getHour() const;
		int getMinute() const;
		int getSecond() const;

		int getHoursUntil(DateTime* other);
		int getMinutesUntil(DateTime* other);
		int getSecondsUntil(DateTime* other);

		DateTime addYears(int years);
		DateTime addMonths(int months);
		DateTime addDays(int days);
		DateTime addHours(int hours);
		DateTime addMinutes(int minutes);
		DateTime addSeconds(int seconds);

		std::string toString();
		
		static int getHoursBetween(DateTime* first, DateTime* second);
		static int getMinutesBetween(DateTime* first, DateTime* second);
		static int getSecondsBetween(DateTime* first, DateTime* second);
		static DateTime normalize(Date* initial, int hours, int minutes, int seconds);
		static DateTime addYears(DateTime* initial, int years);
		static DateTime addMonths(DateTime* initial, int months);
		static DateTime addDays(DateTime* initial, int days);
		static DateTime addHours(DateTime* initial, int hours);
		static DateTime addMinutes(DateTime* initial, int minutes);
		static DateTime addSeconds(DateTime* initial, int seconds);
		static DateTime getNow();
	};
}
