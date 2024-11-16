#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#pragma warning(disable: 4996)

using namespace std;

namespace DateLib
{
	enum enDayOfWeek { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
	
	enum enComperStatus {Before = -1, Equal = 0, After = 1};

	struct stDate
	{
		short Year;
		short Month;
		short Day;
	};

	struct stPeriod
	{
		stDate FromDate;
		stDate ToDate;
	};

	short GetDifferenceInDays(stDate date1, stDate date2, bool includingEndDay = false);//Declaration Function
	
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

	stPeriod ReadFullPeriod()
	{
		stPeriod period;
		cout << "\nEnter Start Date :\n\n";
		period.FromDate = ReadFullDate();
		cout << "\nEnter End Date :\n";
		period.ToDate = ReadFullDate();
		return period;
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

	bool IsDate1BeforeDate2(stDate date1, stDate date2)
	{
		return date2.Year > date1.Year ? true : (date2.Year == date1.Year ? date2.Month > date1.Month ? true : (date2.Month == date1.Month ? date2.Day > date1.Day : false) : false);
	}

	bool IsDate1AfterDate2(stDate date1, stDate date2) 
	{
		return !IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2);

	}

	enComperStatus GetComperDateResult(stDate date1, stDate date2)
	{
		if (IsDate1BeforeDate2(date1, date2))
			return enComperStatus::Before;

		if (IsDate1EqualDate2(date1, date2))
			return enComperStatus::Equal;

		/*if (IsDate1AfterDate2(date1, date2))
			return enComperStatus::After;*/
		
		//This IsFaster
		return enComperStatus::After;
	}

