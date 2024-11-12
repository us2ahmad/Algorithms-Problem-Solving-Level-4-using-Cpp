//#include <iostream>
//using namespace std;
//
//struct stDate 
//{
//	short Year;
//	short Month;
//	short Day;
//};
//
//short ReadNumber(const string& message) 
//{
//	printf( message.c_str());
//	short number;
//	cin >> number;
//	return number;
//}
//
//bool IsLeapYear(short year) 
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
//}
//
//short GetDaysCountInMonth(short year,short month)
//{
//	if (month < 1 || month >12)
//		return 0;
//
//	short arrayNumberDaysInMonth[]{31,28,31,30,31,30,31,31,30,31,30,31};
//
//	return month == 2 && IsLeapYear(year) ? 29 : arrayNumberDaysInMonth[month - 1];
//}
//
//short GetCountDaysFromBeginYearToEnteredDate(short year, short month,short day)
//{
//	short totalDays = 0;
//
//	for (short i = 1; i <= month-1; i++)
//		totalDays += GetDaysCountInMonth(year, i);
//	
//	return totalDays + day;
//}
//
//stDate DateAddDays(short days,stDate date) 
//{
//	short totalDays = days + GetCountDaysFromBeginYearToEnteredDate(date.Year, date.Month, date.Day);
//	short daysInMonth;
//	date.Month = 1;
//
//	while (true)
//	{
//		 daysInMonth = GetDaysCountInMonth(date.Year, date.Month);
//
//		if (daysInMonth < totalDays)
//		{
//			totalDays -= daysInMonth;
//			date.Month++;
//
//			if (date.Month > 12)
//				date.Month = 1;
//		}
//		else 
//		{
//			date.Day = totalDays;
//			break;
//		}
//
//	}
//
//	return date;
//}
//
//stDate ReadFullDate() 
//{
//	stDate date;
//	date.Day = ReadNumber("Please Enter a Day ? ");
//	cout << endl;
//	date.Month = ReadNumber("Please Enter a Month ? ");
//	cout << endl;
//	date.Year = ReadNumber("Please Enter a Year ? ");
//	cout << endl;
//
//	return date;
//}
//
//short ReadDaysAdd() 
//{
//	short addDay = ReadNumber("How Many days to add ? ");
//	cout << endl;
//	return addDay;
//}
//
//int main() 
//{
//	stDate date = ReadFullDate();
//	short daysAdd = ReadDaysAdd();
//
//	date = DateAddDays( daysAdd,date);
//
//	cout << "Date after adding [" << daysAdd << "] days is : "<< date.Day << "/" << date.Month << "/" << date .Year << endl;
//
//	return 0;
//}