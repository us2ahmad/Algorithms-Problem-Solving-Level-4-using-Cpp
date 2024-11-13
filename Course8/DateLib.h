#pragma once
#include <iostream>
#include <ctime>

#pragma warning(disable: 4996)

using namespace std;

namespace DateLib 
{
	struct stDate
	{
		short Year;
		short Month;
		short Day;
	};

	short ReadNumber(const string& message)
	{
		printf(message.c_str());
		short number;
		cin >> number;
		return number;
	}

	stDate ReadFullDate()
	{
		stDate date;
		date.Day = ReadNumber("Please Enter a Day ? ");
		cout << endl;
		date.Month = ReadNumber("Please Enter a Month ? ");
		cout << endl;
		date.Year = ReadNumber("Please Enter a Year ? ");
		cout << endl;

		return date;
	}
	
	bool IsLeapYear(short year)
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}

	int GetDaysFromYear(short year) 
	{
		return IsLeapYear(year) ? 366 : 365 ;
	}
	
	int GetHoursFromYear(short year) 
	{
		return GetDaysFromYear(year) * 24;
	}
	
	int GetMinutesFromYear(short year)
	{
		return GetHoursFromYear(year) * 60;
	}
	
	int GetSecondsFromYear(int minutes)
	{
		return GetMinutesFromYear(minutes) * 60;
	}

	short GetDaysNumberInMonth(short year, short month)
	{
		if (month < 1 || month>12)
			return 0;

		short daysNumberInMonth[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

		return month == 2 && IsLeapYear(year) ? 29 : daysNumberInMonth[month - 1];
	}

	bool IsLastDayInMonth(stDate date)
	{
		return GetDaysNumberInMonth(date.Year, date.Month) == date.Day;
	}

	bool IsLastMonthInYear(short month)
	{
		return month == 12;
	}

	bool IsDate1EqualDate2(stDate date1, stDate date2)
	{
		return date2.Year == date1.Year && date2.Month == date1.Month && date2.Day == date1.Day;
	}

	bool IsDate1BeforeDate2(stDate date1,stDate date2)
	{
		return date2.Year > date1.Year ? true : (date2.Year == date1.Year ? date2.Month > date1.Month ? true : ( date2.Month == date1.Month ? date2.Day > date1.Day : false ): false);
	}

	short GetDayOrder(short year,short month,short day = 1)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;
	
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	stDate IncreaseDateByOneDay(stDate date)
	{
		if (IsLastDayInMonth(date))
		{
			if (IsLastMonthInYear(date.Month))
			{
				date.Month = 1;
				date.Year++;
			}
			else
				date.Month++;

			date.Day = 1;
		}
		else
			date.Day++;

		return date;
	}

	stDate IncreaseDateByXDays(stDate date, short days)
	{
		for (short i = 0; i < days; i++)
		{
			date = IncreaseDateByOneDay(date);
		}

		return date;
	}

	stDate IncreaseDateByOneWeek(stDate date)
	{
		for (short i = 0; i < 7; i++)
		{
			date = IncreaseDateByOneDay(date);

		}
		return date;
	}

	stDate IncreaseDateByXWeeks(stDate date, short weeks)
	{
		for (short i = 0; i < weeks; i++)
		{
			date = IncreaseDateByOneWeek(date);

		}

		return date;
	}

	stDate IncreaseDateByOneMonth(stDate date)
	{
		if (IsLastMonthInYear(date.Month))
		{
			date.Month = 1;
			date.Year++;
		}
		else
			date.Month++;

		short countDaysInMonth = GetDaysNumberInMonth(date.Year,date.Month);
		if (countDaysInMonth < date.Day)
			date.Day = countDaysInMonth;

		return date;
	}

	stDate IncreaseDateByXMonths(stDate date, short months)
	{
		for (short i = 0; i < months; i++)
		{
			date = IncreaseDateByOneMonth(date);
		}

		return date;
	}

	stDate IncreaseDateByOneYear(stDate date)
	{
		date.Year++;

		return date;
	}

	stDate IncreaseDateByXYears(stDate date, short years)
	{
		for (short i = 0; i < years; i++)
		{
			date=IncreaseDateByOneYear(date);

		}		return date;
	}	

	stDate IncreaseDateByXYearsFaster(stDate date, short years)
	{
		date.Year += years;
		return date;
	}

	stDate IncreaseDateByOneDecade(stDate date)
	{
		date.Year += 10;

		return date;
	}

	stDate IncreaseDateByXDecades(stDate date, short decades)
	{
		for (short i = 0; i < decades; i++)
		{
			date = IncreaseDateByOneDecade(date);
		}

		return date;
	}

	stDate IncreaseDateByXDecadesFaster(stDate date, short decades)
	{
		date.Year += (10 * decades);

		return date;
	}

	stDate IncreaseDateByOneCentury(stDate date)
	{
		date.Year += 100;
		return date;
	}

	stDate IncreaseDateByOneMillennium(stDate date)
	{
		date.Year += 1000;
		return date;
	}

	short GetCountDaysFromBeginYearToEnteredDate(short year, short month,short day)
	{
		short totalDays = 0;

		for (short i = 1; i <= month-1; i++)
			totalDays += GetDaysNumberInMonth(year, i);
	
		return totalDays + day;
	}

	stDate DateAddDays(short days,stDate date) 
	{
		short totalDays = days + GetCountDaysFromBeginYearToEnteredDate(date.Year, date.Month, date.Day);
		short daysInMonth;
		date.Month = 1;

		while (true)
		{
			 daysInMonth = GetDaysNumberInMonth(date.Year, date.Month);

			if (daysInMonth < totalDays)
			{
				totalDays -= daysInMonth;
				date.Month++;

				if (date.Month > 12)
					date.Month = 1;
			}
			else 
			{
				date.Day = totalDays;
				break;
			}

		}

		return date;
	}

	void SwapDate(stDate& date1, stDate& date2)
	{
		stDate temp;
		temp = date1;
		date1 = date2;
		date2 = temp;
	}
	
	short GetDifferenceInDays(stDate date1, stDate date2, bool includingEndDay = false) 
	{
		short days = 0;
		short swapFlagValue = 1;
	
		if (!IsDate1BeforeDate2(date1, date2)) 
		{
			swapFlagValue = -1;
			SwapDate(date1, date2);
		}
	
		while (!IsDate1EqualDate2(date1,date2))
		{
			date1 = IncreaseDateByOneDay(date1);
			days++;
		}
		return  (includingEndDay ? ++days : days) *swapFlagValue;
	}

	stDate GetDateNow()
	{
		stDate date;
		time_t t = time(0);
	
		tm* now = localtime(&t);
		
		date.Day = now->tm_mday;
		date.Month = now->tm_mon + 1;
		date.Year = now->tm_year + 1900;
	
		return date;
	}
}