	string GetDayName(short day) 
	{
		string arrayDays[]{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
		return arrayDays[day];
	}

	short GetCountDaysFromBeginYearToEnteredDate(short year, short month, short day)
	{
		short totalDays = 0;

		for (short i = 1; i <= month - 1; i++)
			totalDays += GetDaysNumberInMonth(year, i);

		return totalDays + day;
	}

	short GetCountDaysFromBeginYearToEnteredDate(stDate date)
	{
		return GetCountDaysFromBeginYearToEnteredDate(date.Year, date.Month, date.Day);
	}
	
	short GetDayOfWeekOrder(short year, short month, short day = 1)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short GetDayOfWeekOrder(stDate date)
	{
		return GetDayOfWeekOrder(date.Year,date.Month,date.Day);
	}

	bool IsEndOfWeek(stDate date)
	{
		return GetDayOfWeekOrder(date) == enDayOfWeek::Saturday;
	}

	bool IsWeekEnd(stDate date)
	{
		return  GetDayOfWeekOrder(date) == enDayOfWeek::Friday;
	}

	bool IsBusinessDay(stDate date) 
	{
		return !IsWeekEnd(date);
	}

	short DaysUntilTheEndOfWeek(stDate date)
	{
		return 6 - GetDayOfWeekOrder(date);
	}
	
	short DaysUntilTheEndOfMonth(stDate date)
	{
		stDate date2 = date;
		date2.Day = GetDaysNumberInMonth(date2.Year, date2.Month);

		return GetDifferenceInDays(date,date2,true);
	}
	
	short DaysUntilTheEndOfYear(stDate date)
	{
		stDate date2 = date;
		
		date2.Month = 12;
		date2.Day = 31;
		
		return GetDifferenceInDays(date, date2, true);
	}

	stDate DateAddDays(short days, stDate date)
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
		stDate temp = date1;
		date1 = date2;
		date2 = temp;
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

	short GetDayInCurrentMonth(stDate date)
	{
		short countDaysInMonth = GetDaysNumberInMonth(date.Year, date.Month);
		if (countDaysInMonth < date.Day)
			return countDaysInMonth;
			
		return date.Day;
	}

#pragma region FunctionIncreaseDate

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
		return IncreaseDateByXDays(date,7);
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

		date.Day = GetDayInCurrentMonth(date);


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

		date.Day = GetDayInCurrentMonth(date);

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
		
		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate IncreaseDateByOneDecade(stDate date)
	{
		date.Year += 10;

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate IncreaseDateByXDecades(stDate date, short decades)
	{
		return IncreaseDateByXYearsFaster(date, decades * 10);
	}

	stDate IncreaseDateByXDecadesFaster(stDate date, short decades)
	{
		date.Year += (10 * decades);

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate IncreaseDateByOneCentury(stDate date)
	{
		date.Year += 100;
		
		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate IncreaseDateByOneMillennium(stDate date)
	{
		date.Year += 1000;

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

#pragma endregion

#pragma region FunctionDecreaseDate

	stDate DecreaseDateByOneDay(stDate date)
	{
		if (--date.Day == 0)
		{
			if (--date.Month == 0) 
			{
				date.Month = 12;
				date.Year--;
			}
			date.Day = GetDaysNumberInMonth(date.Year, date.Month);
		}
		
		return date;
	}

	stDate DecreaseDateByXDays(stDate date, short days)
	{
		for (short i = 0; i < days; i++)
		{
			date = DecreaseDateByOneDay(date);
		}

		return date;
	}

	stDate DecreaseDateByOneWeek(stDate date)
	{
		return DecreaseDateByXDays(date,7);
	}

	stDate DecreaseDateByXWeeks(stDate date, short weeks)
	{
		for (short i = 0; i < weeks; i++)
		{
			date = DecreaseDateByOneWeek(date);
		}

		return date;
	}

	stDate DecreaseDateByOneMonth(stDate date)
	{
		if ( --date.Month == 0)
		{
			date.Month=1;
			date.Year--;
		}
	
		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate DecreaseDateByXMonths(stDate date, short months)
	{
		for (short i = 0; i < months; i++)
		{
			date = DecreaseDateByOneMonth(date);
		}

		return date;
	}

	stDate DecreaseDateByOneYear(stDate date)
	{
		date.Year--;

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate DecreaseDateByXYears(stDate date, short years)
	{
		for (short i = 0; i < years; i++)
		{
			date = DecreaseDateByOneYear(date);
		}	
		
		return date;
	}

	stDate DecreaseDateByXYearsFaster(stDate date, short years)
	{
		date.Year -= years;

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate DecreaseDateByOneDecade(stDate date)
	{
		date.Year -= 10;

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate DecreaseDateByXDecades(stDate date, short decades)
	{
		return DecreaseDateByXYearsFaster(date, decades * 10);
	}

	stDate DecreaseDateByXDecadesFaster(stDate date, short decades)
	{
		date.Year -= (10 * decades);

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate DecreaseDateByOneCentury(stDate date)
	{
		date.Year -= 100;

		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

	stDate DecreaseDateByOneMillennium(stDate date)
	{
		date.Year -= 1000;
		
		date.Day = GetDayInCurrentMonth(date);

		return date;
	}

#pragma endregion

	short GetDifferenceInDays(stDate date1, stDate date2, bool includeEndDay)
	{
		short days = 0;
		short swapFlagValue = 1;

		if (!IsDate1BeforeDate2(date1, date2))
		{
			swapFlagValue = -1;
			SwapDate(date1, date2);
		}

		while (!IsDate1EqualDate2(date1, date2))
		{
			date1 = IncreaseDateByOneDay(date1);
			days++;
		}
		return  (includeEndDay ? ++days : days) * swapFlagValue;
	}

	short GetPeriodLengthInDays(stPeriod period, bool includeEndDay = false)
	{
		return GetDifferenceInDays(period.FromDate, period.ToDate, includeEndDay);
	}

	short CalculateVacationDays(stDate fromDate, stDate toDate)
	{

		short daysCount = 0;

		while (IsDate1BeforeDate2(fromDate, toDate))
		{
			if (IsBusinessDay(fromDate))
				daysCount++;

			fromDate = IncreaseDateByOneDay(fromDate);
		}
		return daysCount;

	}

	stDate CalculateVacationReturnDate(stDate fromDate, short daysCount)
	{
		short i = 0;

		while (i < daysCount)
		{
			if (IsBusinessDay(fromDate))
				i++;

			fromDate = IncreaseDateByOneDay(fromDate);
		}

		return fromDate;
	}

	bool IsPeriodsOverLap(stPeriod period1, stPeriod period2)
	{
		//return IsDate1BeforeDate2(period1.FromDate, period2.ToDate) && IsDate1BeforeDate2(period2.FromDate, period1.ToDate); //This My Solution

		if (GetComperDateResult(period2.ToDate, period1.FromDate) == enComperStatus::Before ||
			GetComperDateResult(period2.FromDate, period1.ToDate) == enComperStatus::After)
			return false;
		else
			return true;
	}

	bool IsDateInPeriod(stPeriod period, stDate date)
	{
		return !(GetComperDateResult(date, period.FromDate) == enComperStatus::Before ||
			GetComperDateResult(date, period.ToDate) == enComperStatus::After);
	}

	short CountOverlapDays(stPeriod period1, stPeriod period2)
	{
		if (!IsPeriodsOverLap(period1, period2))
			return 0;
	
		short overlapDaysCount = 0;

		if (GetPeriodLengthInDays(period1) < GetPeriodLengthInDays(period2))
		{
			while (!IsDate1EqualDate2(period1.FromDate, period1.ToDate))
			{
				if (IsDateInPeriod(period2, period1.FromDate))
					overlapDaysCount++;

				period1.FromDate = IncreaseDateByOneDay(period1.FromDate);
			}
		}
		else
		{
			while (!IsDate1EqualDate2(period2.FromDate, period2.ToDate))
			{
				if (IsDateInPeriod(period1, period2.FromDate))
					overlapDaysCount++;

				period2.FromDate = IncreaseDateByOneDay(period2.FromDate);
			}
		}

		return overlapDaysCount;
	}

	bool IsValidate(stDate date)
	{
		if (date.Month < 1 || date.Month > 12)
			return false;

		if (GetDaysNumberInMonth(date.Year, date.Month) < date.Day || date.Day < 1)
			return false;

		return true;
	}

	string ReadStringDate()
	{
		cout << "Please Enter Date dd/mm/yyyy ? ";
		string dateSting;
		getline(cin >> ws, dateSting);
		return dateSting;
	}

	vector<string> SplitString(string text, string delim = " ")
	{
		vector<string> vWords;
		short pos = 0;
		string sWord = "";

		while ((pos = text.find(delim)) != string::npos)
		{
			sWord = text.substr(0, pos);

			if (sWord != "")
				vWords.push_back(sWord);

			text.erase(0, pos + delim.length());
		}

		if (text != "" && !vWords.empty())
			vWords.push_back(text);

		return vWords;
	}

	stDate StringToDate(string dateString)
	{
		vector<string> vDate = SplitString(dateString, "/");

		stDate date;
		date.Day = stoi(vDate[0]);
		date.Month = stoi(vDate[1]);
		date.Year = stoi(vDate[2]);

		return date;
	}

	string DateToString(stDate date, string delim = "/")
	{
		return  to_string(date.Day) + delim + to_string(date.Month) + delim + to_string(date.Year);
	}

	string ReplaceWordInString(string text, string stringToReplace, string stringReplaceTo)
	{
		short pos = 0;
		while ((pos = text.find(stringToReplace)) != string::npos)
		{
			text = text.replace(pos, stringToReplace.length(), stringReplaceTo);
		}
		return text;

	}

	string FormateDate(stDate date, string formate = "dd/mm/yyyy")
	{
		string formattedDate = "";
		formattedDate = ReplaceWordInString(formate, "dd", to_string(date.Day));
		formattedDate = ReplaceWordInString(formattedDate, "mm", to_string(date.Month));
		formattedDate = ReplaceWordInString(formattedDate, "yyyy", to_string(date.Year));

		return formattedDate;
	}
}
